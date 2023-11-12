// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <string>
#include <vector>
#include <array>

#include "verb.db.hpp"

const std::array<std::wstring, 9> verbDB::tenseStrings {
    L"infinitif",
    L"participe présent",
    L"présent",
    L"imparfait",
    L"futur",
    L"passé composé",
    L"plus-que-parfait",
    L"subjonctif",
    L"conditionnel"
};

const std::array<std::wstring, 9> verbDB::personStrings {
    L"",
    L"je/j'",
    L"tu",
    L"il",
    L"elle",
    L"nous",
    L"vous",
    L"ils",
    L"elles"
};

const std::vector<const verbDB::Verb*> verbDB::allVerbs {
    &verbDB::acheter,
    &verbDB::agir,
    &verbDB::aller,
    &verbDB::amener,
    &verbDB::apercevoir,
    &verbDB::apparaitre,
    &verbDB::appeler,
    &verbDB::applaudir,
    &verbDB::appuyer,
    &verbDB::atteindre,
    &verbDB::attendre,
    &verbDB::avancer,
    &verbDB::avoir,
    &verbDB::battre,
    &verbDB::bavarder,
    &verbDB::boire,
    &verbDB::choisir,
    &verbDB::conduire,
    &verbDB::confondre,
    &verbDB::connaitre,
    &verbDB::construire,
    &verbDB::courir,
    &verbDB::couvrir,
    &verbDB::craindre,
    &verbDB::croire,
    &verbDB::cueillir,
    &verbDB::decevoir,
    &verbDB::demolir,
    &verbDB::detruire,
    &verbDB::devoir,
    &verbDB::dire,
    &verbDB::disparaitre,
    &verbDB::donner,
    &verbDB::dormir,
    &verbDB::ecrire,
    &verbDB::effacer,
    &verbDB::employer,
    &verbDB::enlever,
    &verbDB::entendre,
    &verbDB::envoyer,
    &verbDB::esperer,
    &verbDB::essayer,
    &verbDB::essuyer,
    &verbDB::eteindre,
    &verbDB::etre,
    &verbDB::exagerer,
    &verbDB::faire
};

std::vector<const verbDB::Verb*> verbDB::verbsER = {};
std::vector<const verbDB::Verb*> verbDB::verbsIR = {};
std::vector<const verbDB::Verb*> verbDB::verbsOIR = {};
std::vector<const verbDB::Verb*> verbDB::verbsRE = {};

void verbDB::initTypeVectors() {
    for (const verbDB::Verb* pVerb : verbDB::allVerbs) {
        switch (pVerb->verbType) {

            case verbDB::VerbType::er :
                verbDB::verbsER.push_back(pVerb);
                break;
        
            case verbDB::VerbType::ir :
                verbDB::verbsIR.push_back(pVerb);
                break;
            
            case verbDB::VerbType::oir :
                verbDB::verbsOIR.push_back(pVerb);
                break;
            
            case verbDB::VerbType::re :
                verbDB::verbsRE.push_back(pVerb);
                break;
        }
    }
}
