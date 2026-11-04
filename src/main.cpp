// Conjugateur: French verb conjugation trainer
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
#include <wx/uilocale.h>
#include <wx/translation.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/aboutdlg.h>
#include <wx/intl.h>


#include "mainframe.hpp"
#include "verb.db.hpp"


// The main app class with a locale and an overridden OnInit().
class Conjugateur : public wxApp {
    public:
        bool OnInit() override;
        wxLocale* locale;
};

wxIMPLEMENT_APP(Conjugateur);

// Set the locale, initialise verbDB, set the app name and initialise the
// main top-level frame.
bool Conjugateur::OnInit() {

    wxUILocale::UseDefault();

    wxTranslations *translations = new wxTranslations();
    translations->SetLanguage(wxLANGUAGE_FRENCH);
    translations->AddStdCatalog();

    wxTranslations::Set(translations);

    verbDB::initTypeVectors();

    this->SetAppDisplayName(wxT("Conjugateur"));
    
    auto window = new MainFrame(wxT("Conjugateur"));
    window->Center();

    window->Show();

    return true;
}
