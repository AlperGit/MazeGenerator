#pragma once
#include "Typedef.h"
//The maximum size of the stack
#define MAXSIZE 1024


//Is the stack currently empty
int isempty();

/* Check if the stack is full */
int isfull();

/* Function to return the topmost element in the stack */
Cell peek();

/* Function to delete from the stack */
Cell pop();

/* Function to insert into the stack */
Cell push(Cell data);