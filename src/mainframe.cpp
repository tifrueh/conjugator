// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include <vector>

#include "conjugateur.hpp"
#include "id.hpp"
#include "mainframe.hpp"
#include "toppanel.hpp"

MainFrame::MainFrame(wxString title) : wxFrame(NULL, wxID_ANY, title) {

    topPanel = new TopPanel(this);

    topPanelSizer = new wxBoxSizer(wxVERTICAL);

    topPanelSizer->Add(
        topPanel,
        1,
        wxEXPAND | wxALL,
        20
    );

    Bind(wxEVT_BUTTON, &MainFrame::OnOkay, this, winID::okayButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnReset, this, winID::resetButton);

    SetSizerAndFit(topPanelSizer);
}

void MainFrame::OnOkay(wxCommandEvent& event) {
    std::vector<conj::VerbForm> verbForms = topPanel->GetVerbForms(10);

    for (conj::VerbForm verbForm : verbForms) {
        std::cout << verbForm.tense + ": " + verbForm.person + " " + verbForm.form + "\n";
    }
}

void MainFrame::OnReset(wxCommandEvent& event) {
    topPanel->Reset();
}
