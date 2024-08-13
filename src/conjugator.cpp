// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "conjugator.hpp"

bool cjgt::QuizData::operator==(const cjgt::QuizData& quizData) const {
    return 
        this->verb_name == quizData.verb_name &&
        this->tense == quizData.tense &&
        this->person == quizData.person &&
        this->form == quizData.form;
}

cjgt::Language::Language(
        const std::wstring& name,
        const std::vector<Category>& categories,
        const std::vector<Tense>& tenses
) {
    this->name = name;
    this->categories = categories;
    this->tenses = tenses;
}

const std::wstring* cjgt::Language::get_name() const {
    return &this->name;
}

std::vector<const cjgt::Category*> cjgt::Language::get_categories() const {
    std::vector<const cjgt::Category*> output;

    for (std::vector<cjgt::Category>::const_iterator it = this->categories.begin(); it != this->categories.end(); ++it) {
        output.push_back(&(*it));
    }

    return output;
}

std::vector<const cjgt::Tense*> cjgt::Language::get_tenses() const {

    std::vector<const cjgt::Tense*> output;

    for (std::vector<cjgt::Tense>::const_iterator it = this->tenses.begin(); it != this->tenses.end(); ++it) {
        output.push_back(&(*it));
    }

    return output;
}

std::map<std::wstring, const verbDB::Verb*> cjgt::Language::get_verbs() const {

    std::map<std::wstring, const verbDB::Verb*> local_verbs;

    for (cjgt::Category category : this->categories) {
        for (const verbDB::Verb* verb : category.verbs) {
            local_verbs[verb->name] = verb;
        }
    }

    return local_verbs;
}

cjgt::QuizData cjgt::Language::get_random_quiz_data(
        const std::vector<const cjgt::Category*>& categories,
        const std::vector<const cjgt::Tense*>& tenses
) const {

    std::random_device device;
    std::default_random_engine engine(device());

    std::uniform_int_distribution<std::vector<const cjgt::Category*>::size_type> category_distribution(0, categories.size() - 1);
    const cjgt::Category* category = categories.at(category_distribution(engine));

    std::uniform_int_distribution<std::vector<const verbDB::Verb*>::size_type> verb_distribution(0, category->verbs.size() - 1);
    const verbDB::Verb* verb = category->verbs.at(verb_distribution(engine));

    std::uniform_int_distribution<std::vector<const cjgt::Tense*>::size_type> tense_distribution(0, tenses.size() - 1);
    const cjgt::Tense* tense = tenses.at(tense_distribution(engine));

    std::uniform_int_distribution<std::vector<std::wstring>::size_type> person_distribution(0, tense->persons.size() - 1);
    std::vector<std::wstring>::size_type person_index = person_distribution(engine);
    const std::wstring* person = &tense->persons.at(person_index);

    const std::wstring* form = get_verb_form(verb, person_index, tense);

    cjgt::QuizData data;
    data.verb_name = &verb->name;
    data.tense = tense;
    data.person = person;
    data.form = form;

    return data;
}

const std::wstring* cjgt::get_verb_form(
                    const verbDB::Verb* verb,
                    const std::vector<std::wstring>::size_type& person,
                    const Tense* tense
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

const cjgt::Language* cjgt::get_language(const cjgt::LanguageID& id) {
    std::map<cjgt::LanguageID, const cjgt::Language*>::const_iterator element = cjgt::languages.find(id);

    if (element == cjgt::languages.end()) {
        return nullptr;
    }

    return element->second;
};
