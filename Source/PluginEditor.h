/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.12

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AutoPannerAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                        public juce::Slider::Listener,
                                        public juce::Button::Listener
{
public:
    //==============================================================================
    AutoPannerAudioProcessorEditor (AutoPannerAudioProcessor& owner);
    ~AutoPannerAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    AutoPannerAudioProcessor& audioProcessor;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> m_gainSlider;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::ToggleButton> m_harmonic1Button;
    std::unique_ptr<juce::ToggleButton> m_harmonic2Button;
    std::unique_ptr<juce::ToggleButton> m_harmonic3Button;
    std::unique_ptr<juce::ToggleButton> m_harmonic4Button;
    std::unique_ptr<juce::Slider> m_attack1Slider;
    std::unique_ptr<juce::Slider> m_attack2Slider;
    std::unique_ptr<juce::Slider> m_attack3Slider;
    std::unique_ptr<juce::Slider> m_attack4Slider;
    std::unique_ptr<juce::Slider> m_release1Slider;
    std::unique_ptr<juce::Slider> m_release2Slider;
    std::unique_ptr<juce::Slider> m_release3Slider;
    std::unique_ptr<juce::Slider> m_release4Slider;
    std::unique_ptr<juce::ToggleButton> m_autoPanButton;
    std::unique_ptr<juce::Slider> m_autoPanRateSlider;
    std::unique_ptr<juce::Slider> m_autoPanDepthSlider;
    std::unique_ptr<juce::ToggleButton> m_delayButton;
    std::unique_ptr<juce::Slider> m_delayTap1Slider;
    std::unique_ptr<juce::Slider> m_delayTap2Slider;
    std::unique_ptr<juce::Slider> m_delayTap3Slider;
    std::unique_ptr<juce::Slider> m_delayFeedbackSlider;
    std::unique_ptr<juce::Slider> m_delayMixSlider;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<juce::Label> juce__label4;
    std::unique_ptr<juce::Label> juce__label5;
    std::unique_ptr<juce::Label> juce__label6;
    std::unique_ptr<juce::Label> juce__label7;
    std::unique_ptr<juce::Label> juce__label8;
    std::unique_ptr<juce::Label> juce__label9;
    std::unique_ptr<juce::TextButton> m_store1Button;
    std::unique_ptr<juce::TextButton> m_store2Button;
    std::unique_ptr<juce::TextButton> m_store3Button;
    std::unique_ptr<juce::TextButton> m_recall1Button;
    std::unique_ptr<juce::TextButton> m_recall2Button;
    std::unique_ptr<juce::TextButton> m_recall3Button;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Label> juce__label10;
    std::unique_ptr<juce::Label> juce__label11;
    std::unique_ptr<juce::Label> juce__label12;
    std::unique_ptr<juce::Label> juce__label13;
    std::unique_ptr<juce::Label> juce__label14;
    std::unique_ptr<juce::Label> juce__label15;
    std::unique_ptr<juce::Label> juce__label16;
    std::unique_ptr<juce::Label> juce__label17;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AutoPannerAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

