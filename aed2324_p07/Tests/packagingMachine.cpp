#include "packagingMachine.h"

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
	return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
	boxes.push(b1);
	return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
	return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
	return this->boxes;
}


//=============================================================================
// Exercise 1: Packaging
//=============================================================================
// Subexercise 1.1: Load Objects
//=============================================================================

unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    auto it = objs.begin();
    int i = 0;
    while (it != objs.end()) {
        if (it->getWeight() <= boxCapacity) {
            objects.push(*it);
            objs.erase(it);
            i++;
        }
        else it++;
    }
    cout << objects.top().getID() << endl;
	return i;
}


//=============================================================================
// Subexercise 1.2: Search Box
//=============================================================================
Box PackagingMachine::searchBox(Object& obj) {
    HeapBox aux;
    Box b;
    bool done = false;
    while (!boxes.empty()) {
        if (!done && boxes.top().getFree() >= obj.getWeight()) {
            b = boxes.top();
            done = true;
        }
        else {
            aux.push(boxes.top());
        }
        boxes.pop();
    }
    if (!done) {
        b = Box();
    }
    boxes = aux;
    return b;
}



//=============================================================================
// Subexercise 1.3: Pack Objects
//=============================================================================
unsigned PackagingMachine::packObjects() {
    while (!objects.empty()) {
        Box bx = searchBox(const_cast<Object &>(objects.top()));
        bx.addObject(const_cast<Object &>(objects.top()));
        boxes.push(bx);
        objects.pop();
    }
	return boxes.size();
}


//=============================================================================
// Subexercise 1.4: Box with More Objects
//=============================================================================
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    stack<Object> res;
    if (boxes.empty()) return res;
    HeapBox aux = boxes;
    Box b;
    int max = 0;
    while (!aux.empty()) {
        if (aux.top().getObjects().size() > max) {
            max = aux.top().getObjects().size();
            res = aux.top().getObjects();
        }
        aux.pop();
    }
	return res;
}
