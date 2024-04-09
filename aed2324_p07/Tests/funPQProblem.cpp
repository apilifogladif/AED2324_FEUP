#include "funPQProblem.h"

FunPQProblem::FunPQProblem() {}


//=============================================================================
// Exercise 2: Minimum Cost
//=============================================================================
int FunPQProblem::minCost(const vector<int> &ropes) {
    cout << ropes.size() << " -> ";
    std::priority_queue<int, std::vector<int>, std::greater<int>> r;
    for (int s : ropes) r.push(s);
    cout << r.size() << endl;
    int minCost = 0;
    int last = 0;
    while (!r.empty()) {
        if (last == 0) {
            last = r.top();
            r.pop();
        }
        else {
            last += r.top();
            r.pop();
            r.push(last);
            minCost += last;
            last = 0;
        }
    }
    return minCost;
}
