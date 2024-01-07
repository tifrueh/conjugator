// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include <wx/aboutdlg.h>

#include "toppanel.hpp"
#include "inspectorframe.hpp"


class MainFrame : public wxFrame {
    public:
        explicit MainFrame(const wxString& title);
        wxAboutDialogInfo GetInfo();
    
    private:
        wxAboutDialogInfo info;
        wxMenuBar* menuBar;
        wxMenu* menuEdit;
        wxMenu* menuQuiz;
        wxMenu* menuHelp;
        wxBoxSizer* topPanelSizer = nullptr;
        TopPanel* topPanel = nullptr;
        InspectorFrame* inspector = nullptr;
        void enableMenuBar();
        void disableMenuBar();
        void computeNewSize();
        void OnOkay(wxCommandEvent& event);
        void OnCheck(wxCommandEvent& event);
        void OnSolution(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSelectVerbs(wxCommandEvent& event);
        void OnSelectTenses(wxCommandEvent& event);
        void OnUnselectAll(wxCommandEvent& event);
        void OnGitHub(wxCommandEvent& event);
        void OnInspector(wxCommandEvent& event);
        void OnInspectorClose(wxWindowDestroyEvent& event);
        void OnVerbBox(wxCommandEvent& event);
};
