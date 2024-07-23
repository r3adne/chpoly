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

    bool keyPressed (const juce::KeyPress &key) override;

 private:
    ChPolyProcessor& p;

    juce::Slider gainslider;
    juce::OwnedArray<juce::Slider> harmonicsliders;

    juce::OwnedArray<juce::SliderParameterAttachment> atts;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChPolyEditor)
};
