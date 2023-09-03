// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <string>
#include <vector>

namespace verbDB {

    struct Verb {

        std::string infinitif;
        std::string participePresent;

        std::string presentJe;
        std::string presentTu;
        std::string presentIl;
        std::string presentElle;
        std::string presentNous;
        std::string presentVous;
        std::string presentIls;
        std::string presentElles;

        std::string imparfaitJe;
        std::string imparfaitTu;
        std::string imparfaitIl;
        std::string imparfaitElle;
        std::string imparfaitNous;
        std::string imparfaitVous;
        std::string imparfaitIls;
        std::string imparfaitElles;

        std::string futurJe;
        std::string futurTu;
        std::string futurIl;
        std::string futurElle;
        std::string futurNous;
        std::string futurVous;
        std::string futurIls;
        std::string futurElles;

        std::string passeComposeJe;
        std::string passeComposeTu;
        std::string passeComposeIl;
        std::string passeComposeElle;
        std::string passeComposeNous;
        std::string passeComposeVous;
        std::string passeComposeIls;
        std::string passeComposeElles;

        std::string plusQueParfaitJe;
        std::string plusQueParfaitTu;
        std::string plusQueParfaitIl;
        std::string plusQueParfaitElle;
        std::string plusQueParfaitNous;
        std::string plusQueParfaitVous;
        std::string plusQueParfaitIls;
        std::string plusQueParfaitElles;

        std::string subjonctifJe;
        std::string subjonctifTu;
        std::string subjonctifIl;
        std::string subjonctifElle;
        std::string subjonctifNous;
        std::string subjonctifVous;
        std::string subjonctifIls;
        std::string subjonctifElles;

        std::string contidionnelJe;
        std::string contidionnelTu;
        std::string contidionnelIl;
        std::string contidionnelElle;
        std::string contidionnelNous;
        std::string contidionnelVous;
        std::string contidionnelIls;
        std::string contidionnelElles;
    };

    extern Verb acheter;
    extern Verb agir;
    extern Verb aller;
    extern Verb amener;
    extern Verb apercevoir;
    extern Verb apparaitre;
    extern Verb appeler;
    extern Verb applaudir;
    extern Verb appuyer;
    extern Verb atteindre;
    extern Verb attendre;
    extern Verb avancer;
    extern Verb avoir;
    extern Verb battre;
    extern Verb bavarder;
    extern Verb boire;
    extern Verb choisir;
    extern Verb commencer;
    extern Verb conduire;
    extern Verb confondre;
    extern Verb connaitre;
    extern Verb construire;
    extern Verb courir;
    extern Verb couvrir;
    extern Verb craindre;
    extern Verb croire;
    extern Verb cueillir;
    extern Verb decevoir;
    extern Verb demolir;
    extern Verb detruire;
    extern Verb devoir;
    extern Verb dire;
    extern Verb disparaitre;
    extern Verb donner;
    extern Verb dormir;
    extern Verb ecrire;
    extern Verb effacer;
    extern Verb employer;
    extern Verb enlever;
    extern Verb entendre;
    extern Verb envoyer;
    extern Verb esperer;
    extern Verb essayer;
    extern Verb essuyer;
    extern Verb eteindre;
    extern Verb etre;
    extern Verb exagerer;
    extern Verb faire;
    extern Verb falloir;
    extern Verb fermer;
    extern Verb fuir;
    extern Verb grimper;
    extern Verb guerir;
    extern Verb inventer;
    extern Verb jeter;
    extern Verb joindre;
    extern Verb lancer;
    extern Verb laver;
    extern Verb lire;
    extern Verb maigrir;
    extern Verb manger;
    extern Verb mener;
    extern Verb mentir;
    extern Verb mettre;
    extern Verb mourir;
    extern Verb nager;
    extern Verb naitre;
    extern Verb nettoyer;
    extern Verb obéir;
    extern Verb offrir;
    extern Verb ouvrir;
    extern Verb paraitre;
    extern Verb partir;
    extern Verb payer;
    extern Verb peindre;
    extern Verb perdre;
    extern Verb peser;
    extern Verb placer;
    extern Verb plaire;
    extern Verb pleuvoir;
    extern Verb pouvoir;
    extern Verb preferer;
    extern Verb prendre;
    extern Verb produire;
    extern Verb proteger;
    extern Verb ranger;
    extern Verb reagir;
    extern Verb recevoir;
    extern Verb reduire;
    extern Verb reflechir;
    extern Verb remplir;
    extern Verb rendre;
    extern Verb repondre;
    extern Verb reussir;
    extern Verb rire;
    extern Verb rompre;
    extern Verb sAssoir;
    extern Verb sEnnuyer;
    extern Verb sInquieter;
    extern Verb savoir;
    extern Verb secher;
    extern Verb sentir;
    extern Verb sePlaindre;
    extern Verb sePromener;
    extern Verb seRejouir;
    extern Verb servir;
    extern Verb seTaire;
    extern Verb sortir;
    extern Verb souffrir;
    extern Verb suffire;
    extern Verb suivre;
    extern Verb tenir;
    extern Verb traduire;
    extern Verb valoir;
    extern Verb vendre;
    extern Verb venir;
    extern Verb vieillir;
    extern Verb vivre;
    extern Verb voir;
    extern Verb vouloir;

    extern std::vector<Verb*> verbsER;
    extern std::vector<Verb*> verbsIR;
    extern std::vector<Verb*> verbsOIR;
    extern std::vector<Verb*> verbsRE;
};
