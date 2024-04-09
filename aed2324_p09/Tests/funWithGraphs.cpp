#include "funWithGraphs.h"


//=============================================================================
// Exercise 2: Vertex degrees
//=============================================================================
// Subexercise 2.1: outDegree
//=============================================================================
//TODO
int FunWithGraphs::outDegree(const Graph<int> g, const int &v) {
    auto vertex = g.findVertex(v);
    if (vertex == NULL) return -1;
    return vertex->getAdj().size();
}


//=============================================================================
// Subexercise 2.2: inDegree
//=============================================================================
//TODO
int FunWithGraphs::inDegree(const Graph<int> g, const int &v) {
    auto vertex = g.findVertex(v);
    if (vertex == NULL) return -1;
    int c = 0;
    for (auto vtx : g.getVertexSet()) {
        for (auto edge : vtx->getAdj()) {
            if (edge.getDest() == vertex) {
                c++;
                continue;
            }
        }
    }
    return c;
}

//=============================================================================
// Subexercise 2.3: weightedOutDegree
//=============================================================================
// TODO
int FunWithGraphs::weightedOutDegree(const Graph<int> g, const int &v) {
    auto vertex = g.findVertex(v);
    if (vertex == NULL) return -1;
    int c = 0;
    for (auto edge : vertex->getAdj()) {
        c += edge.getWeight();
    }
    return c;
}
