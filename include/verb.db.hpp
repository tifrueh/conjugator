// Copyright (C) 2023 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <string>
#include <vector>

namespace verbDB {

    struct verb {

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

        std::string passe_composeJe;
        std::string passe_composeTu;
        std::string passe_composeIl;
        std::string passe_composeElle;
        std::string passe_composeNous;
        std::string passe_composeVous;
        std::string passe_composeIls;
        std::string passe_composeElles;

        std::string imparfaitJe;
        std::string imparfaitTu;
        std::string imparfaitIl;
        std::string imparfaitElle;
        std::string imparfaitNous;
        std::string imparfaitVous;
        std::string imparfaitIls;
        std::string imparfaitElles;

        std::string plusQueParfaitJe;
        std::string plusQueParfaitTu;
        std::string plusQueParfaitIl;
        std::string plusQueParfaitElle;
        std::string plusQueParfaitNous;
        std::string plusQueParfaitVous;
        std::string plusQueParfaitIls;
        std::string plusQueParfaitElles;

        std::string futurJe;
        std::string futurTu;
        std::string futurIl;
        std::string futurElle;
        std::string futurNous;
        std::string futurVous;
        std::string futurIls;
        std::string futurElles;

        std::string contidionnelJe;
        std::string contidionnelTu;
        std::string contidionnelIl;
        std::string contidionnelElle;
        std::string contidionnelNous;
        std::string contidionnelVous;
        std::string contidionnelIls;
        std::string contidionnelElles;

        std::string subjonctifJe;
        std::string subjonctifTu;
        std::string subjonctifIl;
        std::string subjonctifElle;
        std::string subjonctifNous;
        std::string subjonctifVous;
        std::string subjonctifIls;
        std::string subjonctifElles;
    };

    std::vector<verb> erVerbs;
    std::vector<verb> irVerbs;
    std::vector<verb> oirVerbs;
    std::vector<verb> reVerbs;

};
