// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <map>
#include <string>

#include "conjugateur.hpp"
#include "verb.db.hpp"


// This panel displays all forms of a verb in a specified tense.
class VerbViewPanel : public wxPanel {
    public:
        // Construct a new VerbViewPanel, specifying the tense as int.
        VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb& verb, const int &tense);

        // Construct a new VerbViewPanel, specifying the tense as enum.
        VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb& verb, const verbDB::Tense& tense);

        // Reset the verb of the verb view panel.
        void setVerb(const verbDB::Verb& inputVerb);

    private:
        wxBoxSizer* sizer;

        verbDB::Verb verb;
        int tense;
        std::wstring tenseString;
        std::wstring infinitifString;

        wxStaticText* titleLabel;
        wxStaticText* infinitifLabel;
        std::map<int, wxStaticText*> formLabels;
};
