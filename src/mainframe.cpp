// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#ifndef __WXOSX__
    #include "config.hpp"
#endif


#include <vector>

#include "id.hpp"
#include "toppanel.hpp"
#include "inspectorframe.hpp"

#include "mainframe.hpp"

#include "conjugateur.xpm"

// Construct a new MainFrame.
MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {

    SetIcon(wxICON(conjugateur));

    info.SetName(wxT("Conjugateur"));
    info.SetCopyright(wxT("Copyright © 2023-2024 Timo Früh"));
    
    // Set version in the app info to VERSION_STR only if not on macOS.
    #ifndef __WXOSX__
        info.SetVersion(VERSION_STR);
    #endif

    // Add a bunch more info to the app, but only on GTK, as it is the only
    // platform to support such a detailed "About" window.
    #ifdef __WXGTK__
        info.SetIcon(wxICON(conjugateur));
        info.SetDescription(wxT("Entraîneur de conjugaison des verbes français"));
        info.SetWebSite(wxT("https://github.com/tifrueh/conjugateur"), wxT("GitHub"));
        info.AddDeveloper(wxT("Timo Früh"));

        info.SetLicense(wxT("This program is free software: you can redistribute it and/or modify\n"
                            "it under the terms of the GNU General Public License as published by\n"
                            "the Free Software Foundation, either version 3 of the License, or\n"
                            "(at your option) any later version.\n"
                            "\n"
                            "This program is distributed in the hope that it will be useful,\n"
                            "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
                            "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
                            "GNU General Public License for more details.\n"
                            "\n"
                            "You should have received a copy of the GNU General Public License\n"
                            "along with this program.  If not, see <https://www.gnu.org/licenses/>."));


        info.AddTranslator(wxT("Stephane Junique"));
        info.AddTranslator(wxT("Nicolas Velin"));
        info.AddTranslator(wxT("Gérard Durand"));
    #endif

    // Define a menu bar and add all menu items.
    menuBar = new wxMenuBar();

    menuEdit = new wxMenu();
    menuQuiz = new wxMenu();
    menuHelp = new wxMenu();

    menuBar->Append(menuEdit, wxT("Édition"));
    menuBar->Append(menuQuiz, wxT("Quiz"));
    menuBar->Append(menuHelp, wxT("Aide"));

    menuEdit->Append(wxID_CUT);
    menuEdit->Append(wxID_COPY);
    menuEdit->Append(wxID_PASTE);
    menuEdit->AppendSeparator();
    menuEdit->Append(wxID_SELECTALL);

    menuQuiz->Append(winID::menuQuizSelectVerbs, wxT("Sélectionner tous les verbes\tCtrl-1"));
    menuQuiz->Append(winID::menuQuizSelectTenses, wxT("Sélectionner tous les temps\tCtrl-2"));
    menuQuiz->Append(winID::menuQuizUnselectAll, wxT("Désélectionner tout\tCtrl-0"));
    menuQuiz->AppendSeparator();
    menuQuiz->Append(winID::menuQuizOkay, wxT("Gérer\tCtrl-Enter"));
    menuQuiz->Append(winID::menuQuizCheck, wxT("Contrôler\tCtrl-Shift-Enter"));
    menuQuiz->Append(winID::menuQuizSolution, wxT("Solutions\tCtrl-S"));
    menuQuiz->AppendSeparator();
    menuQuiz->Append(winID::menuInspectorOpen, wxT("Ouvrir Inspecteur\tCtrl-I"));

    menuHelp->Append(wxID_ABOUT, wxT("À propos de Conjugateur"));
    menuHelp->AppendSeparator();
    menuHelp->Append(winID::menuHelpGitHub, wxT("GitHub"));

    this->SetMenuBar(menuBar);

    // Create a new top panel in which all windows will reside (so that
    // keyboard focus is handled automatically).
    topPanel = new TopPanel(this);
    topPanel->ResetFocus();

    // Create a new wxBoxSizer and add the top panel to it.
    topPanelSizer = new wxBoxSizer(wxVERTICAL);

    topPanelSizer->Add(
        topPanel,
        1,
        wxEXPAND | wxALL,
        0
    );

    // Bind events to their corresponding method.
    Bind(wxEVT_BUTTON, &MainFrame::OnOkay, this, winID::okayButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnCheck, this, winID::checkButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnSolution, this, winID::solutionButton);
    Bind(wxEVT_MENU, &MainFrame::OnOkay, this, winID::menuQuizOkay);
    Bind(wxEVT_MENU, &MainFrame::OnCheck, this, winID::menuQuizCheck);
    Bind(wxEVT_MENU, &MainFrame::OnSolution, this, winID::menuQuizSolution);
    Bind(wxEVT_MENU, &MainFrame::OnSelectVerbs, this, winID::menuQuizSelectVerbs);
    Bind(wxEVT_MENU, &MainFrame::OnSelectTenses, this, winID::menuQuizSelectTenses);
    Bind(wxEVT_MENU, &MainFrame::OnUnselectAll, this, winID::menuQuizUnselectAll);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnGitHub, this, winID::menuHelpGitHub);
    Bind(wxEVT_MENU, &MainFrame::OnInspector, this, winID::menuInspectorOpen);
    Bind(wxEVT_LISTBOX, &MainFrame::OnVerbBox, this, winID::inspectorVerbBox);
    Bind(wxEVT_DESTROY, &MainFrame::OnInspectorClose, this, winID::inspector);

    SetSizerAndFit(topPanelSizer);
}

