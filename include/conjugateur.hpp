// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <map>
#include <string>
#include <vector>
#include <random>

#include "verb.db.hpp"


// This namespace contains all functionality related to manipulating the verb database.
namespace cjgt {

    struct Category {
        unsigned int id;
        std::wstring name;
        std::vector<verbDB::Verb*> verbs;

        bool operator==(const Category& Category) const;
    };

    struct Tense {
        std::vector<verbDB::Verb*>::size_type position;
        std::wstring name;
        std::vector<std::wstring> persons;

        bool operator==(const Tense& Tense) const;
    };

    struct QuizData {
        std::wstring* verb_name;
        Tense* tense;
        std::wstring* person;
        std::wstring* form;

        bool operator==(const QuizData& QuizItemData) const;
    };

    class Language{
        public:
            Language(
                    const std::wstring& name,
                    const std::vector<Category>& categories,
                    const std::vector<Tense>& tenses
            );

            std::wstring* getName();
            std::vector<Category*> getCategories();
            std::vector<Tense*> getTenses();
            std::map<std::wstring, verbDB::Verb*> getVerbs();
            verbDB::Verb* getVerb(std::wstring);

            QuizData getRandomQuizData(const std::vector<Category*>& categories, const std::vector<Tense*>& tenses);

        private:
            std::wstring name;
            std::vector<Category> categories;
            std::vector<Tense> tenses;
            std::map<std::wstring, verbDB::Verb*> verbs;
            std::random_device random_device;
            std::default_random_engine random_engine;
    };

    std::wstring* getVerbForm(
            verbDB::Verb* verb,
            const std::vector<std::wstring>::size_type& person,
            Tense* tense
    );

    std::wstring strip(const std::wstring& string);

    extern Language french;
}
