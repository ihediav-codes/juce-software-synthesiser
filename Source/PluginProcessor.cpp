/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AutoPannerAudioProcessor::AutoPannerAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
                       
                        
#endif


// CONSTRUCTOR 
// Initialises the the synthesiser envelopes for  all four harmonics (attack and release parameters can be controlled in GUI
{    
    theADSRParameters1.attack = 0.01;
    theADSRParameters1.decay = 0.5;
    theADSRParameters1.sustain = 0.5;
    theADSRParameters1.release = 0.01;
    theADSR1.setParameters(theADSRParameters1);
    
    theADSRParameters2.attack = 0.01;
    theADSRParameters2.decay = 0.5;
    theADSRParameters2.sustain = 0.5;
    theADSRParameters2.release = 0.01;
    theADSR2.setParameters(theADSRParameters2);
    
    theADSRParameters3.attack = 0.01;
    theADSRParameters3.decay = 0.5;
    theADSRParameters3.sustain = 0.5;
    theADSRParameters3.release = 0.01;
    theADSR3.setParameters(theADSRParameters3);
    
    theADSRParameters4.attack = 0.01;
    theADSRParameters4.decay = 0.5;
    theADSRParameters4.sustain = 0.5;
    theADSRParameters4.release = 0.01;
    theADSR4.setParameters(theADSRParameters4);
}

AutoPannerAudioProcessor::~AutoPannerAudioProcessor()
{
    
}

//==============================================================================
const juce::String AutoPannerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AutoPannerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AutoPannerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AutoPannerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AutoPannerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AutoPannerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AutoPannerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AutoPannerAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String AutoPannerAudioProcessor::getProgramName (int index)
{
    return {};
}

void AutoPannerAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void AutoPannerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    
    
    // Configure four oscillators used to generate the harmonic content
    m_LfoInstance1.setFrequency(200.0f); 
    m_LfoInstance1.setDepth(1);
    m_LfoInstance1.setSamplingFrequency(44100);
    
    m_LfoInstance2.setFrequency(200.0f);
    m_LfoInstance2.setDepth(1);
    m_LfoInstance2.setSamplingFrequency(44100);
    
    m_LfoInstance3.setFrequency(200.0f);
    m_LfoInstance3.setDepth(1);
    m_LfoInstance3.setSamplingFrequency(44100);
   
    m_LfoInstance4.setFrequency(200.0f);
    m_LfoInstance4.setDepth(1);
    m_LfoInstance4.setSamplingFrequency(44100);
    
    // Set sample rate for all ADSR envelope generators
    theADSR1.setSampleRate(sampleRate);
    theADSR2.setSampleRate(sampleRate);
    theADSR3.setSampleRate(sampleRate);
    theADSR4.setSampleRate(sampleRate); 
   
   // Initialise three delay taps used for the multi-tap delay effect
    m_DelayTap1.initialise(sampleRate, 2000);
    m_DelayTap2.initialise(sampleRate, 2000);
    m_DelayTap3.initialise(sampleRate, 2000);

    m_DelayTap1.setDelay(m_delayTap1Time);
    m_DelayTap2.setDelay(m_delayTap2Time);
    m_DelayTap3.setDelay(m_delayTap3Time);

}

void AutoPannerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AutoPannerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

// Initialise three delay taps used for the multi-tap delay effect
int AutoPannerAudioProcessor::noteToFreq(int note)
    {
        float a = 440; 
        float freq;
        freq = (a/32)*pow(2, (((float)note-9)/12));
        return freq;
    }

