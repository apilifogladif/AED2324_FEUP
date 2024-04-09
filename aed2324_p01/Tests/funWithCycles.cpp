#include "funWithCycles.h"

//=============================================================================
// Exercise 1: Palindromes
//=============================================================================
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    unsigned length = s.size();
    for (unsigned i = 0; i < length/2; i++)
        if (s[i] != s[length-i-1])
            return false;
    return true;
}


//=============================================================================
// Exercise 2: Palindrome Sentences
//=============================================================================
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    unsigned length = s.size();
    std::string aux = "";
    for (unsigned i = 0; i < length; i++) {
        if ((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z')) {aux += tolower(s[i]);}
    }
    return palindrome(aux);
}


//=============================================================================
// Exercise 3: Interesting Numbers
//=============================================================================
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    n++;
    while (digitSum(n) != sum) {
        n++;
    }
    return n;
}

// This auxiliary function should return the sum of the digits of n
// TODO
int FunWithCycles::digitSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}


//=============================================================================
// Exercise 4: Winter is coming
//=============================================================================
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    unsigned length = v.size();
    int a = 0;
    int f = 0;
    bool neg = false;
    for (unsigned i = 0; i < length - 1; i++) {
        if (v[i + 1] - v[i] < 0 and neg) {a++; }
        else if (v[i + 1] - v[i] < 0 and !neg) {a = 1; neg = true; }
        else if (v[i + 1] - v[i] > 0 and neg) {
            if (a > f) {f = a; }
            neg = false;
        }
    }
    if (a > f) {f = a; }
    return f;
}

//=============================================================================
// Exercise 5: Playing with vectors
//=============================================================================

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    int a  = 0;
    for (int i : v) {
        if (i == n) {a++;}
    }
    return a;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    for (int i : v) {
        if (count(v, i) > 1) {return true; }
    }
    return false;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {
    if (hasDuplicates(v)) {
        int i = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (count(v, v[i]) > 1) {
                auto it = v.begin() + i;
                v.erase(it);
            }
        }
    }
}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    auto itt = v1.begin();
    auto ittt = v2.begin();
    while (itt != v1.end()) {
        while (*ittt < *itt and ittt != v2.end()) {
                ans.push_back(*ittt);
                ittt++;
        }
        ans.push_back(*itt);
        itt++;
    }
    while (ittt != v2.end()) {
        ans.push_back(*ittt);
        ittt++;
    }
    return ans;
}


//=============================================================================
// Exercise 6: Playing with prime numbers
//=============================================================================

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    for (int i = 2; i < n / 2; i++) {
        if(n % i == 0) {return false;}
    }
    return true;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0 and n != 1) {
            n /= i;
            ans.push_back(i);
        }
    }
    return ans;
}
#include <algorithm>

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    for (int i = 2; i <= n; i++) {ans.push_back(i);}
    auto it = ans.begin();
    while (*it <= n / 2) {
        if (*it != 0) {
            auto p = *it;
            int i = 2;
            while (p * i <= n) {
                auto aux = find(ans.begin(), ans.end(), p * i);
                if (aux != ans.end()) { *aux = 0; }
                i++;
            }
        }
        it++;
    }
    vector<int> primes;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] != 0) {primes.push_back(ans[i]); }
    }
    return primes;
}
