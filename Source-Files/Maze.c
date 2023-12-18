#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Include-Files/Maze.h"
#include "../Include-Files/Stack.h"
#include "../Include-Files/Typedef.h"

#define MAX_NEIGHBORS 4

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

/// @brief Return up, right, down and left position from this cell if in bounds
/// @param currentCell The current cell to retrieve the neighbors
/// @param neigbors The neigbors as an array sorted: up, right, down and left
/// @param neighborCount The amount of neighbors to this cell
/// @return True if there are neigbors for this cell else false
bool findAllPossibleNeighbors(Cell currentCell, Cell * neigbors, int * neighborCount)
{
    //Set the initial amount of neighbors to 0
    *neighborCount = 0;
    Vector2 posUp;
    Vector2 posRight;
    Vector2 posDown;
    Vector2 posLeft;
    //Set the upper position
    posUp.x = currentCell.position.x;
    posUp.y = currentCell.position.y + 1;

    posRight.x = currentCell.position.x + 1;
    posRight.y = currentCell.position.y;

    posDown.x = currentCell.position.x;
    posDown.y = currentCell.position.y - 1;

    posLeft.x = currentCell.position.x - 1;
    posLeft.y = currentCell.position.y;

    //Check if upper position would be in bounds of playing field
    if (isInBounds(posUp.x, posUp.y))
    {
        //Get the cell from upper position and return it
        Cell * cellFromPosition = getMazeCellFromPosition(posUp);
        //Check if cell has not been visited then add it as a neigbor
        if(!cellFromPosition->visited)
        {
            //Assign Cell as a neigbor of this position and return it.
            neigbors[*neighborCount] = *cellFromPosition;
            *neighborCount += 1;
        }
    }

    if (isInBounds(posRight.x, posRight.y))
    {
        //Get the cell from upper position and return it
        Cell * cellFromPosition = getMazeCellFromPosition(posRight);
        //Check if cell has not been visited then add it as a neigbor
        if(!cellFromPosition->visited)
        {
            //Assign Cell as a neigbor of this position and return it.
            neigbors[*neighborCount] = *cellFromPosition;
            *neighborCount += 1;
        }
    }

    if (isInBounds(posDown.x, posDown.y))
    {
        //Get the cell from upper position and return it
        Cell * cellFromPosition = getMazeCellFromPosition(posDown);
        //Check if cell has not been visited then add it as a neigbor
        if(!cellFromPosition->visited)
        {
            //Assign Cell as a neigbor of this position and return it.
            neigbors[*neighborCount] = *cellFromPosition;
            *neighborCount += 1;
        }
    }

    if (isInBounds(posLeft.x, posLeft.y))
    {
        //Get the cell from upper position and return it
        Cell * cellFromPosition = getMazeCellFromPosition(posLeft);
        //Check if cell has not been visited then add it as a neigbor
        if(!cellFromPosition->visited)
        {
            //Assign Cell as a neigbor of this position and return it.
            neigbors[*neighborCount] = *cellFromPosition;
            *neighborCount += 1;
        }
    }

    //If Count of neighbor cell is higher than 0 return true else false
    if(neighborCount > 0)
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
    //Set amount of cells to be generated to 0
    int generatedCells = 0; 
    //Empty the stack so it can be started fresh
    resetStack();
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
        Cell neighbors[MAX_NEIGHBORS];
        //Amount of found neigbors
        int neigborCount = 0;
        int * p_neighborCount = &neigborCount;
        //Check if there are neighbors for this cell
        bool foundNeighbors = findAllPossibleNeighbors(currentCell, neighbors, p_neighborCount);
        //If amount of neighbors is 0 that means the path has found a dead end
        if (foundNeighbors == false)
        {
            //Remove last cell from the path stack and set it as the new cell
            currentCell = pop();
        }
        //Else
        else
        {
            //Randomly select one of these as the next Cell 
            srand(time(NULL));
            int nextIndex = rand() % neigborCount;
            //Add current cell to the path stack
            push(currentCell);
            //Set new cell from randomly selected Index
            currentCell = neighbors[nextIndex];
            //Increase the generated cells amount
            generatedCells++;
        }

    }
    

}