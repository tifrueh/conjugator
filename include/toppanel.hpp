// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include <vector>

#include "conjugateur.hpp"
#include "quizitem.hpp"

class TopPanel : public wxPanel {
    public:
        TopPanel(wxWindow* parent);
        std::vector<conj::VerbForm> GetVerbForms(const int& count);
        void Reset();

    private:
        wxBoxSizer* topsizer = nullptr;
        wxStaticBoxSizer* formSelectionSizer = nullptr;
        wxStaticBoxSizer* quizSizer = nullptr;
        wxStaticText* verbTypeTitle = nullptr;
        wxCheckBox* checkBoxER = nullptr;
        wxCheckBox* checkBoxIR = nullptr;
        wxCheckBox* checkBoxOIR = nullptr;
        wxCheckBox* checkBoxRE = nullptr;
        wxStaticText* tenseTitle = nullptr;
        wxCheckBox* checkBoxParticipePresent = nullptr;
        wxCheckBox* checkBoxPresent = nullptr;
        wxCheckBox* checkBoxImparfait = nullptr;
        wxCheckBox* checkBoxFutur = nullptr;
        wxCheckBox* checkBoxPasseCompose = nullptr;
        wxCheckBox* checkBoxPlusQueParfait = nullptr;
        wxCheckBox* checkBoxSubjonctif = nullptr;
        wxCheckBox* checkBoxConditionnel = nullptr;
        wxBoxSizer* buttonSizer = nullptr;
        wxButton* okayButton = nullptr;
        wxButton* resetButton = nullptr;
        QuizItem* item1 = nullptr;
};
