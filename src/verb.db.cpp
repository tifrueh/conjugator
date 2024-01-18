// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include <string>
#include <vector>
#include <array>

#include "verb.db.hpp"

// An array containing all tense names as strings and IN THE SAME ORDER AS THE
// verbDB::Tense ENUMERATOR!!!
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

// An array containing all persons as strings and IN THE SAME ORDER AS THE
// verbDB::Person ENUMERATOR!!!
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

// A vector containing pointers to all known verbs.
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
    &verbDB::faire,
    &verbDB::fermer,
    &verbDB::fuir,
    &verbDB::grimper,
    &verbDB::guerir,

    &verbDB::sAssoir,
    &verbDB::sEnnuyer,
    &verbDB::sInquieter,
    &verbDB::savoir,
    &verbDB::secher,
    &verbDB::sentir,
    &verbDB::sePlaindre,
    &verbDB::sePromener,
    &verbDB::seRejouir,
    &verbDB::servir,
    &verbDB::seTaire,
    &verbDB::souffrir,
    &verbDB::suffire,
    &verbDB::suivre,
    &verbDB::tenir,
    &verbDB::traduire,
    &verbDB::valoir,
    &verbDB::vendre,
    &verbDB::venir,
    &verbDB::vivre,
    &verbDB::voir,
    &verbDB::vouloir
};

// Four vectors, one for earch verb suffix supported.
std::vector<const verbDB::Verb*> verbDB::verbsER = {};
std::vector<const verbDB::Verb*> verbDB::verbsIR = {};
std::vector<const verbDB::Verb*> verbDB::verbsOIR = {};
std::vector<const verbDB::Verb*> verbDB::verbsRE = {};

// Sort all the verb pointers from allVerbs into the suffix vectors.
// This method MUST and MAY ONLY be called ONCE.
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
