//
// Created by thomas on 17/03/22.
//
#pragma once

#include <juce_gui_extra/juce_gui_extra.h>
//#include <juce_core/threads/juce_ChildProcess.h>

class setupper  : public juce::Component
{
public:
    //==============================================================================
    setupper() : updateMessage("Loading...")
    {
        setSize(300,300);
        addAndMakeVisible(updater);
        updater.setFont(juce::Font(16.0f, juce::Font::bold));
        updater.setText(updateMessage, juce::dontSendNotification);
        updater.setColour(juce::Label::textColourId, juce::Colours::orange);
        updater.setJustificationType(juce::Justification::bottomLeft);
        updater.setSize (200, 20);

        VSTProcess.start("firefox", 0);

    }

    void paint (juce::Graphics& g) override {}

    void resized() override
    {
        updater.setBounds(0, 0, 200, 20);
    }

    ~setupper(){
        VSTProcess.kill();
    }

private:
    //==============================================================================
    juce::Label updater;
    juce::ChildProcess VSTProcess;
    std::string updateMessage;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (setupper)
};
