// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "verbview.hpp"


VerbView::VerbView(wxWindow* parent, wxWindowID id, const cjgt::Language* language, const verbDB::Verb* verb) : wxPanel(parent, id) {
    this->language = language;
    this->verb = verb;
    
    this->sizer = new wxBoxSizer(wxVERTICAL);

    this->tensebook = new wxChoicebook(this, wxID_ANY);

    // Create a verb view panel for each tense from present to conditionnel and add it to the tensebook.
    for (const cjgt::Tense* tense : this->language->get_tenses()) {
        if (tense->show_in_inspecteur) {
            this->pages.insert({tense, new VerbViewPanel(this->tensebook, wxID_ANY, verb, tense)});
            this->tensebook->AddPage(this->pages.at(tense), wxString(tense->name));
        }
    }

    this->sizer->Add(tensebook, 0, wxEXPAND | wxALL, 10);

    this->SetSizerAndFit(sizer);

}

void VerbView::set_verb(const verbDB::Verb* verb) {
    this->verb = verb;

    for (const cjgt::Tense* tense : this->language->get_tenses()) {
        if (tense->show_in_inspecteur) {
            this->pages.at(tense)->set_verb(verb);
        }
    }

    this->sizer->SetSizeHints(this);
}
