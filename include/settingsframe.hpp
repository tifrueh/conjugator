// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include "id.hpp"
#include "settingspanel.hpp"


// The most top-level frame of the settings window.
class SettingsFrame : public wxFrame {
    public:
        // Construct a new settings frame.
        SettingsFrame(wxWindow* parent, const wxWindowID& winID, const wxString& title);

        void writeConfig();

    private:
        wxBoxSizer* topSizer;
        SettingsPanel* settingsPanel;
};
