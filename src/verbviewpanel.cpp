// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "verbviewpanel.hpp"


VerbViewPanel::VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb* verb, const cjgt::Tense* tense) : wxPanel(parent, id) {
    this->verb = verb;
    this->tense = tense;
    sizer = new wxBoxSizer(wxVERTICAL);

    if (cjgt::strip(verb->forms[1]) == L"") {
        infinitifString = verb->name;
    } else {
        infinitifString = verb->name + L" – " + verb->forms[0];
    }

    titleLabel = new wxStaticText(this, wxID_ANY, wxString(this->tense->name));
    titleLabel->SetMinSize(wxSize(200, titleLabel->GetMinHeight()));

    infinitifLabel = new wxStaticText(this, wxID_ANY, wxString(infinitifString));

    wxFont titleFont = titleLabel->GetFont();
    titleFont.Scale(1.5);
    titleFont.MakeBold();
    titleLabel->SetFont(titleFont);

    sizer->AddSpacer(5);

    sizer->Add(titleLabel, 0, wxEXPAND, 0);
    sizer->Add(infinitifLabel, 0, wxEXPAND, 0);

    sizer->AddSpacer(10);

    // Add a label so the sizer for each verb form of the tense.
    for (std::wstring person : this->tense->persons) {
        formLabels.insert({person, new wxStaticText(this, wxID_ANY, wxEmptyString)});
        sizer->Add(formLabels.at(person), 0, wxEXPAND, 0);
    }

    this->SetSizerAndFit(sizer);

    this->setVerb(verb);
}


void VerbViewPanel::setVerb(const verbDB::Verb* verb) {
    this->verb = verb;

    if (cjgt::strip(verb->forms[1]) == L"") {
        infinitifString = verb->name;
    } else {
        infinitifString = verb->name + L" – " + verb->forms[1];
    }

   infinitifLabel->SetLabel(infinitifString);

    for (std::vector<std::wstring>::size_type i = 0; i < this->tense->persons.size(); i++) {
        std::wstring person = this->tense->persons[i];
        const std::wstring* form = cjgt::getVerbForm(verb, i, this->tense);
        formLabels.at(person)->SetLabel(wxString(person) + wxT(" ") + *form);

        // Hide empty forms
        if (*form == L"") {
            sizer->Hide(formLabels.at(person));
        } else {
            sizer->Show(formLabels.at(person));
        }
    }

    sizer->SetSizeHints(this);
}
