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
    verbTypeChoices.Add(wxT("-er"));
    verbTypeChoices.Add(wxT("-ir"));
    verbTypeChoices.Add(wxT("-oir"));
    verbTypeChoices.Add(wxT("-re"));
    verbTypeBox = new wxCheckListBox(this, wxID_ANY, wxDefaultPosition, wxSize(wxDefaultSize.GetX(), 90), verbTypeChoices);

    topsizer->Add(
        verbTypeTitle,
        0,
        wxEXPAND |
        wxALL,
        10
    );

    topsizer->Add(
        verbTypeBox,
        0,
        wxEXPAND |
        wxLEFT | wxRIGHT | wxBOTTOM,
        10
    );

    SetSizerAndFit(topsizer);
}
