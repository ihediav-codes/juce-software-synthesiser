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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AutoPannerAudioProcessorEditor::AutoPannerAudioProcessorEditor (AutoPannerAudioProcessor& owner)
    : AudioProcessorEditor(owner),audioProcessor(owner)
{
    //[Constructor_pre] You can add your own custom stuff here..

    //[/Constructor_pre]

    m_gainSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (m_gainSlider.get());
    m_gainSlider->setRange (0, 1, 0);
    m_gainSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_gainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_gainSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff257da9));
    m_gainSlider->setColour (juce::Slider::thumbColourId, juce::Colours::crimson);
    m_gainSlider->setColour (juce::Slider::trackColourId, juce::Colour (0xff2d91bc));
    m_gainSlider->addListener (this);

    m_gainSlider->setBounds (504, 520, 136, 176);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS ("Master Gain\n")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (20.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centred);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::Label::backgroundColourId, juce::Colour (0x00921717));
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (496, 448, 160, 112);

    m_harmonic1Button.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (m_harmonic1Button.get());
    m_harmonic1Button->setButtonText (TRANS ("Harmonic 1"));
    m_harmonic1Button->addListener (this);
    m_harmonic1Button->setToggleState (true, juce::dontSendNotification);

    m_harmonic1Button->setBounds (40, 200, 127, 16);

    m_harmonic2Button.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (m_harmonic2Button.get());
    m_harmonic2Button->setButtonText (TRANS ("Harmonic 2"));
    m_harmonic2Button->addListener (this);
    m_harmonic2Button->setToggleState (true, juce::dontSendNotification);

    m_harmonic2Button->setBounds (40, 232, 127, 16);

    m_harmonic3Button.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (m_harmonic3Button.get());
    m_harmonic3Button->setButtonText (TRANS ("Harmonic 3"));
    m_harmonic3Button->addListener (this);
    m_harmonic3Button->setToggleState (true, juce::dontSendNotification);

    m_harmonic3Button->setBounds (40, 264, 127, 16);

    m_harmonic4Button.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (m_harmonic4Button.get());
    m_harmonic4Button->setButtonText (TRANS ("Harmonic 4"));
    m_harmonic4Button->addListener (this);
    m_harmonic4Button->setToggleState (true, juce::dontSendNotification);

    m_harmonic4Button->setBounds (40, 296, 127, 16);

    m_attack1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_attack1Slider.get());
    m_attack1Slider->setRange (0.01, 5, 0.01);
    m_attack1Slider->setSliderStyle (juce::Slider::LinearHorizontal);
    m_attack1Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_attack1Slider->addListener (this);

    m_attack1Slider->setBounds (144, 200, 160, 16);

    m_attack2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_attack2Slider.get());
    m_attack2Slider->setRange (0.01, 5, 0.01);
    m_attack2Slider->setSliderStyle (juce::Slider::LinearHorizontal);
    m_attack2Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_attack2Slider->addListener (this);

    m_attack2Slider->setBounds (144, 232, 160, 16);

    m_attack3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_attack3Slider.get());
    m_attack3Slider->setRange (0.01, 5, 0.01);
    m_attack3Slider->setSliderStyle (juce::Slider::LinearHorizontal);
    m_attack3Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_attack3Slider->addListener (this);

    m_attack3Slider->setBounds (144, 264, 160, 16);

    m_attack4Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_attack4Slider.get());
    m_attack4Slider->setRange (0.01, 5, 0.01);
    m_attack4Slider->setSliderStyle (juce::Slider::LinearHorizontal);
    m_attack4Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_attack4Slider->addListener (this);

    m_attack4Slider->setBounds (144, 296, 160, 16);

    m_release1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_release1Slider.get());
    m_release1Slider->setRange (0.01, 5, 0.01);
    m_release1Slider->setSliderStyle (juce::Slider::LinearHorizontal);
    m_release1Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_release1Slider->addListener (this);

    m_release1Slider->setBounds (304, 200, 160, 16);

    m_release2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_release2Slider.get());
    m_release2Slider->setRange (0.01, 5, 0.01);
    m_release2Slider->setSliderStyle (juce::Slider::LinearHorizontal);
    m_release2Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_release2Slider->addListener (this);

    m_release2Slider->setBounds (304, 232, 160, 16);

    m_release3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_release3Slider.get());
    m_release3Slider->setRange (0.01, 5, 0.01);
    m_release3Slider->setSliderStyle (juce::Slider::LinearHorizontal);
    m_release3Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_release3Slider->addListener (this);

    m_release3Slider->setBounds (304, 264, 160, 16);

    m_release4Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_release4Slider.get());
    m_release4Slider->setRange (0.01, 5, 0.01);
    m_release4Slider->setSliderStyle (juce::Slider::LinearHorizontal);
    m_release4Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_release4Slider->addListener (this);

    m_release4Slider->setBounds (304, 296, 160, 16);

    m_autoPanButton.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (m_autoPanButton.get());
    m_autoPanButton->setButtonText (TRANS ("Auto Pan"));
    m_autoPanButton->addListener (this);

    m_autoPanButton->setBounds (520, 184, 144, 24);

    m_autoPanRateSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_autoPanRateSlider.get());
    m_autoPanRateSlider->setRange (0.1, 10, 0.1);
    m_autoPanRateSlider->setSliderStyle (juce::Slider::LinearVertical);
    m_autoPanRateSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_autoPanRateSlider->addListener (this);

    m_autoPanRateSlider->setBounds (520, 208, 40, 200);

    m_autoPanDepthSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_autoPanDepthSlider.get());
    m_autoPanDepthSlider->setRange (0, 1, 0.01);
    m_autoPanDepthSlider->setSliderStyle (juce::Slider::LinearVertical);
    m_autoPanDepthSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_autoPanDepthSlider->addListener (this);

    m_autoPanDepthSlider->setBounds (584, 208, 40, 200);

    m_delayButton.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (m_delayButton.get());
    m_delayButton->setButtonText (TRANS ("Delay On"));
    m_delayButton->addListener (this);

    m_delayButton->setBounds (48, 416, 150, 24);

    m_delayTap1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_delayTap1Slider.get());
    m_delayTap1Slider->setRange (1, 2000, 1);
    m_delayTap1Slider->setSliderStyle (juce::Slider::LinearHorizontal);
    m_delayTap1Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 60, 20);
    m_delayTap1Slider->addListener (this);

    m_delayTap1Slider->setBounds (120, 456, 136, 16);

    m_delayTap2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_delayTap2Slider.get());
    m_delayTap2Slider->setRange (1, 2000, 1);
    m_delayTap2Slider->setSliderStyle (juce::Slider::LinearHorizontal);
    m_delayTap2Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 60, 20);
    m_delayTap2Slider->addListener (this);

    m_delayTap2Slider->setBounds (120, 488, 136, 16);

    m_delayTap3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_delayTap3Slider.get());
    m_delayTap3Slider->setRange (1, 2000, 1);
    m_delayTap3Slider->setSliderStyle (juce::Slider::LinearHorizontal);
    m_delayTap3Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 60, 20);
    m_delayTap3Slider->addListener (this);

    m_delayTap3Slider->setBounds (120, 520, 136, 16);

    m_delayFeedbackSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_delayFeedbackSlider.get());
    m_delayFeedbackSlider->setRange (0, 0.99, 0.01);
    m_delayFeedbackSlider->setSliderStyle (juce::Slider::LinearVertical);
    m_delayFeedbackSlider->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 40, 20);
    m_delayFeedbackSlider->addListener (this);

    m_delayFeedbackSlider->setBounds (272, 376, 40, 144);

    m_delayMixSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_delayMixSlider.get());
    m_delayMixSlider->setRange (0, 1, 0.01);
    m_delayMixSlider->setSliderStyle (juce::Slider::LinearVertical);
    m_delayMixSlider->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 60, 20);
    m_delayMixSlider->addListener (this);

    m_delayMixSlider->setBounds (384, 376, 40, 144);

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS ("Tap 1 Time")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (11.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (48, 448, 79, 32);

    juce__label4.reset (new juce::Label ("new label",
                                         TRANS ("Tap 2 Time")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (11.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centredLeft);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (48, 480, 79, 32);

    juce__label5.reset (new juce::Label ("new label",
                                         TRANS ("Tap 3 Time\n")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (11.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centredLeft);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (48, 512, 79, 32);

    juce__label6.reset (new juce::Label ("new label",
                                         TRANS ("Feedback")));
    addAndMakeVisible (juce__label6.get());
    juce__label6->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label6->setJustificationType (juce::Justification::centredLeft);
    juce__label6->setEditable (false, false, false);
    juce__label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label6->setBounds (264, 520, 150, 24);

    juce__label7.reset (new juce::Label ("new label",
                                         TRANS ("Wet/Dry Mix")));
    addAndMakeVisible (juce__label7.get());
    juce__label7->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label7->setJustificationType (juce::Justification::centredLeft);
    juce__label7->setEditable (false, false, false);
    juce__label7->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label7->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label7->setBounds (368, 520, 150, 24);

    juce__label8.reset (new juce::Label ("new label",
                                         TRANS ("Attack")));
    addAndMakeVisible (juce__label8.get());
    juce__label8->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label8->setJustificationType (juce::Justification::centredLeft);
    juce__label8->setEditable (false, false, false);
    juce__label8->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label8->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label8->setBounds (144, 168, 150, 24);

    juce__label9.reset (new juce::Label ("new label",
                                         TRANS ("Release")));
    addAndMakeVisible (juce__label9.get());
    juce__label9->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label9->setJustificationType (juce::Justification::centredLeft);
    juce__label9->setEditable (false, false, false);
    juce__label9->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label9->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label9->setBounds (304, 168, 150, 24);

    m_store1Button.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (m_store1Button.get());
    m_store1Button->setButtonText (TRANS ("Store 1"));
    m_store1Button->addListener (this);

    m_store1Button->setBounds (56, 648, 96, 24);

    m_store2Button.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (m_store2Button.get());
    m_store2Button->setButtonText (TRANS ("Store 2"));
    m_store2Button->addListener (this);

    m_store2Button->setBounds (208, 648, 96, 24);

    m_store3Button.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (m_store3Button.get());
    m_store3Button->setButtonText (TRANS ("Store 3"));
    m_store3Button->addListener (this);

    m_store3Button->setBounds (352, 648, 96, 24);

    m_recall1Button.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (m_recall1Button.get());
    m_recall1Button->setButtonText (TRANS ("Recall 1"));
    m_recall1Button->addListener (this);

    m_recall1Button->setBounds (56, 680, 96, 24);

    m_recall2Button.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (m_recall2Button.get());
    m_recall2Button->setButtonText (TRANS ("Recall 2"));
    m_recall2Button->addListener (this);

    m_recall2Button->setBounds (208, 680, 96, 24);

    m_recall3Button.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (m_recall3Button.get());
    m_recall3Button->setButtonText (TRANS ("Recall 3"));
    m_recall3Button->addListener (this);

    m_recall3Button->setBounds (352, 680, 96, 24);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS ("Depth")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (584, 400, 48, 32);

    juce__label10.reset (new juce::Label ("new label",
                                          TRANS ("Rate\n")));
    addAndMakeVisible (juce__label10.get());
    juce__label10->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label10->setJustificationType (juce::Justification::centredLeft);
    juce__label10->setEditable (false, false, false);
    juce__label10->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label10->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label10->setBounds (520, 400, 40, 32);

    juce__label11.reset (new juce::Label ("new label",
                                          TRANS ("Presets")));
    addAndMakeVisible (juce__label11.get());
    juce__label11->setFont (juce::Font (25.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label11->setJustificationType (juce::Justification::centredLeft);
    juce__label11->setEditable (false, false, false);
    juce__label11->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label11->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label11->setBounds (56, 608, 150, 24);

    juce__label12.reset (new juce::Label ("new label",
                                          TRANS ("Delay")));
    addAndMakeVisible (juce__label12.get());
    juce__label12->setFont (juce::Font (25.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label12->setJustificationType (juce::Justification::centredLeft);
    juce__label12->setEditable (false, false, false);
    juce__label12->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label12->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label12->setBounds (48, 376, 150, 24);

    juce__label13.reset (new juce::Label ("new label",
                                          TRANS ("Harmonics")));
    addAndMakeVisible (juce__label13.get());
    juce__label13->setFont (juce::Font (25.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label13->setJustificationType (juce::Justification::centredLeft);
    juce__label13->setEditable (false, false, false);
    juce__label13->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label13->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label13->setBounds (56, 136, 150, 24);

    juce__label14.reset (new juce::Label ("new label",
                                          TRANS ("AutoPanner")));
    addAndMakeVisible (juce__label14.get());
    juce__label14->setFont (juce::Font (25.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label14->setJustificationType (juce::Justification::centredLeft);
    juce__label14->setEditable (false, false, false);
    juce__label14->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label14->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label14->setBounds (512, 136, 150, 24);

    juce__label15.reset (new juce::Label ("new label",
                                          TRANS ("Additional  Feature")));
    addAndMakeVisible (juce__label15.get());
    juce__label15->setFont (juce::Font (10.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label15->setJustificationType (juce::Justification::centredLeft);
    juce__label15->setEditable (false, false, false);
    juce__label15->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label15->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label15->setBounds (536, 152, 150, 24);

    juce__label16.reset (new juce::Label ("new label",
                                          TRANS ("Vee Synth")));
    addAndMakeVisible (juce__label16.get());
    juce__label16->setFont (juce::Font ("LiSong Pro", 70.00f, juce::Font::bold | juce::Font::italic));
    juce__label16->setJustificationType (juce::Justification::centredLeft);
    juce__label16->setEditable (false, false, false);
    juce__label16->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label16->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label16->setBounds (48, 32, 480, 72);

    juce__label17.reset (new juce::Label ("new label",
                                          TRANS ("version 26")));
    addAndMakeVisible (juce__label17.get());
    juce__label17->setFont (juce::Font ("LiSong Pro", 25.00f, juce::Font::bold));
    juce__label17->setJustificationType (juce::Justification::centredLeft);
    juce__label17->setEditable (false, false, false);
    juce__label17->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label17->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label17->setBounds (384, 48, 480, 72);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (700, 750);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

AutoPannerAudioProcessorEditor::~AutoPannerAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_gainSlider = nullptr;
    juce__label = nullptr;
    m_harmonic1Button = nullptr;
    m_harmonic2Button = nullptr;
    m_harmonic3Button = nullptr;
    m_harmonic4Button = nullptr;
    m_attack1Slider = nullptr;
    m_attack2Slider = nullptr;
    m_attack3Slider = nullptr;
    m_attack4Slider = nullptr;
    m_release1Slider = nullptr;
    m_release2Slider = nullptr;
    m_release3Slider = nullptr;
    m_release4Slider = nullptr;
    m_autoPanButton = nullptr;
    m_autoPanRateSlider = nullptr;
    m_autoPanDepthSlider = nullptr;
    m_delayButton = nullptr;
    m_delayTap1Slider = nullptr;
    m_delayTap2Slider = nullptr;
    m_delayTap3Slider = nullptr;
    m_delayFeedbackSlider = nullptr;
    m_delayMixSlider = nullptr;
    juce__label3 = nullptr;
    juce__label4 = nullptr;
    juce__label5 = nullptr;
    juce__label6 = nullptr;
    juce__label7 = nullptr;
    juce__label8 = nullptr;
    juce__label9 = nullptr;
    m_store1Button = nullptr;
    m_store2Button = nullptr;
    m_store3Button = nullptr;
    m_recall1Button = nullptr;
    m_recall2Button = nullptr;
    m_recall3Button = nullptr;
    juce__label2 = nullptr;
    juce__label10 = nullptr;
    juce__label11 = nullptr;
    juce__label12 = nullptr;
    juce__label13 = nullptr;
    juce__label14 = nullptr;
    juce__label15 = nullptr;
    juce__label16 = nullptr;
    juce__label17 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AutoPannerAudioProcessorEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff1a1d23));

    {
        float x = 28.0f, y = 120.0f, width = 444.0f, height = 208.0f;
        juce::Colour fillColour = juce::Colour (0xff202630);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 28.0f, y = 356.0f, width = 444.0f, height = 204.0f;
        juce::Colour fillColour = juce::Colour (0xff1e2630);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 28.0f, y = 596.0f, width = 444.0f, height = 128.0f;
        juce::Colour fillColour = juce::Colour (0xff20242d);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 500.0f, y = 120.0f, width = 148.0f, height = 320.0f;
        juce::Colour fillColour = juce::Colour (0xff222730);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 500.0f, y = 464.0f, width = 148.0f, height = 260.0f;
        juce::Colour fillColour = juce::Colour (0xff222730);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AutoPannerAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AutoPannerAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_gainSlider.get())
    {
        //[UserSliderCode_m_gainSlider] -- add your slider handling code here..
        audioProcessor.updateParameters(kGain,m_gainSlider->getValue());
        //[/UserSliderCode_m_gainSlider]
    }
    else if (sliderThatWasMoved == m_attack1Slider.get())
    {
        //[UserSliderCode_m_attack1Slider] -- add your slider handling code here..
        audioProcessor.setAttack1(m_attack1Slider->getValue());
        //[/UserSliderCode_m_attack1Slider]
    }
    else if (sliderThatWasMoved == m_attack2Slider.get())
    {
        //[UserSliderCode_m_attack2Slider] -- add your slider handling code here..
        audioProcessor.setAttack2(m_attack2Slider->getValue());
        //[/UserSliderCode_m_attack2Slider]
    }
    else if (sliderThatWasMoved == m_attack3Slider.get())
    {
        //[UserSliderCode_m_attack3Slider] -- add your slider handling code here..
        audioProcessor.setAttack3(m_attack3Slider->getValue());
        //[/UserSliderCode_m_attack3Slider]
    }
    else if (sliderThatWasMoved == m_attack4Slider.get())
    {
        //[UserSliderCode_m_attack4Slider] -- add your slider handling code here..
        audioProcessor.setAttack4(m_attack4Slider->getValue());
        //[/UserSliderCode_m_attack4Slider]
    }
    else if (sliderThatWasMoved == m_release1Slider.get())
    {
        //[UserSliderCode_m_release1Slider] -- add your slider handling code here..
        audioProcessor.setRelease1(m_release1Slider->getValue());
        //[/UserSliderCode_m_release1Slider]
    }
    else if (sliderThatWasMoved == m_release2Slider.get())
    {
        //[UserSliderCode_m_release2Slider] -- add your slider handling code here..
        audioProcessor.setRelease2(m_release2Slider->getValue());
        //[/UserSliderCode_m_release2Slider]
    }
    else if (sliderThatWasMoved == m_release3Slider.get())
    {
        //[UserSliderCode_m_release3Slider] -- add your slider handling code here..
        audioProcessor.setRelease3(m_release3Slider->getValue());
        //[/UserSliderCode_m_release3Slider]
    }
    else if (sliderThatWasMoved == m_release4Slider.get())
    {
        //[UserSliderCode_m_release4Slider] -- add your slider handling code here..
        audioProcessor.setRelease4(m_release4Slider->getValue());
        //[/UserSliderCode_m_release4Slider]
    }
    else if (sliderThatWasMoved == m_autoPanRateSlider.get())
    {
        //[UserSliderCode_m_autoPanRateSlider] -- add your slider handling code here..
        audioProcessor.setAutoPanRate(m_autoPanRateSlider->getValue());
        //[/UserSliderCode_m_autoPanRateSlider]
    }
    else if (sliderThatWasMoved == m_autoPanDepthSlider.get())
    {
        //[UserSliderCode_m_autoPanDepthSlider] -- add your slider handling code here..
        audioProcessor.setAutoPanDepth(m_autoPanDepthSlider->getValue());
        //[/UserSliderCode_m_autoPanDepthSlider]
    }
    else if (sliderThatWasMoved == m_delayTap1Slider.get())
    {
        //[UserSliderCode_m_delayTap1Slider] -- add your slider handling code here..
        audioProcessor.setDelayTap1Time(m_delayTap1Slider->getValue());
        //[/UserSliderCode_m_delayTap1Slider]
    }
    else if (sliderThatWasMoved == m_delayTap2Slider.get())
    {
        //[UserSliderCode_m_delayTap2Slider] -- add your slider handling code here..
        audioProcessor.setDelayTap2Time(m_delayTap2Slider->getValue());
        //[/UserSliderCode_m_delayTap2Slider]
    }
    else if (sliderThatWasMoved == m_delayTap3Slider.get())
    {
        //[UserSliderCode_m_delayTap3Slider] -- add your slider handling code here..
        audioProcessor.setDelayTap3Time(m_delayTap3Slider->getValue());
        //[/UserSliderCode_m_delayTap3Slider]
    }
    else if (sliderThatWasMoved == m_delayFeedbackSlider.get())
    {
        //[UserSliderCode_m_delayFeedbackSlider] -- add your slider handling code here..
        audioProcessor.setDelayFeedback(m_delayFeedbackSlider->getValue());
        //[/UserSliderCode_m_delayFeedbackSlider]
    }
    else if (sliderThatWasMoved == m_delayMixSlider.get())
    {
        //[UserSliderCode_m_delayMixSlider] -- add your slider handling code here..
        audioProcessor.setDelayMix(m_delayMixSlider->getValue());
        //[/UserSliderCode_m_delayMixSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void AutoPannerAudioProcessorEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_harmonic1Button.get())
    {
        //[UserButtonCode_m_harmonic1Button] -- add your button handler code here..
        audioProcessor.setHarmonicEnabled(1, m_harmonic1Button->getToggleState());
        //[/UserButtonCode_m_harmonic1Button]
    }
    else if (buttonThatWasClicked == m_harmonic2Button.get())
    {
        //[UserButtonCode_m_harmonic2Button] -- add your button handler code here..
        audioProcessor.setHarmonicEnabled(2, m_harmonic2Button->getToggleState());
        //[/UserButtonCode_m_harmonic2Button]
    }
    else if (buttonThatWasClicked == m_harmonic3Button.get())
    {
        //[UserButtonCode_m_harmonic3Button] -- add your button handler code here..
        audioProcessor.setHarmonicEnabled(3, m_harmonic3Button->getToggleState());
        //[/UserButtonCode_m_harmonic3Button]
    }
    else if (buttonThatWasClicked == m_harmonic4Button.get())
    {
        //[UserButtonCode_m_harmonic4Button] -- add your button handler code here..
        audioProcessor.setHarmonicEnabled(4, m_harmonic4Button->getToggleState());
        //[/UserButtonCode_m_harmonic4Button]
    }
    else if (buttonThatWasClicked == m_autoPanButton.get())
    {
        //[UserButtonCode_m_autoPanButton] -- add your button handler code here..
        audioProcessor.setAutoPanEnabled(m_autoPanButton->getToggleState());
        //[/UserButtonCode_m_autoPanButton]
    }
    else if (buttonThatWasClicked == m_delayButton.get())
    {
        //[UserButtonCode_m_delayButton] -- add your button handler code here..
        audioProcessor.setDelayEnabled(m_delayButton->getToggleState());
        //[/UserButtonCode_m_delayButton]
    }
    else if (buttonThatWasClicked == m_store1Button.get())
    {
        //[UserButtonCode_m_store1Button] -- add your button handler code here..
        audioProcessor.storePreset(1);
        //[/UserButtonCode_m_store1Button]
    }
    else if (buttonThatWasClicked == m_store2Button.get())
    {
        //[UserButtonCode_m_store2Button] -- add your button handler code here..
        audioProcessor.storePreset(2);
        //[/UserButtonCode_m_store2Button]
    }
    else if (buttonThatWasClicked == m_store3Button.get())
    {
        //[UserButtonCode_m_store3Button] -- add your button handler code here..
        audioProcessor.storePreset(3);
        //[/UserButtonCode_m_store3Button]
    }
    else if (buttonThatWasClicked == m_recall1Button.get())
    {
        //[UserButtonCode_m_recall1Button] -- add your button handler code here..
        audioProcessor.loadPreset(1);
        //[/UserButtonCode_m_recall1Button]
    }
    else if (buttonThatWasClicked == m_recall2Button.get())
    {
        //[UserButtonCode_m_recall2Button] -- add your button handler code here..
        audioProcessor.loadPreset(2);
        //[/UserButtonCode_m_recall2Button]
    }
    else if (buttonThatWasClicked == m_recall3Button.get())
    {
        //[UserButtonCode_m_recall3Button] -- add your button handler code here..
        audioProcessor.loadPreset(3);
        //[/UserButtonCode_m_recall3Button]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AutoPannerAudioProcessorEditor"
                 componentName="" parentClasses="public juce::AudioProcessorEditor"
                 constructorParams="AutoPannerAudioProcessor&amp; owner" variableInitialisers="AudioProcessorEditor(owner),audioProcessor(owner)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff1a1d23">
    <ROUNDRECT pos="28 120 444 208" cornerSize="10.0" fill="solid: ff202630"
               hasStroke="0"/>
    <ROUNDRECT pos="28 356 444 204" cornerSize="10.0" fill="solid: ff1e2630"
               hasStroke="0"/>
    <ROUNDRECT pos="28 596 444 128" cornerSize="10.0" fill="solid: ff20242d"
               hasStroke="0"/>
    <ROUNDRECT pos="500 120 148 320" cornerSize="10.0" fill="solid: ff222730"
               hasStroke="0"/>
    <ROUNDRECT pos="500 464 148 260" cornerSize="10.0" fill="solid: ff222730"
               hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="Gain" id="3d197013152db5cb" memberName="m_gainSlider" virtualName=""
          explicitFocusOrder="0" pos="504 520 136 176" bkgcol="ff257da9"
          thumbcol="ffdc143c" trackcol="ff2d91bc" min="0.0" max="1.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="500baa4ea001f4b5" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="496 448 160 112" bkgCol="921717"
         edTextCol="ff000000" edBkgCol="0" labelText="Master Gain&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="20.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="ed00801cbc2c7367" memberName="m_harmonic1Button"
                virtualName="" explicitFocusOrder="0" pos="40 200 127 16" buttonText="Harmonic 1"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="85ff023a1d4fc680" memberName="m_harmonic2Button"
                virtualName="" explicitFocusOrder="0" pos="40 232 127 16" buttonText="Harmonic 2"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="fe47b9bf449ab9d1" memberName="m_harmonic3Button"
                virtualName="" explicitFocusOrder="0" pos="40 264 127 16" buttonText="Harmonic 3"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="712ded36dfc77032" memberName="m_harmonic4Button"
                virtualName="" explicitFocusOrder="0" pos="40 296 127 16" buttonText="Harmonic 4"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <SLIDER name="new slider" id="5e05f0510cf0932d" memberName="m_attack1Slider"
          virtualName="" explicitFocusOrder="0" pos="144 200 160 16" min="0.01"
          max="5.0" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="214bef0352dc2d2" memberName="m_attack2Slider"
          virtualName="" explicitFocusOrder="0" pos="144 232 160 16" min="0.01"
          max="5.0" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="cf2bff25832a53f4" memberName="m_attack3Slider"
          virtualName="" explicitFocusOrder="0" pos="144 264 160 16" min="0.01"
          max="5.0" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="6de262835cfd940c" memberName="m_attack4Slider"
          virtualName="" explicitFocusOrder="0" pos="144 296 160 16" min="0.01"
          max="5.0" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="239fee4ecaa127e9" memberName="m_release1Slider"
          virtualName="" explicitFocusOrder="0" pos="304 200 160 16" min="0.01"
          max="5.0" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="75519dfd99c40389" memberName="m_release2Slider"
          virtualName="" explicitFocusOrder="0" pos="304 232 160 16" min="0.01"
          max="5.0" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="fd996d9c76ac543d" memberName="m_release3Slider"
          virtualName="" explicitFocusOrder="0" pos="304 264 160 16" min="0.01"
          max="5.0" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="32250aa32376b691" memberName="m_release4Slider"
          virtualName="" explicitFocusOrder="0" pos="304 296 160 16" min="0.01"
          max="5.0" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TOGGLEBUTTON name="new toggle button" id="3704330ca2c89933" memberName="m_autoPanButton"
                virtualName="" explicitFocusOrder="0" pos="520 184 144 24" buttonText="Auto Pan"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="new slider" id="3211248e657dc7ee" memberName="m_autoPanRateSlider"
          virtualName="" explicitFocusOrder="0" pos="520 208 40 200" min="0.1"
          max="10.0" int="0.1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="7fd844cc68246dc1" memberName="m_autoPanDepthSlider"
          virtualName="" explicitFocusOrder="0" pos="584 208 40 200" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TOGGLEBUTTON name="new toggle button" id="c6fa440168316efb" memberName="m_delayButton"
                virtualName="" explicitFocusOrder="0" pos="48 416 150 24" buttonText="Delay On"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="new slider" id="1f149877a55d1bb4" memberName="m_delayTap1Slider"
          virtualName="" explicitFocusOrder="0" pos="120 456 136 16" min="1.0"
          max="2000.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="a21ad5b7035131fd" memberName="m_delayTap2Slider"
          virtualName="" explicitFocusOrder="0" pos="120 488 136 16" min="1.0"
          max="2000.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="f02f8041e7cb1b24" memberName="m_delayTap3Slider"
          virtualName="" explicitFocusOrder="0" pos="120 520 136 16" min="1.0"
          max="2000.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="1d58c9f2c031d888" memberName="m_delayFeedbackSlider"
          virtualName="" explicitFocusOrder="0" pos="272 376 40 144" min="0.0"
          max="0.99" int="0.01" style="LinearVertical" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="cdcf014634759579" memberName="m_delayMixSlider"
          virtualName="" explicitFocusOrder="0" pos="384 376 40 144" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="a2b6033ea1b4e361" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="48 448 79 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Tap 1 Time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="11.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="da55a95c3a30336a" memberName="juce__label4"
         virtualName="" explicitFocusOrder="0" pos="48 480 79 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Tap 2 Time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="11.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="2131df4c9c36075c" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="48 512 79 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Tap 3 Time&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f743a0e0be29875" memberName="juce__label6"
         virtualName="" explicitFocusOrder="0" pos="264 520 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Feedback" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="deb07b6b57039adb" memberName="juce__label7"
         virtualName="" explicitFocusOrder="0" pos="368 520 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Wet/Dry Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="723bd831854e0923" memberName="juce__label8"
         virtualName="" explicitFocusOrder="0" pos="144 168 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="320e7e4a086779cf" memberName="juce__label9"
         virtualName="" explicitFocusOrder="0" pos="304 168 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="5d7a4533b7b2eb3" memberName="m_store1Button"
              virtualName="" explicitFocusOrder="0" pos="56 648 96 24" buttonText="Store 1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d8ddf22eebd9450e" memberName="m_store2Button"
              virtualName="" explicitFocusOrder="0" pos="208 648 96 24" buttonText="Store 2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="f0bddcf6951c5851" memberName="m_store3Button"
              virtualName="" explicitFocusOrder="0" pos="352 648 96 24" buttonText="Store 3"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="8e91a53ba7068608" memberName="m_recall1Button"
              virtualName="" explicitFocusOrder="0" pos="56 680 96 24" buttonText="Recall 1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="808fea35c486237a" memberName="m_recall2Button"
              virtualName="" explicitFocusOrder="0" pos="208 680 96 24" buttonText="Recall 2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="10198408a2a3bd7f" memberName="m_recall3Button"
              virtualName="" explicitFocusOrder="0" pos="352 680 96 24" buttonText="Recall 3"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="86412019c66d3cd5" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="584 400 48 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="c3b75439bf6dd021" memberName="juce__label10"
         virtualName="" explicitFocusOrder="0" pos="520 400 40 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Rate&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="7f8ce8e1ca13f476" memberName="juce__label11"
         virtualName="" explicitFocusOrder="0" pos="56 608 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Presets" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="25.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="45d2305d06403f3c" memberName="juce__label12"
         virtualName="" explicitFocusOrder="0" pos="48 376 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Delay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="25.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f625a8b528204c25" memberName="juce__label13"
         virtualName="" explicitFocusOrder="0" pos="56 136 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Harmonics" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="25.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="1959267c7d737f41" memberName="juce__label14"
         virtualName="" explicitFocusOrder="0" pos="512 136 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="AutoPanner" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="25.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="115ea00660063c60" memberName="juce__label15"
         virtualName="" explicitFocusOrder="0" pos="536 152 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Additional  Feature" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="d7dbd9b87fc1f40f" memberName="juce__label16"
         virtualName="" explicitFocusOrder="0" pos="48 32 480 72" edTextCol="ff000000"
         edBkgCol="0" labelText="Vee Synth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="LiSong Pro" fontsize="70.0"
         kerning="0.0" bold="1" italic="1" justification="33" typefaceStyle="Bold Italic"/>
  <LABEL name="new label" id="b400a0751e7ba9fe" memberName="juce__label17"
         virtualName="" explicitFocusOrder="0" pos="384 48 480 72" edTextCol="ff000000"
         edBkgCol="0" labelText="version 26" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="LiSong Pro" fontsize="25.0"
         kerning="0.0" bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

