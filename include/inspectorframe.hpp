// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include "id.hpp"
#include "inspectorpanel.hpp"
#include "conjugator.hpp"
#include "verb.db.hpp"

#include "inspecteur.xpm"


// The most top-level frame of the inspector window.
class InspectorFrame : public wxFrame {
    public:
        // Construct a new inspector frame.
        InspectorFrame(wxWindow* parent, const wxWindowID& winID, const wxString& title, const cjgt::Language* language);
        
        // Set the verb of the verbview to the one selected in the verbbox and set the
        // sizehints of the frame from the topsizer.
        void updateVerb();

    private:
        wxBoxSizer* topSizer;
        InspectorPanel* inspectorPanel;
};
