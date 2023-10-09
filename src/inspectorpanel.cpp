// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "verb.db.hpp"
#include "id.hpp"

#include "inspectorpanel.hpp"


InspectorPanel::InspectorPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    topsizer = new wxBoxSizer(wxHORIZONTAL);

    verbs = wxArrayString();

    for (const verbDB::Verb* verb : verbDB::allVerbs) {
        verbs.Add(wxString(verb->infinitif));
    }

    verbBox = new wxListBox(this, inspectorVerbBox, wxDefaultPosition, wxDefaultSize, verbs, wxLB_SINGLE);
    verbBox->SetSelection(0, true);

    topsizer->Add(verbBox, 0, wxEXPAND, 0);

    this->SetSizerAndFit(topsizer);
}