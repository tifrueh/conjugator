// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "toppanel.hpp"


TopPanel::TopPanel(wxWindow* parent, const cjgt::Language* language) : wxPanel(parent, wxID_ANY) {

    this->language = language;

    // Add a horizontal box sizer.
    this->top_sizer = new wxBoxSizer(wxHORIZONTAL);

    // Add a vertical static box sizer to hold the form selection checkboxes.
    this->sizer_control_box = new wxStaticBoxSizer(wxVERTICAL, this, _("Category/tense selection"));

    this->sizer_categories = new wxBoxSizer(wxVERTICAL);
    this->sizer_tenses = new wxBoxSizer(wxVERTICAL);

    // Add a vertical static box sizer to hold a sizer, which, in turn, will hold all quiz items.
    this->sizer_quiz_box = new wxStaticBoxSizer(wxVERTICAL, this, _("Quiz"));

    // Add a flex grid sizer to hold all quiz items.
    this->sizer_quiz = new wxFlexGridSizer(3, wxSize(10, 3));
    this->sizer_quiz->AddGrowableCol(1, 1);

    this->quiz_items_count = 15;

    for (int i = 0; i < this->quiz_items_count; i++) {
        this->sizer_quiz->AddGrowableRow(i, 1);
    }

    // Add all the contents of the formSelectionSizer and, in turn, add it to the topsizer.
    this->title_categories = new wxStaticText(this, wxID_ANY, _("Categories"), wxDefaultPosition, wxSize(250, wxDefaultSize.GetY()));
    wxFont titleFont = this->title_categories->GetFont();
    titleFont.Scale(1.1);
    titleFont.MakeBold();
    this->title_categories->SetFont(titleFont);

    this->title_tenses = new wxStaticText(this, wxID_ANY, _("Tenses"), wxDefaultPosition, wxSize(250, wxDefaultSize.GetY()));
    this->title_tenses->SetFont(titleFont);

    this->sizer_buttons = new wxBoxSizer(wxHORIZONTAL);

    this->button_next = new wxButton(this, winID::button_next, _("Next"));
    this->button_check = new wxButton(this, winID::button_check, _("Check"));
    this->button_solutions = new wxButton(this, winID::button_solutions, _("Solutions"));

    int midSpace = 5;
    int bigSpace = 10;
    int hugeSpace = 15;

    this->sizer_buttons->Add(
        this->button_next,
        0,
        wxEXPAND |
        wxALL,
        midSpace
    );

    this->sizer_buttons->Add(
        this->button_check,
        0,
        wxEXPAND |
        wxALL,
        midSpace
    );

    this->sizer_buttons->Add(
        this->button_solutions,
        0,
        wxEXPAND |
        wxALL,
        midSpace
    );

    this->sizer_control_box->AddSpacer(bigSpace);

    this->sizer_control_box->Add(
        this->title_categories,
        0,
        wxEXPAND |
        wxLEFT | wxRIGHT,
        bigSpace
    );

    this->sizer_control_box->AddSpacer(bigSpace);

    this->sizer_control_box->Add(
        this->sizer_categories,
        0,
        wxEXPAND |
        wxLEFT | wxRIGHT,
        bigSpace
    );

    this->set_categories();

    this->sizer_control_box->AddSpacer(hugeSpace);

    this->sizer_control_box->Add(
        this->title_tenses,
        0,
        wxEXPAND |
        wxLEFT | wxRIGHT,
        bigSpace
    );

    this->sizer_control_box->AddSpacer(bigSpace);

    this->sizer_control_box->Add(
        this->sizer_tenses,
        0,
        wxEXPAND |
        wxLEFT | wxRIGHT,
        bigSpace
    );

    this->set_tenses();

    this->sizer_control_box->AddStretchSpacer();

    this->sizer_control_box->Add(
        this->sizer_buttons,
        0,
        wxCENTER |
        wxTOP,
        hugeSpace
    );

    std::vector<cjgt::QuizData> quizDatas = get_quiz_datas(this->quiz_items_count);
    QuizItem* itemPtr = nullptr;

    for (int i = 0; i < this->quiz_items_count; i++) {
        itemPtr = new QuizItem(this, this->sizer_quiz, quizDatas.at(i));
        quiz_items.push_back(itemPtr);
    }

    this->sizer_quiz_box->Add(
        this->sizer_quiz,
        1,
        wxEXPAND | wxALL,
        bigSpace
    );

    this->top_sizer->Add(
        this->sizer_control_box,
        0,
        wxEXPAND | wxTOP | wxBOTTOM | wxLEFT,
        20
    );

    this->top_sizer->AddSpacer(bigSpace);

    // Add the sizer_quiz_box to the topsizer.
    this->top_sizer->Add(
        this->sizer_quiz_box,
        1,
        wxEXPAND | wxTOP | wxBOTTOM | wxRIGHT,
        20
    );

    SetSizerAndFit(this->top_sizer);
}

