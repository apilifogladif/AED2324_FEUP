#include "funListStackQueueProblem.h"
#include "cell.h"

FunListStackQueueProblem::FunListStackQueueProblem() {}


//=============================================================================
// Exercise 1: Remove Higher
//=============================================================================
list<int> FunListStackQueueProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    auto it = values.begin();
    while (it != values.end()) {
        if (*it > x) {
            l1.push_back(*it);
            it = values.erase(it);
        }
        else {it++; }
    }
    return l1;
}


//=============================================================================
// Exercise 2: Overlapping Intervals
//=============================================================================
list<pair<int,int>> FunListStackQueueProblem::overlappingIntervals(list<pair<int,int>> values) {
    list<pair<int,int>> res;
    values.sort();
    auto it1 = values.begin();
    auto it2 = values.begin();
    pair<int, int> aux = {0, 0};
    while (it1 != values.end()) {
        aux.first = it1->first;
        aux.second = it1->second;
        it2 = it1;
        while (it2 != values.end()) {
            if (it2->first > aux.first and aux.second > it2->first) {
                if (aux.second < it2->second) {
                    aux.second = it2->second;
                    it2 = values.erase(it2);
                }
                else {
                    it2 = values.erase(it2);
                    it2++;
                }
            }
            else {it2++;}
        }
        res.push_back(aux);
        it1 = values.erase(it1);
    }
    return res;
}


//=============================================================================
// Exercise 4: Binary Numbers
//=============================================================================
vector<string> FunListStackQueueProblem::binaryNumbers(int n) {
    vector<string> res;
    queue<string> aux;
    aux.push("1");
    for (int i = 0; i < n; i++) {
        res.push_back(aux.front());
        aux.push(aux.front() + "0");
        aux.push(aux.front() + "1");
        aux.pop();
    }
    return res;
}


//=============================================================================
// Exercise 5: Calculate Span
//=============================================================================
vector<int> FunListStackQueueProblem::calculateSpan(const vector<int>& prices) {
    vector<int> res;
    stack<int> aux;
    int n = 1;
    for (int price : prices) {
        if (aux.empty()) {
            aux.push(price);
            res.push_back(1);
        }
        else if (aux.top() > price) {
            res.push_back(1);
            aux.push(price);
        }
        else if (aux.top() <= price) {
            cout << "C" << price << endl;
            while (!aux.empty() && aux.top() <= price) {
                n += res[res.size() - n];
                aux.pop();
            }
            res.push_back(n);
            n = 1;
            aux.push(price);
        }
    }
    return res;
}


//=============================================================================
// Exercise 7: Knight Jumps
//=============================================================================
//TODO
int FunListStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {
    return -1;
}
