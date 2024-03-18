// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "checkerpanel.hpp"


CheckerPanel::CheckerPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    topSizer = new wxBoxSizer(wxVERTICAL);
    statusSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    titleLabel = new wxStaticText(this, wxID_ANY, wxString("Rechercher des mises à jour"));
    wxFont titleFont = titleLabel->GetFont();
    titleFont.Scale(1.1);
    titleFont.MakeBold();
    titleLabel->SetFont(titleFont);

    activityIndicator = new wxActivityIndicator(this);
    activityIndicator->Start();
    activityLabel = new wxStaticText(this, wxID_ANY, wxString("Recherche en cours"));

    cancelButton = new wxButton(this, wxID_ANY, wxString("Annuler"));
    checkAgainButton = new wxButton(this, wxID_ANY, wxString("Rechercher de nouveau"));
    downloadButton = new wxButton(this, wxID_ANY, wxString("Télécharger"));

    topSizer->Add(
        titleLabel,
        0,
        wxALL | wxEXPAND,
        10
    );

    topSizer->Add(
        statusSizer,
        0,
        wxALL | wxEXPAND,
        10
    );

    topSizer->Add(
        buttonSizer,
        0,
        wxALL | wxEXPAND,
        10
    );

    statusSizer->Add(
        activityIndicator,
        0,
        wxALL | wxALIGN_CENTRE_VERTICAL,
        2
    );

    statusSizer->Add(
        activityLabel,
        1,
        wxALL | wxALIGN_CENTRE_VERTICAL,
        2
    );

    buttonSizer->Add(
        cancelButton,
        1,
        wxALL | wxEXPAND,
        2
    );

    buttonSizer->Add(
        checkAgainButton,
        1,
        wxALL | wxEXPAND,
        2
    );

    buttonSizer->Add(
        downloadButton,
        1,
        wxALL | wxEXPAND,
        2
    );

    this->SetSizerAndFit(topSizer);
}
