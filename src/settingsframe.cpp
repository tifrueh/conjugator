// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "settingsframe.hpp"


// Define the wx style for the inspecteur window.
#define wxINSPECTEUR_STYLE wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxFRAME_FLOAT_ON_PARENT

SettingsFrame::SettingsFrame(wxWindow *parent, const wxWindowID &winID, const wxString &title) : wxFrame(parent, winID, title, wxDefaultPosition, wxDefaultSize, wxINSPECTEUR_STYLE) {

    this->top_sizer = new wxBoxSizer(wxHORIZONTAL);

    this->settings_panel = new SettingsPanel(this);

    this->top_sizer->Add(this->settings_panel, 1, wxEXPAND | wxALL, 20);

    this->SetSizerAndFit(this->top_sizer);
}

void SettingsFrame::write_config() {
    this->settings_panel->write_config();
}
