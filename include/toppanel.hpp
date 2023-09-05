// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class TopPanel : public wxPanel {
    public:
        TopPanel(wxWindow* parent);

    private:
        wxBoxSizer* topsizer = nullptr;
        wxStaticText* verbTypeTitle = nullptr;
        wxArrayString verbTypeChoices;
        wxCheckListBox* verbTypeBox = nullptr;        
};
