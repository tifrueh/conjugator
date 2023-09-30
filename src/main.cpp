// Conjugateur: French verb conjugation trainer
// Copyright (C) 2023 Timo Früh

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
#include <wx/intl.h>

#include "verb.db.hpp"
#include "mainframe.hpp"

class Conjugateur : public wxApp {
    public:
        virtual bool OnInit();
        wxLocale* locale;
};

wxIMPLEMENT_APP(Conjugateur);

bool Conjugateur::OnInit() {

    locale = new wxLocale();

    locale->Init(wxLANGUAGE_FRENCH);

    locale->AddCatalog(wxT("wxstd"));

    verbDB::initTypeVectors();

    this->SetAppDisplayName(wxT("Conjugateur"));
    
    MainFrame* window = new MainFrame(wxT("Conjugateur"));
    window->Center();

    window->Show();

    return true;
}
