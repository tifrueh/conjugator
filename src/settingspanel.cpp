// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "settingspanel.hpp"


SettingsPanel::SettingsPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    topsizer = new wxBoxSizer(wxVERTICAL);
    buttonsizer = new wxBoxSizer(wxHORIZONTAL);

    langTitle = new wxStaticText(this, wxID_ANY, _("Quiz language"));

    wxFont titleFont = langTitle->GetFont();
    titleFont.MakeBold();
    langTitle->SetFont(titleFont);

    choiceLang = new wxChoice(this, wxID_ANY);

    for (std::pair<cjgt::LanguageID, const cjgt::Language*> language : cjgt::languages) {
        choiceLang->Insert(*language.second->getName(), language.first);
    }

    updateTitle = new wxStaticText(this, wxID_ANY, _("Update checker"));

    titleFont = updateTitle->GetFont();
    titleFont.MakeBold();
    updateTitle->SetFont(titleFont);

    checkBoxStartupCheck = new wxCheckBox(this, wxID_ANY, _("Check for updates on startup"));

    buttonCancel = new wxButton(this, winID::settingsCancel, _("Cancel"));
    buttonSave = new wxButton(this, winID::settingsSave, _("Save"));

    buttonsizer->Add(
            buttonCancel,
            1,
            wxEXPAND | wxALL,
            5
    );

    buttonsizer->Add(
            buttonSave,
            1,
            wxEXPAND | wxALL,
            5
    );

    topsizer->Add(
        langTitle,
        0,
        wxEXPAND | wxBOTTOM,
        5
    );

    topsizer->Add(
        choiceLang,
        0,
        wxEXPAND | wxBOTTOM,
        20
    );

    topsizer->Add(
        updateTitle,
        0,
        wxEXPAND | wxBOTTOM,
        5
    );

    topsizer->Add(
        checkBoxStartupCheck,
        0,
        wxEXPAND | wxBOTTOM,
        5
    );

    topsizer->Add(
        buttonsizer,
        0,
        wxEXPAND | wxALL,
        5
    );

    bool checkForUpdateOnStartup = true;
    wxConfigBase::Get()->Read("checkForUpdateOnStartup", &checkForUpdateOnStartup);

    size_t quizLanguage = cjgt::LanguageID::French;
    wxConfigBase::Get()->Read("quizLanguage", &quizLanguage);

    choiceLang->SetSelection(quizLanguage);
    checkBoxStartupCheck->SetValue(checkForUpdateOnStartup);

    this->SetSizerAndFit(topsizer);
}

void SettingsPanel::writeConfig() {
    wxConfigBase::Get()->Write("checkForUpdateOnStartup", this->checkBoxStartupCheck->GetValue());
    wxConfigBase::Get()->Write("quizLanguage", this->choiceLang->GetSelection());
}
