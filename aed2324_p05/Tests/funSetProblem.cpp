#include <algorithm>
#include "funSetProblem.h"

FunSetProblem::FunSetProblem() {}


//=============================================================================
// Exercise 2: FunSetProblem
//=============================================================================
// TODO
pair<int,int> FunSetProblem::pairSum(const vector<int> &values, int sum) {
    std::multiset<int> multiSet;
    for (int i: values) multiSet.insert(i);
    auto it = multiSet.begin();
    auto aux = it;
    int x = 0;
    int y = 0;
    while (it != multiSet.end()) {
        if (sum - *it < *it) {
            if ((aux = find(multiSet.begin(), it, sum - *it)) != it) {
                x = *it;
                y = *aux;
                break;
            }
        }
        else if (sum - *it > *it) {
            if ((aux = find(it, multiSet.end(), sum - *it)) != multiSet.end()) {
                x = *it;
                y = *aux;
                break;
            }
        }
        it++;
    }
    return make_pair(x, y);
}