// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include <wx/aboutdlg.h>

#include "toppanel.hpp"


class MainFrame : public wxFrame {
    public:
        MainFrame(wxString title);
        wxAboutDialogInfo GetInfo();
    
    private:
        wxAboutDialogInfo info;
        wxBoxSizer* topPanelSizer = nullptr;
        TopPanel* topPanel = nullptr;
};