// Enable all menus in the menu bar.
void MainFrame::enableMenuBar() {
    for (size_t menu = 0; menu < menuBar->GetMenuCount(); menu++) {
        menuBar->EnableTop(menu, true);
    }
}

// Disable all menus in the menu bar.
void MainFrame::disableMenuBar() {
    for (size_t menu = 0; menu < menuBar->GetMenuCount(); menu++) {
        menuBar->EnableTop(menu, false);
    }
}

// Resize the mainframe only if more space is needed.
void MainFrame::computeNewSize() {
    topPanelSizer->Layout();

    if (this->GetClientSize().GetX() < topPanelSizer->GetMinSize().GetX()) {
        topPanelSizer->SetSizeHints(this);
    } else {
        this->SetMinClientSize(topPanelSizer->ComputeFittingClientSize(this));
    }
}

// Regenerate the quiz and compute the new size of the mainframe when the okay
// button is clicked.
void MainFrame::OnOkay(wxCommandEvent& event) {
    topPanel->GenerateQuiz();
    topPanel->ResetFocus();

    computeNewSize();
}

// Check all answers when the check button is clicked.
void MainFrame::OnCheck(wxCommandEvent& event) {
    topPanel->Check();
}

// Show the solutions to the quiz and compute the new size of the mainframe
// when the solutions button is clicked.
void MainFrame::OnSolution(wxCommandEvent& event) {
    topPanel->ShowSolutions();

    computeNewSize();
}

// Show and about box with the app info when the about menu entry is selected.
void MainFrame::OnAbout(wxCommandEvent& event) {
   wxAboutBox(GetInfo(), this);
}

// Select all verbs when the corresponding menu entry is selected.
void MainFrame::OnSelectVerbs(wxCommandEvent& event) {
    topPanel->SelectAllVerbs();
}

// Select all tenses when the corresponding menu entry is selected.
void MainFrame::OnSelectTenses(wxCommandEvent& event) {
    topPanel->SelectAllTenses();
}

// Unselect all verbs and tenses when the corresponding menu entry is selected.
void MainFrame::OnUnselectAll(wxCommandEvent& event) {
    topPanel->UnselectAll();
}

// Open the app's github page in the default browser when the corresponding
// menu entry is selected.
void MainFrame::OnGitHub(wxCommandEvent& event) {
    wxLaunchDefaultBrowser(wxT("https://github.com/tifrueh/conjugateur"));
}

// Open the inspector and disable everything related to the mainframe when the
// corresponding menu entry is clicked.
void MainFrame::OnInspector(wxCommandEvent &event) {
    if (inspector == nullptr) {
        inspector = new InspectorFrame(this, winID::inspector, wxT("Inspecteur"));
    }
    topPanel->SetFocusIgnoringChildren();
    topPanel->Disable();
    this->disableMenuBar();
    inspector->Show();
}

// Reset the pointer to the inspector and enable everything related to the
// mainframe when the inspector is closed.
void MainFrame::OnInspectorClose(wxWindowDestroyEvent& event) {
    inspector = nullptr;
    this->enableMenuBar();
    topPanel->Enable();
    topPanel->ResetFocus();
}

// Update the verb in the verbview of the inspector when a new verb is selected
// in the verbbox.
void MainFrame::OnVerbBox(wxCommandEvent &event) {
    inspector->updateVerb();
}

// Return the app info.
wxAboutDialogInfo MainFrame::GetInfo() {
    return info;
}
