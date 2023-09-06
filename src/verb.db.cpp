// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in main.cpp

#include <string>
#include <vector>
#include <array>

#include "verb.db.hpp"

const std::array<std::string, 9> verbDB::tenseStrings {
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

const std::array<std::string, 8> verbDB::personStrings {
    "je/j'",
    "tu",
    "il",
    "elle",
    "nous",
    "vous",
    "ils",
    "elles"
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

const verbDB::Verb verbDB::agir = {

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

const verbDB::Verb verbDB::aller = {

    verbDB::VerbType::er,

    "aller",
    "allant",

    "vais",
    "vas",
    "va",
    "va",
    "allons",
    "allez",
    "vont",
    "vont",

    "allais",
    "allais",
    "allait",
    "allait",
    "allions",
    "alliez",
    "allaient",
    "allaient",

    "irai",
    "iras",
    "ira",
    "ira",
    "irons",
    "irez",
    "iront",
    "iront",

    "suis allé",
    "es allé",
    "est allé",
    "est allée",
    "sommes allés",
    "êtes allés",
    "sont allés",
    "sont allées",

    "étais allé",
    "etais allé",
    "etait allé",
    "etait allée",
    "étions allés",
    "étiez allés",
    "étaient allés",
    "étaient allées",

    "aille",
    "ailles",
    "aille",
    "aille",
    "allions",
    "alliez",
    "aillent",
    "aillent",

    "irais",
    "irais",
    "irait",
    "irait",
    "irions",
    "iriez",
    "iraient",
    "iraient"
};

const verbDB::Verb verbDB::amener = {

    verbDB::VerbType::er,

    "amener",
    "amenant",

    "amène",
    "amènes",
    "amène",
    "amène",
    "amenons",
    "amenez",
    "amènent",
    "amènent",

    "amenais",
    "amenais",
    "amenait",
    "amenait",
    "amenions",
    "ameniez",
    "amenaient",
    "amenaient",

    "amènerai",
    "amèneras",
    "amènera",
    "amènera",
    "amènerons",
    "amènerez",
    "amèneront",
    "amèneront",

    "ai amené",
    "as amené",
    "a amené",
    "a amené",
    "avons amené",
    "avez amené",
    "ont amené",
    "ont amené",

    "avais amené",
    "avais amené",
    "avait amené",
    "avait amené",
    "avions amené",
    "aviez amené",
    "avaient amené",
    "avaient amené",

    "amène",
    "amènes",
    "amène",
    "amène",
    "amenions",
    "ameniez",
    "amènent",
    "amènent",

    "amènerais",
    "amènerais",
    "amènerait",
    "amènerait",
    "amènerions",
    "amèneriez",
    "amèneraient",
    "amèneraient"
};

const verbDB::Verb verbDB::apercevoir = {

    verbDB::VerbType::oir,

    "apercevoir",
    "apercevant",

    "aperçois",
    "aperçois",
    "aperçoit",
    "aperçoit",
    "apercevons",
    "apercevez",
    "aperçoivent",
    "aperçoivent",

    "apercevais",
    "apercevais",
    "apercevait",
    "apercevait",
    "apercevions",
    "aperceviez",
    "apercevaient",
    "apercevaient",

    "apercevrai",
    "apercevras",
    "apercevra",
    "apercevra",
    "apercevrons",
    "apercevrez",
    "apercevront",
    "apercevront",

    "ai aperçu",
    "as aperçu",
    "a aperçu",
    "a aperçu",
    "avons aperçu",
    "avez aperçu",
    "ont aperçu",
    "ont aperçu",

    "avais aperçu",
    "avais aperçu",
    "avait aperçu",
    "avait aperçu",
    "avions aperçu",
    "aviez aperçu",
    "avaient aperçu",
    "avaient aperçu",

    "aperçoive",
    "aperçoives",
    "aperçoive",
    "aperçoive",
    "apercevions",
    "aperceviez",
    "aperçoivent",
    "aperçoivent",

    "apercevrais",
    "apercevrais",
    "apercevrait",
    "apercevrait",
    "apercevrions",
    "apercevriez",
    "apercevraient",
    "apercevraient"
};

const verbDB::Verb verbDB::apparaitre = {

    verbDB::VerbType::re,

    "apparaître",
    "apparaissant",

    "apparais",
    "apparais",
    "apparait",
    "apparait",
    "apparaissons",
    "apparaissez",
    "apparaissent",
    "apparaissent",

    "apparaissais",
    "apparaissais",
    "apparaissait",
    "apparaissait",
    "apparaissions",
    "apparaissiez",
    "apparaissaient",
    "apparaissaient",

    "apparaîtrai",
    "apparaîtras",
    "apparaîtra",
    "apparaîtra",
    "apparaîtrons",
    "apparaîtrez",
    "apparaîtront",
    "apparaîtront",

    "ai apparu",
    "as apparu",
    "a apparu",
    "a apparu",
    "avons apparu",
    "avez apparu",
    "ont apparu",
    "ont apparu",

    "avais apparu",
    "avais apparu",
    "avait apparu",
    "avait apparu",
    "avions apparu",
    "aviez apparu",
    "avaient apparu",
    "avaient apparu",

    "apparaisse",
    "apparaisses",
    "apparaisse",
    "apparaisse",
    "apparaissions",
    "apparaissiez",
    "apparaissent",
    "apparaissent",

    "apparaîtrais",
    "apparaîtrais",
    "apparaîtrait",
    "apparaîtrait",
    "apparaîtrions",
    "apparaîtriez",
    "apparaîtraient",
    "apparaîtraient"
};

const verbDB::Verb verbDB::appeler = {

    verbDB::VerbType::er,

    "appeler",
    "appelant",

    "appelle",
    "appelles",
    "appelle",
    "appelle",
    "appelons",
    "appelez",
    "appellent",
    "appellent",

    "appelais",
    "appelais",
    "appelait",
    "appelait",
    "appelions",
    "appeliez",
    "appelaient",
    "appelaient",

    "appellerai",
    "appelleras",
    "appellera",
    "appellera",
    "appellerons",
    "appellerez",
    "appelleront",
    "appelleront",

    "ai appelé",
    "as appelé",
    "a appelé",
    "a appelé",
    "avons appelé",
    "avez appelé",
    "ont appelé",
    "ont appelé",

    "avais appelé",
    "avais appelé",
    "avait appelé",
    "avait appelé",
    "avions appelé",
    "aviez appelé",
    "avaient appelé",
    "avaient appelé",

    "appelle",
    "appelles",
    "appelle",
    "appelle",
    "appelions",
    "appeliez",
    "appellent",
    "appellent",

    "appellerais",
    "appellerais",
    "appellerait",
    "appellerait",
    "appellerions",
    "appelleriez",
    "appelleraient",
    "appelleraient"
};

const verbDB::Verb verbDB::applaudir = {
    
    verbDB::VerbType::ir,

    "applaudir",
    "applaudissant",

    "applaudis",
    "applaudis",
    "applaudit",
    "applaudit",
    "applaudissons",
    "applaudissez",
    "applaudissent",
    "applaudissent",

    "applaudissais",
    "applaudissais",
    "applaudissait",
    "applaudissait",
    "applaudissions",
    "applaudissiez",
    "applaudissaient",
    "applaudissaient",

    "applaudirai",
    "applaudiras",
    "applaudira",
    "applaudira",
    "applaudirons",
    "applaudirez",
    "applaudiront",
    "applaudiront",

    "ai applaudi",
    "as applaudi",
    "a applaudi",
    "a applaudi",
    "avons applaudi",
    "avez applaudi",
    "ont applaudi",
    "ont applaudi",

    "avais applaudi",
    "avais applaudi",
    "avait applaudi",
    "avait applaudi",
    "avions applaudi",
    "aviez applaudi",
    "avaient applaudi",
    "avaient applaudi",

    "applaudisse",
    "applaudisses",
    "applaudisse",
    "applaudisse",
    "applaudissions",
    "applaudissiez",
    "applaudissent",
    "applaudissent",

    "applaudirais",
    "applaudirais",
    "applaudirait",
    "applaudirait",
    "applaudirions",
    "applaudiriez",
    "applaudiraient",
    "applaudiraient"
};

const verbDB::Verb verbDB::appuyer = {

    verbDB::VerbType::er,

    "appuyer",
    "appuyant",

    "appuie",
    "appuies",
    "appuie",
    "appuie",
    "appuyons",
    "appuyez",
    "appuient",
    "appuient",

    "appuyais",
    "appuyais",
    "appuyait",
    "appuyait",
    "appuyions",
    "appuyiez",
    "appuyaient",
    "appuyaient",

    "appuierai",
    "appuieras",
    "appuiera",
    "appuiera",
    "appuierons",
    "appuierez",
    "appuieront",
    "appuieront",

    "ai appuyé",
    "as appuyé",
    "a appuyé",
    "a appuyé",
    "avons appuyé",
    "avez appuyé",
    "ont appuye",
    "ont appuye",

    "avais appuyé",
    "avais appuyé",
    "avait appuyé",
    "avait appuyé",
    "avions appuyé",
    "aviez appuyé",
    "avaient appuyé",
    "avaient appuyé",

    "appuie",
    "appuies",
    "appuie",
    "appuie",
    "appuyions",
    "appuyiez",
    "appuient",
    "appuient",

    "appuierais",
    "appuierais",
    "appuierait",
    "appuierait",
    "appuierions",
    "appuieriez",
    "appuieraient",
    "appuieraient"
};

const verbDB::Verb verbDB::atteindre = {

    verbDB::VerbType::re,

    "atteindre",
    "atteignant",

    "atteins",
    "atteins",
    "atteint",
    "atteint",
    "atteignons",
    "atteignez",
    "atteignent",
    "atteignent",

    "atteignais",
    "atteignais",
    "attegnait",
    "attegnait",
    "atteignions",
    "atteigniez",
    "atteignaient",
    "atteignaient",

    "atteindrai",
    "atteindras",
    "atteindra",
    "atteindra",
    "atteindrons",
    "atteindrez",
    "atteindront",
    "atteindront",

    "ai atteint",
    "as atteint",
    "a atteint",
    "a atteint",
    "avons atteint",
    "avez atteint",
    "ont atteint",
    "ont atteint",

    "avais atteint",
    "avais atteint",
    "avait atteint",
    "avait atteint",
    "avions atteint",
    "aviez atteint",
    "avaient atteint",
    "avaient atteint",

    "atteigne",
    "atteignes",
    "aggeigne",
    "aggeigne",
    "atteignions",
    "aggeigniez",
    "atteignent",
    "atteignent",

    "atteindrais",
    "atteindrais",
    "atteindrait",
    "atteindrait",
    "atteindrions",
    "atteindriez",
    "atteindraient",
    "atteindraient"
};
