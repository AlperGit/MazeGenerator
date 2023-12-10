#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Include-Files/Stack.h"
#include "../Include-Files/Maze.h"

int main()
{
    //Set grid size
    Vector2 gridSize;
    gridSize.x = 4;
    gridSize.y = 4;
    //Create a random starting position for x and y
    srand(time(NULL));
    Vector2 startingPos;
    startingPos.x = rand() % gridSize.x;
    startingPos.y = rand() % gridSize.y;
    printf("Starting positions:\n");
    printf("X: %d\n", startingPos.x);
    printf("Y: %d\n", startingPos.y);
    //Create a random number cells to generate
    int size = gridSize.x * gridSize.y;
    printf("grid size: %d\n", size);
    int amountCellsToGenerate = rand() % size;
    printf("Amount of Cells to generate: %d\n", amountCellsToGenerate);
    //Initialize the maze array and assign memory
    int err_code = initMaze(gridSize, startingPos, amountCellsToGenerate);
    //CHeck if there was an error during initialization
    if(err_code != 0)
    {
        printf("There was an error during initialization\n");
        return 1;
    }
    //Generate maze with specified amount of cells
    generateMaze();
    //Display Maze on the screen
    displayMaze();
}