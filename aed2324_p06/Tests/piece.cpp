#include "piece.h"

Piece::Piece(string i, float d): id(i), diameter(d) {}

string Piece::getId() const {
    return id;
}

float Piece::getDiameter() const {
    return diameter;
}


//=============================================================================
// Exercise 8: Nuts and Bolts
//=============================================================================
//TODO
bool Piece::operator < (const Piece &p2) const {
    if (this->diameter < p2.getDiameter()) return true;
    return false;
}