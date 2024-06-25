// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "inspectorframe.hpp"


// Define the wx style for the inspecteur window.
#define wxINSPECTEUR_STYLE wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxFRAME_FLOAT_ON_PARENT

InspectorFrame::InspectorFrame(wxWindow *parent, const wxWindowID &winID, const wxString &title, const cjgt::Language* language) : wxFrame(parent, winID, title, wxDefaultPosition, wxDefaultSize, wxINSPECTEUR_STYLE) {
    SetIcon(wxICON(inspecteur));

    this->top_sizer = new wxBoxSizer(wxHORIZONTAL);

    this->inspector_panel = new InspectorPanel(this, language);

    this->top_sizer->Add(this->inspector_panel, 1, wxEXPAND, 0);

    this->SetSizerAndFit(this->top_sizer);
}

void InspectorFrame::update_verb() {
    this->inspector_panel->set_verb_from_box();
    this->top_sizer->SetSizeHints(this);
}
