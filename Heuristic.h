#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "Node.h"
#include <cmath>

using namespace std;

class Heuristic { //abstract class
    public:
        Heuristic(){} //default constructor
        
        virtual int runHeuristic(Node* curr, Node* goal) = 0; //pure virtual
};

class MisplacedTileHeuristic : public Heuristic { //subclass 1
    public:
        MisplacedTileHeuristic(){}; //default constructor

        virtual int runHeuristic(Node* curr, Node* goal){
            int counter = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (curr -> matrix.at(i).at(j) != goal -> matrix.at(i).at(j)) { //checks each position on the door to see if its the same as the goal state
                        counter++; //if not the same increment pointer
                    }
                }
            }
            return counter;
        }
};

class EuclideanHeuristic : public Heuristic { //subclass 2
    public:
        EuclideanHeuristic(){} //default constructor

        virtual int runHeuristic(Node* curr, Node* goal){
            vector<pair<int, int>> sol = {make_pair(2, 2), make_pair(0, 0), make_pair(0, 1), make_pair(0, 2), 
                                          make_pair(1, 0), make_pair(1, 1), make_pair(1, 2), make_pair(2, 0), make_pair(2, 1)}; //solution vector. Coordinates that each number should be in.
            int counter = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (curr -> matrix.at(i).at(j) != goal -> matrix.at(i).at(j)) {
                        if (curr -> matrix.at(i).at(j) != 0) {
                            double a = std::abs(i - sol.at(curr -> matrix.at(i).at(j)).first); //compute difference in row
                            double b = std::abs(j - sol.at(curr -> matrix.at(i).at(j)).second); //compute difference in column
                            double c = sqrt(pow(a, 2) + pow(b, 2)); //using pythagorean theorem to find direct distance
                            counter += c; //add total to the counter
                        }
                    }
                }
            }
            return counter;
        }
};

#endif