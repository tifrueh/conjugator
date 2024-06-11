// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "settingsframe.hpp"


// Define the wx style for the inspecteur window.
#define wxINSPECTEUR_STYLE wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxFRAME_FLOAT_ON_PARENT

SettingsFrame::SettingsFrame(wxWindow *parent, const wxWindowID &winID, const wxString &title) : wxFrame(parent, winID, title, wxDefaultPosition, wxDefaultSize, wxINSPECTEUR_STYLE) {

    topSizer = new wxBoxSizer(wxHORIZONTAL);

    settingsPanel = new SettingsPanel(this);

    topSizer->Add(settingsPanel, 1, wxEXPAND, 0);

    this->SetSizerAndFit(topSizer);
}
