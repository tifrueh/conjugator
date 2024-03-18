// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/activityindicator.h>


#include "id.hpp"

// The most top-level frame of the checker window.
class CheckerPanel : public wxPanel {
    public:
        // Construct a new checker frame.
        CheckerPanel(wxWindow* parent);

    private:
        wxBoxSizer* topSizer;
        wxBoxSizer* statusSizer;
        wxBoxSizer* buttonSizer;

        wxStaticText* titleLabel;
        wxActivityIndicator* activityIndicator;
        wxStaticText* activityLabel;

        wxButton* cancelButton;
        wxButton* checkAgainButton;
        wxButton* downloadButton;
};
