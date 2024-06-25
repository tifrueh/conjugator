// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "mainframe.hpp"


MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {

    SetIcon(wxICON(conjugator));

    this->info.SetName(wxT("Conjugator"));
    this->info.SetCopyright(wxT("Copyright © 2023-2024 Timo Früh"));
    
    // Set version in the app info to TAG_STR only if not on macOS.
    #ifndef __WXOSX__
        this->info.SetVersion(TAG_STR);
    #endif

    // Add a bunch more info to the app, but only on GTK, as it is the only
    // platform to support such a detailed "About" window.
    #ifdef __WXGTK__
        this->info.SetIcon(wxICON(conjugator));
        this->info.SetDescription(_("Verb conjugation trainer"));
        this->info.SetWebSite(wxT("https://github.com/tifrueh/conjugator"), wxT("GitHub"));
        this->info.AddDeveloper(wxT("Timo Früh"));

        this->info.SetLicense(wxT("This program is free software: you can redistribute it and/or modify\n"
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


        this->info.AddTranslator(wxT("Stephane Junique"));
        this->info.AddTranslator(wxT("Nicolas Velin"));
        this->info.AddTranslator(wxT("Gérard Durand"));
    #endif

    // Define a menu bar and add all menu items.
    this->menu_bar = new wxMenuBar();

    this->menu_edit = new wxMenu();
    this->menu_quiz = new wxMenu();
    this->menu_help = new wxMenu();

    this->menu_bar->Append(this->menu_edit, _("Edit"));
    this->menu_bar->Append(this->menu_quiz, _("Quiz"));
    this->menu_bar->Append(this->menu_help, _("Help"));

    this->menu_edit->Append(wxID_CUT);
    this->menu_edit->Append(wxID_COPY);
    this->menu_edit->Append(wxID_PASTE);
    this->menu_edit->AppendSeparator();
    this->menu_edit->Append(wxID_SELECTALL);

    this->menu_quiz->Append(winID::menu_select_categories, _("Select all categories\tCtrl-1"));
    this->menu_quiz->Append(winID::menu_select_tenses, _("Select all tenses\tCtrl-2"));
    this->menu_quiz->Append(winID::menu_unselect_all, _("Unselect all\tCtrl-0"));
    this->menu_quiz->AppendSeparator();
    this->menu_quiz->Append(winID::menu_next, _("Next\tCtrl-Enter"));
    this->menu_quiz->Append(winID::menu_check, _("Check\tCtrl-Shift-Enter"));
    this->menu_quiz->Append(winID::menu_solutions, _("Solutions\tCtrl-S"));
    this->menu_quiz->AppendSeparator();
    this->menu_quiz->Append(winID::menu_inspector, _("Open inspector\tCtrl-I"));
    this->menu_quiz->AppendSeparator();
    this->menu_quiz->Append(wxID_PREFERENCES, _("Settings…\tCtrl-,"));

    this->menu_help->Append(wxID_ABOUT, _("About Conjugator"));
    this->menu_help->AppendSeparator();
    this->menu_help->Append(winID::menu_github, wxT("GitHub"));

    this->SetMenuBar(this->menu_bar);

    // Read config.
    this->load_config();

    // Create a new top panel in which all windows will reside (so that
    // keyboard focus is handled automatically).
    this->top_panel = new TopPanel(this, this->language);
    this->top_panel->reset_focus();

    // Create a new wxBoxSizer and add the top panel to it.
    this->top_panel_sizer = new wxBoxSizer(wxVERTICAL);

    this->top_panel_sizer->Add(
        this->top_panel,
        1,
        wxEXPAND | wxALL,
        0
    );

    // Bind events to their corresponding method.
    Bind(wxEVT_BUTTON, &MainFrame::OnNext, this, winID::button_next);
    Bind(wxEVT_BUTTON, &MainFrame::OnCheck, this, winID::button_check);
    Bind(wxEVT_BUTTON, &MainFrame::OnSolution, this, winID::button_solutions);
    Bind(wxEVT_BUTTON, &MainFrame::OnSettingsSave, this, winID::settings_save);
    Bind(wxEVT_BUTTON, &MainFrame::OnSettingsCancel, this, winID::settings_cancel);
    Bind(wxEVT_MENU, &MainFrame::OnNext, this, winID::menu_next);
    Bind(wxEVT_MENU, &MainFrame::OnCheck, this, winID::menu_check);
    Bind(wxEVT_MENU, &MainFrame::OnSolution, this, winID::menu_solutions);
    Bind(wxEVT_MENU, &MainFrame::OnSelectCategories, this, winID::menu_select_categories);
    Bind(wxEVT_MENU, &MainFrame::OnSelectTenses, this, winID::menu_select_tenses);
    Bind(wxEVT_MENU, &MainFrame::OnUnselectAll, this, winID::menu_unselect_all);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnGitHub, this, winID::menu_github);
    Bind(wxEVT_MENU, &MainFrame::OnUpdateChecker, this, winID::menu_update_checker);
    Bind(wxEVT_MENU, &MainFrame::OnInspector, this, winID::menu_inspector);
    Bind(wxEVT_MENU, &MainFrame::OnSettings, this, wxID_PREFERENCES);
    Bind(wxEVT_LISTBOX, &MainFrame::OnVerbBox, this, winID::inspector_verb_box);
    Bind(wxEVT_DESTROY, &MainFrame::OnInspectorClose, this, winID::inspector);
    Bind(wxEVT_DESTROY, &MainFrame::OnSettingsClose, this, winID::settings);
    Bind(wxEVT_WEBREQUEST_STATE, &MainFrame::HandleUpdateChecker, this, winID::request_update_checker);

    SetSizerAndFit(this->top_panel_sizer);
}

void MainFrame::enable_menu_bar() {
    for (size_t menu = 0; menu < this->menu_bar->GetMenuCount(); menu++) {
        this->menu_bar->EnableTop(menu, true);
    }
}

void MainFrame::disable_menu_bar() {
    for (size_t menu = 0; menu < this->menu_bar->GetMenuCount(); menu++) {
        this->menu_bar->EnableTop(menu, false);
    }
}

void MainFrame::compute_new_size() {
    this->top_panel_sizer->Layout();

    if (this->GetClientSize().GetX() < this->top_panel_sizer->GetMinSize().GetX()) {
        this->top_panel_sizer->SetSizeHints(this);
    } else {
        this->SetMinClientSize(this->top_panel_sizer->ComputeFittingClientSize(this));
    }
}

void MainFrame::OnNext(wxCommandEvent& event) {
    this->top_panel->generate_quiz();
    this->top_panel->reset_focus();

    compute_new_size();
}

void MainFrame::OnCheck(wxCommandEvent& event) {
    this->top_panel->check();
}

void MainFrame::OnSolution(wxCommandEvent& event) {
    this->top_panel->show_solutions();

    compute_new_size();
}

void MainFrame::OnAbout(wxCommandEvent& event) {
   wxAboutBox(get_info(), this);
}

void MainFrame::OnSelectCategories(wxCommandEvent& event) {
    this->top_panel->select_all_categories();
}

void MainFrame::OnSelectTenses(wxCommandEvent& event) {
    this->top_panel->select_all_tenses();
}

void MainFrame::OnUnselectAll(wxCommandEvent& event) {
    this->top_panel->unselect_all();
}

void MainFrame::OnGitHub(wxCommandEvent& event) {
    wxLaunchDefaultBrowser(wxT("https://github.com/tifrueh/conjugator/wiki/"));
}

void MainFrame::OnInspector(wxCommandEvent &event) {
    if (this->inspector == nullptr) {
        this->inspector = new InspectorFrame(this, winID::inspector, wxT("Inspector"), this->language);
    }
    this->top_panel->SetFocusIgnoringChildren();
    this->top_panel->Disable();
    this->disable_menu_bar();
    this->inspector->Show();
}

void MainFrame::OnInspectorClose(wxWindowDestroyEvent& event) {
    this->inspector = nullptr;
    this->enable_menu_bar();
    this->top_panel->Enable();
    this->top_panel->reset_focus();
}

void MainFrame::OnVerbBox(wxCommandEvent &event) {
    this->inspector->update_verb();
}

void MainFrame::OnSettings(wxCommandEvent &event) {
    if (this->settings == nullptr) {
        this->settings = new SettingsFrame(this, winID::settings, _("Settings"));
    };
    this->settings->Show();
}

void MainFrame::OnSettingsClose(wxWindowDestroyEvent& event) {
    this->settings = nullptr;
}

void MainFrame::OnSettingsSave(wxCommandEvent& event) {
    this->settings->write_config();
    this->settings->Destroy();
    this->reload_config();
    this->top_panel->set_language(language);
    this->compute_new_size();
}

void MainFrame::OnSettingsCancel(wxCommandEvent& event) {
    this->settings->Destroy();
}

void MainFrame::checkForUpdates(const bool& failSilently) {
    this->update_checker.setFailSilently(failSilently);
    this->update_checker.start(this, "https://api.github.com/repos/tifrueh/conjugator/releases/latest", winID::request_update_checker);
}

void MainFrame::OnUpdateChecker(wxCommandEvent& event) {
    this->checkForUpdates();
}

void MainFrame::HandleUpdateChecker(wxWebRequestEvent& event) {
    this->update_checker.showResult(event);
}

wxAboutDialogInfo MainFrame::get_info() {
    return info;
}

void MainFrame::load_config() {
    bool checkForUpdateOnStartup = true;
    bool checkForUpdateOnStartupDefined = wxConfigBase::Get()->Read("checkForUpdateOnStartup", &checkForUpdateOnStartup);

    bool disableUpdateChecker = false;
    bool disableUpdateCheckerDefined = wxConfigBase::Get()->Read("disableUpdateChecker", &disableUpdateChecker);

    if (checkForUpdateOnStartup && ! disableUpdateChecker) {
        // Check for updates and set failSilently to true
        this->checkForUpdates(true);
    }

    if (! disableUpdateChecker) {
        this->menu_help->Append(winID::menu_update_checker, _("Check for updates"));
    }

    // Initialise config if some keys are not defined yet.
    if (! checkForUpdateOnStartupDefined) {
        wxConfigBase::Get()->Write("checkForUpdateOnStartup", checkForUpdateOnStartup);
    }

    if (! disableUpdateCheckerDefined) {
        wxConfigBase::Get()->Write("disableUpdateChecker", disableUpdateChecker);
    }

    // Load the reloadable part of the config.
    this->reload_config();

}

void MainFrame::reload_config() {
    size_t quizLanguage = cjgt::LanguageID::French;
    bool quizLanguageDefined = wxConfigBase::Get()->Read("quizLanguage", &quizLanguage);

    if (! quizLanguageDefined) {
        wxConfigBase::Get()->Write("quizLanguage", quizLanguage);
    }

    const cjgt::Language* config_language = cjgt::get_language((cjgt::LanguageID) quizLanguage);

    if (config_language == nullptr) {
        this->language = &cjgt::french;
    } else {
        this->language = config_language;
    }
}
