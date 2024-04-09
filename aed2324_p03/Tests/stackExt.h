# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
	stack<T> values;
	stack<T> minimums;
public:
	StackExt() {};
	bool empty() const; 
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

//=============================================================================
// Exercise 3: StackExt class
//=============================================================================
//TODO
template <class T>
bool StackExt<T>::empty() const {
    return this->values.empty();
}

//TODO
template <class T>
T& StackExt<T>::top() {
    return this->values.top();
}

//TODO
template <class T>
void StackExt<T>::pop() {
    if (this->values.top() == this->minimums.top()) {
        this->minimums.pop();
    }
    this->values.pop();
}

//TODO
template <class T>
void StackExt<T>::push(const T& val) {
    this->values.push(val);
    if (this->minimums.empty() or val <= this->minimums.top()) {
        this->minimums.push(val);
    }
}

//TODO
template <class T>
T& StackExt<T>::findMin() {
    return this->minimums.top();
}
