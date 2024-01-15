// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#ifndef __WXOSX__
    #include "config.h"
#endif


#include <vector>

#include "id.hpp"
#include "toppanel.hpp"
#include "inspectorframe.hpp"

#include "mainframe.hpp"

#include "conjugateur.xpm"

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {

    SetIcon(wxICON(conjugateur));

    info.SetName(wxT("Conjugateur"));
    info.SetCopyright(wxT("Copyright © 2023-2024 Timo Früh"));
    
    #ifndef __WXOSX__
        info.SetVersion(VERSION_STR);
    #endif

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

    topPanel = new TopPanel(this);
    topPanel->ResetFocus();

    topPanelSizer = new wxBoxSizer(wxVERTICAL);

    topPanelSizer->Add(
        topPanel,
        1,
        wxEXPAND | wxALL,
        0
    );

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

void MainFrame::enableMenuBar() {
    for (size_t menu = 0; menu < menuBar->GetMenuCount(); menu++) {
        menuBar->EnableTop(menu, true);
    }
}

void MainFrame::disableMenuBar() {
    for (size_t menu = 0; menu < menuBar->GetMenuCount(); menu++) {
        menuBar->EnableTop(menu, false);
    }
}

void MainFrame::computeNewSize() {
    topPanelSizer->Layout();

    if (this->GetClientSize().GetX() < topPanelSizer->GetMinSize().GetX()) {
        topPanelSizer->SetSizeHints(this);
    } else {
        this->SetMinClientSize(topPanelSizer->ComputeFittingClientSize(this));
    }
}

void MainFrame::OnOkay(wxCommandEvent& event) {
    topPanel->GenerateQuiz();
    topPanel->ResetFocus();

    computeNewSize();
}

void MainFrame::OnCheck(wxCommandEvent& event) {
    topPanel->Check();
}

void MainFrame::OnSolution(wxCommandEvent& event) {
    topPanel->ShowSolutions();

    computeNewSize();
}

void MainFrame::OnAbout(wxCommandEvent& event) {
   wxAboutBox(GetInfo(), this);
}

void MainFrame::OnSelectVerbs(wxCommandEvent& event) {
    topPanel->SelectAllVerbs();
}

void MainFrame::OnSelectTenses(wxCommandEvent& event) {
    topPanel->SelectAllTenses();
}

void MainFrame::OnUnselectAll(wxCommandEvent& event) {
    topPanel->UnselectAll();
}

void MainFrame::OnGitHub(wxCommandEvent& event) {
    wxLaunchDefaultBrowser(wxT("https://github.com/tifrueh/conjugateur"));
}

void MainFrame::OnInspector(wxCommandEvent &event) {
    if (inspector == nullptr) {
        inspector = new InspectorFrame(this, winID::inspector, wxT("Inspecteur"));
    }
    topPanel->SetFocusIgnoringChildren();
    topPanel->Disable();
    this->disableMenuBar();
    inspector->Show();
}

void MainFrame::OnInspectorClose(wxWindowDestroyEvent& event) {
    inspector = nullptr;
    this->enableMenuBar();
    topPanel->Enable();
    topPanel->ResetFocus();
}

void MainFrame::OnVerbBox(wxCommandEvent &event) {
    inspector->updateVerb();
}

wxAboutDialogInfo MainFrame::GetInfo() {
    return info;
}
