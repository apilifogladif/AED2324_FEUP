#include "funWithDFS.h"
#include <algorithm>
#include <iostream>


//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.1: Nodes at distance k (DFS)
//=============================================================================
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res);

vector<Person> FunWithDFS::nodesAtDistanceDFS(const Graph<Person> *g, const Person &source, int k) {
    vector<Person> res;
    Vertex<Person>* firstVertex = g->findVertex(source);

    if (firstVertex == nullptr) {
        return res;
    }
    if (k == 0) {
        res.push_back(source);
        return res;
    }

    for (auto i : g->getVertexSet()) {
        i->setVisited(false);
    }
    firstVertex->setVisited(true);

    for (auto vtx : firstVertex->getAdj()) {
        if (!vtx.getDest()->isVisited()) {
            nodesAtDistanceDFSVisit(g, vtx.getDest(), k - 1, res);
        }
    }

    return res;
}

void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *firstVertex, int k, vector<Person> &res) {
    vector<Person> aux;
    firstVertex->setVisited(true);

    if (k > 0) {
        for (auto edge : firstVertex->getAdj()) {
            if (!edge.getDest()->isVisited()) {
                nodesAtDistanceDFSVisit(g, edge.getDest(), k - 1, res);
            }
        }
    }
    else if (k == 0) {
        res.push_back(firstVertex->getInfo());
    }
}


//=============================================================================
// Exercise 2.3: Directed Acyclic Graph
//=============================================================================
//In the Graph class, implement the member function below, in the funWithDFS.cpp file:
//bool isDAG(Graph<int> g);
//This function checks whether the directed graph is acyclic (Directed Acyclic Graph, or DAG for short), that
//        is, the graph does not contain cycles, in which case the function returns true. Otherwise, the function returns
//false.
//Suggestion: Adapt the depth-first search algorithm

//without changing the parameters of the functions

// TODO
bool dfsIsDAG(Vertex<int> *v);

bool FunWithDFS::isDAG(Graph<int> g) {
    for (Vertex<int>* vertex : g.getVertexSet()) {
        vertex->setVisited(false);
        vertex->setProcessing(false);
    }
    auto first = g.getVertexSet()[0];
    for (auto e : first->getAdj()) {
        if (!dfsIsDAG(e.getDest())) {
            return false; // Cycle found, not a DAG
        }
    }
    return true; // No cycles found, it's a DAG
}

// TODO
bool dfsIsDAG(Vertex<int> *v) {
    if (v->isVisited() && !v->isProcessing()) {
        return true; // Already visited, no cycle found
    }
    v->setVisited(true);
    v->setProcessing(true);

    for (const Edge<int>& edge : v->getAdj()) {
        if (!edge.getDest()->isVisited()) {
            if (!dfsIsDAG(edge.getDest())) {
                return false; // Cycle detected
            }
        } else if (edge.getDest()->isProcessing()) {
            return false; // Cycle detected
        }
    }

    v->setProcessing(false); // Reset inStack status for backtracking
    return true;
}
