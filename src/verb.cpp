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
    out.append("tu " + verb.presentTu + "\n");
    out.append("il " + verb.presentIl + "\n");
    out.append("elle " + verb.presentElle + "\n");
    out.append("nous " + verb.presentNous + "\n");
    out.append("vous " + verb.presentVous + "\n");
    out.append("ils " + verb.presentIls + "\n");
    out.append("elles " + verb.presentElles + "\n");

    out.append("\n");
    out.append("imparfait\n");
    out.append("---------\n");
    out.append("je/j' " + verb.imparfaitJe + "\n");
    out.append("tu " + verb.imparfaitTu + "\n");
    out.append("il " + verb.imparfaitIl + "\n");
    out.append("elle " + verb.imparfaitElle + "\n");
    out.append("nous " + verb.imparfaitNous + "\n");
    out.append("vous " + verb.imparfaitVous + "\n");
    out.append("ils " + verb.imparfaitIls + "\n");
    out.append("elles " + verb.imparfaitElles + "\n");

    out.append("\n");
    out.append("futur\n");
    out.append("-----\n");
    out.append("je/j' " + verb.futurJe + "\n");
    out.append("tu " + verb.futurTu + "\n");
    out.append("il " + verb.futurIl + "\n");
    out.append("elle " + verb.futurElle + "\n");
    out.append("nous " + verb.futurNous + "\n");
    out.append("vous " + verb.futurVous + "\n");
    out.append("ils " + verb.futurIls + "\n");
    out.append("elles " + verb.futurElles + "\n");

    out.append("\n");
    out.append("passé composé\n");
    out.append("-------------\n");
    out.append("je/j' " + verb.passeComposeJe + "\n");
    out.append("tu " + verb.passeComposeTu + "\n");
    out.append("il " + verb.passeComposeIl + "\n");
    out.append("elle " + verb.passeComposeElle + "\n");
    out.append("nous " + verb.passeComposeNous + "\n");
    out.append("vous " + verb.passeComposeVous + "\n");
    out.append("ils " + verb.passeComposeIls + "\n");
    out.append("elles " + verb.passeComposeElles + "\n");

    out.append("\n");
    out.append("plus-que-parfait\n");
    out.append("----------------\n");
    out.append("je/j' " + verb.plusQueParfaitJe + "\n");
    out.append("tu " + verb.plusQueParfaitTu + "\n");
    out.append("il " + verb.plusQueParfaitIl + "\n");
    out.append("elle " + verb.plusQueParfaitElle + "\n");
    out.append("nous " + verb.plusQueParfaitNous + "\n");
    out.append("vous " + verb.plusQueParfaitVous + "\n");
    out.append("ils " + verb.plusQueParfaitIls + "\n");
    out.append("elles " + verb.plusQueParfaitElles + "\n");

    out.append("\n");
    out.append("subjonctif\n");
    out.append("----------\n");
    out.append("je/j' " + verb.subjonctifJe + "\n");
    out.append("tu " + verb.subjonctifTu + "\n");
    out.append("il " + verb.subjonctifIl + "\n");
    out.append("elle " + verb.subjonctifElle + "\n");
    out.append("nous " + verb.subjonctifNous + "\n");
    out.append("vous " + verb.subjonctifVous + "\n");
    out.append("ils " + verb.subjonctifIls + "\n");
    out.append("elles " + verb.subjonctifElles + "\n");

    out.append("\n");
    out.append("conditionnel\n");
    out.append("------------\n");
    out.append("je/j' " + verb.conditionnelJe + "\n");
    out.append("tu " + verb.conditionnelTu + "\n");
    out.append("il " + verb.conditionnelIl + "\n");
    out.append("elle " + verb.conditionnelElle + "\n");
    out.append("nous " + verb.conditionnelNous + "\n");
    out.append("vous " + verb.conditionnelVous + "\n");
    out.append("ils " + verb.conditionnelIls + "\n");
    out.append("elles " + verb.conditionnelElles + "\n");


    std::cout << out;
}
