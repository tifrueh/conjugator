// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once


#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/srchctrl.h>

#include "inspectorpanel.hpp"


// The most top-level frame of the inspector window.
class InspectorFrame : public wxFrame {
    public:
        InspectorFrame(wxWindow* parent, const wxWindowID& winID, const wxString& title);
        void updateVerb();

    private:
        wxBoxSizer* topSizer;
        InspectorPanel* inspectorPanel;
};
