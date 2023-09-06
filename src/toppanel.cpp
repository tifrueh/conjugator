// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include <vector>
#include <ctime>

#include "conjugateur.hpp"
#include "id.hpp"
#include "verb.db.hpp"
#include "toppanel.hpp"

TopPanel::TopPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {

    topsizer = new wxBoxSizer(wxVERTICAL);

    verbTypeTitle = new wxStaticText(this, wxID_ANY, wxT("Types de verbes"), wxDefaultPosition, wxSize(250, wxDefaultSize.GetY()));
    wxFont titleFont = verbTypeTitle->GetFont();
    titleFont.Scale(1.1);
    titleFont.MakeBold();
    verbTypeTitle->SetFont(titleFont);

    checkBoxER = new wxCheckBox(this, winID::checkBoxER, wxT("-er"));
    checkBoxIR = new wxCheckBox(this, winID::checkBoxIR, wxT("-ir"));
    checkBoxOIR = new wxCheckBox(this, winID::checkBoxOIR, wxT("-oir"));
    checkBoxRE = new wxCheckBox(this, winID::checkBoxRE, wxT("-re"));

    tenseTitle = new wxStaticText(this, wxID_ANY, wxT("Temps"), wxDefaultPosition, wxSize(250, wxDefaultSize.GetY()));
    tenseTitle->SetFont(titleFont);

    checkBoxParticipePresent = new wxCheckBox(this, winID::checkBoxParticipePresent, wxString(verbDB::tenseStrings.at(1)));
    checkBoxPresent = new wxCheckBox(this, winID::checkBoxPresent, wxString(verbDB::tenseStrings.at(2)));
    checkBoxImparfait = new wxCheckBox(this, winID::checkBoxImparfait, wxString(verbDB::tenseStrings.at(3)));
    checkBoxFutur = new wxCheckBox(this, winID::checkBoxFutur, wxString(verbDB::tenseStrings.at(4)));
    checkBoxPasseCompose = new wxCheckBox(this, winID::checkBoxPasseCompose, wxString(verbDB::tenseStrings.at(5)));
    checkBoxPlusQueParfait = new wxCheckBox(this, winID::checkBoxPlusQueParfait, wxString(verbDB::tenseStrings.at(6)));
    checkBoxSubjonctif = new wxCheckBox(this, winID::checkBoxSubjonctif, wxString(verbDB::tenseStrings.at(7)));
    checkBoxConditionnel = new wxCheckBox(this, winID::checkBoxConditionnel, wxString(verbDB::tenseStrings.at(8)));

    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    okayButton = new wxButton(this, winID::okayButton, wxT("gérer"));
    resetButton = new wxButton(this, winID::resetButton, wxT("réinitialiser"));

    buttonSizer->Add(
        okayButton,
        0,
        wxEXPAND |
        wxALL,
        5
    );

    buttonSizer->Add(
        resetButton,
        0,
        wxEXPAND |
        wxALL,
        5
    );

    topsizer->Add(
        verbTypeTitle,
        0,
        wxEXPAND |
        wxBOTTOM,
        10
    );

    topsizer->Add(
        checkBoxER,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxIR,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxOIR,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxRE,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->AddSpacer(15);

    topsizer->Add(
        tenseTitle,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        10
    );

    topsizer->Add(
        checkBoxParticipePresent,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxPresent,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxImparfait,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxFutur,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxPasseCompose,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxPlusQueParfait,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxSubjonctif,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxConditionnel,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        buttonSizer,
        0,
        wxCENTER |
        wxTOP,
        15
    );

    SetSizerAndFit(topsizer);
}

std::vector<conj::VerbForm> TopPanel::GetVerbForms(const int& count) {
    std::vector<const verbDB::Verb*> usableVerbs;
    std::vector<verbDB::Tense> usableTenses;
    std::vector<conj::VerbForm> verbForms;

    if (checkBoxER->GetValue()) {
        usableVerbs.insert(std::end(usableVerbs), std::begin(verbDB::verbsER), std::end(verbDB::verbsER));
    }

    if (checkBoxIR->GetValue()) {
        usableVerbs.insert(std::end(usableVerbs), std::begin(verbDB::verbsIR), std::end(verbDB::verbsIR));
    }

    if (checkBoxOIR->GetValue()) {
        usableVerbs.insert(std::end(usableVerbs), std::begin(verbDB::verbsOIR), std::end(verbDB::verbsOIR));
    }

    if (checkBoxRE->GetValue()) {
        usableVerbs.insert(std::end(usableVerbs), std::begin(verbDB::verbsRE), std::end(verbDB::verbsRE));
    }


    if (checkBoxParticipePresent->GetValue()) {
        usableTenses.push_back(verbDB::Tense::participePresent);
    }

    if (checkBoxPresent->GetValue()) {
        usableTenses.push_back(verbDB::Tense::present);
    }

    if (checkBoxImparfait->GetValue()) {
        usableTenses.push_back(verbDB::Tense::imparfait);
    }

    if (checkBoxFutur->GetValue()) {
        usableTenses.push_back(verbDB::Tense::futur);
    }

    if (checkBoxPasseCompose->GetValue()) {
        usableTenses.push_back(verbDB::Tense::passeCompose);
    }

    if (checkBoxPlusQueParfait->GetValue()) {
        usableTenses.push_back(verbDB::Tense::plusQueParfait);
    }

    if (checkBoxSubjonctif->GetValue()) {
        usableTenses.push_back(verbDB::Tense::subjonctif);
    }

    if (checkBoxConditionnel->GetValue()) {
        usableTenses.push_back(verbDB::Tense::conditionnel);
    }

    const verbDB::Verb* verb;
    verbDB::Tense tense;
    int randomPosVerb;
    int randomPosTense;
    int randomPers;
    
    for (int i = 0; i < count; i++) {
        std::srand(std::time(0));
        randomPosVerb = std::rand() % usableVerbs.size();
        randomPosTense = std::rand() % usableTenses.size();

        randomPers = std::rand() % verbDB::Person::elles;

        verb = usableVerbs.at(randomPosVerb);
        tense = usableTenses.at(randomPosTense);

        verbForms.push_back(conj::getVerbForm(*verb, tense, randomPers));
    }

    return verbForms;
}

void TopPanel::Reset() {
    checkBoxER->SetValue(false);
    checkBoxIR->SetValue(false);
    checkBoxOIR->SetValue(false);
    checkBoxRE->SetValue(false);

    checkBoxParticipePresent->SetValue(false);
    checkBoxPresent->SetValue(false);
    checkBoxImparfait->SetValue(false);
    checkBoxFutur->SetValue(false);
    checkBoxPasseCompose->SetValue(false);
    checkBoxPlusQueParfait->SetValue(false);
    checkBoxSubjonctif->SetValue(false);
    checkBoxConditionnel->SetValue(false);
}
