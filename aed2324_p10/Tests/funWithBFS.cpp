#include "funWithBFS.h"
#include <algorithm>
#include <iostream>


//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.2: Nodes at distance k (BFS)
//=============================================================================
// TODO
vector<Person> FunWithBFS::nodesAtDistanceBFS(const Graph<Person> *g, const Person &source, int k) {
    vector<Person> res;
    vector<Vertex<Person>*> final;
    vector<Vertex<Person>*> aux;
    Vertex<Person>* firstVertex = g->findVertex(source);
    final.push_back(firstVertex);
    for (int i = 1; i < k + 1; i++) {
        aux = final;
        final.clear();
        for (Vertex<Person>* v : aux) {
            for (Edge<Person> e: v->getAdj()) {
                auto it = std::find(aux.begin(), aux.end(), e.getDest());
                if (it == aux.end())
                    final.push_back(e.getDest());
            }
        }
    }

    for (Vertex<Person>* v : final) {
        res.push_back(v->getInfo());
    }
    return res;
}

//=============================================================================
// Exercise 2.2: Max New Children
//=============================================================================
// TODO
int FunWithBFS::maxNewChildren(const Graph<Person> *g, const Person &source, Person &info) {
    auto first = nodesAtDistanceBFS(g, source, 1);
    int c = 0;
    int aux = 0;
    for (const auto& f : first) {
        aux = 0;
        auto next = nodesAtDistanceBFS(g, f, 1);
        for (const auto& i : next) {
            auto it = find(first.begin(), first.end(), i);
            if (it != first.end()) aux++;
        }
        if (next.size() - aux > c) {
            c = next.size() - aux;
            info = f;
        }
    }
    return c;
}


