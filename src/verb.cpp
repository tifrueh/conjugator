// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <string>
#include <iostream>

#include "verb.db.hpp"

#include "verb.hpp"

void displayVerb(verbDB::Verb verb) {
    std::string out;

    out.append("+" + std::string(verb.infinitif.length(), '-') + "+\n");
    out.append("|" + verb.infinitif + "|\n");
    out.append("+" + std::string(verb.infinitif.length(), '-') + "+\n");

    out.append("\n");
    out.append("présent\n");
    out.append("-------\n");
    out.append("je/j' " + verb.presentJe + "\n");
    out.append("tu" + verb.presentTu + "\n");
    out.append("il" + verb.presentIl + "\n");
    out.append("elle" + verb.presentElle + "\n");
    out.append("nous" + verb.presentNous + "\n");
    out.append("vous" + verb.presentVous + "\n");
    out.append("ils" + verb.presentIls + "\n");
    out.append("elles" + verb.presentElles + "\n");

    std::cout << out;
}
