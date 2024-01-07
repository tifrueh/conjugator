// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once


#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <map>
#include <array>
#include <string>

#include <wx/vscroll.h>

#include "verbviewpanel.hpp"

#include "verb.db.hpp"


class VerbView : public wxScrolled<wxWindow> {
    public:
        VerbView(wxWindow* parent, wxWindowID id, const verbDB::Verb& verb);
        void setVerb(const verbDB::Verb& inputVerb);

    private:
        VerbViewPanel* verbViewPanel;

        verbDB::Verb verb;
};
