// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <string>
#include <vector>

#include "verb.db.hpp"

std::array<std::string, 9> verbDB::tenseStrings {
    "infinitif",
    "participe présent",
    "présent",
    "imparfait",
    "futur",
    "passé composé",
    "plus-que-parfait",
    "subjonctif",
    "conditionnel"
};

std::array<std::string, 8> verbDB::personStrings {
    "je/j'",
    "tu",
    "il",
    "elle",
    "nous",
    "vous",
    "ils",
    "elles"
};

verbDB::Verb verbDB::acheter = {
    "acheter",
    "achetant",

    "achète",
    "achètes",
    "achète",
    "achète",
    "achetons",
    "achetez",
    "achètent",
    "achètent",

    "achetais",
    "achetais",
    "achetait",
    "achetait",
    "achetions",
    "achetiez",
    "achetaient",
    "achetaient",

    "achèterai",
    "achèteras",
    "achètera",
    "achètera",
    "achèterons",
    "achèterez",
    "achèteront",
    "achèteront",

    "ai acheté",
    "as acheté",
    "a acheté",
    "a acheté",
    "avons acheté",
    "avez acheté",
    "ont acheté",
    "ont acheté",

    "avais acheté",
    "avais acheté",
    "avait acheté",
    "avait acheté",
    "avions acheté",
    "aviez acheté",
    "avaient acheté",
    "avaient acheté",

    "achète",
    "achètes",
    "achète",
    "achète",
    "achetions",
    "achetiez",
    "achètent",
    "achètent",

    "achèterais",
    "achèterais",
    "achèterait",
    "achèterait",
    "achèterions",
    "achèteriez",
    "achèteraient",
    "achèteraient"
};

std::vector<verbDB::Verb*> verbDB::verbsER = {
    &verbDB::acheter,
};
