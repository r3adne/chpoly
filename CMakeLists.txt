# chpoly CMakeLists.txt

cmake_minimum_required(VERSION 3.22)

project(CHPOLY VERSION 0.0.1)

add_subdirectory(JUCE)                    # If you've put JUCE in a subdirectory called JUCE

# juce_set_vst2_sdk_path(...)
# juce_set_aax_sdk_path(...)

# `juce_add_plugin` adds a static library target with the name passed as the first argument
# (AudioPluginExample here). This target is a normal CMake target, but has a lot of extra properties set
# up by default. As well as this shared code static library, this function adds targets for each of
# the formats specified by the FORMATS arguments. This function accepts many optional arguments.
# Check the readme at `docs/CMake API.md` in the JUCE repo for the full list.
juce_add_plugin(chpoly
     VERSION 0.0.1                               # Set this if the plugin version is different to the project version
    # ICON_BIG ...                              # ICON_* arguments specify a path to an image file to use as an icon for the Standalone
    # ICON_SMALL ...
     COMPANY_NAME girlwiththread                          # Specify the name of the plugin's author
     IS_SYNTH FALSE                       # Is this a synth or an effect?
     NEEDS_MIDI_INPUT FALSE               # Does the plugin need midi input?
     NEEDS_MIDI_OUTPUT FALSE              # Does the plugin need midi output?
     IS_MIDI_EFFECT FALSE                 # Is this plugin a MIDI effect?
     EDITOR_WANTS_KEYBOARD_FOCUS TRUE    # Does the editor need keyboard focus?
     COPY_PLUGIN_AFTER_BUILD FALSE        # Should the plugin be installed to a default location after building?
     PLUGIN_MANUFACTURER_CODE aRia               # A four-character manufacturer id with at least one upper-case character
     PLUGIN_CODE chLy                            # A unique four-character plugin id with exactly one upper-case character
                                                # GarageBand 10.3 requires the first letter to be upper-case, and the remaining letters to be lower-case
    FORMATS AU VST3                  # The formats to build. Other valid formats are: AAX Unity VST AU AUv3
    PRODUCT_NAME "chpoly")        # The name of the final executable, which can differ from the target name



target_sources(chpoly
    PRIVATE
        PluginEditor.cpp
        PluginProcessor.cpp)

target_compile_definitions(chpoly
        PUBLIC
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0)

# juce_add_binary_data(BinaryData SOURCES ...)

target_link_libraries(chpoly
    PRIVATE
        # BinaryData
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
