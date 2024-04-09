#include "funHashingProblem.h"

FunHashingProblem::FunHashingProblem() {}


//=============================================================================
// Exercise 1: Find Duplicates
//=============================================================================
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    vector<int> res;
    unordered_set<int> window;
    for (int i = 0; i < values.size(); ++i) {
        if (i > k) {
            window.erase(values[i - k - 1]);
        }

        if (window.find(values[i]) != window.end()) {
            res.push_back(values[i]);
        }
        window.insert(values[i]);
    }
    return res;
}

