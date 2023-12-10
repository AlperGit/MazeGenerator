#include <stdio.h>
#include <stdlib.h>

#include "../Include-Files/Stack.h"
#include "../Include-Files/Maze.h"

int main()
{
    //Set grid size
    Vector2 gridSize;
    gridSize.x = 3;
    gridSize.y = 3;
    //Create a random starting position for x and y
    srand(0);
    Vector2 startingPos;
    startingPos.x = rand() % gridSize.x;
    startingPos.y = rand() % gridSize.y;
    //Create a random number cells to generate
    int amountCellsToGenerate = rand() % (gridSize.x * gridSize.y);
    
    //Initialize the maze array and assign memory
    initMaze(gridSize, startingPos, amountCellsToGenerate);
    //Generate maze with specified amount of cells
    //Display Maze on the screen
}