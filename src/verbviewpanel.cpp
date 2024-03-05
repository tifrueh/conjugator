// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "verbviewpanel.hpp"


VerbViewPanel::VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb &verb, const int &tense) : wxPanel(parent, id) {
    this->verb = verb;
    this->tense = tense;
    sizer = new wxBoxSizer(wxVERTICAL);
    
    tenseString = cjgt::getTense(tense);
    infinitifString = verb.infinitif + L" – " + verb.translation;
    
    titleLabel = new wxStaticText(this, wxID_ANY, wxString(tenseString));
    titleLabel->SetMinSize(wxSize(200, titleLabel->GetMinHeight()));

    infinitifLabel = new wxStaticText(this, wxID_ANY, wxString(infinitifString));

    formLabels.insert({verbDB::Person::none, new wxStaticText(this, wxID_ANY, wxEmptyString)});

    wxFont titleFont = titleLabel->GetFont();
    titleFont.Scale(1.5);
    titleFont.MakeBold();
    titleLabel->SetFont(titleFont);

    sizer->AddSpacer(5);

    sizer->Add(titleLabel, 0, wxEXPAND, 0);
    sizer->Add(infinitifLabel, 0, wxEXPAND, 0);

    sizer->AddSpacer(10);
    sizer->Add(formLabels.at(verbDB::Person::none), 0, wxEXPAND, 0);
    
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

    infinitifLabel->SetLabel(verb.infinitif + " – " + verb.translation);

    cjgt::VerbForm participePresent = cjgt::getVerbForm(verb, verbDB::Tense::participePresent, verbDB::Person::none);
    formLabels.at(verbDB::Person::none)->SetLabel(wxString(cjgt::getFormString(participePresent)));
    
    // Hide the participe present if it is empty or if the VerbView's tense is
    // any other than the present.
    if (participePresent.form == L"" || tense != verbDB::Tense::present) {
        sizer->Hide(formLabels.at(verbDB::Person::none));
    } else {
        sizer->Show(formLabels.at(verbDB::Person::none));
    }
    
    for (int person = verbDB::Person::je; person <= verbDB::Person::elles; person++) {
        cjgt::VerbForm verbForm = cjgt::getVerbForm(verb, tense, person);
        formLabels.at(person)->SetLabel(wxString(cjgt::getFormString(verbForm)));
        
        // Hide empty forms
        if (verbForm.form == L"") {
            sizer->Hide(formLabels.at(person));
        } else {
            sizer->Show(formLabels.at(person));
        }
    }
    
    sizer->SetSizeHints(this);
}
