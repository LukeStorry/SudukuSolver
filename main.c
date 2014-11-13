/* A suduko solver program in C
 * input as much of a suduko as possible, and then the program will atempt to solve.
 * a work in progress by Luke Storry
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void inputSize(int *n, int *cols);
int *inputSud(int *suduko, int n, int cols);
 

int main (void) {
    int n, cols;
    int *suduko;
    inputSize(&n,&cols);
    inputSud(suduko,n, cols);
 
    return 0;
}

void inputSize(int *n, int *cols) {
    
    
};

int *inputSud(int *suduko, int n, int m) {
    int ;
    suduko = malloc(n*m*sizeof(int));
    printf("Please enter your suduko puzzle below, row by row");
    for (i=0, i<)
    intpoutrow(*)
