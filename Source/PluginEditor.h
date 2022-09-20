#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class SimpleOscillatorAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleOscillatorAudioProcessorEditor (SimpleOscillatorAudioProcessor&);
    ~SimpleOscillatorAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    SimpleOscillatorAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleOscillatorAudioProcessorEditor)
};
