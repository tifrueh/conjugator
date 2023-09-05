// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "mainframe.hpp"
#include "toppanel.hpp"

MainFrame::MainFrame(wxString title) : wxFrame(NULL, wxID_ANY, title) {

    topPanel = new TopPanel(this);

    topPanelSizer = new wxBoxSizer(wxVERTICAL);

    topPanelSizer->Add(
        topPanel,
        1,
        wxEXPAND,
        0
    );

    SetSizerAndFit(topPanelSizer);
}
