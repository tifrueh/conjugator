// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "conjugateur.hpp"

cjgt::Language::Language(
        const std::wstring& name,
        const std::vector<Category>& categories,
        const std::vector<Tense>& tenses
) {
    this->name = name;
    this->categories = categories;
    this->tenses = tenses;

    this->random_engine.seed(this->random_device());
}

void cjgt::Language::addVerb(verbDB::Verb* verb, cjgt::Category* category) {
    this->verbs[verb->name] = verb;
    this->categorised_verbs[category].push_back(verb);
}

std::wstring* cjgt::Language::getName() {
    return &this->name;
}

std::vector<cjgt::Category>* cjgt::Language::getCategories() {
    return &this->categories;
}

std::vector<cjgt::Tense>* cjgt::Language::getTenses() {
    return &this->tenses;
}

std::map<std::wstring, verbDB::Verb*>* cjgt::Language::getVerbs() {
    return &this->verbs;
}

cjgt::QuizItem cjgt::Language::getRandomQuizItem(
        const std::vector<cjgt::Category*>& categories,
        const std::vector<cjgt::Tense*>& tenses
) {
    std::uniform_int_distribution<unsigned int> category_distribution(0, categories.size() - 1);
    cjgt::Category* category = categories.at(category_distribution(this->random_engine));

    std::vector<verbDB::Verb*> verbs = this->categorised_verbs.at(category);

    std::uniform_int_distribution<unsigned int> verb_distribution(0, verbs.size() - 1);
    verbDB::Verb* verb = verbs.at(verb_distribution(this->random_engine));

    std::uniform_int_distribution<unsigned int> tense_distribution(0, tenses.size() - 1);
    cjgt::Tense* tense = tenses.at(tense_distribution(this->random_engine));

    std::uniform_int_distribution<std::vector<std::wstring>::size_type> person_distribution(0, tense->persons.size() - 1);
    std::vector<std::wstring>::size_type person_index = person_distribution(this->random_engine);
    std::wstring* person = &tense->persons.at(person_index);

    std::wstring* form = this->getVerbForm(verb, person_index, tense);

    cjgt::QuizItem item;
    item.verb_name = &verb->name;
    item.tense = tense;
    item.person = person;
    item.form = form;

    return item;
}

std::wstring* cjgt::Language::getVerbForm(
                    verbDB::Verb* verb,
                    const std::vector<std::wstring>::size_type& person,
                    Tense* tense
) {
    return &verb->forms.at(tense->position + person);
};
