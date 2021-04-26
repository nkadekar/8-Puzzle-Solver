#ifndef CCOST_H
#define CCOST_H

#include "Node.h"
#include "Heuristic.h"

using namespace std;

struct CompareCost {                                    //Helper Class for the Priority Queue Functions
    virtual bool operator() (Node* p1, Node* p2) {
        return p1 -> cost > p2->cost;                   //Makes the priority queue sort from least to greatest
    }
};

struct MisplacedTileCompareCost {                       //Helper Class for the Priority Queue Functions
    virtual bool operator() (Node* p1, Node* p2) {
        vector<vector<int>> goalvector = {{1,2,3}, {4,5,6}, {7,8,0}};
        Node* goal = new Node(goalvector, 0, nullptr);
        Heuristic* heuristic = new MisplacedTileHeuristic();        //Calls heuristic to add the costs together and sort from least to greatest
        return (p1 -> cost) + heuristic->runHeuristic(p1, goal) > p2->cost + heuristic->runHeuristic(p2, goal); //computes g(n) + h(n) with h(n) being misplaced tiles
    }
};

struct EuclideanCompareCost {                           //Helper Class for the Priority Queue Functions
    virtual bool operator() (Node* p1, Node* p2) {
    vector<vector<int>> goalvector = {{1,2,3}, {4,5,6}, {7,8,0}};
    Node* goal = new Node(goalvector, 0, nullptr);
    Heuristic* heuristic = new EuclideanHeuristic();                //Calls heuristic to add the costs together and sort from least to greatest 
    return (p1 -> cost) + heuristic->runHeuristic(p1, goal) > p2->cost + heuristic->runHeuristic(p2, goal); //computes g(n) + h(n) with h(n) being euclidean distance
    }
};

#endif

//Used: https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/