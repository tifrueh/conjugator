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
        std::vector<cjgt::QuizData> get_quiz_datas(const unsigned int& count);

        // Reset the keyboard focus to the first quiz item.
        void reset_focus();

        // Generate a new quiz. Show a message if there are not enough possible verb
        // forms selected to generate the desired amount of questions.
        // Note: This error should not be possible, but it was possible during early
        // development stages, when not many verbs were added yet, so it'll just stay
        // in place as a safety measure.
        void generate_quiz();

        // Evaluate all quiz items.
        void check();

        // Evaluate all quiz items, show all solutions and set the size hints of the
        // topsizer to accommodate the solution labels.
        void show_solutions();

        // Select all category checkboxes.
        void select_all_categories();

        // Select all tense checkboxes.
        void select_all_tenses();

        // Unselect all checkboxes.
        void unselect_all();

        void set_language(const cjgt::Language* language);

    private:
        int quiz_items_count;
        const cjgt::Language* language;
        wxBoxSizer* top_sizer = nullptr;
        wxStaticBoxSizer* sizer_control_box = nullptr;
        wxBoxSizer* sizer_categories = nullptr;
        wxBoxSizer* sizer_tenses = nullptr;
        wxStaticBoxSizer* sizer_quiz_box = nullptr;
        wxFlexGridSizer* sizer_quiz = nullptr;

        wxStaticText* title_categories = nullptr;
        std::map<const cjgt::Category*, wxCheckBox*> check_boxes_category;

        wxStaticText* title_tenses = nullptr;
        std::map<const cjgt::Tense*, wxCheckBox*> check_boxes_tense;

        wxBoxSizer* sizer_buttons = nullptr;
        wxButton* button_next = nullptr;
        wxButton* button_check = nullptr;
        wxButton* button_solutions = nullptr;
        std::vector<QuizItem*> quiz_items;

        void set_categories();
        void set_tenses();

        void set_category_check_boxes(const bool& status);
        void set_tense_check_boxes(const bool& status);
};
