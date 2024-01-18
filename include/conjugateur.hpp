// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <string>

#include "verb.db.hpp"

// This namespace contains all functionality related to verb forms.
namespace cjgt {

    // A structure containing a form of a verb, including its corresponding
    // infinitif, tense and person.
    struct VerbForm {
        std::wstring infinitif;
        std::wstring tense;
        std::wstring person;
        std::wstring form;
        bool operator==(const VerbForm& verbForm) const;
    };

    const verbDB::Verb* getVerb(const std::wstring& infinitif);
    VerbForm getVerbForm(const verbDB::Verb& verb, const verbDB::Tense& tense, const verbDB::Person& person);
    VerbForm getVerbForm(const verbDB::Verb& verb, const int& tense, const int& person);
    std::wstring getTense(const verbDB::Tense& tense);
    std::wstring getTense(const int& tense);
    std::wstring getPerson(const verbDB::Person& person);
    std::wstring getPerson(const int& person);
    std::wstring getFormString(const VerbForm& verbForm);
    std::wstring strip(const std::wstring& string);
}
