#include <stdio.h>
#include <stdlib.h>

#include "../Include-Files/Maze.h"
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

int initMaze(Vector2 grid_size, Vector2 starting_position, int amount_of_cells_to_generate)
{
    //Check if amount of cells to generate exceeds gridsize
    int sizeToCheck = gridSize.x * gridSize.y;
    //Is the amount of cells to generate bigger than the grid size
    if (sizeToCheck > amount_of_cells_to_generate)
    {
        //Yes return amount of cells to big error
        return 1;
    }
    //Initialize maze
    gridSize = grid_size;
    startingPosition = starting_position;
    amountOfCellsToGenerate = amount_of_cells_to_generate;
    //Initialize the maze for a specific memory amount to fit the complete grid
    maze = malloc(sizeof(Cell) * gridSize.x * gridSize.y);

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

void resetCells()
{
    //Iterate over complete maze length
    for (int i = 0; i < (gridSize.x * gridSize.y); i++)
    {
        Cell newCell;
        //Get the right position of the cell in x direction
        //The x position is the res
        newCell.position.x = i % gridSize.x;
        newCell.position.y = i / gridSize.y;
        newCell.visited = false;
        maze[i] = newCell;
    }   
}

void displayMaze()
{
    printf("Maze:\n");
    //Iterate over complete maze length
    for (int i = 0; i < (gridSize.x * gridSize.y); i++)
    {
        //Add a linebreak whenever there is a new line
        if( i > 0 && i % gridSize.x == 0)
        {
            printf("\n");
        }
        //If the Cell has been visited print a C else a X
        if (maze[i].visited)
        {
            printf("C");
        }
        else
        {
            printf("X");
        }
    }
    printf("\n");
}

//Return the cell that is defined from position
Cell * getMazeCellFromPosition(Vector2 position)
{
    int index = 0;
    index = (position.y * gridSize.y) + position.x;
    return &maze[index];
}

int generateMaze()
{
    //Initialize the cell stack to be used as the path that was taken
    //Set amount of cells to be generated to 0
    int generatedCells = 0;

    //Reset the cells so they are not visited and have appropriate position
    resetCells();

    //Get the current cell that is used from starting position
    Cell * p_currentCell = getMazeCellFromPosition(startingPosition);
    Cell currentCell = *p_currentCell;

    //Create the route for this maze to be solvable
    while (generatedCells < amountOfCellsToGenerate)
    {
        //Set the current cell as visited
        currentCell.visited = true;
        //Find all possible neighbors of this cell
        //Randomly select one of these neighbors
        //Is one o
    }
    

}