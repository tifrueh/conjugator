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

QuizItem::QuizItem(wxWindow* parent, wxFlexGridSizer* sizer, const cjgt::VerbForm& verbForm) {
    this->verbForm = verbForm;
    this->sizer = sizer;
    this->parent = parent;

    if (verbForm.tense == cjgt::getTense(verbDB::Tense::participePresent)) {
        questionString = verbForm.infinitif + L": " + verbForm.tense;
    } else {
        questionString = verbForm.infinitif + L": " + verbForm.tense + L" – " + verbForm.person;
    }

    question = new wxStaticText(parent, 
        wxID_ANY, 
        wxString(questionString)
    );

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

    textCtrl->Refresh();

    return correct;
}

void QuizItem::showSolution() {
    solution->SetLabelText(verbForm.form);
}
