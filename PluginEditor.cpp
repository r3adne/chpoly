#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ChPolyEditor::ChPolyEditor (ChPolyProcessor& _p)
    : AudioProcessorEditor (&_p), p (_p)
{

    for (int i = 0; i < NUM_HARMONICS; ++i)
    {

        std::unique_ptr<juce::SliderParameterAttachment> att = std::make_unique<juce::SliderParameterAttachment>(juce::RangedAudioParameter>(*p.harmonicparams[i]), harmonicsliders[i], nullptr);
    }


    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

ChPolyEditor::~ChPolyEditor()
{
}

//==============================================================================
void ChPolyEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void ChPolyEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

bool ChPolyEditor::keyPressed (const juce::KeyPress &key)
{
    if ((key.getModifiers().isCommandDown() || key.getModifiers().isCtrlDown()) && key.isKeyCode('r'))
    {
        p.randomize();
    }
}
