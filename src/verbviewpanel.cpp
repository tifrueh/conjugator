// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "verb.db.hpp"
#include "conjugateur.hpp"

#include "verbviewpanel.hpp"

VerbViewPanel::VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb &verb) : wxPanel(parent, id) {
    this->verb = verb;
    sizer = new wxBoxSizer(wxVERTICAL);

    formLabels.insert({{verbDB::Tense::infinitif, verbDB::Person::none}, new wxStaticText(this, wxID_ANY, wxEmptyString)});
    formLabels.insert({{verbDB::Tense::participePresent, verbDB::Person::none}, new wxStaticText(this, wxID_ANY, wxEmptyString)});

    wxFont titleFont = formLabels.at({verbDB::Tense::infinitif, verbDB::Person::none})->GetFont();
    titleFont.Scale(1.5);
    titleFont.MakeBold();
    formLabels.at({verbDB::Tense::infinitif, verbDB::Person::none})->SetFont(titleFont);

    sizer->AddSpacer(5);

    sizer->Add(formLabels.at({verbDB::Tense::infinitif, verbDB::Person::none}), 0, wxEXPAND | wxLEFT | wxRIGHT, 10);
    sizer->Add(formLabels.at({verbDB::Tense::participePresent, verbDB::Person::none}), 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    sizer->AddSpacer(10);

    for (int tense = verbDB::Tense::present; tense <= verbDB::Tense::conditionnel; tense++) {
        sizer->AddSpacer(10);
        titleLabels.insert({tense, new wxStaticText(this, wxID_ANY, wxString(cjgt::getTense((int) tense)))});
        titleLabels.at(tense)->SetFont(titleFont);

        sizer->Add(titleLabels.at(tense), 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

        for (int person = verbDB::Person::je; person <= verbDB::Person::elles; person++) {
            formLabels.insert({{tense, person}, new wxStaticText(this, wxID_ANY, wxEmptyString)});
            sizer->Add(formLabels.at({tense, person}), 0, wxEXPAND | wxLEFT | wxRIGHT, 10);
        }
    }
    
    sizer->AddSpacer(5);

    this->SetSizerAndFit(sizer);

    setVerb(verb);
}

void VerbViewPanel::setVerb(const verbDB::Verb &inputVerb) {
    verb = inputVerb;
    formLabels.at({verbDB::Tense::infinitif, verbDB::Person::none})->SetLabel(verb.infinitif);
    formLabels.at({verbDB::Tense::participePresent, verbDB::Person::none})->SetLabel(verb.participePresent);

    for (int tense = verbDB::Tense::present; tense <= verbDB::Tense::conditionnel; tense++) {
        for (int person = verbDB::Person::je; person <= verbDB::Person::elles; person++) {
            cjgt::VerbForm verbForm = cjgt::getVerbForm(verb, tense, person);
            formLabels.at({tense, person})->SetLabel(wxString(cjgt::getFormString(verbForm)));
        }
    }
    this->Fit();
}
