#include "funWithComplexity.h"

//=============================================================================
// Exercise 4: Analyzing a river
//=============================================================================
// TODO
#include <iostream>
int FunWithComplexity::river(const vector<int> & v, int k, int t) {

    cout << "  . HERE river" << endl;
    int aux = 0;
    int f = 0;
    for (int i = 0; i < k; i++) if (v[i] >= t) aux++;
    if ((k % 2 == 0 and aux >= k /2) or (k % 2 != 0 and aux >= k / 2 + 1)) f++;
    for (int i = 0; i <= v.size() - k - 1; i++) {
        if (v[i] >= t)  aux--;
        if (v[i + k] >= t) aux++;
        if ((k % 2 == 0 and aux >= k /2) or (k % 2 != 0 and aux >= k / 2 + 1)) f++;
    }
    return f;
}

//=============================================================================
// Exercise 5: Spiral of Numbers
//=============================================================================
// TODO
pair<int, int> FunWithComplexity::spiral(int N) {
    //vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int f = 0;
    int n = 0;
    int lastF = 0;

    while (f < N) {
        lastF = f;
        n++;
        f = n * n - n + 1;
    }

    //f >= N > lastF
    int idx = n / 2;
    int aux = 1;
    if (n % 2 == 0) aux = -1 ;

    int currentNum = f;
    pair<int, int> currentPos = {aux * -1 * idx, aux * idx};

    int changeDir = 0;
    while (currentNum > N and N > lastF) {
        if (changeDir == n - 1) {
            currentPos.first += aux;
            currentNum--;
        }
        else {
            currentPos.second -= aux;
            currentNum--;
            changeDir++;
        }
    }
    return currentPos;
}


//=============================================================================
// Exercise 7: Squared notebook
//=============================================================================
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    int init = 2;
    int sum = 0;
    pair<int, int> currentPos = {0, 0};
    int currentNum = 1;
    while (currentNum < a) {
        cout << "Find a: " << currentPos.first << ", " << currentPos.second << " => " << currentNum << endl;
        currentNum += init;
        init++;
        currentPos.first += 1;
    }

    return sum;
}