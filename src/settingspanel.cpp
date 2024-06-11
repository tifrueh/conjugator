// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "settingspanel.hpp"


SettingsPanel::SettingsPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    topsizer = new wxBoxSizer(wxHORIZONTAL);
    buttonsizer = new wxBoxSizer(wxVERTICAL);

    testtitle = new wxStaticText(this, wxID_ANY, _("Quiz language"));

    topsizer->Add(
        testtitle,
        0,
        wxEXPAND | wxALL,
        5
    );

    this->SetSizerAndFit(topsizer);
}
