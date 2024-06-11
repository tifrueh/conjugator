// Conjugator: Verb conjugation trainer
// Copyright (C) 2023-2024 Timo Früh

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/aboutdlg.h>
#include <wx/translation.h>
#include <wx/uilocale.h>
#include <wx/log.h>
#include <wx/config.h>


#include "mainframe.hpp"
#include "verb.db.hpp"


// The main app class with a locale and an overridden OnInit().
class Conjugator : public wxApp {
    public:
        bool OnInit() override;
        wxTranslations* translations;
};

wxIMPLEMENT_APP(Conjugator);

// Set the locale, initialise verbDB, set the app name and initialise the
// main top-level frame.
bool Conjugator::OnInit() {

    wxUILocale::UseDefault();

    translations = new wxTranslations();

    wxString language = wxUILocale::GetLanguageCanonicalName(wxUILocale::GetSystemLanguage());

    translations->SetLanguage(language);

    translations->AddCatalog(wxT("wxstd"));
    translations->AddCatalog(wxT("conjugator"));

    wxTranslations::Set(translations);

    wxStandardPaths::Get().SetFileLayout(wxStandardPaths::FileLayout_XDG);
    wxConfig* config = new wxConfig("conjugator", "ch.tifrueh", CONFIG_FILENAME);

    wxConfigBase::Set(config);

    this->SetAppDisplayName(wxT("Conjugator"));

    auto window = new MainFrame(wxT("Conjugator"));
    window->Center();

    window->Show();

    return true;
}
