#include "funWithGraphs.h"

//=============================================================================
// Exercise 2.1: Connected Components
//=============================================================================
// TODO
void dfsVisit(Vertex<int> *v);
int funWithGraphs::connectedComponents(Graph<int> *g) {
    vector<int> res;
    int c = 0;
    for (auto v : g->getVertexSet())
        v->setVisited(false);
    for (auto v : g->getVertexSet())
        if (! v->isVisited()) {
            c++;
            dfsVisit(v);
        }
    return c;
}

void dfsVisit(Vertex<int> *v) {
    v->setVisited(true);
    for (auto & e : v->getAdj()) {
        auto w = e.getDest();
        if ( ! w->isVisited())
            dfsVisit(w);
    }
}


//=============================================================================
// Exercise 2.2: Giant Component
//=============================================================================
// TODO
int dfsGC(Vertex<int> *v);
int funWithGraphs::giantComponent(Graph<int> *g) {
    vector<int> res;
    int aux;
    int max = 0;
    for (auto v : g->getVertexSet())
        v->setVisited(false);
    for (auto v : g->getVertexSet())
        if (! v->isVisited()) {
            aux = dfsGC(v);
            if (aux > max) {
                max = aux;
            }
        }
    return max;
}

int dfsGC(Vertex<int> *v) {
    v->setVisited(true);
    int c = 1;
    for (auto & e : v->getAdj()) {
        auto w = e.getDest();
        if ( ! w->isVisited())
            c += dfsGC(w);
    }
    return c;
}


//=============================================================================
// Exercise 2.3: Strongly Connected Components
//=============================================================================
// TODO
void dfs_scc(Graph<int> *g, Vertex<int> *v, stack<int> &s, list<list<int>> &l, int &i);

list<list<int>> funWithGraphs::scc(Graph<int> *g){
    list<list<int>> res;
    int i = 0;

    // mark all vertices as unvisited
    for (auto v : g->getVertexSet()) v->setVisited(false);

    // initialize stack to store vertices visited in current DFS traversal
    stack<int> s;

    list<int> sec;
    for (auto v : g->getVertexSet()) {
        if (!v->isVisited()) {
            dfs_scc(g, v, s, res, i);
        }
    }
    return res;
}
void dfs_scc(Graph<int> *g, Vertex<int> *v, stack<int> &s, list<list<int>> &l, int &i) {
    v->setProcessing(true);
    v->setNum(i);
    v->setLow(i);
    i++;
    v->setVisited(true);
    s.push(v->getInfo());
    for (auto & e : v->getAdj()) {
        auto w = e.getDest();
        if (!w->isVisited()) {
            dfs_scc(g, w, s, l, i);
            v->setLow(min(v->getLow(), w->getLow()));
        }
        else if (w->isProcessing() == 1) {
            v->setLow(min(v->getLow(), w->getLow()));
        }
    }
    if (v->getLow() == v->getNum()) {
        list<int> component;
        int u = 0;
        while (u != v->getInfo()) {
            u = s.top();
            s.pop();
            component.push_back(u);
        }
        l.push_back(component);
    }
    v->setProcessing(false);
}


//=============================================================================
// Exercise 2.4: Articulation Points
//=============================================================================
// TODO
void dfs_art(Graph<int> *g, Vertex<int> *v, stack<int> &s, unordered_set<int> &res, int &i);
unordered_set<int> funWithGraphs::articulationPoints(Graph<int> *g) {
    unordered_set<int> res;
    stack<int> s;
    int index = 1;
    for (auto v : g->getVertexSet())
        v->setVisited(false);

    for (auto v : g->getVertexSet()) {
        if (! v->isVisited())
            dfs_art(g, v, s, res, index);
    }

    return res;
}

void dfs_art(Graph<int> *g, Vertex<int> *v, stack<int> &s, unordered_set<int> &l, int &i){
    v->setVisited(true);

    v->setLow(i);
    v->setNum(i);
    v->setProcessing(true);
    s.push(v->getInfo());
    i++;

    int count = 0;

    for (auto & e : v->getAdj()) {
        auto w = e.getDest();
        if (!w->isVisited()) {
            count++;
            dfs_art(g, w, s, l, i);
            v->setLow(min(v->getLow(), w->getLow()));
            if (w->getLow() >= v->getNum() && v->getNum() != 1)
                l.insert(v->getInfo());
        } else if (w->isProcessing())
            v->setLow(min(v->getLow(), w->getNum()));
        if (count > 1 && v->getNum() == 1)
            l.insert(v->getInfo());
    }

    v->setProcessing(false);
    s.pop();
}