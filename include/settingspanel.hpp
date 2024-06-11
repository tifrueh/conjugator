// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/config.h>


#include <string>

#include "id.hpp"
#include "conjugator.hpp"


// The only panel of the settings window.
class SettingsPanel : public wxPanel {
    public:
        // Construct a new settings panel.
        explicit SettingsPanel(wxWindow* parent);

    private:
        wxBoxSizer* topsizer;
        wxBoxSizer* buttonsizer;
        wxStaticText* langTitle;
        wxChoice* choiceLang;
        wxStaticText* updateTitle;
        wxCheckBox* checkBoxStartupCheck;
        wxButton* buttonCancel;
        wxButton* buttonSave;
};
