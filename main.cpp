#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <sstream>

#include "Node.h"
#include "Problem.h"
#include "Heuristic.h"

using namespace std;

int main() {
    vector<vector<int>> goal = {{1,2,3}, {4,5,6}, {7,8,0}}; //goal vector
    vector<vector<int>> default_puzzle = {{1,0,3}, {4,2,6}, {7,5,8}}; //default puzzle assigned
    vector<vector<int>> custom_initial_vec; //vector for userinput
    Node* goalState = new Node(goal, 0, nullptr); //
    bool isCustom = false;
    
    cout << "Welcome to 862142793 & 862146661 8 puzzle solver." << endl << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;

    int userInput;

    cin >> userInput;

    while (userInput != 1 && userInput != 2) { //avoids invalid input
        cout << "Please re-enter a valid answer\n";
        cin >> userInput;
    }

    //isCustom is automatically set to false so if the user enters 1, the default puzzle will be automatically set

    if (userInput == 2) { //grabs 3 sets of 3 numbers that are pushed into a vector of vectors to end up with a matrix of 3 by 3
        cout << "Enter your puzzle, use a zero to represent the blank\nEnter the first row, use space or tabs between numbers\n";
        stringstream ssin;
        int lineInteger;
        string userInput2;
        vector<int> firstRow;
        vector<int> secondRow;
        vector<int> thirdRow;
        cin.ignore(); //skip \n character
        getline(cin, userInput2);
        ssin << userInput2;

        while(ssin >> lineInteger) {
            firstRow.push_back(lineInteger);
        }

        ssin.clear();
        cout << "Enter the second row, use space or tabs between numbers\n";
        getline(cin, userInput2);
        ssin << userInput2;

        while(ssin >> lineInteger) {
            secondRow.push_back(lineInteger);
        }

        ssin.clear();
        cout << "Enter the third row, use space or tabs between numbers\n";
        getline(cin, userInput2);
        ssin << userInput2;

        while(ssin >> lineInteger) {
            thirdRow.push_back(lineInteger);
        }
        custom_initial_vec.push_back(firstRow);
        custom_initial_vec.push_back(secondRow);
        custom_initial_vec.push_back(thirdRow);
        isCustom = true;
    }
    
    Node* initialState = nullptr;
    if (isCustom) {
        initialState = new Node(custom_initial_vec, 0, nullptr); //use custom puzzle if '2' is inputed
    }
    else {
        initialState = new Node(default_puzzle, 0, nullptr); //use default if '1' is inputed
    }
    cout << "Select algorithm. (1) for Uniform Cost Search, (2) for the Misplaced Tile Heuristic, or (3) the Eucledian Distance Heuristic.\n";
    cin.clear(); //clear cin buffer
    int algoChoice;
    cin >> algoChoice;

    while (algoChoice != 1 && algoChoice != 2 && algoChoice !=3) {
        cout << "Please re-enter a valid answer\n";
        cin >> userInput;
    }

    Problem* puzzle = new Problem(initialState, goalState);

    int maxQueueSize = 0; 
    int nodesExpanded = 0; 

    if (algoChoice == 1){ //(1) for Uniform Cost Search, (2) for the Misplaced Tile Heuristic, or (3) the Eucledian Distance Heuristic
        puzzle -> UniformCostSearch(nodesExpanded, maxQueueSize);
    }
    else if (algoChoice == 2){
        puzzle -> AStarMissingTileSearch(nodesExpanded, maxQueueSize);
    }
    else if (algoChoice == 3){
        puzzle -> AstarEuclideanSearch(nodesExpanded, maxQueueSize);
    }
    
    cout << "Number of nodes expanded: " << nodesExpanded << endl;
    cout << "Max Queue Size: " << maxQueueSize << endl;

    return 0;
}