#include <stdio.h>
#include "../Include-Files/Stack.h"

int main()
{
    Cell cellA;
    cellA.position.x = 0;
    cellA.position.y = 0;

    Cell cellB;
    cellB.position.x = 5;
    cellB.position.y = 5;

    printf("Is Empty: %d\n", isempty());
    push(cellB);
    push(cellA);
    printf("%f:%f \n", peek().position.x, peek().position.y);
    printf("Is Full: %d\n", isfull());
    
}