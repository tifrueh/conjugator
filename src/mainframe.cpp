// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "mainframe.hpp"


MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {

    SetIcon(wxICON(conjugator));

    info.SetName(wxT("Conjugator"));
    info.SetCopyright(wxT("Copyright © 2023-2024 Timo Früh"));
    
    // Set version in the app info to TAG_STR only if not on macOS.
    #ifndef __WXOSX__
        info.SetVersion(TAG_STR);
    #endif

    // Add a bunch more info to the app, but only on GTK, as it is the only
    // platform to support such a detailed "About" window.
    #ifdef __WXGTK__
        info.SetIcon(wxICON(conjugator));
        info.SetDescription(_("Verb conjugation trainer"));
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

    menuBar->Append(menuEdit, _("Edit"));
    menuBar->Append(menuQuiz, _("Quiz"));
    menuBar->Append(menuHelp, _("Help"));

    menuEdit->Append(wxID_CUT);
    menuEdit->Append(wxID_COPY);
    menuEdit->Append(wxID_PASTE);
    menuEdit->AppendSeparator();
    menuEdit->Append(wxID_SELECTALL);

    menuQuiz->Append(winID::menuQuizSelectVerbs, _("Select all categories\tCtrl-1"));
    menuQuiz->Append(winID::menuQuizSelectTenses, _("Select all tenses\tCtrl-2"));
    menuQuiz->Append(winID::menuQuizUnselectAll, _("Unselect all\tCtrl-0"));
    menuQuiz->AppendSeparator();
    menuQuiz->Append(winID::menuQuizOkay, _("Next\tCtrl-Enter"));
    menuQuiz->Append(winID::menuQuizCheck, _("Check\tCtrl-Shift-Enter"));
    menuQuiz->Append(winID::menuQuizSolution, _("Solutions\tCtrl-S"));
    menuQuiz->AppendSeparator();
    menuQuiz->Append(winID::menuInspectorOpen, _("Open inspector\tCtrl-I"));

    menuHelp->Append(wxID_ABOUT, _("About Conjugator"));
    menuHelp->AppendSeparator();
    menuHelp->Append(winID::menuHelpGitHub, wxT("GitHub"));

    this->SetMenuBar(menuBar);

    this->language = &cjgt::french;

    // Create a new top panel in which all windows will reside (so that
    // keyboard focus is handled automatically).
    topPanel = new TopPanel(this, this->language);
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
    Bind(wxEVT_MENU, &MainFrame::OnUpdateChecker, this, winID::menuHelpUpdateChecker);
    Bind(wxEVT_MENU, &MainFrame::OnInspector, this, winID::menuInspectorOpen);
    Bind(wxEVT_LISTBOX, &MainFrame::OnVerbBox, this, winID::inspectorVerbBox);
    Bind(wxEVT_DESTROY, &MainFrame::OnInspectorClose, this, winID::inspector);
    Bind(wxEVT_WEBREQUEST_STATE, &MainFrame::HandleUpdateChecker, this, winID::requestUpdateChecker);

    wxStandardPaths::Get().SetFileLayout(wxStandardPaths::FileLayout_XDG);
    config = new wxConfig("conjugator", "ch.tifrueh", CONFIG_FILENAME);

    bool checkForUpdateOnStartup = true;
    bool checkForUpdateOnStartupDefined = config->Read("checkForUpdateOnStartup", &checkForUpdateOnStartup);

    bool disableUpdateChecker = false;
    bool disableUpdateCheckerDefined = config->Read("disableUpdateChecker", &disableUpdateChecker);

    if (checkForUpdateOnStartup && ! disableUpdateChecker) {
        // Check for updates and set failSilently to true
        this->checkForUpdates(true);
    }

    if (! disableUpdateChecker) {
        menuHelp->Append(winID::menuHelpUpdateChecker, _("Check for updates"));
    }

    if (! checkForUpdateOnStartupDefined) {
        config->Write("checkForUpdateOnStartup", checkForUpdateOnStartup);
    }

    if (! disableUpdateCheckerDefined) {
        config->Write("disableUpdateChecker", disableUpdateChecker);
    }

    delete config;

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
    wxLaunchDefaultBrowser(wxT("https://github.com/tifrueh/conjugateur/wiki/"));
}

void MainFrame::OnInspector(wxCommandEvent &event) {
    if (inspector == nullptr) {
        inspector = new InspectorFrame(this, winID::inspector, wxT("Inspector"), this->language);
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

void MainFrame::checkForUpdates(const bool& failSilently) {
    updateChecker.setFailSilently(failSilently);
    updateChecker.start(this, "https://api.github.com/repos/tifrueh/conjugateur/releases/latest", winID::requestUpdateChecker);
}

void MainFrame::OnUpdateChecker(wxCommandEvent& event) {
    this->checkForUpdates();
}

void MainFrame::HandleUpdateChecker(wxWebRequestEvent& event) {
    updateChecker.showResult(event);
}

wxAboutDialogInfo MainFrame::GetInfo() {
    return info;
}
