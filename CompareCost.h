#ifndef CCOST_H
#define CCOST_H

#include "Node.h"

using namespace std;

struct CompareCost {
    virtual bool operator() (Node* p1, Node* p2) {
        return p1 -> cost > p2->cost;
    }
};

struct MisplacedTileCompareCost {
    virtual bool operator() (Node* p1, Node* p2, Node* goal) {
        Heuristic* heuristic = new MisplacedTileHeuristic();
        return (p1 -> cost) + heuristic->runHeuristic(p1, goal) > p2->cost + heuristic->runHeuristic(p2, goal);
    }
};

struct EuclideanCompareCost {
    virtual bool operator() (Node* p1, Node* p2, Node* goal) {
    Heuristic* heuristic = new EuclideanHeuristic();
    return (p1 -> cost) + heuristic->runHeuristic(p1, goal) > p2->cost + heuristic->runHeuristic(p2, goal);
    }
};

#endif

//Used: https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/