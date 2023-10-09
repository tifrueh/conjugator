// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
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
    info.SetVersion(wxT("1.0.0-dev"));
    info.SetCopyright(wxT(
        "Copyright (C) 2023 Timo Früh\n"
        "This program is free and open source software, licensed under the GNU General Public License 3.0. "
        "For further information, see <https:://www.gnu.org/licenses>."
    ));

    menuBar = new wxMenuBar();

    menuQuiz = new wxMenu();
    menuHelp = new wxMenu();

    menuBar->Append(menuQuiz, wxT("Quiz"));
    menuBar->Append(menuHelp, wxT("Aide"));

    menuQuiz->Append(winID::menuQuizSelectVerbs, wxT("Sélectionner tous les verbes\tCtrl-1"));
    menuQuiz->Append(winID::menuQuizSelectTenses, wxT("Sélectionner tous les temps\tCtrl-2"));
    menuQuiz->Append(winID::menuQuizUnselectAll, wxT("Désélectionner tout\tCtrl-0"));
    menuQuiz->AppendSeparator();
    menuQuiz->Append(winID::menuQuizOkay, wxT("Gérer\tCtrl-Enter"));
    menuQuiz->Append(winID::menuQuizCheck, wxT("Contrôler\tCtrl-Shift-Enter"));
    menuQuiz->Append(winID::menuQuizSolution, wxT("Solutions\tCtrl-S"));

    menuHelp->Append(wxID_ABOUT, wxT("À propos Conjugateur"));
    menuHelp->Append(winID::menuHelpInspecteur, wxT("Inspecteur"));
    menuHelp->AppendSeparator();
    menuHelp->Append(winID::menuHelpGitHub, wxT("GitHub"));

    this->SetMenuBar(menuBar);

    topPanel = new TopPanel(this);

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
    Bind(wxEVT_MENU, &MainFrame::OnInspector, this, winID::menuHelpInspecteur);
    Bind(wxEVT_LISTBOX, &MainFrame::OnVerbBox, this, winID::inspectorVerbBox);

    SetSizerAndFit(topPanelSizer);
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
    inspector = new InspectorFrame(this, wxID_ANY, wxT("Inspecteur"));
    inspector->Show();
}

void MainFrame::OnVerbBox(wxCommandEvent &event) {
    inspector->updateVerb();
}

wxAboutDialogInfo MainFrame::GetInfo() {
    return info;
}
