/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SoftClip.h"
#include "RMSComp.h"



//==============================================================================
/**
*/
class FasterMasterAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
  FasterMasterAudioProcessor();
//    juce::AudioProcessorEditor::juce::AudioProcessorEditor(){}
    ~FasterMasterAudioProcessor() override;
//    FasterMasterAudioProcessor(double l = 0, double w = 0);
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
//    void processSignal(float * signal, const int numSamples, const int c);
    

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

    float gain = 1.f;
    bool  muteOn = false;
    
//    SoftClip softClip;
    
    
private:
   SoftClip softClip;
    RMSComp rmsComp;
   
   
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FasterMasterAudioProcessor)
};
