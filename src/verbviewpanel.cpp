// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "verbviewpanel.hpp"


VerbViewPanel::VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb* verb, const cjgt::Tense* tense) : wxPanel(parent, id) {
    this->verb = verb;
    this->tense = tense;
    this->sizer = new wxBoxSizer(wxVERTICAL);

    if (cjgt::strip(verb->forms[1]) == L"") {
        this->infinitive_string = verb->name;
    } else {
        this->infinitive_string = verb->name + L" – " + verb->forms[1];
    }

    this->label_title = new wxStaticText(this, wxID_ANY, wxString(this->tense->name));
    this->label_title->SetMinSize(wxSize(200, this->label_title->GetMinHeight()));

    this->label_infinitive = new wxStaticText(this, wxID_ANY, wxString(this->infinitive_string));

    wxFont titleFont = this->label_title->GetFont();
    titleFont.Scale(1.5);
    titleFont.MakeBold();
    this->label_title->SetFont(titleFont);

    this->sizer->AddSpacer(5);

    this->sizer->Add(this->label_title, 0, wxEXPAND, 0);
    this->sizer->Add(this->label_infinitive, 0, wxEXPAND, 0);

    this->sizer->AddSpacer(10);

    // Add a label so the sizer for each verb form of the tense.
    for (std::wstring person : this->tense->persons) {
        this->labels_forms.insert({person, new wxStaticText(this, wxID_ANY, wxEmptyString)});
        sizer->Add(this->labels_forms.at(person), 0, wxEXPAND, 0);
    }

    this->SetSizerAndFit(sizer);

    this->set_verb(verb);
}


void VerbViewPanel::set_verb(const verbDB::Verb* verb) {
    this->verb = verb;

    if (cjgt::strip(verb->forms[1]) == L"") {
        this->infinitive_string = verb->name;
    } else {
        this->infinitive_string = verb->name + L" – " + verb->forms[1];
    }

   this->label_infinitive->SetLabel(this->infinitive_string);

    for (std::vector<std::wstring>::size_type i = 0; i < this->tense->persons.size(); i++) {
        std::wstring person = this->tense->persons[i];
        const std::wstring* form = cjgt::get_verb_form(verb, i, this->tense);
        this->labels_forms.at(person)->SetLabel(wxString(person) + wxT(" ") + *form);

        // Hide empty forms
        if (*form == L"") {
            sizer->Hide(this->labels_forms.at(person));
        } else {
            sizer->Show(this->labels_forms.at(person));
        }
    }

    sizer->SetSizeHints(this);
}
