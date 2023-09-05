// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <string>

#include "verb.db.hpp"

namespace conj {
    void displayVerb(verbDB::Verb verb);
    std::string getVerbForm(verbDB::Verb verb, verbDB::Tense tense, verbDB::Person person);
    std::string getVerbForm(verbDB::Verb verb, int tense, int person);
    std::string getTense(verbDB::Tense tense);
    std::string getTense(int tense);
    std::string getPerson(verbDB::Person person);
    std::string getPerson(int person);
};
