/* A suduku solver program in C
 * input as much of a suduku as possible, and then the program will atempt to solve.
 * a work in progress by Luke Storry
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int US; // to save typing it out every time.

#include "../include/IO.h"
#include "../include/textybits.h"
#include "../include/solver.h"

int main (void) {
    US size *suduku;
    intro();
    printf("Hit <ENTER> to begin!"); getchar(); //getchar captures the enter>
    inputSize(&size);
    suduku = malloc(size * size * sizeof(US));
    inputSuduku(suduku, size);
    solveSuduku(suduku, size);

    printf("\n\n\n    Output:n\n");
    outputSuduku(suduku, size);
    return 0;
}

