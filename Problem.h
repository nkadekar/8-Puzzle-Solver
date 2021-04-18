#ifndef PROBLEM_H
#define PROBLEM_H

#include <string>
#include "Node.h"

using namespace std;

class Problem {
    private:
        Node* initialState;
        Node* goalState;
    public:
        Problem(Node* initialState, Node* goalstate) {
            this->initialState = initialState;
            this->goalState = goalstate;
        }

        Node* up(Node* target) {
            if (target -> row == 0) {
                return nullptr;
            }
            Node* temp = new Node(target->matrix);
            
            temp -> Swap(target -> row, target -> column, target -> row - 1, target -> column);
            temp -> row -= 1; 
            
            return temp;
        }

        Node* down(Node* target) {
            if (target -> row == 2) {
                return nullptr;
            }
            Node* temp = new Node(target->matrix);
            
            temp -> Swap(target -> row, target -> column, target -> row + 1, target -> column);
            temp -> row += 1;
            
            return temp;
        }

        Node* left(Node* target) {
            if (target -> column == 0) {
                return nullptr;
            }
            Node* temp = new Node(target->matrix);
            
            temp -> Swap(target -> row, target -> column, target -> row, target -> column - 1);
            temp -> column -= 1;
            
            return temp;
        }

        Node* right(Node* target) {
            if (target -> column == 2) {
                return nullptr;
            }
            Node* temp = new Node(target->matrix);
            
            temp -> Swap(target -> row, target -> column, target -> row, target -> column + 1);
            temp -> column += 1;
            
            return temp;
        }
};

// {1 2 3}
// {4 * 6}
// {7 8 5}

#endif