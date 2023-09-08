// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <string>

#include "verb.db.hpp"

namespace conj {

    struct VerbForm {
        std::string infinitif;
        std::string tense;
        std::string person;
        std::string form;
        bool operator==(const VerbForm& verbForm);
    };
    
    void displayVerb(const verbDB::Verb& verb);
    VerbForm getVerbForm(const verbDB::Verb& verb, const verbDB::Tense& tense, const verbDB::Person& person);
    VerbForm getVerbForm(const verbDB::Verb& verb, const int& tense, const int& person);
    std::string getTense(const verbDB::Tense& tense);
    std::string getTense(const int& tense);
    std::string getPerson(const verbDB::Person& person);
    std::string getPerson(const int& person);
    std::string strip(const std::string& string);
};
