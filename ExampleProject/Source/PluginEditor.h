/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ExampleProjectAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                            public juce::Slider::Listener,
                                            public juce::Button::Listener
{
public:
    ExampleProjectAudioProcessorEditor (ExampleProjectAudioProcessor&);
    ~ExampleProjectAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider * slider) override;
    void buttonClicked(juce::Button * button) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ExampleProjectAudioProcessor& audioProcessor;
    
    juce::Slider gainSlider;
    
    juce::ToggleButton muteButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ExampleProjectAudioProcessorEditor)
};
