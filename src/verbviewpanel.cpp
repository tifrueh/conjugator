// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "verb.db.hpp"
#include "conjugateur.hpp"

#include "verbviewpanel.hpp"

VerbViewPanel::VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb &verb, const int &tense) : wxPanel(parent, id) {
    this->verb = verb;
    this->tense = tense;
    sizer = new wxBoxSizer(wxVERTICAL);
    
    tenseString = cjgt::getTense(tense);
    
    titleLabel = new wxStaticText(this, wxID_ANY, wxString(tenseString));
    formLabels.insert({verbDB::Person::none, new wxStaticText(this, wxID_ANY, wxEmptyString)});

    wxFont titleFont = titleLabel->GetFont();
    titleFont.Scale(1.5);
    titleFont.MakeBold();
    titleLabel->SetFont(titleFont);

    sizer->AddSpacer(5);

    sizer->Add(titleLabel, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);
    
    if (tense == verbDB::Tense::present) {
        sizer->Add(formLabels.at(verbDB::Person::none), 0, wxEXPAND | wxLEFT | wxRIGHT, 10);
    }

    sizer->AddSpacer(10);

    for (int person = verbDB::Person::je; person <= verbDB::Person::elles; person++) {
        formLabels.insert({person, new wxStaticText(this, wxID_ANY, wxEmptyString)});
        sizer->Add(formLabels.at(person), 0, wxEXPAND | wxLEFT | wxRIGHT, 10);
    }
    
    sizer->AddSpacer(5);
    
    this->setVerb(verb);

    this->SetSizerAndFit(sizer);
}


VerbViewPanel::VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb& verb, const verbDB::Tense& tense) {
    VerbViewPanel(parent, id, verb, tense);
}

void VerbViewPanel::setVerb(const verbDB::Verb& inputVerb) {
    this->verb = inputVerb;

    cjgt::VerbForm participePresent = cjgt::getVerbForm(verb, verbDB::Tense::participePresent, verbDB::Person::none);
    formLabels.at(verbDB::Person::none)->SetLabel(wxString("participe present: " + cjgt::getFormString(participePresent)));
    
    for (int person = verbDB::Person::je; person <= verbDB::Person::elles; person++) {
        cjgt::VerbForm verbForm = cjgt::getVerbForm(verb, tense, person);
        formLabels.at(person)->SetLabel(wxString(cjgt::getFormString(verbForm)));
    }
    
    this->Fit();
}
