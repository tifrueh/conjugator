// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "checkerframe.hpp"


// Define the wx style for the checker window.
#define wxCHECKER_STYLE wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxFRAME_FLOAT_ON_PARENT

CheckerFrame::CheckerFrame(wxWindow *parent, const wxWindowID &winID, const wxString &title) : wxFrame(parent, winID, title, wxDefaultPosition, wxDefaultSize, wxCHECKER_STYLE) {

    topSizer = new wxBoxSizer(wxHORIZONTAL);

    checkerPanel = new CheckerPanel(this);

    topSizer->Add(checkerPanel, 1, wxEXPAND, 0);

    this->SetSizerAndFit(topSizer);
}
