# CS170 - Project 1

* Instructions

    * Open bash, command prompt, any terminal
    * Run g++ *.cpp on the correct destination folder
    * Run ./a.exe (./a.out if on mac)
    * Default puzzle is {{1,0,3}, {4,2,6}, {7,5,8}}

* Example Output: 
```
Welcome to 862142793 & 862146661 8 puzzle solver.
Type "1" to use a default puzzle, or "2" to enter your own puzzle.
1
Select algorithm. (1) for Uniform Cost Search, (2) for the Misplaced Tile Heuristic, or (3) the Eucledian Distance Heuristic.
1
{1 0 3}
{4 2 6}
{7 5 8}

{0 1 3}
{4 2 6}
{7 5 8}

{1 2 3}
{4 0 6}
{7 5 8}

{1 3 0}
{4 2 6}
{7 5 8}

{1 2 3}
{0 4 6}
{7 5 8}

{1 2 3}
{4 6 0}
{7 5 8}

{1 3 6}
{4 2 0}
{7 5 8}

{4 1 3}
{0 2 6}
{7 5 8}

{1 2 3}
{4 5 6}
{7 0 8}

{1 2 3}
{7 4 6}
{0 5 8}

{1 3 6}
{4 0 2}
{7 5 8}

{4 1 3}
{2 0 6}
{7 5 8}

{1 2 3}
{4 5 6}
{7 8 0}

This is the solution path:
{1 0 3}
{4 2 6}
{7 5 8}

{1 2 3}
{4 0 6}
{7 5 8}

{1 2 3}
{4 5 6}
{7 0 8}

{1 2 3}
{4 5 6}
{7 8 0}

Number of nodes expanded: 12
Max Queue Size: 14
```