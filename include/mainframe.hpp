// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "config.hpp"

#include <wx/aboutdlg.h>
#include <wx/config.h>
#include <wx/stdpaths.h>


#include "id.hpp"
#include "conjugateur.hpp"
#include "inspectorframe.hpp"
#include "toppanel.hpp"
#include "updatechecker.hpp"

#include "conjugator.xpm"


// The top-level frame containing the whole application.
class MainFrame : public wxFrame {
    public:
        // Construct a new MainFrame.
        explicit MainFrame(const wxString& title);

        // Return the app info.
        wxAboutDialogInfo GetInfo();
    
    private:
        wxAboutDialogInfo info;
        const cjgt::Language* language;
        wxMenuBar* menuBar;
        wxMenu* menuEdit;
        wxMenu* menuQuiz;
        wxMenu* menuHelp;
        wxConfig* config;
        UpdateChecker updateChecker;
        wxBoxSizer* topPanelSizer = nullptr;
        TopPanel* topPanel = nullptr;
        InspectorFrame* inspector = nullptr;
        
        // Enable all menus in the menu bar.
        void enableMenuBar();

        // Disable all menus in the menu bar.
        void disableMenuBar();

        // Resize the mainframe only if more space is needed.
        void computeNewSize();

        // Regenerate the quiz and compute the new size of the mainframe when the okay
        // button is clicked.
        void OnOkay(wxCommandEvent& event);

        // Check all answers when the check button is clicked.
        void OnCheck(wxCommandEvent& event);
        
        // Show the solutions to the quiz and compute the new size of the mainframe
        // when the solutions button is clicked.
        void OnSolution(wxCommandEvent& event);

        // Show and about box with the app info when the about menu entry is selected.
        void OnAbout(wxCommandEvent& event);

        // Select all verbs when the corresponding menu entry is selected.
        void OnSelectVerbs(wxCommandEvent& event);

        // Select all tenses when the corresponding menu entry is selected.
        void OnSelectTenses(wxCommandEvent& event);

        // Unselect all verbs and tenses when the corresponding menu entry is selected.
        void OnUnselectAll(wxCommandEvent& event);

        // Open the app's github page in the default browser when the corresponding
        // menu entry is selected.
        void OnGitHub(wxCommandEvent& event);

        // Open the inspector and disable everything related to the mainframe when the
        // corresponding menu entry is clicked.
        void OnInspector(wxCommandEvent& event);

        // Reset the pointer to the inspector and enable everything related to the
        // mainframe when the inspector is closed.
        void OnInspectorClose(wxWindowDestroyEvent& event);

        // Update the verb in the verbview of the inspector when a new verb is selected
        // in the verbbox.
        void OnVerbBox(wxCommandEvent& event);

        // Check for updates.
        void checkForUpdates(const bool& failSilently = false);

        // Callback for the update checker menu item.
        void OnUpdateChecker(wxCommandEvent& event);

        // Handle update checker results.
        void HandleUpdateChecker(wxWebRequestEvent& event);
};
