// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <algorithm>
#include <stdexcept>
#include <map>
#include <string>
#include <vector>

#include "verb.db.hpp"


// This namespace contains all functionality related to manipulating the verb database.
namespace cjgt {

    struct QuizItem {
        std::wstring infinitif;
        std::wstring tense;
        std::wstring person;
        std::wstring form;

        bool operator==(const QuizItem& QuizItem) const;
    };

    struct Verb {
        std::wstring infinitif;
        std::wstring translation;
    };

    struct Tense {
        std::wstring name;
        unsigned int width;
    };

    class Language{
        public:
            Language(const std::wstring& name,
                    const std::vector<std::wstring>& persons,
                    const std::vector<std::wstring>& categories,
                    const std::vector<Tense>& tenses);

            std::wstring* getName();
            std::vector<std::wstring>* getPersons();
            std::vector<std::wstring>* getCategories();
            std::vector<std::wstring>* getTenses();
            std::vector<std::vector<std::wstring>*> getVerbs();
            QuizItem getRandomQuizItem(const std::wstring& category, const std::wstring& tense);

        private:
            std::wstring name;
            std::vector<std::wstring> categories;
            std::vector<std::wstring> persons;
            std::vector<Tense> tenses;
            std::map<std::wstring, std::vector<std::wstring>> verbs;
    };

    extern Language french;
}
