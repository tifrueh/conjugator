// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <string>
#include <vector>
#include <array>

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

std::vector<verbDB::Verb*> verbDB::allVerbs {
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
    &verbDB::commencer,
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
    &verbDB::falloir,
    &verbDB::fermer,
    &verbDB::fuir,
    &verbDB::grimper,
    &verbDB::guerir,
    &verbDB::inventer,
    &verbDB::jeter,
    &verbDB::joindre,
    &verbDB::lancer,
    &verbDB::laver,
    &verbDB::lire,
    &verbDB::maigrir,
    &verbDB::manger,
    &verbDB::mener,
    &verbDB::mentir,
    &verbDB::mettre,
    &verbDB::mourir,
    &verbDB::nager,
    &verbDB::naitre,
    &verbDB::nettoyer,
    &verbDB::obéir,
    &verbDB::offrir,
    &verbDB::ouvrir,
    &verbDB::paraitre,
    &verbDB::partir,
    &verbDB::payer,
    &verbDB::peindre,
    &verbDB::perdre,
    &verbDB::peser,
    &verbDB::placer,
    &verbDB::plaire,
    &verbDB::pleuvoir,
    &verbDB::pouvoir,
    &verbDB::preferer,
    &verbDB::prendre,
    &verbDB::produire,
    &verbDB::proteger,
    &verbDB::ranger,
    &verbDB::reagir,
    &verbDB::recevoir,
    &verbDB::reduire,
    &verbDB::reflechir,
    &verbDB::remplir,
    &verbDB::rendre,
    &verbDB::repondre,
    &verbDB::reussir,
    &verbDB::rire,
    &verbDB::rompre,
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
    &verbDB::sortir,
    &verbDB::souffrir,
    &verbDB::suffire,
    &verbDB::suivre,
    &verbDB::tenir,
    &verbDB::traduire,
    &verbDB::valoir,
    &verbDB::vendre,
    &verbDB::venir,
    &verbDB::vieillir,
    &verbDB::vivre,
    &verbDB::voir,
    &verbDB::vouloir,
};

std::vector<verbDB::Verb*> verbDB::verbsER = {};
std::vector<verbDB::Verb*> verbDB::verbsIR = {};
std::vector<verbDB::Verb*> verbDB::verbsOIR = {};
std::vector<verbDB::Verb*> verbDB::verbsRE = {};

