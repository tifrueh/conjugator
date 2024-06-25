// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "inspectorpanel.hpp"


InspectorPanel::InspectorPanel(wxWindow* parent, const cjgt::Language* language) : wxPanel(parent, wxID_ANY) {
    this->language = language;
    topsizer = new wxBoxSizer(wxHORIZONTAL);

    wxArrayString verbs = wxArrayString();

    for (std::pair<std::wstring, const verbDB::Verb*> element : this->language->get_verbs()) {
        verbs.Add(wxString(element.first));
    }

    verbBox = new wxListBox(this, winID::inspector_verb_box, wxDefaultPosition, wxDefaultSize, verbs, wxLB_SINGLE | wxLB_SORT);
    verbBox->SetSelection(0, true);

    topsizer->Add(verbBox, 0, wxEXPAND, 0);

    // Initialise a new verbview with the currently selected verb.
    verbView = new VerbView(this, wxID_ANY, this->language, this->language->get_verb(verbBox->GetStringSelection().ToStdWstring()));

    topsizer->Add(verbView, 1, wxEXPAND | wxALL, 0);

    this->SetSizerAndFit(topsizer);
}

void InspectorPanel::setVerbFromBox() {
    verbView->setVerb(this->language->get_verb(verbBox->GetStringSelection().ToStdWstring()));

    topsizer->SetSizeHints(this);
}
