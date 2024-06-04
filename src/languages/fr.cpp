// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../main.cpp

#include "conjugateur.hpp"

cjgt::Tense infinitif = {
    0,
    false,
    false,
    L"infinitif",
    { L"" }
};

cjgt::Tense participe_present = {
    infinitif.position + infinitif.persons.size(),
    true,
    false,
    L"participe présent",
    { L"" }
};

cjgt::Tense present {
    participe_present.position + participe_present.persons.size(),
    true,
    true,
    L"présent",
    {
        L"je/j'",
        L"tu",
        L"il",
        L"elle",
        L"nous",
        L"vous",
        L"ils",
        L"elles"
    }
};

cjgt::Tense imparfait {
    present.position + present.persons.size(),
    true,
    true,
    L"imparfait",
    {
        L"je/j'",
        L"tu",
        L"il",
        L"elle",
        L"nous",
        L"vous",
        L"ils",
        L"elles"
    }
};

cjgt::Tense futur {
    imparfait.position + imparfait.persons.size(),
    true,
    true,
    L"futur",
    {
        L"je/j'",
        L"tu",
        L"il",
        L"elle",
        L"nous",
        L"vous",
        L"ils",
        L"elles"
    }
};

cjgt::Tense passe_compose {
    futur.position + futur.persons.size(),
    true,
    true,
    L"passé composé",
    {
        L"je/j'",
        L"tu",
        L"il",
        L"elle",
        L"nous",
        L"vous",
        L"ils",
        L"elles"
    }
};

cjgt::Tense plus_que_parfait {
    passe_compose.position + passe_compose.persons.size(),
    true,
    true,
    L"plus-que-parfait",
    {
        L"je/j'",
        L"tu",
        L"il",
        L"elle",
        L"nous",
        L"vous",
        L"ils",
        L"elles"
    }
};

cjgt::Tense subjonctif {
    plus_que_parfait.position + plus_que_parfait.persons.size(),
    true,
    true,
    L"subjonctif",
    {
        L"je/j'",
        L"tu",
        L"il",
        L"elle",
        L"nous",
        L"vous",
        L"ils",
        L"elles"
    }
};

cjgt::Tense conditionnel {
    subjonctif.position + subjonctif.persons.size(),
    true,
    true,
    L"conditionnel",
    {
        L"je/j'",
        L"tu",
        L"il",
        L"elle",
        L"nous",
        L"vous",
        L"ils",
        L"elles"
    }
};

cjgt::Category er = {
    L"-er",
    {
        &verbDB::acheter,
        &verbDB::aimer,
        &verbDB::aller,
        &verbDB::amener,
        &verbDB::appeler,
        &verbDB::appuyer,
        &verbDB::avancer,
        &verbDB::bavarder,
        &verbDB::chercher,
        &verbDB::commencer,
        &verbDB::donner,
        &verbDB::effacer,
        &verbDB::employer,
        &verbDB::enlever,
        &verbDB::entrer,
        &verbDB::envoyer,
        &verbDB::esperer,
        &verbDB::essayer,
        &verbDB::essuyer,
        &verbDB::exagerer,
        &verbDB::fermer,
        &verbDB::grimper,
        &verbDB::habiter,
        &verbDB::inventer,
        &verbDB::jeter,
        &verbDB::lancer,
        &verbDB::laver,
        &verbDB::manger,
        &verbDB::mener,
        &verbDB::monter,
        &verbDB::nager,
        &verbDB::nettoyer,
        &verbDB::parler,
        &verbDB::payer,
        &verbDB::peser,
        &verbDB::proteger,
        &verbDB::secher,
        &verbDB::sEnnuyer,
        &verbDB::sePromener,
        &verbDB::sInquieter
    }
};

cjgt::Category ir = {
    L"-ir",
    {
        &verbDB::agir,
        &verbDB::applaudir,
        &verbDB::choisir,
        &verbDB::courir,
        &verbDB::couvrir,
        &verbDB::cueillir,
        &verbDB::demolir,
        &verbDB::dormir,
        &verbDB::finir,
        &verbDB::fuir,
        &verbDB::guerir,
        &verbDB::maigrir,
        &verbDB::mentir,
        &verbDB::mourir,
        &verbDB::obeir,
        &verbDB::offrir,
        &verbDB::ouvrir,
        &verbDB::partir,
        &verbDB::reagir,
        &verbDB::reflechir,
        &verbDB::remplir,
        &verbDB::reussir,
        &verbDB::sentir,
        &verbDB::seRejouir,
        &verbDB::servir,
        &verbDB::sortir,
        &verbDB::souffrir,
        &verbDB::tenir,
        &verbDB::venir,
        &verbDB::vieillir
    }
};

cjgt::Category oir = {
    L"-oir",
    {
        &verbDB::apercevoir,
        &verbDB::avoir,
        &verbDB::decevoir,
        &verbDB::devoir,
        &verbDB::falloir,
        &verbDB::pleuvoir,
        &verbDB::pouvoir,
        &verbDB::recevoir,
        &verbDB::sAsseoir,
        &verbDB::savoir,
        &verbDB::valoir,
        &verbDB::voir,
        &verbDB::vouloir
    }
};

cjgt::Category re = {
    L"-re",
    {
        &verbDB::apparaitre,
        &verbDB::atteindre,
        &verbDB::attendre,
        &verbDB::battre,
        &verbDB::boire,
        &verbDB::conduire,
        &verbDB::confondre,
        &verbDB::connaitre,
        &verbDB::construire,
        &verbDB::craindre,
        &verbDB::croire,
        &verbDB::descendre,
        &verbDB::detruire,
        &verbDB::dire,
        &verbDB::disparaitre,
        &verbDB::ecrire,
        &verbDB::entendre,
        &verbDB::eteindre,
        &verbDB::etre,
        &verbDB::faire,
        &verbDB::joindre,
        &verbDB::lire,
        &verbDB::mettre,
        &verbDB::naitre,
        &verbDB::paraitre,
        &verbDB::peindre,
        &verbDB::perdre,
        &verbDB::plaire,
        &verbDB::prendre,
        &verbDB::produire,
        &verbDB::reduire,
        &verbDB::rendre,
        &verbDB::repondre,
        &verbDB::rire,
        &verbDB::rompre,
        &verbDB::sePlaindre,
        &verbDB::seTaire,
        &verbDB::suffire,
        &verbDB::suivre,
        &verbDB::traduire,
        &verbDB::vendre,
        &verbDB::vivre
    }
};

const cjgt::Language cjgt::french(
        L"French",
        {
            er,
            ir,
            oir,
            re,
        },
        {
            infinitif,
            participe_present,
            present,
            imparfait,
            futur,
            passe_compose,
            plus_que_parfait,
            subjonctif,
            conditionnel
        }
);