std::vector<cjgt::QuizData> TopPanel::get_quiz_datas(const unsigned int& count) {
    std::vector<const cjgt::Category*> usableCategories;
    std::vector<const cjgt::Tense*> usableTenses;
    std::vector<cjgt::QuizData> quizDatas;
    std::vector<const verbDB::Verb*>::size_type usableVerbCount = 0;
    std::vector<const std::wstring*>::size_type usableFormCount = 0;

    for (std::pair<const cjgt::Category*, wxCheckBox*> element : this->check_boxes_category) {

        if (element.second->GetValue() == false) {
            continue;
        }

        usableCategories.push_back(element.first);
        usableVerbCount += element.first->verbs.size();
    }


    for (std::pair<const cjgt::Tense*, wxCheckBox*> element : this->check_boxes_tense) {

        if (element.second->GetValue() == false) {
            continue;
        }

        usableTenses.push_back(element.first);
        usableFormCount += usableVerbCount * element.first->persons.size();
    }

    if (usableFormCount < (unsigned long) count) {
        throw std::invalid_argument( "More forms requested than possible" );
    }

    for (unsigned int i = 0; i < count; i++) {
        cjgt::QuizData quizData = this->language->get_random_quiz_data(usableCategories, usableTenses);

        if (std::find(quizDatas.begin(), quizDatas.end(), quizData) != quizDatas.end()) {
            i--;
        } else if (*quizData.form == L"") {
            i--;
        } else {
            quizDatas.push_back(quizData);
        }
    }

    return quizDatas;
}

void TopPanel::reset_focus() {
    this->quiz_items.at(0)->set_focus();
}

void TopPanel::generate_quiz() {

    std::vector<cjgt::QuizData> quizDatas;

    try {
        quizDatas = this->get_quiz_datas((unsigned int) this->quiz_items.size());
    } catch(const std::invalid_argument& exception) {
        auto dlg = new wxMessageDialog(this, _("It wasn't possible to generate enough questions from your selection. Please select more categories or more tenses."));
        dlg->ShowModal();
        return;
    }

    for (long unsigned int i = 0; i < this->quiz_items.size(); i++) {
        this->quiz_items.at(i)->set_quiz_data(quizDatas.at(i));
    }

    this->top_sizer->SetSizeHints(this);
}

void TopPanel::check() {
    for (QuizItem* item : this->quiz_items) {
        item->evaluate();
    }
}

void TopPanel::show_solutions() {
    for (QuizItem* item : this->quiz_items) {
        item->evaluate();
        item->show_solution();
    }

    this->top_sizer->SetSizeHints(this);

}

void TopPanel::select_all_categories() {
    set_category_check_boxes(true);
}

void TopPanel::select_all_tenses() {
    set_tense_check_boxes(true);
}

void TopPanel::unselect_all() {
    set_category_check_boxes(false);
    set_tense_check_boxes(false);
}

void TopPanel::set_language(const cjgt::Language* language) {
    this->language = language;
    this->set_categories();
    this->set_tenses();
}

void TopPanel::set_category_check_boxes(const bool& status) {
    for (std::pair<const cjgt::Category*, wxCheckBox*> element : this->check_boxes_category) {
        element.second->SetValue(status);
    }
}

void TopPanel::set_tense_check_boxes(const bool& status) {
    for (std::pair<const cjgt::Tense*, wxCheckBox*> element : this->check_boxes_tense) {
        element.second->SetValue(status);
    }
}

void TopPanel::set_categories() {
    this->sizer_categories->Clear();

    for (std::pair<const cjgt::Category*, wxCheckBox*> checkBox : this->check_boxes_category) {
        checkBox.second->Destroy();
    }

    this->check_boxes_category.clear();

    for (const cjgt::Category* category : this->language->get_categories()) {
        this->check_boxes_category[category] = new wxCheckBox(this, wxID_ANY, wxString(category->name));
        this->sizer_categories->Add(
                this->check_boxes_category[category],
                0,
                wxEXPAND | wxLEFT | wxRIGHT,
                10
        );
        this->sizer_categories->AddSpacer(3);
    }

    this->set_category_check_boxes(true);
    this->sizer_categories->Layout();
    this->top_sizer->SetSizeHints(this);
};

void TopPanel::set_tenses() {
    this->sizer_tenses->Clear();

    for (std::pair<const cjgt::Tense*, wxCheckBox*> checkBox : this->check_boxes_tense) {
        this->sizer_tenses->Detach(checkBox.second);
        checkBox.second->Destroy();
    }

    this->check_boxes_tense.clear();

    for (const cjgt::Tense* tense : this->language->get_tenses()) {
        if (tense->show_in_quiz) {
            this->check_boxes_tense[tense] = new wxCheckBox(this, wxID_ANY, wxString(tense->name));
            this->sizer_tenses->Add(
                    this->check_boxes_tense[tense],
                    0,
                    wxEXPAND | wxLEFT | wxRIGHT,
                    10
            );
            this->sizer_tenses->AddSpacer(3);
        }
    }

    this->set_tense_check_boxes(true);
    this->sizer_tenses->Layout();
    this->top_sizer->SetSizeHints(this);
};
