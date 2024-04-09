#include "jackpot.h"


Bet::Bet(vector<int> ns, string p): numbers(ns), player(p) {}

vector<int> Bet::getNumbers() const {
    return numbers;
}

string Bet::getPlayer() const {
    return player;
}

Jackpot::Jackpot()  {}

unsigned Jackpot::getNumBets() const {
    return bets.size();
}


//=============================================================================
// Exercise 2: Jackpot
//=============================================================================
// Subexercise 2.1: Add Bet
//=============================================================================
void Jackpot::addBet(const Bet& b) {
    bool equals = true;
    for (auto bet : bets) {
        equals = true;
        for (int i = 0; i < bet.getNumbers().size(); i++) {
            if (bet.getNumbers()[i] != b.getNumbers()[i]) {
                equals = false;
                break;
            }
        }
        if (equals) break;
    }

    if (!equals) bets.insert(b);
}

//=============================================================================
// Subexercise 2.2: Bets in Number
//=============================================================================
// TODO
unsigned Jackpot::betsInNumber(unsigned num) const {
	unsigned count = 0;
	return count;
}

//=============================================================================
// Subexercise 2.3: Drawn Bets
//=============================================================================
// TODO
vector<string> Jackpot::drawnBets(vector<int> draw) const {
	vector<string> res;
	return res;
}
