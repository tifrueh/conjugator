// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include <algorithm>
#include <string>

#include "conjugator.hpp"
#include "verb.db.hpp"


// A group of windows, consisting of a question label, a text entry for the
// answer and a solution label. It always has to be added to a flex grid sizer.
class QuizItem {
    public:
        // Construct a new quiz item. It will add itself to the wxFlexGridSizer
        // provided as parameter automatically.
        QuizItem(wxWindow* parent, wxFlexGridSizer* sizer, const cjgt::QuizData& data, const bool& translate = false);

        // Set the focus to the text control.
        void set_focus();

        // Reset the verb form this quiz item should ask for.
        void set_quiz_data(const cjgt::QuizData& data, const bool& translate = false);

        // Check if the given answer in the text control is correct and colour it
        // correspondingly.
        bool evaluate();

        // Show the solution to the question.
        void show_solution();

    private:
        wxFlexGridSizer* sizer;
        wxWindow* parent;
        cjgt::QuizData data;
        wxStaticText* question = nullptr;
        wxTextCtrl* text_ctrl = nullptr;
        wxStaticText* solution = nullptr;
        std::wstring question_string;
};
