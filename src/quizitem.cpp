// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "quizitem.hpp"


QuizItem::QuizItem(wxWindow* parent, wxFlexGridSizer* sizer, const cjgt::QuizData& data, const bool& translate) {
    this->data = data;
    this->sizer = sizer;
    this->parent = parent;

    // Don't show a person if the question is prompting for a participe present form.
    if (*data.person == L"") {
        this->question_string = *data.verb_name + L": " + data.tense->name;
    } else {
        this->question_string = *data.verb_name + L": " + data.tense->name + L" – " + *data.person;
    }

    this->question = new wxStaticText(parent, 
        wxID_ANY, 
        wxString(this->question_string)
    );

    // Create a text control with a minimum width of 150.
    this->text_ctrl = new wxTextCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(150, wxDefaultSize.GetY()));

    this->solution = new wxStaticText(parent, wxID_ANY, wxEmptyString);

    this->sizer->Add(
        question,
        0,
        wxALIGN_CENTER_VERTICAL,
        0
    );

    this->sizer->Add(
        this->text_ctrl,
        0,
        wxEXPAND | wxALIGN_CENTER_VERTICAL,
        0
    );

   this->sizer->Add(
        solution,
        0,
        wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT,
        0
    );
}

void QuizItem::set_focus() {
    this->text_ctrl->SetFocus();
}

void QuizItem::set_quiz_data(const cjgt::QuizData& data, const bool& translate) {
    this->data = data;

    std::wstring infinitif;

    if (*data.person == L"") {
        this->question_string = *data.verb_name + L": " + data.tense->name;
    } else {
        this->question_string = *data.verb_name + L": " + data.tense->name + L" – " + *data.person;
    }

    // Set the text colour back to default.
    this->text_ctrl->SetForegroundColour(wxNullColour);

    this->text_ctrl->Clear();

    this->solution->SetLabelText(wxEmptyString);

    this->question->SetLabelText(this->question_string);
}

bool QuizItem::evaluate() {
    bool correct;
    std::wstring text_ctrl_string = std::wstring(this->text_ctrl->GetValue().wchar_str());

    correct = text_ctrl_string == *this->data.form;

    if (cjgt::strip(text_ctrl_string).empty()) {
        this->text_ctrl->SetForegroundColour(wxNullColour);
    }
    else if (correct) {
        this->text_ctrl->SetForegroundColour(*wxGREEN);
    } else {
        this->text_ctrl->SetForegroundColour(*wxRED);
    }

    this->text_ctrl->Refresh();

    return correct;
}

void QuizItem::show_solution() {
    std::wstring solutionStr;

    this->solution->SetLabelText(wxString(*this->data.form));
}
