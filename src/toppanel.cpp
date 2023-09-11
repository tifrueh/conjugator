// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

#include "conjugateur.hpp"
#include "id.hpp"
#include "verb.db.hpp"
#include "toppanel.hpp"

TopPanel::TopPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {

    topsizer = new wxBoxSizer(wxHORIZONTAL);

    formSelectionSizer = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Sélection de verbes/temps"));

    quizBoxSizer = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Quiz"));

    quizSizer = new wxFlexGridSizer(3, wxSize(10, 3));
    quizSizer->AddGrowableCol(1, 1);

    quizItemCount = 20;

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

    checkBoxER->SetValue(true);
    checkBoxPresent->SetValue(true);

    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    okayButton = new wxButton(this, winID::okayButton, wxT("Gérer"));
    checkButton = new wxButton(this, winID::checkButton, wxT("Contrôler"));
    solutionButton = new wxButton(this, winID::solutionButton, wxT("Solutions"));

    buttonSizer->Add(
        okayButton,
        0,
        wxEXPAND |
        wxALL,
        5
    );

    buttonSizer->Add(
        checkButton,
        0,
        wxEXPAND |
        wxALL,
        5
    );

    buttonSizer->Add(
        solutionButton,
        0,
        wxEXPAND |
        wxALL,
        5
    );

    formSelectionSizer->Add(
        verbTypeTitle,
        0,
        wxEXPAND |
        wxBOTTOM,
        10
    );

    formSelectionSizer->Add(
        checkBoxER,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->Add(
        checkBoxIR,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->Add(
        checkBoxOIR,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->Add(
        checkBoxRE,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->AddSpacer(15);

    formSelectionSizer->Add(
        tenseTitle,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        10
    );

    formSelectionSizer->Add(
        checkBoxParticipePresent,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->Add(
        checkBoxPresent,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->Add(
        checkBoxImparfait,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->Add(
        checkBoxFutur,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->Add(
        checkBoxPasseCompose,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->Add(
        checkBoxPlusQueParfait,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->Add(
        checkBoxSubjonctif,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->Add(
        checkBoxConditionnel,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    formSelectionSizer->Add(
        buttonSizer,
        0,
        wxCENTER |
        wxTOP,
        15
    );

    std::vector<cjgt::VerbForm> verbs = GetVerbForms(quizItemCount);
    QuizItem* itemPtr = nullptr;

    for (int i = 0; i < quizItemCount; i++) {
        itemPtr = new QuizItem(this, quizSizer, verbs.at(i));
        quizItems.push_back(itemPtr);
    }

    quizBoxSizer->Add(
        quizSizer,
        1,
        wxEXPAND | wxALL,
        10
    );

    topsizer->Add(
        formSelectionSizer,
        0,
        0,
        0
    );

    topsizer->Add(
        quizBoxSizer,
        1,
        wxLEFT,
        10
    );

    SetSizerAndFit(topsizer);
}

void TopPanel::GenerateQuiz() {

    std::vector<cjgt::VerbForm> verbForms;

    try {
        verbForms = GetVerbForms(quizItems.size());
    } catch(const std::invalid_argument& exception) {
        wxMessageDialog* dlg = new wxMessageDialog(this, wxT("Il n'est pas possible de générer suffisamment de questions de quiz à partir de votre sélection. Veuillez sélectionner plus de verbes ou plus de temps."));
        dlg->ShowModal();
        return;
    }

    for (long unsigned int i = 0; i < quizItems.size(); i++) {
        quizItems.at(i)->setVerbForm(verbForms.at(i));
    }

    Layout();
}

std::vector<cjgt::VerbForm> TopPanel::GetVerbForms(const int& count) {
    std::vector<const verbDB::Verb*> usableVerbs;
    std::vector<verbDB::Tense> usableTenses;
    std::vector<cjgt::VerbForm> verbForms;

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

    int usableFormCount = 0;

    if (checkBoxParticipePresent->GetValue()) {
        usableTenses.push_back(verbDB::Tense::participePresent);
        usableFormCount += usableVerbs.size();
    }

    if (checkBoxPresent->GetValue()) {
        usableTenses.push_back(verbDB::Tense::present);
        usableFormCount += usableVerbs.size() * 8;
    }

    if (checkBoxImparfait->GetValue()) {
        usableTenses.push_back(verbDB::Tense::imparfait);
        usableFormCount += usableVerbs.size() * 8;
    }

    if (checkBoxFutur->GetValue()) {
        usableTenses.push_back(verbDB::Tense::futur);
        usableFormCount += usableVerbs.size() * 8;
    }

    if (checkBoxPasseCompose->GetValue()) {
        usableTenses.push_back(verbDB::Tense::passeCompose);
        usableFormCount += usableVerbs.size() * 8;
    }

    if (checkBoxPlusQueParfait->GetValue()) {
        usableTenses.push_back(verbDB::Tense::plusQueParfait);
        usableFormCount += usableVerbs.size() * 8;
    }

    if (checkBoxSubjonctif->GetValue()) {
        usableTenses.push_back(verbDB::Tense::subjonctif);
        usableFormCount += usableVerbs.size() * 8;
    }

    if (checkBoxConditionnel->GetValue()) {
        usableTenses.push_back(verbDB::Tense::conditionnel);
        usableFormCount += usableVerbs.size() * 8;
    }

    if (usableFormCount < count) {
        throw std::invalid_argument( "More forms requested than possible" );
    }

    const verbDB::Verb* verb;
    verbDB::Tense tense;
    cjgt::VerbForm verbForm;
    int randomPosVerb;
    int randomPosTense;
    int randomPers;
    std::srand(std::time(nullptr));
    
    for (int i = 0; i < count; i++) {
        randomPosVerb = std::rand() % usableVerbs.size();

        randomPosTense = std::rand() % usableTenses.size();

        randomPers = std::rand() % (int) verbDB::Person::elles;

        verb = usableVerbs.at(randomPosVerb);
        tense = usableTenses.at(randomPosTense);

        verbForm = cjgt::getVerbForm(*verb, tense, randomPers);

        if (std::find(std::begin(verbForms), std::end(verbForms), verbForm) == std::end(verbForms)) {
            verbForms.push_back(cjgt::getVerbForm(*verb, tense, randomPers));
        } else {
            i--;
        }
    }

    return verbForms;
}

void TopPanel::Check() {
    for (QuizItem* item : quizItems) {
        item->evaluate();
    }
}

void TopPanel::ShowSolutions() {
    for (QuizItem* item : quizItems) {
        item->evaluate();
        item->showSolution();
    }

    Layout();

}

void TopPanel::SelectAllVerbs() {
    checkBoxER->SetValue(true);
    checkBoxIR->SetValue(true);
    checkBoxOIR->SetValue(true);
    checkBoxRE->SetValue(true);
}

void TopPanel::SelectAllTenses() {
    checkBoxParticipePresent->SetValue(true);
    checkBoxPresent->SetValue(true);
    checkBoxImparfait->SetValue(true);
    checkBoxFutur->SetValue(true);
    checkBoxPasseCompose->SetValue(true);
    checkBoxPlusQueParfait->SetValue(true);
    checkBoxSubjonctif->SetValue(true);
    checkBoxConditionnel->SetValue(true);
}

void TopPanel::UnselectAll() {
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
