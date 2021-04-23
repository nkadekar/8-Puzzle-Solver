#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "Node.h"

using namespace std;

class Heuristic { //abstract class
    public:
        Heuristic(){}
        
        virtual int runHeuristic(Node* curr, Node* goal) = 0;
};

class MisplacedTileHeuristic : public Heuristic { //subclass 1
    public:
        MisplacedTileHeuristic(){};

        virtual int runHeuristic(Node* curr, Node* goal){
            int counter = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (curr -> matrix.at(i).at(j) != goal -> matrix.at(i).at(j)) {
                        counter++;
                    }
                }
            }
            return counter;
        }
};

class EuclideanHeuristic : public Heuristic { //subclass 2
    public:
        EuclideanHeuristic(){}

        //THIS IS WRONG FIX IT
        virtual int runHeuristic(Node* curr, Node* goal){
            vector<pair<int, int>> sol = {make_pair(2, 2), make_pair(0, 0), make_pair(0, 1), make_pair(0, 2), 
                                          make_pair(1, 0), make_pair(1, 1), make_pair(1, 2), make_pair(2, 0), make_pair(2, 1)};
            int counter = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (curr -> matrix.at(i).at(j) != goal -> matrix.at(i).at(j)) {
                        if (curr -> matrix.at(i).at(j) != 0) {
                            counter += std::abs(i - sol.at(curr -> matrix.at(i).at(j)).first) + std::abs(j - sol.at(curr -> matrix.at(i).at(j)).second);
                        }
                    }
                }
            }
            return counter;
        }
};

#endif