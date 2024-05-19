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

    struct Person {
        unsigned int id;
        std::wstring name;

        bool operator==(const Person& Person) const;
    };

    struct Category {
        unsigned int id;
        std::wstring name;

        bool operator==(const Category& Category) const;
    };

    struct Tense {
        unsigned int id;
        std::wstring name;
        unsigned int width;

        bool operator==(const Tense& Tense) const;
    };

    class Language{
        public:
            Language(const std::wstring& name,
                    const std::vector<Person>& persons,
                    const std::vector<Category>& categories,
                    const std::vector<Tense>& tenses);

            std::wstring* getName();
            std::vector<Person>* getPersons();
            std::vector<Category>* getCategories();
            std::vector<Tense>* getTenses();
            std::vector<verbDB::Verb*> getVerbs();
            QuizItem getRandomQuizItem(const Category& category, const Tense& tense);

        private:
            std::wstring name;
            std::vector<Person> persons;
            std::vector<Category> categories;
            std::vector<Tense> tenses;
            std::map<std::wstring, verbDB::Verb> verbs;
    };

    extern Language french;
}
