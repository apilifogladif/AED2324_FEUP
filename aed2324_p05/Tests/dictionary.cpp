#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}


//=============================================================================
// Exercise 1: Dictionary
//=============================================================================
//TODO
bool WordMean::operator< (const WordMean& wm2) const {
    return this->word < wm2.getWord();
}

//=============================================================================
// Subexercise 1.1: Create Dictionary
//=============================================================================
//TODO
void Dictionary::readFile(ifstream &f) {
    string word, meaning;

    while (!f.eof()) {
        getline(f, word);
        getline(f, meaning);
        words.insert(WordMean(word, meaning));
    }
}

//=============================================================================
// Subexercise 1.2: Print Dictionary
//=============================================================================
//TODO
void Dictionary::print() const {
    for (WordMean a: words) {
        cout << a.getWord() << "\n";
        cout << a.getMeaning() << "\n";
    }
}

//=============================================================================
// Subexercise 1.3: Consult Dictionary
//=============================================================================
//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    bool found = false;
    string meaning = "word not found";
    for (WordMean a: words) {
        if (w1 == a.getWord()) {
            meaning = a.getMeaning();
            found = true;
        }
        else if (w1 < a.getWord()) {
            next = a;
            if (!found) {
                break;
            }
        }
        else {
            previous = a;
        }
    }
    return meaning;
}

//=============================================================================
// Subexercise 1.4: Update Dictionary
//=============================================================================
//TODO
bool Dictionary::update(string w1, string m1) {
    WordMean prev("", "");
    WordMean next("", "");
    string meaning = consult(w1, prev, next);
    if (meaning == "word not found") {
        addWord(WordMean(w1, m1));
        return false;
    }
    words.erase(WordMean(w1, meaning));
    words.insert(WordMean(w1, m1));
    return true;
}
