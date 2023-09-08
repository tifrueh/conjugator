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

QuizItem::QuizItem(wxWindow* parent, const conj::VerbForm& verbForm) : wxBoxSizer(wxHORIZONTAL) {
    this->verbForm = verbForm;

    question = new wxStaticText(parent, 
        wxID_ANY, 
        wxString(verbForm.infinitif + ": " + verbForm.tense + " – " + verbForm.person),
        wxDefaultPosition,
        wxSize(200, wxDefaultSize.GetY()),
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

void QuizItem::setVerbForm(const conj::VerbForm& verbForm) {
    this->verbForm = verbForm;

    textCtrl->SetForegroundColour(wxNullColour);

    textCtrl->Clear();

    solution->SetLabelText(wxEmptyString);

    question->SetLabelText(verbForm.infinitif + ": " + verbForm.tense + " – " + verbForm.person);
}

bool QuizItem::evaluate() {
    bool correct;
    std::string textCtrlString = std::string(textCtrl->GetLineText(0).mb_str());

    correct = verbForm.form == conj::strip(textCtrlString);

    if (correct) {
        textCtrl->SetForegroundColour(*wxGREEN);
    } else {
        textCtrl->SetForegroundColour(*wxRED);
    }

    return correct;
}

void QuizItem::showSolution() {
    solution->SetLabelText(verbForm.form);
}
