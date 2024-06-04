// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "toppanel.hpp"


TopPanel::TopPanel(wxWindow* parent, const cjgt::Language* language) : wxPanel(parent, wxID_ANY) {

    this->language = language;

    // Add a horizontal box sizer.
    topsizer = new wxBoxSizer(wxHORIZONTAL);

    // Add a vertical static box sizer to hold the form selection checkboxes.
    formSelectionSizer = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Sélection de verbes/temps"));

    // Add a vertical static box sizer to hold a sizer, which, in turn, will hold all quiz items.
    quizBoxSizer = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Quiz"));

    // Add a flex grid sizer to hold all quiz items.
    quizSizer = new wxFlexGridSizer(3, wxSize(10, 3));
    quizSizer->AddGrowableCol(1, 1);

    quizItemCount = 15;

    for (int i = 0; i < quizItemCount; i++) {
        quizSizer->AddGrowableRow(i, 1);
    }

    // Add all the contents of the formSelectionSizer and, in turn, add it to the topsizer.
    verbTypeTitle = new wxStaticText(this, wxID_ANY, wxT("Types de verbes"), wxDefaultPosition, wxSize(250, wxDefaultSize.GetY()));
    wxFont titleFont = verbTypeTitle->GetFont();
    titleFont.Scale(1.1);
    titleFont.MakeBold();
    verbTypeTitle->SetFont(titleFont);

    tenseTitle = new wxStaticText(this, wxID_ANY, wxT("Temps"), wxDefaultPosition, wxSize(250, wxDefaultSize.GetY()));
    tenseTitle->SetFont(titleFont);

    addSettingsTitle = new wxStaticText(this, wxID_ANY, wxT("Paramètres additionels"), wxDefaultPosition, wxSize(250, wxDefaultSize.GetY()));
    addSettingsTitle->SetFont(titleFont);

    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    okayButton = new wxButton(this, winID::okayButton, wxT("Gérer"));
    checkButton = new wxButton(this, winID::checkButton, wxT("Contrôler"));
    solutionButton = new wxButton(this, winID::solutionButton, wxT("Solutions"));

    int smallSpace = 3;
    int midSpace = 5;
    int bigSpace = 10;
    int hugeSpace = 15;

    buttonSizer->Add(
        okayButton,
        0,
        wxEXPAND |
        wxALL,
        midSpace
    );

    buttonSizer->Add(
        checkButton,
        0,
        wxEXPAND |
        wxALL,
        midSpace
    );

    buttonSizer->Add(
        solutionButton,
        0,
        wxEXPAND |
        wxALL,
        midSpace
    );

    formSelectionSizer->AddSpacer(bigSpace);

    formSelectionSizer->Add(
        verbTypeTitle,
        0,
        wxEXPAND |
        wxLEFT | wxRIGHT,
        bigSpace
    );

    formSelectionSizer->AddSpacer(bigSpace);

    for (const cjgt::Category* category : this->language->getCategories()) {
        this->categoryCheckBoxes[category] = new wxCheckBox(this, wxID_ANY, wxString(category->name));
        this->formSelectionSizer->Add(
                this->categoryCheckBoxes[category],
                0,
                wxEXPAND | wxLEFT | wxRIGHT,
                bigSpace
        );
    }

    this->SetAllVerbs(true);

    formSelectionSizer->AddSpacer(hugeSpace);

    formSelectionSizer->Add(
        tenseTitle,
        0,
        wxEXPAND |
        wxLEFT | wxRIGHT,
        bigSpace
    );

    formSelectionSizer->AddSpacer(bigSpace);

    for (const cjgt::Tense* tense : this->language->getTenses()) {
        if (tense->show_in_quiz) {
            this->tenseCheckBoxes[tense] = new wxCheckBox(this, wxID_ANY, wxString(tense->name));
            formSelectionSizer->Add(
                    this->tenseCheckBoxes[tense],
                    0,
                    wxEXPAND | wxLEFT | wxRIGHT,
                    bigSpace
            );
        }
    }

    this->SetAllTenses(true);

    formSelectionSizer->AddStretchSpacer();

    formSelectionSizer->Add(
        buttonSizer,
        0,
        wxCENTER |
        wxTOP,
        15
    );

    std::vector<cjgt::QuizData> quizDatas = GetQuizDatas(quizItemCount);
    QuizItem* itemPtr = nullptr;

    for (int i = 0; i < quizItemCount; i++) {
        itemPtr = new QuizItem(this, quizSizer, quizDatas.at(i));
        quizItems.push_back(itemPtr);
    }

    quizBoxSizer->Add(
        quizSizer,
        1,
        wxEXPAND | wxALL,
        bigSpace
    );

    topsizer->Add(
        formSelectionSizer,
        0,
        wxEXPAND | wxTOP | wxBOTTOM | wxLEFT,
        20
    );

    topsizer->AddSpacer(bigSpace);

    // Add the quizBoxSizer to the topsizer.
    topsizer->Add(
        quizBoxSizer,
        1,
        wxEXPAND | wxTOP | wxBOTTOM | wxRIGHT,
        20
    );

    SetSizerAndFit(topsizer);
}