// Main audio processing loop.    
void AutoPannerAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    float* leftData = buffer.getWritePointer(0);
    float* rightData = buffer.getWritePointer(1);
    float lfoVal1;
    float lfoVal2;
    float lfoVal3;
    float lfoVal4;
    float lfoSum;
    int midiNotenumber;

    // Process incoming MIDI messages and update oscillator frequencies and ADSR envelope states.
    if (midiMessages.isEmpty() == false)
        for (const auto metadata : midiMessages)
    {
        auto message = metadata.getMessage();
        if (message.isNoteOn())
        {
            
            // Start all ADSR envelopes 
            theADSR1.noteOn();
            theADSR2.noteOn();
            theADSR3.noteOn();
            theADSR4.noteOn();
            
            midiNotenumber = message.getNoteNumber();
            
            m_LfoInstance1.setFrequency(noteToFreq(midiNotenumber));
            m_LfoInstance1.setDepth((float)message.getVelocity()/127.0);
            
            m_LfoInstance2.setFrequency(noteToFreq(midiNotenumber+12));
            m_LfoInstance2.setDepth((float)message.getVelocity()/127.0);
            
            m_LfoInstance3.setFrequency(noteToFreq(midiNotenumber+6));
            m_LfoInstance3.setDepth((float)message.getVelocity()/127.0);
            
            m_LfoInstance4.setFrequency(noteToFreq(midiNotenumber-6));
            m_LfoInstance4.setDepth((float)message.getVelocity()/127.0);
            
            
        }
        
        // Stop all ADSR envelopes 
        if (message.isNoteOff())
        {
            theADSR1.noteOff();
            theADSR2.noteOff();
            theADSR3.noteOff();
            theADSR4.noteOff();
        }
    }
     
    
  
    // Generate audio sample-by-sample
    for (int i = 0; i < buffer.getNumSamples(); i++)
    {   
        // Generate four harmonics and apply their ADSR envelopes
        lfoVal1 = m_LfoInstance1.process()*theADSR1.getNextSample();
        lfoVal2 = m_LfoInstance2.process()*theADSR2.getNextSample();
        lfoVal3 = m_LfoInstance3.process()*theADSR3.getNextSample();
        lfoVal4 = m_LfoInstance4.process()*theADSR4.getNextSample();
        
       
        lfoSum = 0.0f;

        // Sum only the harmonics currently enabled by the user
        if (m_harmonic1On)
            lfoSum += lfoVal1;

        if (m_harmonic2On)
            lfoSum += lfoVal2;

        if (m_harmonic3On)
            lfoSum += lfoVal3;

        if (m_harmonic4On)
            lfoSum += lfoVal4;
        
        // Apply master output gain
        float drySignal = lfoSum * m_gainSliderValue;

        float outputSignal = drySignal;

        // Multi-tap delay consisting of three independent delay lines.
        if (m_delayOn)
        {
            float delayInput = drySignal + (m_feedbackSample * m_delayFeedback);

            float tap1 = delayInput;
            float tap2 = delayInput;
            float tap3 = delayInput;

            m_DelayTap1.process(tap1);
            m_DelayTap2.process(tap2);
            m_DelayTap3.process(tap3);
    
            float delayedSignal = (tap1 * 0.5f) + (tap2 * 0.3f) + (tap3 * 0.2f);

            m_feedbackSample = delayedSignal;
            
            
            // The delayed outputs are mixed with the original signal using a wet/dry control
            outputSignal = (drySignal * (1.0f - m_delayMix)) + (delayedSignal * m_delayMix);
        }
        
        
        
        
    // Automatically move the signal between left and right channel using a low-frequency sinusoidal modulation signal.   
    if (m_autoPanOn)
    {
        float panLFO = std::sin(m_autoPanPhase) * m_autoPanDepth;

        // Calculate stereo gain coefficients
        float leftGain = 0.5f * (1.0f - panLFO);
        float rightGain = 0.5f * (1.0f + panLFO);

        leftData[i] = outputSignal * leftGain;
        rightData[i] = outputSignal * rightGain;

        m_autoPanPhase += juce::MathConstants<float>::twoPi * m_autoPanRate / getSampleRate();

        if (m_autoPanPhase >= juce::MathConstants<float>::twoPi)
            m_autoPanPhase -= juce::MathConstants<float>::twoPi;
    }
    
    else
    {
        leftData[i] = outputSignal;
        rightData[i] = outputSignal;
    }
         
         
         
       
    }
}

//==============================================================================
bool AutoPannerAudioProcessor::hasEditor() const
{
    return true; 
}

juce::AudioProcessorEditor* AutoPannerAudioProcessor::createEditor()
{
    return new AutoPannerAudioProcessorEditor (*this);
}

//==============================================================================
void AutoPannerAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AutoPannerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

void AutoPannerAudioProcessor::updateParameters(int param, float value)
{
    if (param == kGain)
    {
        m_gainSliderValue = value;
        DBG("Gain = " << m_gainSliderValue);
    }
}


void AutoPannerAudioProcessor::setHarmonicEnabled(int harmonicNumber, bool enabled)
{
    if (harmonicNumber == 1)
        m_harmonic1On = enabled;

    if (harmonicNumber == 2)
        m_harmonic2On = enabled;

    if (harmonicNumber == 3)
        m_harmonic3On = enabled;

    if (harmonicNumber == 4)
        m_harmonic4On = enabled;
}




