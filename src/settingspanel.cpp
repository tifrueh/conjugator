// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "settingspanel.hpp"


SettingsPanel::SettingsPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    this->top_sizer = new wxBoxSizer(wxVERTICAL);
    this->settings_sizer = new wxBoxSizer(wxVERTICAL);
    this->button_sizer = new wxBoxSizer(wxHORIZONTAL);

    this->title_lang = new wxStaticText(this, wxID_ANY, _("Quiz language"));

    wxFont titleFont = this->title_lang->GetFont();
    titleFont.MakeBold();
    this->title_lang->SetFont(titleFont);

    this->choice_lang = new wxChoice(this, wxID_ANY);

    for (std::pair<cjgt::LanguageID, const cjgt::Language*> language : cjgt::languages) {
        this->choice_lang->Insert(*language.second->get_name(), language.first);
    }

    this->title_update = new wxStaticText(this, wxID_ANY, _("Update checker"));

    titleFont = this->title_update->GetFont();
    titleFont.MakeBold();
    this->title_update->SetFont(titleFont);

    this->do_startup_check = new wxCheckBox(this, wxID_ANY, _("Check for updates on startup"));

    this->button_cancel = new wxButton(this, winID::settings_cancel, _("Cancel"));
    this->button_save = new wxButton(this, winID::settings_save, _("Save"));

    this->button_sizer->Add(
            this->button_cancel,
            1,
            wxEXPAND | wxRIGHT,
            5
    );

    this->button_sizer->Add(
            this->button_save,
            1,
            wxEXPAND | wxLEFT,
            5
    );

    this->settings_sizer->Add(
        this->title_lang,
        0,
        wxEXPAND | wxBOTTOM,
        5
    );

    this->settings_sizer->Add(
        this->choice_lang,
        0,
        wxEXPAND | wxBOTTOM,
        20
    );

    this->settings_sizer->Add(
        this->title_update,
        0,
        wxEXPAND | wxBOTTOM,
        5
    );

    this->settings_sizer->Add(
        do_startup_check,
        0,
        wxEXPAND | wxBOTTOM,
        5
    );

    this->top_sizer->Add(
        this->settings_sizer,
        0,
        wxEXPAND | wxALL,
        20
    );

    this->top_sizer->Add(
        this->button_sizer,
        0,
        wxEXPAND | wxRIGHT | wxBOTTOM | wxLEFT,
        20
    );

    bool checkForUpdateOnStartup = true;
    wxConfigBase::Get()->Read("checkForUpdateOnStartup", &checkForUpdateOnStartup);

    size_t quizLanguage = cjgt::LanguageID::French;
    wxConfigBase::Get()->Read("quizLanguage", &quizLanguage);

    this->choice_lang->SetSelection(quizLanguage);
    this->do_startup_check->SetValue(checkForUpdateOnStartup);

    this->SetSizerAndFit(this->top_sizer);
}

void SettingsPanel::write_config() {
    wxConfigBase::Get()->Write("checkForUpdateOnStartup", this->do_startup_check->GetValue());
    wxConfigBase::Get()->Write("quizLanguage", this->choice_lang->GetSelection());
}
