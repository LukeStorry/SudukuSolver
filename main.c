/* A suduko solver program in C
 * input as much of a suduko as possible, and then the program will atempt to solve.
 * a work in progress by Luke Storry
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void inputSize(int *rows, int *cols);
void inputSuduku(int *suduko, int rows, int cols);
void inputRow(int *row, int cols);
void outputSuduku (int* suduko, int rows, int cols);
void outputLine(int cols); 
void outputRow(int* row, int cols);

int main (void) {
    int rows, cols, *suduko;
    inputSize(&rows,&cols);
    inputSuduku(suduko,rows, cols);
    printf("\n\n\n TestL: is this it? \n\n")
    outputSuduku(suduku,rows,cols)
    return 0;
}

void inputSize(int *rows, int *cols) {
    unsigned short input;
    printf("How many rows does the suduko have? ");
    scanf(" %2u ",input);
    *rows = input;
    printf("How many columns does the suduko have? ");
    scanf(" %2u ",input);
    *cols = input;
};

void inputSuduku(int *suduko, int rows, int cols) {
    unsigned short i;
    suduko = malloc(rows*cols*sizeof(int));
    printf("Please enter your suduko puzzle below, row by row:\n");
    outputLine(cols);
    for ( i=0 ; i<rows ; i++ ) {
        inputRow(&(suduko[i*rows]),cols);
        outputLine(cols);
    };
    printf("Thanks!");
};

void inputRow(int *row, int cols) {
    unsigned short j;
    printf("|│");
    for (j=0 ; j<cols ; j++) {
        printf(" ");
        scanf(" %2u ", row[j]);
        printf(" │");
    };
    printf("|");
};

void outputSuduku (int* suduku, int rows, int cols) {
    unsigned short i;
    outputLine(cols);
    for ( i=0 ; i<rows ; i++ ) {
        outputRow(suduku+i, cols);
        outputLine(cols);
    };
};

void outputLine(int cols) { //perhaps add a second argument for double lines?
    unsigned short i;
    for ( i = 0 ; i<cols ; i++ ) {
        printf("─");
    }
    printf("\n");
};

void outputRow(int* row, int cols) {
    unsigned short j;
    printf("||");
    for (j=0 ; j<cols ; j++) {
            printf(" %u |",row[j]);
        };
    printf("|");
};
