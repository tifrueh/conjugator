// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once


#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <map>
#include <string>

#include "verb.db.hpp"


// This panel displays all forms of a verb in a specified tense.
class VerbViewPanel : public wxPanel {
    public:
        VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb& verb, const int &tense);
        VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb& verb, const verbDB::Tense& tense);
        void setVerb(const verbDB::Verb& inputVerb);

    private:
        wxBoxSizer* sizer;

        verbDB::Verb verb;
        int tense;
        std::wstring tenseString;

        wxStaticText* titleLabel;
        std::map<int, wxStaticText*> formLabels;
};
