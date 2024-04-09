#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}


//=============================================================================
// Exercise 4: Min Difference
//=============================================================================
// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if (nc > values.size()) return -1;

    // sorting values
    vector<unsigned> sortedValues = values;
    sort(sortedValues.begin(), sortedValues.end());

    // finding min diff
    unsigned min = sortedValues[nc - 1] - sortedValues[0];
    for (int i = 1; i <= sortedValues.size() - nc; i++) {
        unsigned diff = sortedValues[i + nc - 1] - sortedValues[i];
        if (diff < min) {
            min = diff;
        }
    }
    return min;
}


//=============================================================================
// Exercise 6: Num Inversions (extra)
//=============================================================================
//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    unsigned count = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) count++;
        }
    }
    return count;
}


//=============================================================================
// Exercise 7: Nuts and Bolts (extra)
//=============================================================================
// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
    for (int n = 0; n < nuts.size(); n++) {
        for (int b = 0; b < bolts.size(); b++) {
            if (nuts[n].getDiameter() == bolts[b].getDiameter()) {
                swap(bolts[b], bolts[n]);
            }
        }
    }
}
