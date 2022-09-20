#include "PluginProcessor.h"
#include "PluginEditor.h"


SimpleOscillatorAudioProcessorEditor::SimpleOscillatorAudioProcessorEditor (SimpleOscillatorAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

    setSize (400, 300);
}

SimpleOscillatorAudioProcessorEditor::~SimpleOscillatorAudioProcessorEditor()
{
}

//==============================================================================
void SimpleOscillatorAudioProcessorEditor::paint (juce::Graphics& g)
{

    g.fillAll (juce::Colours::black);
}

void SimpleOscillatorAudioProcessorEditor::resized()
{

}
