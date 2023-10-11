// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "verb.db.hpp"
#include "conjugateur.hpp"

#include "verbview.hpp"

VerbView::VerbView(wxWindow* parent, wxWindowID id, const verbDB::Verb &verb) : wxScrolled<wxWindow>(parent, id) {
    this->verb = verb;
    sizer = new wxBoxSizer(wxVERTICAL);

    formLabels.insert({{verbDB::Tense::infinitif, verbDB::Person::none}, new wxStaticText(this, wxID_ANY, wxEmptyString)});
    formLabels.insert({{verbDB::Tense::participePresent, verbDB::Person::none}, new wxStaticText(this, wxID_ANY, wxEmptyString)});

    wxFont titleFont = formLabels.at({verbDB::Tense::infinitif, verbDB::Person::none})->GetFont();
    titleFont.Scale(1.5);
    titleFont.MakeBold();
    formLabels.at({verbDB::Tense::infinitif, verbDB::Person::none})->SetFont(titleFont);

    sizer->Add(formLabels.at({verbDB::Tense::infinitif, verbDB::Person::none}), 0, wxEXPAND, 3);
    sizer->Add(formLabels.at({verbDB::Tense::participePresent, verbDB::Person::none}), 0, wxEXPAND, 3);

    sizer->AddSpacer(10);

    for (int tense = verbDB::Tense::present; tense <= verbDB::Tense::conditionnel; tense++) {
        sizer->AddSpacer(10);
        titleLabels.insert({tense, new wxStaticText(this, wxID_ANY, wxString(cjgt::getTense((int) tense)))});
        titleLabels.at(tense)->SetFont(titleFont);

        sizer->Add(titleLabels.at(tense), 0, wxEXPAND, 3);

        for (int person = verbDB::Person::je; person <= verbDB::Person::elles; person++) {
            formLabels.insert({{tense, person}, new wxStaticText(this, wxID_ANY, wxEmptyString)});
            sizer->Add(formLabels.at({tense, person}), 0, wxEXPAND, 3);
        }
    }

    setVerb(verb);

    this->SetMinSize(wxSize(200, 300));

    this->SetSizer(sizer);
    this->FitInside();
    this->SetScrollRate(3, 3);

}

void VerbView::setVerb(const verbDB::Verb &inputVerb) {
    verb = inputVerb;
    formLabels.at({verbDB::Tense::infinitif, verbDB::Person::none})->SetLabel(verb.infinitif);
    formLabels.at({verbDB::Tense::participePresent, verbDB::Person::none})->SetLabel(verb.participePresent);

    for (int tense = verbDB::Tense::present; tense <= verbDB::Tense::conditionnel; tense++) {
        for (int person = verbDB::Person::je; person <= verbDB::Person::elles; person++) {
            cjgt::VerbForm verbForm = cjgt::getVerbForm(verb, tense, person);
            formLabels.at({tense, person})->SetLabel(wxString(cjgt::getFormString(verbForm)));
        }
    }
}