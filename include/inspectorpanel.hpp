// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once


#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "verb.db.hpp"

#include "verbview.hpp"

// The only panel of the inspector, containing the verbbox and the verbview.
class InspectorPanel : public wxPanel {
    public:
        explicit InspectorPanel(wxWindow* parent);
        void setVerbFromBox();

    private:
        wxArrayString verbs;
        wxListBox* verbBox;
        wxBoxSizer* topsizer;
        VerbView* verbView;
};
