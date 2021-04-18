#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node{
 public:
    vector<vector<int>> matrix; //holds data in the node
    int column = 0;
    int row = 0;
    // Node* parent;
    
    Node(vector<vector<int>> Matrix) {
        this->matrix = Matrix;
        for (int i = 0; i < Matrix.size(); i++) {
            for (int j = 0; j < Matrix.at(i).size(); j++) {
                if(Matrix.at(i).at(j) == 0) {
                    row = i;
                    column = j;
                }
            }
        }
    }
    
    void Swap(int r1, int c1, int r2, int c2) {
        int temp = this -> matrix.at(r2).at(c2);
        matrix.at(r2).at(c2) = matrix.at(r1).at(c1);
        matrix.at(r1).at(c1) = temp;
    }

    void Print() {
        for (int i = 0; i < matrix.size(); i++) {
            cout << "{";
            for (int j = 0; j < matrix.at(i).size(); j++) {
                cout << matrix.at(i).at(j);
                if (j != matrix.at(i).size() - 1){
                    cout << " ";
                }
            }
            cout << "}";
            cout << endl;
        
        }

        cout << endl;
    }
};

#endif 