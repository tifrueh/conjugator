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

const std::array<std::wstring, 8> verbDB::personStrings {
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

const verbDB::Verb verbDB::acheter = {

    verbDB::VerbType::er,

    L"acheter",
    L"achetant",

    L"achète",
    L"achètes",
    L"achète",
    L"achète",
    L"achetons",
    L"achetez",
    L"achètent",
    L"achètent",

    L"achetais",
    L"achetais",
    L"achetait",
    L"achetait",
    L"achetions",
    L"achetiez",
    L"achetaient",
    L"achetaient",

    L"achèterai",
    L"achèteras",
    L"achètera",
    L"achètera",
    L"achèterons",
    L"achèterez",
    L"achèteront",
    L"achèteront",

    L"ai acheté",
    L"as acheté",
    L"a acheté",
    L"a acheté",
    L"avons acheté",
    L"avez acheté",
    L"ont acheté",
    L"ont acheté",

    L"avais acheté",
    L"avais acheté",
    L"avait acheté",
    L"avait acheté",
    L"avions acheté",
    L"aviez acheté",
    L"avaient acheté",
    L"avaient acheté",

    L"achète",
    L"achètes",
    L"achète",
    L"achète",
    L"achetions",
    L"achetiez",
    L"achètent",
    L"achètent",

    L"achèterais",
    L"achèterais",
    L"achèterait",
    L"achèterait",
    L"achèterions",
    L"achèteriez",
    L"achèteraient",
    L"achèteraient"
};

const verbDB::Verb verbDB::agir = {

    verbDB::VerbType::ir,

    L"agir",
    L"agissant",

    L"agis",
    L"agis",
    L"agit",
    L"agit",
    L"agissons",
    L"agissez",
    L"agissent",
    L"agissent",

    L"agissais",
    L"agissais",
    L"agissait",
    L"agissait",
    L"agissions",
    L"agissiez",
    L"agissaient",
    L"agissaient",

    L"agirai",
    L"agiras",
    L"agira",
    L"agira",
    L"agirons",
    L"agirez",
    L"agiront",
    L"agiront",

    L"ai agi",
    L"as agi",
    L"a agi",
    L"a agi",
    L"avons agi",
    L"avez agi",
    L"ont agi",
    L"ont agi",

    L"avais agi",
    L"avais agi",
    L"avait agi",
    L"avait agi",
    L"avions agi",
    L"aviez agi",
    L"avaient agi",
    L"avaient agi",

    L"agisse",
    L"agisses",
    L"agisse",
    L"agisse",
    L"agissions",
    L"agissiez",
    L"agissent",
    L"agissent",

    L"agirais",
    L"agirais",
    L"agirait",
    L"agirait",
    L"agirions",
    L"agiriez",
    L"agiraient",
    L"agiraient"
};

const verbDB::Verb verbDB::aller = {

    verbDB::VerbType::er,

    L"aller",
    L"allant",

    L"vais",
    L"vas",
    L"va",
    L"va",
    L"allons",
    L"allez",
    L"vont",
    L"vont",

    L"allais",
    L"allais",
    L"allait",
    L"allait",
    L"allions",
    L"alliez",
    L"allaient",
    L"allaient",

    L"irai",
    L"iras",
    L"ira",
    L"ira",
    L"irons",
    L"irez",
    L"iront",
    L"iront",

    L"suis allé",
    L"es allé",
    L"est allé",
    L"est allée",
    L"sommes allés",
    L"êtes allés",
    L"sont allés",
    L"sont allées",

    L"étais allé",
    L"etais allé",
    L"etait allé",
    L"etait allée",
    L"étions allés",
    L"étiez allés",
    L"étaient allés",
    L"étaient allées",

    L"aille",
    L"ailles",
    L"aille",
    L"aille",
    L"allions",
    L"alliez",
    L"aillent",
    L"aillent",

    L"irais",
    L"irais",
    L"irait",
    L"irait",
    L"irions",
    L"iriez",
    L"iraient",
    L"iraient"
};

const verbDB::Verb verbDB::amener = {

    verbDB::VerbType::er,

    L"amener",
    L"amenant",

    L"amène",
    L"amènes",
    L"amène",
    L"amène",
    L"amenons",
    L"amenez",
    L"amènent",
    L"amènent",

    L"amenais",
    L"amenais",
    L"amenait",
    L"amenait",
    L"amenions",
    L"ameniez",
    L"amenaient",
    L"amenaient",

    L"amènerai",
    L"amèneras",
    L"amènera",
    L"amènera",
    L"amènerons",
    L"amènerez",
    L"amèneront",
    L"amèneront",

    L"ai amené",
    L"as amené",
    L"a amené",
    L"a amené",
    L"avons amené",
    L"avez amené",
    L"ont amené",
    L"ont amené",

    L"avais amené",
    L"avais amené",
    L"avait amené",
    L"avait amené",
    L"avions amené",
    L"aviez amené",
    L"avaient amené",
    L"avaient amené",

    L"amène",
    L"amènes",
    L"amène",
    L"amène",
    L"amenions",
    L"ameniez",
    L"amènent",
    L"amènent",

    L"amènerais",
    L"amènerais",
    L"amènerait",
    L"amènerait",
    L"amènerions",
    L"amèneriez",
    L"amèneraient",
    L"amèneraient"
};

const verbDB::Verb verbDB::apercevoir = {

    verbDB::VerbType::oir,

    L"apercevoir",
    L"apercevant",

    L"aperçois",
    L"aperçois",
    L"aperçoit",
    L"aperçoit",
    L"apercevons",
    L"apercevez",
    L"aperçoivent",
    L"aperçoivent",

    L"apercevais",
    L"apercevais",
    L"apercevait",
    L"apercevait",
    L"apercevions",
    L"aperceviez",
    L"apercevaient",
    L"apercevaient",

    L"apercevrai",
    L"apercevras",
    L"apercevra",
    L"apercevra",
    L"apercevrons",
    L"apercevrez",
    L"apercevront",
    L"apercevront",

    L"ai aperçu",
    L"as aperçu",
    L"a aperçu",
    L"a aperçu",
    L"avons aperçu",
    L"avez aperçu",
    L"ont aperçu",
    L"ont aperçu",

    L"avais aperçu",
    L"avais aperçu",
    L"avait aperçu",
    L"avait aperçu",
    L"avions aperçu",
    L"aviez aperçu",
    L"avaient aperçu",
    L"avaient aperçu",

    L"aperçoive",
    L"aperçoives",
    L"aperçoive",
    L"aperçoive",
    L"apercevions",
    L"aperceviez",
    L"aperçoivent",
    L"aperçoivent",

    L"apercevrais",
    L"apercevrais",
    L"apercevrait",
    L"apercevrait",
    L"apercevrions",
    L"apercevriez",
    L"apercevraient",
    L"apercevraient"
};

const verbDB::Verb verbDB::apparaitre = {

    verbDB::VerbType::re,

    L"apparaître",
    L"apparaissant",

    L"apparais",
    L"apparais",
    L"apparait",
    L"apparait",
    L"apparaissons",
    L"apparaissez",
    L"apparaissent",
    L"apparaissent",

    L"apparaissais",
    L"apparaissais",
    L"apparaissait",
    L"apparaissait",
    L"apparaissions",
    L"apparaissiez",
    L"apparaissaient",
    L"apparaissaient",

    L"apparaîtrai",
    L"apparaîtras",
    L"apparaîtra",
    L"apparaîtra",
    L"apparaîtrons",
    L"apparaîtrez",
    L"apparaîtront",
    L"apparaîtront",

    L"ai apparu",
    L"as apparu",
    L"a apparu",
    L"a apparu",
    L"avons apparu",
    L"avez apparu",
    L"ont apparu",
    L"ont apparu",

    L"avais apparu",
    L"avais apparu",
    L"avait apparu",
    L"avait apparu",
    L"avions apparu",
    L"aviez apparu",
    L"avaient apparu",
    L"avaient apparu",

    L"apparaisse",
    L"apparaisses",
    L"apparaisse",
    L"apparaisse",
    L"apparaissions",
    L"apparaissiez",
    L"apparaissent",
    L"apparaissent",

    L"apparaîtrais",
    L"apparaîtrais",
    L"apparaîtrait",
    L"apparaîtrait",
    L"apparaîtrions",
    L"apparaîtriez",
    L"apparaîtraient",
    L"apparaîtraient"
};

const verbDB::Verb verbDB::appeler = {

    verbDB::VerbType::er,

    L"appeler",
    L"appelant",

    L"appelle",
    L"appelles",
    L"appelle",
    L"appelle",
    L"appelons",
    L"appelez",
    L"appellent",
    L"appellent",

    L"appelais",
    L"appelais",
    L"appelait",
    L"appelait",
    L"appelions",
    L"appeliez",
    L"appelaient",
    L"appelaient",

    L"appellerai",
    L"appelleras",
    L"appellera",
    L"appellera",
    L"appellerons",
    L"appellerez",
    L"appelleront",
    L"appelleront",

    L"ai appelé",
    L"as appelé",
    L"a appelé",
    L"a appelé",
    L"avons appelé",
    L"avez appelé",
    L"ont appelé",
    L"ont appelé",

    L"avais appelé",
    L"avais appelé",
    L"avait appelé",
    L"avait appelé",
    L"avions appelé",
    L"aviez appelé",
    L"avaient appelé",
    L"avaient appelé",

    L"appelle",
    L"appelles",
    L"appelle",
    L"appelle",
    L"appelions",
    L"appeliez",
    L"appellent",
    L"appellent",

    L"appellerais",
    L"appellerais",
    L"appellerait",
    L"appellerait",
    L"appellerions",
    L"appelleriez",
    L"appelleraient",
    L"appelleraient"
};

const verbDB::Verb verbDB::applaudir = {
    
    verbDB::VerbType::ir,

    L"applaudir",
    L"applaudissant",

    L"applaudis",
    L"applaudis",
    L"applaudit",
    L"applaudit",
    L"applaudissons",
    L"applaudissez",
    L"applaudissent",
    L"applaudissent",

    L"applaudissais",
    L"applaudissais",
    L"applaudissait",
    L"applaudissait",
    L"applaudissions",
    L"applaudissiez",
    L"applaudissaient",
    L"applaudissaient",

    L"applaudirai",
    L"applaudiras",
    L"applaudira",
    L"applaudira",
    L"applaudirons",
    L"applaudirez",
    L"applaudiront",
    L"applaudiront",

    L"ai applaudi",
    L"as applaudi",
    L"a applaudi",
    L"a applaudi",
    L"avons applaudi",
    L"avez applaudi",
    L"ont applaudi",
    L"ont applaudi",

    L"avais applaudi",
    L"avais applaudi",
    L"avait applaudi",
    L"avait applaudi",
    L"avions applaudi",
    L"aviez applaudi",
    L"avaient applaudi",
    L"avaient applaudi",

    L"applaudisse",
    L"applaudisses",
    L"applaudisse",
    L"applaudisse",
    L"applaudissions",
    L"applaudissiez",
    L"applaudissent",
    L"applaudissent",

    L"applaudirais",
    L"applaudirais",
    L"applaudirait",
    L"applaudirait",
    L"applaudirions",
    L"applaudiriez",
    L"applaudiraient",
    L"applaudiraient"
};

const verbDB::Verb verbDB::appuyer = {

    verbDB::VerbType::er,

    L"appuyer",
    L"appuyant",

    L"appuie",
    L"appuies",
    L"appuie",
    L"appuie",
    L"appuyons",
    L"appuyez",
    L"appuient",
    L"appuient",

    L"appuyais",
    L"appuyais",
    L"appuyait",
    L"appuyait",
    L"appuyions",
    L"appuyiez",
    L"appuyaient",
    L"appuyaient",

    L"appuierai",
    L"appuieras",
    L"appuiera",
    L"appuiera",
    L"appuierons",
    L"appuierez",
    L"appuieront",
    L"appuieront",

    L"ai appuyé",
    L"as appuyé",
    L"a appuyé",
    L"a appuyé",
    L"avons appuyé",
    L"avez appuyé",
    L"ont appuye",
    L"ont appuye",

    L"avais appuyé",
    L"avais appuyé",
    L"avait appuyé",
    L"avait appuyé",
    L"avions appuyé",
    L"aviez appuyé",
    L"avaient appuyé",
    L"avaient appuyé",

    L"appuie",
    L"appuies",
    L"appuie",
    L"appuie",
    L"appuyions",
    L"appuyiez",
    L"appuient",
    L"appuient",

    L"appuierais",
    L"appuierais",
    L"appuierait",
    L"appuierait",
    L"appuierions",
    L"appuieriez",
    L"appuieraient",
    L"appuieraient"
};

const verbDB::Verb verbDB::atteindre = {

    verbDB::VerbType::re,

    L"atteindre",
    L"atteignant",

    L"atteins",
    L"atteins",
    L"atteint",
    L"atteint",
    L"atteignons",
    L"atteignez",
    L"atteignent",
    L"atteignent",

    L"atteignais",
    L"atteignais",
    L"attegnait",
    L"attegnait",
    L"atteignions",
    L"atteigniez",
    L"atteignaient",
    L"atteignaient",

    L"atteindrai",
    L"atteindras",
    L"atteindra",
    L"atteindra",
    L"atteindrons",
    L"atteindrez",
    L"atteindront",
    L"atteindront",

    L"ai atteint",
    L"as atteint",
    L"a atteint",
    L"a atteint",
    L"avons atteint",
    L"avez atteint",
    L"ont atteint",
    L"ont atteint",

    L"avais atteint",
    L"avais atteint",
    L"avait atteint",
    L"avait atteint",
    L"avions atteint",
    L"aviez atteint",
    L"avaient atteint",
    L"avaient atteint",

    L"atteigne",
    L"atteignes",
    L"aggeigne",
    L"aggeigne",
    L"atteignions",
    L"aggeigniez",
    L"atteignent",
    L"atteignent",

    L"atteindrais",
    L"atteindrais",
    L"atteindrait",
    L"atteindrait",
    L"atteindrions",
    L"atteindriez",
    L"atteindraient",
    L"atteindraient"
};
