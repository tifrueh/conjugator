// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include <string>

#include "conjugateur.hpp"

class QuizItem {
    public:
        QuizItem(wxWindow* parent, wxFlexGridSizer* sizer, const cjgt::VerbForm& verbForm);
        bool evaluate();
        void showSolution();
        void setVerbForm(const cjgt::VerbForm& form);

    private:
        wxFlexGridSizer* sizer;
        wxWindow* parent;
        cjgt::VerbForm verbForm;
        wxStaticText* question = nullptr;
        wxTextCtrl* textCtrl = nullptr;
        wxStaticText* solution = nullptr;
        std::wstring questionString;
};
