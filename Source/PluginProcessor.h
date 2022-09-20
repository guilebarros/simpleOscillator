#pragma once

#include <JuceHeader.h>

class SimpleOscillatorAudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    SimpleOscillatorAudioProcessor();
    ~SimpleOscillatorAudioProcessor() override;

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

private:
    
    // lambda function(sine)
    //juce::dsp::Oscillator<float> osc { [] (float x) { return std::sin (x); }};
    
    // lambda function(saw)
    //juce::dsp::Oscillator<float> osc { [](float x) { return x / juce::MathConstants<float>::pi; }};
    
    
    // lambda function(square)
    juce::dsp::Oscillator<float> osc { [](float x) { return x < 0.0f ? -1.0f : 1.0f; }, 200};
    
    juce::dsp::Gain<float> gain;
    
    // WAVE EQUATIONS
    
    // { return std::sin (x); }  // sine wave
    // { return x / juce::MathConstants<float>::pi; } // saw wave
    // { return x < 0.0f ? -1.0f : 1.0f; } // square wave

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleOscillatorAudioProcessor)
};
