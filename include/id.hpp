// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


// This enum contains the all necessary window IDs.
enum winID {
    checkBoxER,
    checkBoxIR,
    checkBoxOIR,
    checkBoxRE,
    checkBoxParticipePresent,
    checkBoxPresent,
    checkBoxImparfait,
    checkBoxFutur,
    checkBoxPasseCompose,
    checkBoxPlusQueParfait,
    checkBoxSubjonctif,
    checkBoxConditionnel,
    okayButton,
    checkButton,
    solutionButton,
    menuQuizSelectVerbs,
    menuQuizSelectTenses,
    menuQuizUnselectAll,
    menuQuizOkay,
    menuQuizCheck,
    menuQuizSolution,
    menuInspectorOpen,
    menuHelpGitHub,
    inspectorVerbBox,
    inspector
};
