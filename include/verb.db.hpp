// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <string>
#include <vector>


// This namespace contains all functionality related to the verb database.
namespace verbDB {

    struct Verb {
        std::wstring name;
        std::wstring translation;

        std::vector<std::wstring> forms;
    };

    // Declare all verbs.
    extern const Verb acheter;
    extern const Verb agir;
    extern const Verb aimer;
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
    extern const Verb chercher;
    extern const Verb choisir;
    extern const Verb commencer;
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
    extern const Verb descendre;
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
    extern const Verb entrer;
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
    extern const Verb finir;
    extern const Verb fuir;
    extern const Verb grimper;
    extern const Verb guerir;
    extern const Verb habiter;
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
    extern const Verb monter;
    extern const Verb mourir;
    extern const Verb nager;
    extern const Verb naitre;
    extern const Verb nettoyer;
    extern const Verb obeir;
    extern const Verb offrir;
    extern const Verb ouvrir;
    extern const Verb paraitre;
    extern const Verb parler;
    extern const Verb partir;
    extern const Verb payer;
    extern const Verb peindre;
    extern const Verb perdre;
    extern const Verb peser;
    extern const Verb plaire;
    extern const Verb pleuvoir;
    extern const Verb pouvoir;
    extern const Verb prendre;
    extern const Verb produire;
    extern const Verb proteger;
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
    extern const Verb sAsseoir;
    extern const Verb savoir;
    extern const Verb secher;
    extern const Verb sEnnuyer;
    extern const Verb sentir;
    extern const Verb sePlaindre;
    extern const Verb sePromener;
    extern const Verb seRejouir;
    extern const Verb servir;
    extern const Verb seTaire;
    extern const Verb sInquieter;
    extern const Verb sortir;
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
}
