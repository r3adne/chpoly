#pragma once

#include "PluginProcessor.h"

//==============================================================================
class ChPolyEditor final : public juce::AudioProcessorEditor
{
public:
    explicit ChPolyEditor (ChPolyProcessor&);
    ~ChPolyEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ChPolyProcessor& processorRef;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChPolyEditor)
};
