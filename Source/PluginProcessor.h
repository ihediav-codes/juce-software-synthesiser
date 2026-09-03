/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "LFO.h"
#include "DelayLine.h"

//==============================================================================
/**
*/

// Parameter IDs used by updateParameters()
enum Parameters
{
    kGain,
};


// Main processor class for the synthesiser plugin
class AutoPannerAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    AutoPannerAudioProcessor();
    ~AutoPannerAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    // General parameter update function    
    void updateParameters(int param, float value);
    
    // Harmonic on/off control
    void setHarmonicEnabled(int harmonicNumber, bool enabled);
    
    // Attack and release controls for each harmonic envelope
    void setAttack1(float value);
    void setRelease1(float value);

    void setAttack2(float value);
    void setRelease2(float value);

    void setAttack3(float value);
    void setRelease3(float value);

    void setAttack4(float value);
    void setRelease4(float value);
    
     // Auto-pan effect controls
    void setAutoPanEnabled(bool enabled);
    void setAutoPanRate(float value);
    void setAutoPanDepth(float value);

    // Multi-tap delay effect controls
    void setDelayEnabled(bool enabled);
    void setDelayTap1Time(float value);
    void setDelayTap2Time(float value);
    void setDelayTap3Time(float value);
    void setDelayFeedback(float value);
    void setDelayMix(float value);
    
    // Preset store and recall functions
    void storePreset(int presetNumber);
    void loadPreset(int presetNumber);


private:
    
    // Four oscillator/LFO objects used as harmonic sound sources
    LFO m_LfoInstance1;
    LFO m_LfoInstance2;
    LFO m_LfoInstance3;
    LFO m_LfoInstance4;
    
    // ADSR envelopes for each harmonic
    juce::ADSR theADSR1;
    juce::ADSR::Parameters theADSRParameters1;
    
    juce::ADSR theADSR2;
    juce::ADSR::Parameters theADSRParameters2;
    
    juce::ADSR theADSR3;
    juce::ADSR::Parameters theADSRParameters3;
    
    juce::ADSR theADSR4;
    juce::ADSR::Parameters theADSRParameters4;
    
    
    // Three delay lines used for the multi-tap delay effect
    DelayLine m_DelayTap1;
    DelayLine m_DelayTap2;
    DelayLine m_DelayTap3;
    
    float m_gainSliderValue = 0.7f;
    
    // Three delay lines used for the multi-tap delay effect
    bool m_harmonic1On = true;
    bool m_harmonic2On = true;
    bool m_harmonic3On = true;
    bool m_harmonic4On = true;
    
    // Auto-pan parameters
    bool m_autoPanOn = false;
    float m_autoPanRate = 1.0f;
    float m_autoPanDepth = 1.0f;
    float m_autoPanPhase = 0.0f;
    
    // Multi-tap delay parameters
    bool m_delayOn = true;

    float m_delayTap1Time = 250.0f;
    float m_delayTap2Time = 500.0f;
    float m_delayTap3Time = 750.0f;

    float m_delayFeedback = 0.2f;
    float m_delayMix = 0.5f;

    // Stores the previous delayed signal for feedback
    float m_feedbackSample = 0.0f;
    
    // Structure used to store plugin settings in preset slots
    struct Preset
    {
        float gain;

        float attack1;
        float release1;

        float attack2;
        float release2;

        float attack3;
        float release3;

        float attack4;
        float release4;

        float delayMix;
        float delayFeedback;

        float autoPanRate;
        float autoPanDepth;
    };
    
     // Three user preset slots
    Preset preset1;
    Preset preset2;
    Preset preset3;
    
    int noteToFreq(int note);
    
  
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AutoPannerAudioProcessor)
};
