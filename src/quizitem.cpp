// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


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
        0,
        wxRIGHT,
        10
    );

   this->Add(
        solution,
        0,
        wxALIGN_CENTER_VERTICAL | wxRIGHT,
        10
    );
}