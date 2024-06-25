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

        void write_config();

    private:
        wxBoxSizer* top_sizer;
        wxBoxSizer* button_sizer;
        wxStaticText* title_lang;
        wxChoice* choice_lang;
        wxStaticText* title_update;
        wxCheckBox* do_startup_check;
        wxButton* button_cancel;
        wxButton* button_save;
};
