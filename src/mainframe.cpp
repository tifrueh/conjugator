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

    info.SetName(wxT("Conjugateur"));
    info.SetVersion(wxT("dev"));
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
    menuQuiz->AppendSeparator();
    menuQuiz->Append(winID::menuQuizOkay, wxT("Gérer\tCtrl-Enter"));
    menuQuiz->Append(winID::menuQuizCheck, wxT("Contrôler\tCtrl-Shift-Enter"));
    menuQuiz->Append(winID::menuQuizSolution, wxT("Solutions\tCtrl-S"));

    menuHelp->Append(wxID_ABOUT);

    this->SetMenuBar(menuBar);

    topPanel = new TopPanel(this);

    topPanelSizer = new wxBoxSizer(wxVERTICAL);

    topPanelSizer->Add(
        topPanel,
        1,
        wxEXPAND | wxALL,
        20
    );

    Bind(wxEVT_BUTTON, &MainFrame::OnOkay, this, winID::okayButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnCheck, this, winID::checkButton);
    Bind(wxEVT_BUTTON, &MainFrame::OnSolution, this, winID::solutionButton);
    Bind(wxEVT_MENU, &MainFrame::OnOkay, this, winID::menuQuizOkay);
    Bind(wxEVT_MENU, &MainFrame::OnCheck, this, winID::menuQuizCheck);
    Bind(wxEVT_MENU, &MainFrame::OnSolution, this, winID::menuQuizSolution);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

    SetSizerAndFit(topPanelSizer);
}

void MainFrame::OnOkay(wxCommandEvent& event) {
   topPanel->GenerateQuiz(); 
}

void MainFrame::OnCheck(wxCommandEvent& event) {
    topPanel->Check();
}

void MainFrame::OnSolution(wxCommandEvent& event) {
    topPanel->ShowSolutions();
}

void MainFrame::OnAbout(wxCommandEvent& event) {
   wxAboutBox(GetInfo(), this);
}

wxAboutDialogInfo MainFrame::GetInfo() {
    return info;
}
