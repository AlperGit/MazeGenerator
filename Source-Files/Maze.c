#include "../Include-Files/Maze.h"
#include "../Include-Files/Stack.h"
#include "../Include-Files/Typedef.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NEIGHBORS 4

//The size of the maze in x and y direction
static Vector2 gridSize;
//The starting position in the maze
static Vector2 startingPosition;
//The amount of cells to generate
static int amountOfCellsToGenerate;
//The maze as a 2 dimensional array
static Cell ** maze;

void resetCells()
{
    //Loop through the elements of the maze
    for (int i = 0; i < gridSize.y; i++)
    {
        for (int j = 0; j < gridSize.x; j++)
        {
            maze[i][j].visited = false;
            maze[i][j].position.y = i;
            maze[i][j].position.x = j;
        }
        
    }
}

int initMaze(Vector2 grid_size, Vector2 starting_position, int amount_of_cells_to_generate)
{
    //Init all variables
    gridSize = grid_size;
    startingPosition = starting_position;
    amountOfCellsToGenerate = amount_of_cells_to_generate;
    //initialize the first dimension of the array with y as its "height"
    maze = (Cell **) malloc(gridSize.y * sizeof(Cell *));
    //Initialize the second dimension of the array with x as its "width"
    for(int i = 0; i < gridSize.x; i++)
    {
        maze[i] = (Cell *) malloc(gridSize.x * sizeof(Cell));
    }
    resetCells();
    srand(time(NULL));
    return 0;
}

void displayMaze()
{
    //Loop through the elements of the maze
    for (int i = 0; i < gridSize.y; i++)
    {
        for (int j = 0; j < gridSize.x; j++)
        {
            if( i == startingPosition.y && j == startingPosition.x)
            {
                printf("S");
            }
            else if (maze[i][j].visited)
            {
                printf("C");
            }
            else
            {
                printf(" ");
            }
            
        }
        printf("\n");
        
    }
}

bool isXInBounds(int xPosition)
{
    if(xPosition >= 0 && xPosition <gridSize.x)
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

bool isInBounds(Vector2 position)
{
    if (isXInBounds(position.x) && isYInBounds(position.y))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void getNeighbors(Cell ** neigbors, int * amountNeigbors, Cell currentCell)
{
    //Set amount Neigbors to 0
    *amountNeigbors = 0;
    //Set position of all possible neighbors
    Vector2 up = currentCell.position;
    up.y += 1;
    Vector2 down = currentCell.position;
    down.y -= 1;
    Vector2 right = currentCell.position;
    right.x += 1;
    Vector2 left = currentCell.position;
    left.x -= 1;
    //Check if the upper cell is in bounds
    if(isInBounds(up))
    {
        //Check if the cell was already visited
        if(!maze[up.y][up.x].visited)
        {
            neigbors[*amountNeigbors] = &maze[up.y][up.x];
            *amountNeigbors+=1;
        }
    }
    if(isInBounds(right))
    {
        if(!maze[right.y][right.x].visited)
        {
            neigbors[*amountNeigbors] = &maze[right.y][right.x];
            *amountNeigbors+=1;
        }
    }
    if(isInBounds(down))
    {
        if(!maze[down.y][down.x].visited)
        {
            neigbors[*amountNeigbors] = &maze[down.y][down.x];
            *amountNeigbors+=1;
        }
    }
    if(isInBounds(left))
    {
        if(!maze[left.y][left.x].visited)
        {
            neigbors[*amountNeigbors] = &maze[left.y][left.x];
            *amountNeigbors+=1;
        }
    }
}

int generateMaze()
{
    //Tracks how many Cells have been visited in total
    int visitedCells = 0;
    int amountNeighbors = 0;
    //Set the currentCell of the maze
    Cell * currentCell = &maze[startingPosition.y] [startingPosition.x];
    //Neigbors of the current cell is always the size of 4
    Cell ** neighbors = (Cell ** ) malloc(sizeof(Cell *) * MAX_NEIGHBORS);
    while (visitedCells < amountOfCellsToGenerate)
    {
        //Set the current cell as visited
        currentCell->visited = true;
        //Get the current neighbors  that were not visited and store them in an array
        getNeighbors(neighbors, &amountNeighbors,*currentCell);
        //IF there is more than one neighbor randomly select one of those available neighbors
        if (amountNeighbors > 0)
        {
            int randomIndex = rand() % amountNeighbors;
            //Add current cell to the stack and set the selected neigbor as the current cell
            push(*currentCell);
            currentCell = neighbors[randomIndex];
            visitedCells +=1;
        }
        else
        {
            //If not get the newest element on the stack and set this as the current one
            *currentCell = pop();
        }
        
    }
    
}
