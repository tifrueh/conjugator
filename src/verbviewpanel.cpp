// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "verbviewpanel.hpp"


VerbViewPanel::VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb &verb, const int &tense) : wxPanel(parent, id) {
    this->verb = verb;
    this->tense = tense;
    sizer = new wxBoxSizer(wxVERTICAL);
    
    tenseString = cjgt::getTense(tense);
    
    titleLabel = new wxStaticText(this, wxID_ANY, wxString(tenseString));
    titleLabel->SetMinSize(wxSize(200, titleLabel->GetMinHeight()));
    formLabels.insert({verbDB::Person::none, new wxStaticText(this, wxID_ANY, wxEmptyString)});

    wxFont titleFont = titleLabel->GetFont();
    titleFont.Scale(1.5);
    titleFont.MakeBold();
    titleLabel->SetFont(titleFont);

    sizer->AddSpacer(5);

    sizer->Add(titleLabel, 0, wxEXPAND, 0);
    sizer->Add(formLabels.at(verbDB::Person::none), 0, wxEXPAND, 0);
    
    // Hide item 2, which is the participe present, if the tense is not set to present.
    if (tense != verbDB::Tense::present) {
        sizer->Hide(2);
    }

    sizer->AddSpacer(10);

    // Add a label so the sizer for each verb form of the tense.
    for (int person = verbDB::Person::je; person <= verbDB::Person::elles; person++) {
        formLabels.insert({person, new wxStaticText(this, wxID_ANY, wxEmptyString)});
        sizer->Add(formLabels.at(person), 0, wxEXPAND, 0);
    }

    this->SetSizerAndFit(sizer);
    
    this->setVerb(verb);
}


VerbViewPanel::VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb& verb, const verbDB::Tense& tense) {
    VerbViewPanel(parent, id, verb, tense);
}

void VerbViewPanel::setVerb(const verbDB::Verb& inputVerb) {
    this->verb = inputVerb;

    cjgt::VerbForm participePresent = cjgt::getVerbForm(verb, verbDB::Tense::participePresent, verbDB::Person::none);
    formLabels.at(verbDB::Person::none)->SetLabel(wxString(cjgt::getFormString(participePresent)));
    
    for (int person = verbDB::Person::je; person <= verbDB::Person::elles; person++) {
        cjgt::VerbForm verbForm = cjgt::getVerbForm(verb, tense, person);
        formLabels.at(person)->SetLabel(wxString(cjgt::getFormString(verbForm)));
    }
    
    sizer->SetSizeHints(this);
}
