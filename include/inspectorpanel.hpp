// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <map>
#include <string>


#include "conjugator.hpp"
#include "id.hpp"
#include "verbview.hpp"
#include "verb.db.hpp"


// The only panel of the inspector, containing the verbbox and the verbview.
class InspectorPanel : public wxPanel {
    public:
        // Construct a new inspector panel.
        explicit InspectorPanel(wxWindow* parent, const cjgt::Language* language);

        // Set the verb of the verbview to the one selected in the verbbox and set the
        // sizehints of the panel from the topsizer.
        void set_verb_from_box();

    private:
        const cjgt::Language* language;
        wxListBox* verb_box;
        wxBoxSizer* top_sizer;
        VerbView* verb_view;
        std::map<std::wstring, const verbDB::Verb*> verb_map;
};
