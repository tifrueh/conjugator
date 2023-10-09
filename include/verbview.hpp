// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once


#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <map>
#include <array>
#include <string>

#include "verb.db.hpp"


class VerbView : public wxScrolledWindow {
    public:
        VerbView(wxWindow* parent, wxWindowID id, const verbDB::Verb& verb);
        void setVerb(const verbDB::Verb& inputVerb);

    private:
        wxBoxSizer* sizer;

        verbDB::Verb verb;

        std::map<std::array<int, 2>, wxStaticText*> formLabels;
        std::map<int, wxStaticText*> titleLabels;
};
