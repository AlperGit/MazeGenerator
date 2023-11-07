#pragma once
#include <stdbool.h>
//Structs
//A structure to safe the x and y direction.
struct vector2
{
    float x;
    float y;
};
//The typedefinition for the vector2
typedef struct vector2 Vector2;

//Base for an entry of the maze
struct cell
{
    //Has this cell been visited before?
    bool visited;
    //The position of the cell in x and y direction
    Vector2 position;
};

typedef struct cell Cell;
