// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "toppanel.hpp"

TopPanel::TopPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {

    topsizer = new wxBoxSizer(wxVERTICAL);

    verbTypeTitle = new wxStaticText(this, wxID_ANY, wxT("Types de verbes"), wxDefaultPosition, wxSize(250, wxDefaultSize.GetY()));
    wxFont titleFont = verbTypeTitle->GetFont();
    titleFont.Scale(1.1);
    titleFont.MakeBold();
    verbTypeTitle->SetFont(titleFont);

    checkBoxER = new wxCheckBox(this, wxID_ANY, wxT("-er"));
    checkBoxIR = new wxCheckBox(this, wxID_ANY, wxT("-ir"));
    checkBoxOIR = new wxCheckBox(this, wxID_ANY, wxT("-oir"));
    checkBoxRE = new wxCheckBox(this, wxID_ANY, wxT("-re"));

    topsizer->Add(
        verbTypeTitle,
        0,
        wxEXPAND |
        wxBOTTOM,
        10
    );

    topsizer->Add(
        checkBoxER,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxIR,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxOIR,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxRE,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    SetSizerAndFit(topsizer);
}
