// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "conjugateur.hpp"


const verbDB::Verb* cjgt::getVerb(const std::wstring &infinitif) {
    for (const verbDB::Verb* verb : verbDB::allVerbs) {
        if (verb->infinitif == infinitif) {
            return verb;
        }
    }

    throw std::invalid_argument("Verb not found");

}

cjgt::VerbForm cjgt::getVerbForm(const verbDB::Verb& verb, const int& tense, const int& person) {

    cjgt::VerbForm verbForm;
    verbForm.infinitif = verb.infinitif;
    verbForm.person = cjgt::getPerson(person);
    verbForm.tense = cjgt::getTense(tense);

    if (tense == verbDB::Tense::participePresent) {
        verbForm.form = verb.participePresent;
        verbForm.person = L"";
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
        verbForm.person = L"";
    }

    return verbForm;
}

cjgt::VerbForm cjgt::getVerbForm(const verbDB::Verb& verb, const verbDB::Tense& tense, const verbDB::Person& person) {
    int tenseInt = tense;
    int personInt = person;
    return getVerbForm(verb, tenseInt, personInt);
}

std::wstring cjgt::getTense(const verbDB::Tense& tense) {
    return verbDB::tenseStrings.at(tense);
}

std::wstring cjgt::getTense(const int& tense) {
    return verbDB::tenseStrings.at(tense);
}

std::wstring cjgt::getPerson(const verbDB::Person& person) {
    return verbDB::personStrings.at(person);
}

std::wstring cjgt::getPerson(const int& person) {
    return verbDB::personStrings.at(person);
}

std::wstring cjgt::getFormString(const cjgt::VerbForm& verbForm) {
    
    // Return an empty string if a form is empty (e. g. falloir - je)
    if (verbForm.form == L"") {
        return L"";
    }
    
    std::wstring out;

    wchar_t firstChar = verbForm.form.at(0);

    bool concatJe = (firstChar == L'a') | (firstChar == L'à') | (firstChar == L'â') |
                    (firstChar == L'e') | (firstChar == L'é') | (firstChar == L'è') | (firstChar == L'ê') |
                    (firstChar == L'i') | (firstChar == L'î') |
                    (firstChar == L'o') |
                    (firstChar == L'u') |
                    (firstChar == L'h');

    if (concatJe && verbForm.person == L"je/j'") {
        out = L"j'" + verbForm.form;
    } else if (!concatJe && verbForm.person == L"je/j'") {
        out = L"je " + verbForm.form;
    } else if (verbForm.tense == L"participe présent") {
        out = verbForm.form;
    } else {
        out = verbForm.person + L" " + verbForm.form;
    }

    return out;
}

bool cjgt::VerbForm::operator==(const cjgt::VerbForm& verbForm) const {
    return this->infinitif == verbForm.infinitif && this->person == verbForm.person && this->form == verbForm.form && this->tense == verbForm.tense;
}

std::wstring cjgt::strip(const std::wstring& string) {
    std::wstring outstring = string;
    
    // Calculate the beginning and the count of the stripped string.
    const long unsigned int begin = outstring.find_first_not_of(' ');
    const long unsigned int end = outstring.find_last_not_of(' ');
    const long unsigned int count = end + 1 - begin;

    if (outstring.empty() || begin == std::string::npos) {
        return L"";
    } else {
        outstring = outstring.substr(begin, count);
        return outstring;
    }
}
