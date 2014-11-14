/* A suduku solver program in C
 * input as much of a suduku as possible, and then the program will atempt to solve.
 * a work in progress by Luke Storry
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int US; // to save typing it out every time.

#include "../include/IO.h"
#include "../include/textybits.h"


int main (void) {
    US rows, cols, *suduku;
    intro();
    printf("Hit <ENTER> to begin!"); getchar(); //getchar captures the enter>
    inputSize(&rows, &cols);
    suduku = malloc(rows * cols * sizeof(US));
    inputSuduku(suduku, rows, cols);

    //solve it...

    printf("\n\n\n    Output:n\n");
    outputSuduku(suduku,rows,cols);
    return 0;
}

