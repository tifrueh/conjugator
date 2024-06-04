// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "verbview.hpp"


VerbView::VerbView(wxWindow* parent, wxWindowID id, const cjgt::Language* language, const verbDB::Verb* verb) : wxPanel(parent, id) {
    this->language = language;
    this->verb = verb;
    
    sizer = new wxBoxSizer(wxVERTICAL);
    
    tensebook = new wxChoicebook(this, wxID_ANY);

    // Create a verb view panel for each tense from present to conditionnel and add it to the tensebook.
    for (const cjgt::Tense* tense : this->language->getTenses()) {
        if (tense->show_in_inspecteur) {
            pages.insert({tense, new VerbViewPanel(tensebook, wxID_ANY, verb, tense)});
            tensebook->AddPage(pages.at(tense), wxString(tense->name));
        }
    }

    sizer->Add(tensebook, 0, wxEXPAND | wxALL, 10);

    this->SetSizerAndFit(sizer);

}

void VerbView::setVerb(const verbDB::Verb* verb) {
    this->verb = verb;

    for (const cjgt::Tense* tense : this->language->getTenses()) {
        if (tense->show_in_inspecteur) {
            pages.at(tense)->setVerb(verb);
        }
    }

    sizer->SetSizeHints(this);
}
