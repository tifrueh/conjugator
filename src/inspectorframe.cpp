// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include "verb.db.hpp"
#include "id.hpp"

#include "inspectorpanel.hpp"
#include "inspectorframe.hpp"

InspectorFrame::InspectorFrame(wxWindow *parent, const wxWindowID &winID, const wxString &title) : wxFrame(parent, winID, title) {
    topSizer = new wxBoxSizer(wxHORIZONTAL);

    inspectorPanel = new InspectorPanel(this);

    topSizer->Add(inspectorPanel, 1, wxEXPAND, 0);

    this->SetSizerAndFit(topSizer);
}

void InspectorFrame::updateVerb() {
    inspectorPanel->setVerbFromBox();
}