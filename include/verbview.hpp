// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once


#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/choicebk.h>

#include <map>
#include <string>

#include <wx/vscroll.h>

#include "verbviewpanel.hpp"

#include "verb.db.hpp"


// This panel contains a wxChoicebook with one additional panel for each tense.
class VerbView : public wxPanel {
    public:
        VerbView(wxWindow* parent, wxWindowID id, const verbDB::Verb& verb);
        void setVerb(const verbDB::Verb& inputVerb);

    private:
        wxChoicebook* tensebook;
        std::map<int, VerbViewPanel*> pages;
        
        wxBoxSizer* sizer;

        verbDB::Verb verb;
};
