// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "inspectorpanel.hpp"


InspectorPanel::InspectorPanel(wxWindow* parent, const cjgt::Language* language) : wxPanel(parent, wxID_ANY) {
    this->language = language;
    this->top_sizer = new wxBoxSizer(wxHORIZONTAL);
    this->verb_map = this->language->get_verbs();

    wxArrayString verbs = wxArrayString();

    for (std::pair<std::wstring, const verbDB::Verb*> element : this->verb_map) {
        verbs.Add(wxString(element.first));
    }

    this->verb_box = new wxListBox(this, winID::inspector_verb_box, wxDefaultPosition, wxDefaultSize, verbs, wxLB_SINGLE | wxLB_SORT);
    this->verb_box->SetSelection(0, true);

    this->top_sizer->Add(this->verb_box, 0, wxEXPAND, 0);

    // Initialise a new verbview with the currently selected verb.
    this->verb_view = new VerbView(this, wxID_ANY, this->language, this->verb_map.at(this->verb_box->GetStringSelection().ToStdWstring()));

    this->top_sizer->Add(this->verb_view, 1, wxEXPAND | wxALL, 0);

    this->SetSizerAndFit(this->top_sizer);
}

void InspectorPanel::set_verb_from_box() {
    this->verb_view->set_verb(this->verb_map.at(verb_box->GetStringSelection().ToStdWstring()));

    this->top_sizer->SetSizeHints(this);
}
