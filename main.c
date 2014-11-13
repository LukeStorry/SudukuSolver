/* A suduku solver program in C
 * input as much of a suduku as possible, and then the program will atempt to solve.
 * a work in progress by Luke Storry
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void inputSize(int *rows, int *cols);
void inputSuduku(int *suduku, int rows, int cols);
void inputRow(int *row, int cols);
void outputSuduku (int* suduku, int rows, int cols);
void outputLine(int cols); 
void outputRow(int* row, int cols);

int main (void) {
    int rows, cols, *suduku;
    inputSize(&rows,&cols);
    inputSuduku(suduku,rows, cols);
    printf("\n\n\n TestL: is this it? \n\n");
    outputSuduku(suduku,rows,cols);
    return 0;
}

void inputSize(int *rows, int *cols) {
    unsigned short input;
    printf("How many rows does the suduku have? ");
    scanf(" %2u ",input);
    *rows = input;
    printf("How many columns does the suduku have? ");
    scanf(" %2u ",input);
    *cols = input;
};

void inputSuduku(int *suduku, int rows, int cols) {
    unsigned short i;
    suduku = malloc(rows*cols*sizeof(int));
    printf("Please enter your suduku puzzle below, row by row:\n");
    outputLine(cols);
    for ( i=0 ; i<rows ; i++ ) {
        inputRow(&(suduku[i*rows]),cols);
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
