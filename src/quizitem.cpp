// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "quizitem.hpp"


QuizItem::QuizItem(wxWindow* parent, wxFlexGridSizer* sizer, const cjgt::VerbFormVariations& verbFormVariations) {
    this->verbFormVariations = verbFormVariations;
    this->sizer = sizer;
    this->parent = parent;

    // Don't show a person if the question is prompting for a participe present form.
    if (verbFormVariations.tense == cjgt::getTense(verbDB::Tense::participePresent)) {
        questionString = verbFormVariations.infinitif + L": " + verbFormVariations.tense;
    } else {
        questionString = verbFormVariations.infinitif + L": " + verbFormVariations.tense + L" – " + verbFormVariations.person;
    }

    question = new wxStaticText(parent, 
        wxID_ANY, 
        wxString(questionString)
    );

    // Create a text control with a minimum width of 150.
    textCtrl = new wxTextCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(150, wxDefaultSize.GetY()));

    solution = new wxStaticText(parent, wxID_ANY, wxEmptyString);

    sizer->Add(
        question,
        0,
        wxALIGN_CENTER_VERTICAL,
        0
    );

    sizer->Add(
        textCtrl,
        0,
        wxEXPAND | wxALIGN_CENTER_VERTICAL,
        0
    );

   sizer->Add(
        solution,
        0,
        wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT,
        0
    );
}

void QuizItem::SetFocus() {
    textCtrl->SetFocus();
}

void QuizItem::setVerbFormVariations(const cjgt::VerbFormVariations& formVariations) {
    this->verbFormVariations = formVariations;

    if (formVariations.tense == cjgt::getTense(verbDB::Tense::participePresent)) {
        questionString = formVariations.infinitif + L": " + formVariations.tense;
    } else {
        questionString = formVariations.infinitif + L": " + formVariations.tense + L" – " + formVariations.person;
    }

    // Set the text colour back to default.
    textCtrl->SetForegroundColour(wxNullColour);

    textCtrl->Clear();

    solution->SetLabelText(wxEmptyString);

    question->SetLabelText(questionString);
}

bool QuizItem::evaluate() {
    bool correct;
    std::wstring textCtrlString = std::wstring(textCtrl->GetValue().wchar_str());

    correct = std::find(std::begin(verbFormVariations.forms), std::end(verbFormVariations.forms), textCtrlString) != std::end(verbFormVariations.forms);

    if (cjgt::strip(textCtrlString).empty()) {
        textCtrl->SetForegroundColour(wxNullColour);
    }
    else if (correct) {
        textCtrl->SetForegroundColour(*wxGREEN);
    } else {
        textCtrl->SetForegroundColour(*wxRED);
    }

    textCtrl->Refresh();

    return correct;
}

void QuizItem::showSolution() {
    std::wstring solutionStr;
    
    solutionStr += verbFormVariations.forms.at(0);
    
    for (size_t formVariationIndex = 1; formVariationIndex < verbFormVariations.forms.size(); formVariationIndex++) {
        solutionStr += L" / ";
        solutionStr += verbFormVariations.forms.at(formVariationIndex);
    }

    solution->SetLabelText(wxString(solutionStr));
}
