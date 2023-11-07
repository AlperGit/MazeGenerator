#include <stdio.h>

#include "../Include-Files/Stack.h"
#include "../Include-Files/Typedef.h"

//The size defines the size of the grid that will be generated in x and y direction
Vector2 gridSize;
//This is the exit condition for the mazegenerator
int amountOfCellsToGenerate;
//The starting Position is the index of the cells List which will be generated.
Vector2 startingPosition;
//The minimum amount of cells consist of a startcell and an end cell
const int minimumAmountCells = 2;
//The maze as a two dimensional array is initialized in init
Cell * maze;

int initMaze(Vector2 grid_size, Vector2 starting_position, int amount_of_cell_to_generate)
{
    //Check if amount of cells to generate exceeds gridsize
    int sizeToCheck = gridSize.x * gridSize.y;
    if (sizeToCheck < amount_of_cell_to_generate)
    {
        return 1;
    }
    //Initialize maze
    gridSize = grid_size;
    startingPosition = starting_position;
    amountOfCellsToGenerate = amount_of_cell_to_generate;
    //Initialize the maze as a 2dim array
    maze = malloc(sizeof(*maze) * gridSize.x * gridSize.y);

    return 0;
}


bool isXInBounds(int xPosition)
{
    if(xPosition >= 0 && xPosition < gridSize.x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isYInBounds(int yPosition)
{
    if(yPosition >= 0 && yPosition < gridSize.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isInBounds(int xPosition, int yPosition)
{
    if(isXInBounds(xPosition) && isYInBounds(yPosition))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int generateMaze()
{
    //Initialize the cell stack to be used as the path that was taken
    int generatedCells = 0;

    Cell currentCell;

    //currentCell = maze[startingPosition.x * gridSize.x + gridSize.y];

    //Generate the cells for this maze
    while (generatedCells < amountOfCellsToGenerate)
    {
        //Set the current cell as visited

    }
    
    

}