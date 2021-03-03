/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ExampleProjectAudioProcessorEditor::ExampleProjectAudioProcessorEditor (ExampleProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    gainSlider.addListener(this); // listen to user interaction with this GUI window
    gainSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag); // Circular knob
    gainSlider.setBounds(40,90,120,120); // position on GUI
    gainSlider.setRange(1.f,10.f,.01f);
    //gainSlider.setSkewFactorFromMidPoint(1.f);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 30);
    gainSlider.setValue(audioProcessor.gain);
    addAndMakeVisible(gainSlider);
    
    muteButton.addListener(this);
    muteButton.setBounds(200,90,120,20);
    muteButton.setButtonText("Bypass");
    muteButton.setToggleState(audioProcessor.muteOn, juce::dontSendNotification);
    addAndMakeVisible(muteButton);
    
}

ExampleProjectAudioProcessorEditor::~ExampleProjectAudioProcessorEditor()
{
}

//==============================================================================
void ExampleProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::red);
    g.setFont (15.0f);
    //g.drawFittedText ("My Distortion Plug-in", getLocalBounds(), juce::Justification::centred, 1);
    g.drawFittedText ("Faster Master by DFITZ",20,40, 150,100,juce::Justification::centred,1 );
  
}

void ExampleProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void ExampleProjectAudioProcessorEditor::sliderValueChanged(juce::Slider *slider){
    
    if (slider == &gainSlider){
        audioProcessor.gain = gainSlider.getValue();
    }
    
    
}

void ExampleProjectAudioProcessorEditor::buttonClicked(juce::Button * button){
    
    if (button == &muteButton){
        audioProcessor.muteOn = !audioProcessor.muteOn;
    }
    
}
