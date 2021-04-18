#include <iostream>
#include "Node.h"
#include "Problem.h"
#include <vector>
#include <tuple>

using namespace std;

// Node uniformSearch(Problem* problem) {



// }

int main() {

    
    vector<vector<int>> inState = {{1,2,0}, {4,5,3}, {7,8,6}};

    Node* initState = new Node(inState);

    cout << "Initial State" << endl;
    initState -> Print();
    cout << "Column = " << initState -> column << endl;
    cout << "Row = " << initState -> row << endl;

    vector<vector<int>> goal = {{1,2,3}, {4,5,6}, {7,8,0}};

    Node* goalState = new Node(goal);

    cout << "Goal State" << endl;
    goalState -> Print();
    cout << "Column = " << goalState -> column << endl;
    cout << "Row = " << goalState -> row << endl;

    Problem* puzzle = new Problem(initState, goalState);

    cout << "After one down, up" << endl;

    puzzle -> up(puzzle -> down(initState)) -> Print();
    
    // puzzle -> initialState -> Print();






    return 0;
}