void AutoPannerAudioProcessor::setAutoPanEnabled(bool enabled)
{
    m_autoPanOn = enabled;
}

void AutoPannerAudioProcessor::setAutoPanRate(float value)
{
    m_autoPanRate = value;
}

void AutoPannerAudioProcessor::setAutoPanDepth(float value)
{
    m_autoPanDepth = value;
}



void AutoPannerAudioProcessor::setAttack1(float value)
{
    theADSRParameters1.attack = value;
    theADSR1.setParameters(theADSRParameters1);
}

void AutoPannerAudioProcessor::setRelease1(float value)
{
    theADSRParameters1.release = value;
    theADSR1.setParameters(theADSRParameters1);
}

void AutoPannerAudioProcessor::setAttack2(float value)
{
    theADSRParameters2.attack = value;
    theADSR2.setParameters(theADSRParameters2);
}

void AutoPannerAudioProcessor::setRelease2(float value)
{
    theADSRParameters2.release = value;
    theADSR2.setParameters(theADSRParameters2);
}

void AutoPannerAudioProcessor::setAttack3(float value)
{
    theADSRParameters3.attack = value;
    theADSR3.setParameters(theADSRParameters3);
}

void AutoPannerAudioProcessor::setRelease3(float value)
{
    theADSRParameters3.release = value;
    theADSR3.setParameters(theADSRParameters3);
}

void AutoPannerAudioProcessor::setAttack4(float value)
{
    theADSRParameters4.attack = value;
    theADSR4.setParameters(theADSRParameters4);
}

void AutoPannerAudioProcessor::setRelease4(float value)
{
    theADSRParameters4.release = value;
    theADSR4.setParameters(theADSRParameters4);
}



void AutoPannerAudioProcessor::setDelayEnabled(bool enabled)
{
    m_delayOn = enabled;
}

void AutoPannerAudioProcessor::setDelayTap1Time(float value)
{
    m_delayTap1Time = value;
    m_DelayTap1.setDelay(value);
}

void AutoPannerAudioProcessor::setDelayTap2Time(float value)
{
    m_delayTap2Time = value;
    m_DelayTap2.setDelay(value);
}

void AutoPannerAudioProcessor::setDelayTap3Time(float value)
{
    m_delayTap3Time = value;
    m_DelayTap3.setDelay(value);
}

void AutoPannerAudioProcessor::setDelayFeedback(float value)
{
    m_delayFeedback = value;
}

void AutoPannerAudioProcessor::setDelayMix(float value)
{
    m_delayMix = value;
}


void AutoPannerAudioProcessor::storePreset(int presetNumber)
{
    Preset* currentPreset;

    if (presetNumber == 1)
        currentPreset = &preset1;
    else if (presetNumber == 2)
        currentPreset = &preset2;
    else
        currentPreset = &preset3;

    currentPreset->gain = m_gainSliderValue;

    currentPreset->attack1 = theADSRParameters1.attack;
    currentPreset->release1 = theADSRParameters1.release;

    currentPreset->attack2 = theADSRParameters2.attack;
    currentPreset->release2 = theADSRParameters2.release;

    currentPreset->attack3 = theADSRParameters3.attack;
    currentPreset->release3 = theADSRParameters3.release;

    currentPreset->attack4 = theADSRParameters4.attack;
    currentPreset->release4 = theADSRParameters4.release;

    currentPreset->delayMix = m_delayMix;
    currentPreset->delayFeedback = m_delayFeedback;

    currentPreset->autoPanRate = m_autoPanRate;
    currentPreset->autoPanDepth = m_autoPanDepth;
}




void AutoPannerAudioProcessor::loadPreset(int presetNumber)
{
    Preset* currentPreset;

    if (presetNumber == 1)
        currentPreset = &preset1;
    else if (presetNumber == 2)
        currentPreset = &preset2;
    else
        currentPreset = &preset3;

    m_gainSliderValue = currentPreset->gain;

    setAttack1(currentPreset->attack1);
    setRelease1(currentPreset->release1);

    setAttack2(currentPreset->attack2);
    setRelease2(currentPreset->release2);

    setAttack3(currentPreset->attack3);
    setRelease3(currentPreset->release3);

    setAttack4(currentPreset->attack4);
    setRelease4(currentPreset->release4);

    setDelayMix(currentPreset->delayMix);
    setDelayFeedback(currentPreset->delayFeedback);

    setAutoPanRate(currentPreset->autoPanRate);
    setAutoPanDepth(currentPreset->autoPanDepth);
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AutoPannerAudioProcessor();
}



