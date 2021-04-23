#include <iostream>
#include <vector>
#include <tuple>
#include <utility>

#include "Node.h"
#include "Problem.h"
#include "Heuristic.h"

using namespace std;

int main() {

    vector<vector<int>> goal = {{1,2,3}, {4,5,6}, {7,8,0}};
    vector<vector<int>> inState = {{1,2,0}, {4,5,3}, {7,8,6}};
    vector<vector<int>> impossible = {{1,2,3}, {4,5,6}, {8,7,0}};
    vector<vector<int>> doable = {{0,1,2}, {4,5,3}, {7,8,6}};
    vector<vector<int>> ohboy = {{8,7,1}, {6,0,2}, {5,4,3}};

    Node* initState = new Node(inState, 0);
    Node* goalState = new Node(goal, 0);

    Node* impState = new Node(impossible, 0);
    Node* doableState = new Node(doable, 0);
    Node* ohBoyState = new Node(ohboy, 0);

    Problem* puzzle = new Problem(doableState, goalState);

    // cout << "Initial State" << endl;
    // initState -> Print();
    // cout << "Column = " << initState -> blank_column << endl;
    // cout << "Row = " << initState -> blank_row << endl;

    // cout << "Goal State" << endl;
    // goalState -> Print();
    // cout << "Column = " << goalState -> blank_column << endl;
    // cout << "Row = " << goalState -> blank_row << endl;


    // cout << "After one down, up" << endl;

    // // puzzle -> up(puzzle -> down(initState)) -> Print();
    
    // // puzzle -> initialState -> Print();


    // cout << puzzle -> UniformCostSearch();


    vector<vector<int>> test = {{3,2,8}, {4,5,6}, {7,1,0}};
    Node* testState = new Node(test, 0);
    Heuristic* heuristic = new MisplacedTileHeuristic();
    cout << heuristic->runHeuristic(testState, goalState) << endl;

    return 0;
}