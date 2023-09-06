// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <string>
#include <iostream>

#include "verb.db.hpp"

#include "conjugateur.hpp"

void conj::displayVerb(verbDB::Verb verb) {
    std::string out;
    conj::VerbForm verbForm;

    out.append("+" + std::string(verb.infinitif.length(), '-') + "+\n");
    out.append("|" + verb.infinitif + "|\n");
    out.append("+" + std::string(verb.infinitif.length(), '-') + "+\n");

    for (int i = verbDB::Tense::present; i <= verbDB::Tense::conditionnel; i++) {
        std::string tense = conj::getTense(i);
        out.append("\n");
        out.append(tense + "\n");
        out.append(std::string(tense.length(), '-') + "\n");

        for (int j = verbDB::Person::je; j <= verbDB::Person::elles; j++) {
            verbForm = conj::getVerbForm(verb, i, j);
            out.append(verbForm.person + " " + verbForm.form + "\n");
        }
    }

    std::cout << out;
}

conj::VerbForm conj::getVerbForm(verbDB::Verb verb, int tense, int person) {

    conj::VerbForm verbForm;
    verbForm.infinitif = verb.infinitif;
    verbForm.person = conj::getPerson(person);

    if (tense == verbDB::Tense::participePresent) {
        verbForm.form = verb.participePresent;
    }

    else if (tense == verbDB::Tense::present && person == verbDB::Person::je) {
        verbForm.form = verb.presentJe;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::tu) {
        verbForm.form = verb.presentTu;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::il) {
        verbForm.form = verb.presentIl;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::elle) {
        verbForm.form = verb.presentElle;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::nous) {
        verbForm.form = verb.presentNous;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::vous) {
        verbForm.form = verb.presentVous;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::ils) {
        verbForm.form = verb.presentIls;
    }
    else if (tense == verbDB::Tense::present && person == verbDB::Person::elles) {
        verbForm.form = verb.presentElles;
    }

    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::je) {
        verbForm.form = verb.imparfaitJe;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::tu) {
        verbForm.form = verb.imparfaitTu;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::il) {
        verbForm.form = verb.imparfaitIl;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::elle) {
        verbForm.form = verb.imparfaitElle;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::nous) {
        verbForm.form = verb.imparfaitNous;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::vous) {
        verbForm.form = verb.imparfaitVous;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::ils) {
        verbForm.form = verb.imparfaitIls;
    }
    else if (tense == verbDB::Tense::imparfait && person == verbDB::Person::elles) {
        verbForm.form = verb.imparfaitElles;
    }

    else if (tense == verbDB::Tense::futur && person == verbDB::Person::je) {
        verbForm.form = verb.futurJe;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::tu) {
        verbForm.form = verb.futurTu;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::il) {
        verbForm.form = verb.futurIl;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::elle) {
        verbForm.form = verb.futurElle;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::nous) {
        verbForm.form = verb.futurNous;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::vous) {
        verbForm.form = verb.futurVous;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::ils) {
        verbForm.form = verb.futurIls;
    }
    else if (tense == verbDB::Tense::futur && person == verbDB::Person::elles) {
        verbForm.form = verb.futurElles;
    }

    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::je) {
        verbForm.form = verb.passeComposeJe;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::tu) {
        verbForm.form = verb.passeComposeTu;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::il) {
        verbForm.form = verb.passeComposeIl;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::elle) {
        verbForm.form = verb.passeComposeElle;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::nous) {
        verbForm.form = verb.passeComposeNous;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::vous) {
        verbForm.form = verb.passeComposeVous;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::ils) {
        verbForm.form = verb.passeComposeIls;
    }
    else if (tense == verbDB::Tense::passeCompose && person == verbDB::Person::elles) {
        verbForm.form = verb.passeComposeElles;
    }

    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::je) {
        verbForm.form = verb.plusQueParfaitJe;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::tu) {
        verbForm.form = verb.plusQueParfaitTu;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::il) {
        verbForm.form = verb.plusQueParfaitIl;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::elle) {
        verbForm.form = verb.plusQueParfaitElle;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::nous) {
        verbForm.form = verb.plusQueParfaitNous;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::vous) {
        verbForm.form = verb.plusQueParfaitVous;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::ils) {
        verbForm.form = verb.plusQueParfaitIls;
    }
    else if (tense == verbDB::Tense::plusQueParfait && person == verbDB::Person::elles) {
        verbForm.form = verb.plusQueParfaitElles;
    }

    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::je) {
        verbForm.form = verb.subjonctifJe;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::tu) {
        verbForm.form = verb.subjonctifTu;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::il) {
        verbForm.form = verb.subjonctifIl;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::elle) {
        verbForm.form = verb.subjonctifElle;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::nous) {
        verbForm.form = verb.subjonctifNous;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::vous) {
        verbForm.form = verb.subjonctifVous;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::ils) {
        verbForm.form = verb.subjonctifIls;
    }
    else if (tense == verbDB::Tense::subjonctif && person == verbDB::Person::elles) {
        verbForm.form = verb.subjonctifElles;
    }

    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::je) {
        verbForm.form = verb.conditionnelJe;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::tu) {
        verbForm.form = verb.conditionnelTu;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::il) {
        verbForm.form = verb.conditionnelIl;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::elle) {
        verbForm.form = verb.conditionnelElle;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::nous) {
        verbForm.form = verb.conditionnelNous;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::vous) {
        verbForm.form = verb.conditionnelVous;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::ils) {
        verbForm.form = verb.conditionnelIls;
    }
    else if (tense == verbDB::Tense::conditionnel && person == verbDB::Person::elles) {
        verbForm.form = verb.conditionnelElles;
    }
    else {
        verbForm.form = verb.infinitif;
    }

    return verbForm;
};

conj::VerbForm conj::getVerbForm(verbDB::Verb verb, verbDB::Tense tense, verbDB::Person person) {
    int tenseInt = tense;
    int personInt = person;
    return getVerbForm(verb, tenseInt, personInt);
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
