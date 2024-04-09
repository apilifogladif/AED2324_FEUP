#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

void Game::addKid(const Kid k1) {
 	kids.push_back(k1);
}

list<Kid> Game::getKids() const {
	return this->kids;
}

void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}

//=============================================================================
// Exercise 6: Pim Pam Pum
//=============================================================================
// Subexercise 6.1: Loose Game
//=============================================================================
Kid Game::loseGame(string phrase) {
    unsigned int n = numberOfWords(std::move(phrase));
    cout << "N: " << n << ";" << kids.size() << endl;
    list<Kid> kids_playing = kids;
    auto it = kids_playing.begin();
    unsigned int aux;
    while (n > kids_playing.size()) n -= kids_playing.size();
    unsigned long long i = kids_playing.size();

    if (it != kids_playing.end()) {
        while (kids_playing.size() > 1) {
            cout << "BEGIN" << endl;

            aux = n;
//            cout << "aux: " << aux << endl;
            if (aux > i) aux = n - i; it = kids_playing.begin();
//            cout << "aux: " << aux << endl;

            cout << "aux: " << aux - 1 << endl;
            advance(it, aux - 1);
            cout << it->getName() << endl;
            i = distance(it, kids_playing.end());
//            cout << "i: " << i << endl;
            kids_playing.remove(*it);
            if (i == 1) {it = kids_playing.begin(); i = kids_playing.size();}
            else {i--;}
            cout << "Next: " << it->getName() << endl;
        }
    }
    return *kids_playing.begin();
}


//=============================================================================
// Subexercise 6.2: Rearrange
//=============================================================================
// TODO
list<Kid> Game::rearrange() {
    list<Kid> res;
    return res;
}


//=============================================================================
// Subexercise 6.3: Shuffle
//=============================================================================
// TODO
list<Kid> Game::shuffle() const {
    list<Kid> newList;
    return newList;
}
