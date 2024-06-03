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

std::vector<cjgt::Category*> cjgt::Language::getCategories() {
    std::vector<cjgt::Category*> output;

    for (std::vector<cjgt::Category>::iterator it = this->categories.begin(); it != this->categories.end(); ++it) {
        output.push_back(&(*it));
    }

    return output;
}

std::vector<cjgt::Tense*> cjgt::Language::getTenses() {

    std::vector<cjgt::Tense*> output;

    for (std::vector<cjgt::Tense>::iterator it = this->tenses.begin(); it != this->tenses.end(); ++it) {
        output.push_back(&(*it));
    }

    return output;
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

std::wstring cjgt::strip(const std::wstring& string) {
    std::wstring outstring = string;

    // Calculate the beginning and the count of the stripped string.
    const long unsigned int begin = outstring.find_first_not_of(' ');
    const long unsigned int end = outstring.find_last_not_of(' ');
    const long unsigned int count = end + 1 - begin;

    if (outstring.empty() || begin == std::string::npos) {
        return L"";
    } else {
        outstring = outstring.substr(begin, count);
        return outstring;
    }
}
