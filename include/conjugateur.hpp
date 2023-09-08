// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <string>

#include "verb.db.hpp"

namespace cjgt {

    struct VerbForm {
        std::wstring infinitif;
        std::wstring tense;
        std::wstring person;
        std::wstring form;
        bool operator==(const VerbForm& verbForm);
    };
    
    void displayVerb(const verbDB::Verb& verb);
    VerbForm getVerbForm(const verbDB::Verb& verb, const verbDB::Tense& tense, const verbDB::Person& person);
    VerbForm getVerbForm(const verbDB::Verb& verb, const int& tense, const int& person);
    std::wstring getTense(const verbDB::Tense& tense);
    std::wstring getTense(const int& tense);
    std::wstring getPerson(const verbDB::Person& person);
    std::wstring getPerson(const int& person);
    std::wstring strip(const std::wstring& string);
};
