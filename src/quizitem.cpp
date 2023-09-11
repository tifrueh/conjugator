// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include <string>

#include "verb.db.hpp"
#include "conjugateur.hpp"
#include "quizitem.hpp"

QuizItem::QuizItem(wxWindow* parent, const cjgt::VerbForm& verbForm) : wxBoxSizer(wxHORIZONTAL) {
    this->verbForm = verbForm;

    if (verbForm.tense == cjgt::getTense(verbDB::Tense::participePresent)) {
        questionString = verbForm.infinitif + L": " + verbForm.tense;
    } else {
        questionString = verbForm.infinitif + L": " + verbForm.tense + L" – " + verbForm.person;
    }

    question = new wxStaticText(parent, 
        wxID_ANY, 
        wxString(questionString),
        wxDefaultPosition,
        wxSize(250, wxDefaultSize.GetY()),
        wxALIGN_CENTER_VERTICAL
    );

    textCtrl = new wxTextCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(250, wxDefaultSize.GetY()));

    solution = new wxStaticText(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(250, wxDefaultSize.GetY()), wxALIGN_CENTER_VERTICAL);

    this->Add(
        question,
        0,
        wxALIGN_CENTER_VERTICAL | wxRIGHT,
        10
    );

    this->Add(
        textCtrl,
        1,
        wxRIGHT,
        10
    );

   this->Add(
        solution,
        1,
        wxALIGN_CENTER_VERTICAL | wxRIGHT,
        10
    );
}

void QuizItem::setVerbForm(const cjgt::VerbForm& verbForm) {
    this->verbForm = verbForm;

    if (verbForm.tense == cjgt::getTense(verbDB::Tense::participePresent)) {
        questionString = verbForm.infinitif + L": " + verbForm.tense;
    } else {
        questionString = verbForm.infinitif + L": " + verbForm.tense + L" – " + verbForm.person;
    }

    textCtrl->SetForegroundColour(wxNullColour);

    textCtrl->Clear();

    solution->SetLabelText(wxEmptyString);

    question->SetLabelText(questionString);
}

bool QuizItem::evaluate() {
    bool correct;
    std::wstring textCtrlString = std::wstring(textCtrl->GetLineText(0).wchar_str());

    correct = verbForm.form == cjgt::strip(textCtrlString);

    if (cjgt::strip(textCtrlString) == "") {
        textCtrl->SetForegroundColour(wxNullColour);
    }
    else if (correct) {
        textCtrl->SetForegroundColour(*wxGREEN);
    } else {
        textCtrl->SetForegroundColour(*wxRED);
    }

    return correct;
}

void QuizItem::showSolution() {
    solution->SetLabelText(verbForm.form);
}
