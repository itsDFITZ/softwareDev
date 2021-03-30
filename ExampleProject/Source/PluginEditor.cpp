/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
FasterMasterAudioProcessorEditor::FasterMasterAudioProcessorEditor (FasterMasterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    mixSlider.addListener(this); // listen to user interaction with this GUI window
    mixSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag); // Circular knob
    mixSlider.setBounds(100,90,200,200); // position on GUI
    mixSlider.setRange(0.f,100.f,1.f);
    //mixSlider.setSkewFactorFromMidPoint(1.f);
    mixSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 30);
    mixSlider.setValue(audioProcessor.gain);
    addAndMakeVisible(mixSlider);
    
    muteButton.addListener(this);
    muteButton.setBounds(300,20,120,20);
    muteButton.setButtonText("Bypass");
    muteButton.setToggleState(audioProcessor.muteOn, juce::dontSendNotification);
    addAndMakeVisible(muteButton);
    
}

FasterMasterAudioProcessorEditor::~FasterMasterAudioProcessorEditor()
{
}

//==============================================================================
void FasterMasterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::red);
    g.setFont (15.0f);
    //g.drawFittedText ("My Distortion Plug-in", getLocalBounds(), juce::Justification::centred, 1);
    g.drawFittedText ("FASTER MASTER by DFITZ",125,30, 150,100,juce::Justification::centred,1 );
  
}

void FasterMasterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void FasterMasterAudioProcessorEditor::sliderValueChanged(juce::Slider *slider){
    
    if (slider == &mixSlider){
        audioProcessor.gain = mixSlider.getValue();
    }
    
    
}

void FasterMasterAudioProcessorEditor::buttonClicked(juce::Button * button){
    
    if (button == &muteButton){
        audioProcessor.muteOn = !audioProcessor.muteOn;
    }
    
}
