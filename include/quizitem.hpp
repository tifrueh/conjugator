// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include "conjugateur.hpp"

class QuizItem : public wxBoxSizer {
    public:
        QuizItem(wxWindow* parent, const conj::VerbForm& verbForm);
        bool evaluate();
        void showSolution();
        void setVerbForm(const conj::VerbForm& verbForm);

    private:
        conj::VerbForm verbForm;
        wxStaticText* question = nullptr;
        wxTextCtrl* textCtrl = nullptr;
        wxStaticText* solution = nullptr;
};