void verbDB::initTypeVectors() {
    for (verbDB::Verb* pVerb : verbDB::allVerbs) {
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

verbDB::Verb verbDB::acheter = {

    verbDB::VerbType::er,

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

verbDB::Verb verbDB::agir = {

    verbDB::VerbType::ir,

    "agir",
    "agissant",

    "agis",
    "agis",
    "agit",
    "agit",
    "agissons",
    "agissez",
    "agissent",
    "agissent",

    "agissais",
    "agissais",
    "agissait",
    "agissait",
    "agissions",
    "agissiez",
    "agissaient",
    "agissaient",

    "agirai",
    "agiras",
    "agira",
    "agira",
    "agirons",
    "agirez",
    "agiront",
    "agiront",

    "ai agi",
    "as agi",
    "a agi",
    "a agi",
    "avons agi",
    "avez agi",
    "ont agi",
    "ont agi",

    "avais agi",
    "avais agi",
    "avait agi",
    "avait agi",
    "avions agi",
    "aviez agi",
    "avaient agi",
    "avaient agi",

    "agisse",
    "agisses",
    "agisse",
    "agisse",
    "agissions",
    "agissiez",
    "agissent",
    "agissent",

    "agirais",
    "agirais",
    "agirait",
    "agirait",
    "agirions",
    "agiriez",
    "agiraient",
    "agiraient"
};

verbDB::Verb verbDB::aller;
verbDB::Verb verbDB::amener;
verbDB::Verb verbDB::apercevoir;
verbDB::Verb verbDB::apparaitre;
verbDB::Verb verbDB::appeler;
verbDB::Verb verbDB::applaudir;
verbDB::Verb verbDB::appuyer;
verbDB::Verb verbDB::atteindre;
verbDB::Verb verbDB::attendre;
verbDB::Verb verbDB::avancer;
verbDB::Verb verbDB::avoir;
verbDB::Verb verbDB::battre;
verbDB::Verb verbDB::bavarder;
verbDB::Verb verbDB::boire;
verbDB::Verb verbDB::choisir;
verbDB::Verb verbDB::commencer;
verbDB::Verb verbDB::conduire;
verbDB::Verb verbDB::confondre;
verbDB::Verb verbDB::connaitre;
verbDB::Verb verbDB::construire;
verbDB::Verb verbDB::courir;
verbDB::Verb verbDB::couvrir;
verbDB::Verb verbDB::craindre;
verbDB::Verb verbDB::croire;
verbDB::Verb verbDB::cueillir;
verbDB::Verb verbDB::decevoir;
verbDB::Verb verbDB::demolir;
verbDB::Verb verbDB::detruire;
verbDB::Verb verbDB::devoir;
verbDB::Verb verbDB::dire;
verbDB::Verb verbDB::disparaitre;
verbDB::Verb verbDB::donner;
verbDB::Verb verbDB::dormir;
verbDB::Verb verbDB::ecrire;
verbDB::Verb verbDB::effacer;
verbDB::Verb verbDB::employer;
verbDB::Verb verbDB::enlever;
verbDB::Verb verbDB::entendre;
verbDB::Verb verbDB::envoyer;
verbDB::Verb verbDB::esperer;
verbDB::Verb verbDB::essayer;
verbDB::Verb verbDB::essuyer;
verbDB::Verb verbDB::eteindre;
verbDB::Verb verbDB::etre;
verbDB::Verb verbDB::exagerer;
verbDB::Verb verbDB::faire;
verbDB::Verb verbDB::falloir;
verbDB::Verb verbDB::fermer;
verbDB::Verb verbDB::fuir;
verbDB::Verb verbDB::grimper;
verbDB::Verb verbDB::guerir;
verbDB::Verb verbDB::inventer;
verbDB::Verb verbDB::jeter;
verbDB::Verb verbDB::joindre;
verbDB::Verb verbDB::lancer;
verbDB::Verb verbDB::laver;
verbDB::Verb verbDB::lire;
verbDB::Verb verbDB::maigrir;
verbDB::Verb verbDB::manger;
verbDB::Verb verbDB::mener;
verbDB::Verb verbDB::mentir;
verbDB::Verb verbDB::mettre;
verbDB::Verb verbDB::mourir;
verbDB::Verb verbDB::nager;
verbDB::Verb verbDB::naitre;
verbDB::Verb verbDB::nettoyer;
verbDB::Verb verbDB::obéir;
verbDB::Verb verbDB::offrir;
verbDB::Verb verbDB::ouvrir;
verbDB::Verb verbDB::paraitre;
verbDB::Verb verbDB::partir;
verbDB::Verb verbDB::payer;
verbDB::Verb verbDB::peindre;
verbDB::Verb verbDB::perdre;
verbDB::Verb verbDB::peser;
verbDB::Verb verbDB::placer;
verbDB::Verb verbDB::plaire;
verbDB::Verb verbDB::pleuvoir;
verbDB::Verb verbDB::pouvoir;
verbDB::Verb verbDB::preferer;
verbDB::Verb verbDB::prendre;
verbDB::Verb verbDB::produire;
verbDB::Verb verbDB::proteger;
verbDB::Verb verbDB::ranger;
verbDB::Verb verbDB::reagir;
verbDB::Verb verbDB::recevoir;
verbDB::Verb verbDB::reduire;
verbDB::Verb verbDB::reflechir;
verbDB::Verb verbDB::remplir;
verbDB::Verb verbDB::rendre;
verbDB::Verb verbDB::repondre;
verbDB::Verb verbDB::reussir;
verbDB::Verb verbDB::rire;
verbDB::Verb verbDB::rompre;
verbDB::Verb verbDB::sAssoir;
verbDB::Verb verbDB::sEnnuyer;
verbDB::Verb verbDB::sInquieter;
verbDB::Verb verbDB::savoir;
verbDB::Verb verbDB::secher;
verbDB::Verb verbDB::sentir;
verbDB::Verb verbDB::sePlaindre;
verbDB::Verb verbDB::sePromener;
verbDB::Verb verbDB::seRejouir;
verbDB::Verb verbDB::servir;
verbDB::Verb verbDB::seTaire;
verbDB::Verb verbDB::sortir;
verbDB::Verb verbDB::souffrir;
verbDB::Verb verbDB::suffire;
verbDB::Verb verbDB::suivre;
verbDB::Verb verbDB::tenir;
verbDB::Verb verbDB::traduire;
verbDB::Verb verbDB::valoir;
verbDB::Verb verbDB::vendre;
verbDB::Verb verbDB::venir;
verbDB::Verb verbDB::vieillir;
verbDB::Verb verbDB::vivre;
verbDB::Verb verbDB::voir;
verbDB::Verb verbDB::vouloir;
