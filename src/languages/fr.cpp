// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../main.cpp

#include "conjugateur.hpp"

cjgt::Tense participe_present = {
    1,
    L"participe présent",
    { L"" }
};

cjgt::Tense present {
    participe_present.position + participe_present.persons.size(),
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
        &verbDB::acheter
    }
};

cjgt::Category ir = {
    L"-ir",
    {
        &verbDB::agir
    }
};

cjgt::Category oir = {
    L"-oir",
    {
        &verbDB::apercevoir
    }
};

cjgt::Category re = {
    L"-re",
    {
        &verbDB::apparaitre
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
