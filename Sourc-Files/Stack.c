#include <stdio.h>
#include <stdlib.h>

#include "../Include-Files/Stack.h"
#include "Typedef.h"
//The maximum size of the stack
#define MAXSIZE 1024


//The cell stack that is used 
Cell stack[MAXSIZE];
int top = -1;

/* Check if the stack is empty */
int isempty(){
   if(top == -1)
      return 1;
   else
      return 0;
}

/* Check if the stack is full */
int isfull(){
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

/* Function to return the topmost element in the stack */
Cell peek(){
   return stack[top];
}

/* Function to delete from the stack */
Cell pop(){
   Cell data;
   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

/* Function to insert into the stack */
Cell push(Cell data){
   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}