// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once


#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "verbview.hpp"

class InspectorPanel : public wxPanel {
    public:
        explicit InspectorPanel(wxWindow* parent);

    private:
        wxArrayString verbs;
        wxListBox* verbBox;
        wxBoxSizer* topsizer;
        VerbView* verbView;
};
