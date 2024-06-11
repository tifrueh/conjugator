// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include <algorithm>
#include <random>
#include <stdexcept>
#include <map>
#include <vector>

#include "conjugator.hpp"
#include "id.hpp"
#include "quizitem.hpp"


// The only panel of the mainframe. The rest of the main app controls resides
// within this panel, so that keyboard focus can be handled automatically.
class TopPanel : public wxPanel {
    public:
        // Construct a new TopPanel.
        explicit TopPanel(wxWindow* parent, const cjgt::Language* language);

        // Randomly retrieve as many verb forms as needed for the desired amount of
        // questions based on the selected verbs and tenses.
        std::vector<cjgt::QuizData> GetQuizDatas(const unsigned int& count);

        // Reset the keyboard focus to the first quiz item.
        void ResetFocus();

        // Generate a new quiz. Show a message if there are not enough possible verb
        // forms selected to generate the desired amount of questions.
        // Note: This error should not be possible, but it was possible during early
        // development stages, when not many verbs were added yet, so it'll just stay
        // in place as a safety measure.
        void GenerateQuiz();

        // Evaluate all quiz items.
        void Check();

        // Evaluate all quiz items, show all solutions and set the size hints of the
        // topsizer to accommodate the solution labels.
        void ShowSolutions();

        // Select all verb suffix checkboxes.
        void SelectAllVerbs();

        // Select all tense checkboxes.
        void SelectAllTenses();

        // Unselect all checkboxes.
        void UnselectAll();

        void SetLanguage(const cjgt::Language* language);

    private:
        int quizItemCount;
        const cjgt::Language* language;
        wxBoxSizer* topsizer = nullptr;
        wxStaticBoxSizer* formSelectionSizer = nullptr;
        wxStaticBoxSizer* quizBoxSizer = nullptr;
        wxFlexGridSizer* quizSizer = nullptr;

        wxStaticText* verbTypeTitle = nullptr;
        std::map<const cjgt::Category*, wxCheckBox*> categoryCheckBoxes;

        wxStaticText* tenseTitle = nullptr;
        std::map<const cjgt::Tense*, wxCheckBox*> tenseCheckBoxes;

        wxBoxSizer* buttonSizer = nullptr;
        wxButton* okayButton = nullptr;
        wxButton* checkButton = nullptr;
        wxButton* solutionButton = nullptr;
        std::vector<QuizItem*> quizItems;

        void SetAllVerbs(const bool& status);
        void SetAllTenses(const bool& status);
};