std::vector<cjgt::QuizData> TopPanel::GetQuizDatas(const unsigned int& count) {
    std::vector<const cjgt::Category*> usableCategories;
    std::vector<const cjgt::Tense*> usableTenses;
    std::vector<cjgt::QuizData> quizDatas;
    std::vector<const verbDB::Verb*>::size_type usableVerbCount = 0;
    std::vector<const std::wstring*>::size_type usableFormCount = 0;

    for (std::pair<const cjgt::Category*, wxCheckBox*> element : this->categoryCheckBoxes) {

        if (element.second->GetValue() == false) {
            continue;
        }

        usableCategories.push_back(element.first);
        usableVerbCount += element.first->verbs.size();
    }


    for (std::pair<const cjgt::Tense*, wxCheckBox*> element : this->tenseCheckBoxes) {

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
        cjgt::QuizData quizData = this->language->getRandomQuizData(usableCategories, usableTenses);

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

void TopPanel::ResetFocus() {
    quizItems.at(0)->SetFocus();
}

void TopPanel::GenerateQuiz() {

    std::vector<cjgt::QuizData> quizDatas;

    try {
        quizDatas = GetQuizDatas((unsigned int) quizItems.size());
    } catch(const std::invalid_argument& exception) {
        auto dlg = new wxMessageDialog(this, wxT("Il n'est pas possible de générer suffisamment de questions de quiz à partir de votre sélection. Veuillez sélectionner plus de verbes ou plus de temps."));
        dlg->ShowModal();
        return;
    }

    for (long unsigned int i = 0; i < quizItems.size(); i++) {
        quizItems.at(i)->setQuizData(quizDatas.at(i));
    }

    topsizer->SetSizeHints(this);
}

void TopPanel::Check() {
    for (QuizItem* item : quizItems) {
        item->evaluate();
    }
}

void TopPanel::ShowSolutions() {
    for (QuizItem* item : quizItems) {
        item->evaluate();
        item->showSolution();
    }

    topsizer->SetSizeHints(this);

}

void TopPanel::SelectAllVerbs() {
    SetAllVerbs(true);
}

void TopPanel::SelectAllTenses() {
    SetAllTenses(true);
}

void TopPanel::UnselectAll() {
    SetAllVerbs(false);
    SetAllTenses(false);
}

void TopPanel::SetLanguage(const cjgt::Language* language) {
    this->language = language;
}

void TopPanel::SetAllVerbs(const bool& status) {
    for (std::pair<const cjgt::Category*, wxCheckBox*> element : this->categoryCheckBoxes) {
        element.second->SetValue(true);
    }
}

void TopPanel::SetAllTenses(const bool& status) {
    for (std::pair<const cjgt::Tense*, wxCheckBox*> element : this->tenseCheckBoxes) {
        element.second->SetValue(true);
    }
}
