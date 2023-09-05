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
