// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <string>
#include <iostream>

#include "verb.db.hpp"

#include "conjugateur.hpp"

void conj::displayVerb(verbDB::Verb verb) {
    std::string out;

    out.append("+" + std::string(verb.infinitif.length(), '-') + "+\n");
    out.append("|" + verb.infinitif + "|\n");
    out.append("+" + std::string(verb.infinitif.length(), '-') + "+\n");

    for (int i = verbDB::Tense::present; i <= verbDB::Tense::conditionnel; i++) {
        std::string tense = conj::getTense(i);
        out.append("\n");
        out.append(tense);
        out.append(std::string(tense.length(), '-') + "\n");

        for (int j = verbDB::Person::je; i <= verbDB::Person::elles; j++) {
            out.append(conj::getPerson(j) + " " + conj::getVerbForm(verb, i, j) + "\n");
        }
    }

    std::cout << out;
}

std::string conj::getVerbForm(verbDB::Verb verb, int tense, int person) {

    if (tense == verbDB::Tense::participePresent) {
        return verb.participePresent;
    }

    else if (tense == verbDB::Tense::present && person == verbDB::Person::je) {
        return verb.presentJe;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::tu) {
        return verb.presentTu;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::il) {
        return verb.presentIl;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::elle) {
        return verb.presentElle;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::nous) {
        return verb.presentNous;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::vous) {
        return verb.presentVous;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::ils) {
        return verb.presentIls;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::elles) {
        return verb.presentElles;
    }

    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::je) {
        return verb.imparfaitJe;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::tu) {
        return verb.imparfaitTu;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::il) {
        return verb.imparfaitIl;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::elle) {
        return verb.imparfaitElle;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::nous) {
        return verb.imparfaitNous;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::vous) {
        return verb.imparfaitVous;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::ils) {
        return verb.imparfaitIls;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::elles) {
        return verb.imparfaitElles;
    }

    else if (tense == verbDB::Tense::futur && person == verbDB::Person::je) {
        return verb.futurJe;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::tu) {
        return verb.futurTu;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::il) {
        return verb.futurIl;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::elle) {
        return verb.futurElle;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::nous) {
        return verb.futurNous;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::vous) {
        return verb.futurVous;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::ils) {
        return verb.futurIls;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::elles) {
        return verb.futurElles;
    }

    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::je) {
        return verb.passeComposeJe;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::tu) {
        return verb.passeComposeTu;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::il) {
        return verb.passeComposeIl;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::elle) {
        return verb.passeComposeElle;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::nous) {
        return verb.passeComposeNous;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::vous) {
        return verb.passeComposeVous;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::ils) {
        return verb.passeComposeIls;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::elles) {
        return verb.passeComposeElles;
    }

    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::je) {
        return verb.plusQueParfaitJe;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::tu) {
        return verb.plusQueParfaitTu;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::il) {
        return verb.plusQueParfaitIl;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::elle) {
        return verb.plusQueParfaitElle;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::nous) {
        return verb.plusQueParfaitNous;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::vous) {
        return verb.plusQueParfaitVous;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::ils) {
        return verb.plusQueParfaitIls;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::elles) {
        return verb.plusQueParfaitElles;
    }

    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::je) {
        return verb.subjonctifJe;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::tu) {
        return verb.subjonctifTu;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::il) {
        return verb.subjonctifIl;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::elle) {
        return verb.subjonctifElle;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::nous) {
        return verb.subjonctifNous;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::vous) {
        return verb.subjonctifVous;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::ils) {
        return verb.subjonctifIls;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::elles) {
        return verb.subjonctifElles;
    }

    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::je) {
        return verb.conditionnelJe;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::tu) {
        return verb.conditionnelTu;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::il) {
        return verb.conditionnelIl;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::elle) {
        return verb.conditionnelElle;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::nous) {
        return verb.conditionnelNous;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::vous) {
        return verb.conditionnelVous;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::ils) {
        return verb.conditionnelIls;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::elles) {
        return verb.conditionnelElles;
    }
    else {
        return verb.infinitif;
    }
};

std::string conj::getVerbForm(verbDB::Verb verb, verbDB::Tense tense, verbDB::Person person) {
    int tenseInt = tense;
    int personInt = person;
    getVerbForm(verb, tenseInt, personInt);
}

std::string conj::getTense(verbDB::Tense tense) {
    return verbDB::tenseStrings.at(tense);
}

std::string conj::getTense(int tense) {
    return verbDB::tenseStrings.at(tense);
}

std::string conj::getPerson(verbDB::Person person) {
    return verbDB::personStrings.at(person);
}

std::string conj::getPerson(int person) {
    return verbDB::personStrings.at(person);
}
