// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "verb.db.hpp"
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

    tenseTitle = new wxStaticText(this, wxID_ANY, wxT("Temps"), wxDefaultPosition, wxSize(250, wxDefaultSize.GetY()));
    tenseTitle->SetFont(titleFont);

    checkBoxParticipePresent = new wxCheckBox(this, wxID_ANY, wxString(verbDB::tenseStrings.at(1)));
    checkBoxPresent = new wxCheckBox(this, wxID_ANY, wxString(verbDB::tenseStrings.at(2)));
    checkBoxImparfait = new wxCheckBox(this, wxID_ANY, wxString(verbDB::tenseStrings.at(3)));
    checkBoxFutur = new wxCheckBox(this, wxID_ANY, wxString(verbDB::tenseStrings.at(4)));
    checkBoxPasseCompose = new wxCheckBox(this, wxID_ANY, wxString(verbDB::tenseStrings.at(5)));
    checkBoxPlusQueParfait = new wxCheckBox(this, wxID_ANY, wxString(verbDB::tenseStrings.at(6)));
    checkBoxSubjonctif = new wxCheckBox(this, wxID_ANY, wxString(verbDB::tenseStrings.at(7)));
    checkBoxConditionnel = new wxCheckBox(this, wxID_ANY, wxString(verbDB::tenseStrings.at(8)));

    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    okayButton = new wxButton(this, wxID_ANY, wxT("gérer"));
    resetButton = new wxButton(this, wxID_ANY, wxT("réinitialiser"));

    buttonSizer->Add(
        okayButton,
        0,
        wxEXPAND |
        wxALL,
        5
    );

    buttonSizer->Add(
        resetButton,
        0,
        wxEXPAND |
        wxALL,
        5
    );

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

    topsizer->AddSpacer(15);

    topsizer->Add(
        tenseTitle,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        10
    );

    topsizer->Add(
        checkBoxParticipePresent,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxPresent,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxImparfait,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxFutur,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxPasseCompose,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxPlusQueParfait,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxSubjonctif,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        checkBoxConditionnel,
        0,
        wxEXPAND |
        wxTOP | wxBOTTOM,
        3
    );

    topsizer->Add(
        buttonSizer,
        0,
        wxCENTER |
        wxTOP,
        15
    );

    SetSizerAndFit(topsizer);
}
