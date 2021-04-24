#ifndef PROBLEM_H
#define PROBLEM_H

#include <string>
#include <queue>
#include <cmath>
#include <utility>
#include "Node.h"
#include "CompareCost.h"

using namespace std;

class Problem {
    private:
        Node* initialState; //passed in initial state
        Node* goalState; //passed in goal state

    public:
        Problem(Node* initialState, Node* goalstate) {
                this->initialState = initialState;
                this->goalState = goalstate;
        }

        int UniformCostSearch(int &nodesExpanded, int &maxQueueSize){
            priority_queue<Node*, vector<Node*>, CompareCost> frontier;
            vector<Node*> visited;
            // bool goalFound = false;
            frontier.push(initialState);
            while(!frontier.empty()) {
                if (frontier.size() > maxQueueSize) {
                    maxQueueSize = frontier.size();
                }
                
                //check if top node visited or goal
                Node* curr = frontier.top();
                frontier.pop();

                curr -> Print();

                if(checkGoal(curr, this -> goalState)) {
                    // goalFound = true;
                    return curr -> cost;
                }

                nodesExpanded++;
                
                if(!checkVisited(curr, visited)) {
                    visited.push_back(curr);

                    //if not goal or visited: Run operators and add to frontier if not nullptr and not visited
                    if (up(curr) != nullptr) {
                        if (!checkVisited(up(curr), visited)){
                            frontier.push(up(curr));
                        }
                    }
                    if (left(curr) != nullptr) {
                        if (!checkVisited(left(curr), visited)){
                            frontier.push(left(curr));
                        }
                    }
                    if (down(curr) != nullptr) {
                        if (!checkVisited(down(curr), visited)){
                            frontier.push(down(curr));
                        }
                    }
                    if (right(curr) != nullptr) {
                        if (!checkVisited(right(curr), visited)){
                            frontier.push(right(curr));
                        }
                    }
                }
            }
            return -1;
        }

        //A* misplaced tiles
        int AStarMissingTileSearch(int &nodesExpanded, int &maxQueueSize){
            priority_queue<Node*, vector<Node*>, MisplacedTileCompareCost> frontier;
            vector<Node*> visited;
            // bool goalFound = false;
            frontier.push(initialState);
            while(!frontier.empty()) {
                if (frontier.size() > maxQueueSize) {
                    maxQueueSize = frontier.size();
                }
                //check if top node visited or goal
                Node* curr = frontier.top();
                frontier.pop();

                curr -> Print();

                if(checkGoal(curr, this -> goalState)) {
                    // goalFound = true;
                    return curr -> cost;
                }

                nodesExpanded++;
                
                if(!checkVisited(curr, visited)) {
                    visited.push_back(curr);

                    //if not goal or visited: Run operators and add to frontier if not nullptr and not visited
                    if (up(curr) != nullptr) {
                        if (!checkVisited(up(curr), visited)){
                            frontier.push(up(curr));
                        }
                    }
                    if (left(curr) != nullptr) {
                        if (!checkVisited(left(curr), visited)){
                            frontier.push(left(curr));
                        }
                    }
                    if (down(curr) != nullptr) {
                        if (!checkVisited(down(curr), visited)){
                            frontier.push(down(curr));
                        }
                    }
                    if (right(curr) != nullptr) {
                        if (!checkVisited(right(curr), visited)){
                            frontier.push(right(curr));
                        }
                    }
                }
            }
            return -1;
        }

        int AstarEuclideanSearch(int &nodesExpanded, int &maxQueueSize) {
            priority_queue<Node*, vector<Node*>, EuclideanCompareCost> frontier;
            vector<Node*> visited;
            // bool goalFound = false;
            frontier.push(initialState);
            while(!frontier.empty()) {
                if (frontier.size() > maxQueueSize) {
                    maxQueueSize = frontier.size();
                }
                //check if top node visited or goal
                Node* curr = frontier.top();
                frontier.pop();

                curr -> Print();

                if(checkGoal(curr, this -> goalState)) {
                    // goalFound = true;
                    return curr -> cost;
                }

                nodesExpanded++;
                
                if(!checkVisited(curr, visited)) {
                    visited.push_back(curr);

                    //if not goal or visited: Run operators and add to frontier if not nullptr and not visited
                    if (up(curr) != nullptr) {
                        if (!checkVisited(up(curr), visited)){
                            frontier.push(up(curr));
                        }
                    }
                    if (left(curr) != nullptr) {
                        if (!checkVisited(left(curr), visited)){
                            frontier.push(left(curr));
                        }
                    }
                    if (down(curr) != nullptr) {
                        if (!checkVisited(down(curr), visited)){
                            frontier.push(down(curr));
                        }
                    }
                    if (right(curr) != nullptr) {
                        if (!checkVisited(right(curr), visited)){
                            frontier.push(right(curr));
                        }
                    }
                }
            }
            return -1;
        }

    public:
        Node* up(Node* currState) { //operator 1
            if (currState -> blank_row == 0) {
                return nullptr;
            }
            Node* newState = new Node(currState->matrix, currState -> cost + 1);
            
            newState -> Swap(currState -> blank_row, currState -> blank_column, currState -> blank_row - 1, currState -> blank_column);
            newState -> blank_row -= 1;
            
            return newState;
        }

        Node* down(Node* currState) { //operator 2
            if (currState -> blank_row == 2) {
                return nullptr;
            }
            Node* newState = new Node(currState->matrix, currState -> cost + 1);
            
            newState -> Swap(currState -> blank_row, currState -> blank_column, currState -> blank_row + 1, currState -> blank_column);
            newState -> blank_row += 1;
            
            return newState;
        }

        Node* left(Node* currState) { //operator 3
            if (currState -> blank_column == 0) {
                return nullptr;
            }
            Node* newState = new Node(currState->matrix, currState -> cost + 1);
            
            newState -> Swap(currState -> blank_row, currState -> blank_column, currState -> blank_row, currState -> blank_column - 1);
            newState -> blank_column -= 1;
            
            return newState;
        }

        Node* right(Node* currState) { //operator 4
            if (currState -> blank_column == 2) {
                return nullptr;
            }
            Node* newState = new Node(currState->matrix, currState -> cost + 1);
            
            newState -> Swap(currState -> blank_row, currState -> blank_column, currState -> blank_row, currState -> blank_column + 1);
            newState -> blank_column += 1;
            
            return newState;
        }

        bool checkVisited(Node* compareNode, vector<Node*> visited){ //1 if visited, 0 if not
            for (int i = 0; i < visited.size(); i++){
                bool isEqual = true;
                for (int j = 0; j < 3; j++){
                    for (int k = 0; k < 3; k++){
                        if (compareNode->matrix.at(j).at(k) != visited.at(i)->matrix.at(j).at(k)){
                            isEqual = false;
                        }
                    }
                }
                if (isEqual){
                    return true;
                }
            }
            return false;
        }

        bool checkGoal(Node* compareNode, Node* goal) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (compareNode -> matrix.at(i).at(j) != goal -> matrix.at(i).at(j)) {
                        return false;
                    }
                }
            }
            return true;
        }
};

#endif