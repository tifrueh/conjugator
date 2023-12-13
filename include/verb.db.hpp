// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <string>
#include <vector>
#include <array>

namespace verbDB {

    enum VerbType { er, ir, oir, re };

    struct Verb {

        VerbType verbType;

        std::wstring infinitif;
        std::wstring participePresent;

        std::wstring presentJe;
        std::wstring presentTu;
        std::wstring presentIl;
        std::wstring presentElle;
        std::wstring presentNous;
        std::wstring presentVous;
        std::wstring presentIls;
        std::wstring presentElles;

        std::wstring imparfaitJe;
        std::wstring imparfaitTu;
        std::wstring imparfaitIl;
        std::wstring imparfaitElle;
        std::wstring imparfaitNous;
        std::wstring imparfaitVous;
        std::wstring imparfaitIls;
        std::wstring imparfaitElles;

        std::wstring futurJe;
        std::wstring futurTu;
        std::wstring futurIl;
        std::wstring futurElle;
        std::wstring futurNous;
        std::wstring futurVous;
        std::wstring futurIls;
        std::wstring futurElles;

        std::wstring passeComposeJe;
        std::wstring passeComposeTu;
        std::wstring passeComposeIl;
        std::wstring passeComposeElle;
        std::wstring passeComposeNous;
        std::wstring passeComposeVous;
        std::wstring passeComposeIls;
        std::wstring passeComposeElles;

        std::wstring plusQueParfaitJe;
        std::wstring plusQueParfaitTu;
        std::wstring plusQueParfaitIl;
        std::wstring plusQueParfaitElle;
        std::wstring plusQueParfaitNous;
        std::wstring plusQueParfaitVous;
        std::wstring plusQueParfaitIls;
        std::wstring plusQueParfaitElles;

        std::wstring subjonctifJe;
        std::wstring subjonctifTu;
        std::wstring subjonctifIl;
        std::wstring subjonctifElle;
        std::wstring subjonctifNous;
        std::wstring subjonctifVous;
        std::wstring subjonctifIls;
        std::wstring subjonctifElles;

        std::wstring conditionnelJe;
        std::wstring conditionnelTu;
        std::wstring conditionnelIl;
        std::wstring conditionnelElle;
        std::wstring conditionnelNous;
        std::wstring conditionnelVous;
        std::wstring conditionnelIls;
        std::wstring conditionnelElles;
    };

    extern const Verb acheter;
    extern const Verb agir;
    extern const Verb aller;
    extern const Verb amener;
    extern const Verb apercevoir;
    extern const Verb apparaitre;
    extern const Verb appeler;
    extern const Verb applaudir;
    extern const Verb appuyer;
    extern const Verb atteindre;
    extern const Verb attendre;
    extern const Verb avancer;
    extern const Verb avoir;
    extern const Verb battre;
    extern const Verb bavarder;
    extern const Verb boire;
    extern const Verb choisir;
    extern const Verb commencer;
    extern const Verb commencerEtre;
    extern const Verb conduire;
    extern const Verb confondre;
    extern const Verb connaitre;
    extern const Verb construire;
    extern const Verb courir;
    extern const Verb couvrir;
    extern const Verb craindre;
    extern const Verb croire;
    extern const Verb cueillir;
    extern const Verb decevoir;
    extern const Verb demolir;
    extern const Verb detruire;
    extern const Verb devoir;
    extern const Verb dire;
    extern const Verb disparaitre;
    extern const Verb donner;
    extern const Verb dormir;
    extern const Verb ecrire;
    extern const Verb effacer;
    extern const Verb employer;
    extern const Verb enlever;
    extern const Verb entendre;
    extern const Verb envoyer;
    extern const Verb esperer;
    extern const Verb essayer;
    extern const Verb essuyer;
    extern const Verb eteindre;
    extern const Verb etre;
    extern const Verb exagerer;
    extern const Verb faire;
    extern const Verb falloir;
    extern const Verb fermer;
    extern const Verb fuir;
    extern const Verb grimper;
    extern const Verb guerir;
    extern const Verb inventer;
    extern const Verb jeter;
    extern const Verb joindre;
    extern const Verb lancer;
    extern const Verb laver;
    extern const Verb lire;
    extern const Verb maigrir;
    extern const Verb manger;
    extern const Verb mener;
    extern const Verb mentir;
    extern const Verb mettre;
    extern const Verb mourir;
    extern const Verb nager;
    extern const Verb naitre;
    extern const Verb nettoyer;
    extern const Verb obeir;
    extern const Verb offrir;
    extern const Verb ouvrir;
    extern const Verb paraitre;
    extern const Verb partir;
    extern const Verb payer;
    extern const Verb peindre;
    extern const Verb perdre;
    extern const Verb peser;
    extern const Verb placer;
    extern const Verb plaire;
    extern const Verb pleuvoir;
    extern const Verb pouvoir;
    extern const Verb preferer;
    extern const Verb prendre;
    extern const Verb produire;
    extern const Verb proteger;
    extern const Verb ranger;
    extern const Verb reagir;
    extern const Verb recevoir;
    extern const Verb reduire;
    extern const Verb reflechir;
    extern const Verb remplir;
    extern const Verb rendre;
    extern const Verb repondre;
    extern const Verb reussir;
    extern const Verb rire;
    extern const Verb rompre;
    extern const Verb sAssoir;
    extern const Verb sEnnuyer;
    extern const Verb sInquieter;
    extern const Verb savoir;
    extern const Verb secher;
    extern const Verb sentir;
    extern const Verb sePlaindre;
    extern const Verb sePromener;
    extern const Verb seRejouir;
    extern const Verb servir;
    extern const Verb seTaire;
    extern const Verb sortirAvoir;
    extern const Verb sortirEtre;
    extern const Verb souffrir;
    extern const Verb suffire;
    extern const Verb suivre;
    extern const Verb tenir;
    extern const Verb traduire;
    extern const Verb valoir;
    extern const Verb vendre;
    extern const Verb venir;
    extern const Verb vieillir;
    extern const Verb vivre;
    extern const Verb voir;
    extern const Verb vouloir;

    extern const std::vector<const Verb*> allVerbs;
    extern std::vector<const Verb*> verbsER;
    extern std::vector<const Verb*> verbsIR;
    extern std::vector<const Verb*> verbsOIR;
    extern std::vector<const Verb*> verbsRE;

    enum Tense { infinitif, participePresent, present, imparfait, futur, passeCompose, plusQueParfait, subjonctif, conditionnel };
    enum Person {none, je, tu, il, elle, nous, vous, ils, elles };

    extern const std::array<std::wstring, 9> tenseStrings;
    extern const std::array<std::wstring, 9> personStrings;

    void initTypeVectors();
}
