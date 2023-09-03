// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <string>
#include <iostream>

#include "verb.db.hpp"

#include "verb.hpp"

void displayVerb(verbDB::Verb verb) {
    std::string out;

    out.append(verb.infinitif + "\n");
    out.append("\n");
    out.append("présent\n");
    out.append("-------\n");
    out.append("je/j' " + verb.presentJe + "\n");

    std::cout << out;
}
