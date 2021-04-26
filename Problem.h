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
            priority_queue<Node*, vector<Node*>, CompareCost> frontier; //priority queue
            vector<Node*> visited;  //vector that keeps tracks of nodes already visited
            frontier.push(initialState); //push initial state into the frontier
            while(!frontier.empty()) {  
                if (frontier.size() > maxQueueSize) { //check if current frontier queue is bigger then assign to maxQueueSize
                    maxQueueSize = frontier.size();
                }
                
                // pull from frontier and pop it off from the priority queue
                Node* curr = frontier.top();
                frontier.pop();

                curr -> Print();

                if(checkGoal(curr, this -> goalState)) { //check if top node visited or goal
                    printSolution(curr);
                    return curr -> cost;
                }

                nodesExpanded++; // counter for nodes explored
                
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
            vector<Node*> visited;  //vector that keeps tracks of nodes already visited
            frontier.push(initialState); //push initial state into the frontier
            while(!frontier.empty()) {  
                if (frontier.size() > maxQueueSize) { //check if current frontier queue is bigger then assign to maxQueueSize
                    maxQueueSize = frontier.size();
                }
                
                // pull from frontier and pop it off from the priority queue
                Node* curr = frontier.top();
                frontier.pop();

                curr -> Print();

                if(checkGoal(curr, this -> goalState)) { //check if top node visited or goal
                    printSolution(curr);
                    return curr -> cost;
                }

                nodesExpanded++; // counter for nodes explored
                
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
            vector<Node*> visited;  //vector that keeps tracks of nodes already visited
            frontier.push(initialState); //push initial state into the frontier
            while(!frontier.empty()) {  
                if (frontier.size() > maxQueueSize) { //check if current frontier queue is bigger then assign to maxQueueSize
                    maxQueueSize = frontier.size();
                }
                
                // pull from frontier and pop it off from the priority queue
                Node* curr = frontier.top();
                frontier.pop();

                curr -> Print();

                if(checkGoal(curr, this -> goalState)) { //check if top node visited or goal
                    printSolution(curr);
                    return curr -> cost;
                }

                nodesExpanded++; // counter for nodes explored
                
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

    private: //Helper functions
        Node* up(Node* currState) { //operator 1 (moving up)
            if (currState -> blank_row == 0) {
                return nullptr;
            }
            Node* newState = new Node(currState->matrix, currState -> cost + 1, currState);
            
            newState -> Swap(currState -> blank_row, currState -> blank_column, currState -> blank_row - 1, currState -> blank_column);
            newState -> blank_row -= 1;
            
            return newState;
        }

        Node* down(Node* currState) { //operator 2 (moving down)
            if (currState -> blank_row == 2) {
                return nullptr;
            }
            Node* newState = new Node(currState->matrix, currState -> cost + 1, currState);
            
            newState -> Swap(currState -> blank_row, currState -> blank_column, currState -> blank_row + 1, currState -> blank_column);
            newState -> blank_row += 1;
            
            return newState;
        }

        Node* left(Node* currState) { //operator 3 (moving left)
            if (currState -> blank_column == 0) {
                return nullptr;
            }
            Node* newState = new Node(currState->matrix, currState -> cost + 1, currState);
            
            newState -> Swap(currState -> blank_row, currState -> blank_column, currState -> blank_row, currState -> blank_column - 1);
            newState -> blank_column -= 1;
            
            return newState;
        }

        Node* right(Node* currState) { //operator 4 (moving right)
            if (currState -> blank_column == 2) {
                return nullptr;
            }
            Node* newState = new Node(currState->matrix, currState -> cost + 1, currState);
            
            newState -> Swap(currState -> blank_row, currState -> blank_column, currState -> blank_row, currState -> blank_column + 1);
            newState -> blank_column += 1;
            
            return newState;
        }

        bool checkVisited(Node* compareNode, vector<Node*> visited){ //checks if a node is in the visited list. Returns 1 if visited, 0 if not
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

        bool checkGoal(Node* compareNode, Node* goal) { //checks if a node is the goal state
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (compareNode -> matrix.at(i).at(j) != goal -> matrix.at(i).at(j)) {
                        return false;
                    }
                }
            }
            return true;
        }

        void printSolution(Node* curr){ //prints the solution path recursively using parent pointers
            if (curr -> parent == nullptr){
                cout << "This is the solution path: " << endl;
            }
            else {
                printSolution(curr -> parent);
            }
            curr -> Print();

        }
};

#endif