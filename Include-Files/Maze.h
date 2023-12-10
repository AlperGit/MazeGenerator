#pragma once

#include "Typedef.h"

/* -------------------------------Function Prototypes----------------------------------- */
int initMaze(Vector2 grid_size, Vector2 starting_position, int amount_of_cells_to_generate);

bool isXInBounds(int xPosition);

bool isYInBounds(int yPosition);

bool isInBounds(int xPosition, int yPosition);

void displayMaze();

int generateMaze();

