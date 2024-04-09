#include "funWithSearch.h"


//=============================================================================
// Exercise 1: Elementary Search
//=============================================================================
// Subexercise 1.1: Linear Search
//=============================================================================
// TODO
int FunWithSearch::searchLinear(const vector<int> &v, int key) {
    for (unsigned i=0; i<v.size(); i++)
        if (v[i] == key)
            return i; // key found at index i
    return -1; // key not found
}

//=============================================================================
// Subexercise 1.2: Binary Search
//=============================================================================
// TODO
int FunWithSearch::searchBinary(const vector<int> & v, int key) {
    int low = 0, high = (int)v.size() - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key < v[middle]) high = middle - 1;
        else if (key > v[middle]) low = middle + 1;
        else return middle; // key found at index middle
    }
    return -1; // key not found
}

//=============================================================================
// Exercise 2: Facing Sun
//=============================================================================
// TODO
int FunWithSearch::facingSun(const vector<int> & values) {
    int max = 0;
    int c = 0;
    for (int i: values) {
        if (i > max) {
            c++;
            max = i;
        }
    }
    return c;
}


//=============================================================================
// Exercise 3: Square Root
//=============================================================================
// TODO
int FunWithSearch::squareR(int num) {
    vector<int> vecNum;
    for (int i = 0; i <= num/2; i++) vecNum.push_back(i*i);

    int left = 0;
    int right = vecNum.size();
    int result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vecNum[mid] == num) {
            return mid;
        }
        if (vecNum[mid] < num) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return result;
}


//=============================================================================
// Exercise 5: MinPages (extra)
//=============================================================================
// TODO
int FunWithSearch::minPages(const vector<int> & values, int numSt) {

    return 0;
}
