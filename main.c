/* A suduko solver program in C
 * input as much of a suduko as possible, and then the program will atempt to solve.
 * a work in progress by Luke Storry
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void inputSize(int *rows, int *cols);
int *inputSuduko(int *suduko, int rows, int cols);
void ouputLine(int cols);
void inputRow(int cols);

int main (void) {
    int rows, cols;
    int *suduko;
    inputSize(&rows,&cols);
    inputSud(suduko,n, cols);
 
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

int *inputSuduku(int *suduko, int rows, int cols) {
    unsigned short i;
    suduko = malloc(n*m*sizeof(int));
    printf("Please enter your suduko puzzle below, row by row:\n");
    outputLine(cols);
    for ( i=0 ; i<rows ; i++ ) {
        suduko[i*cols] = inputRow(cols);
        outputLine(cols)
    };
    Thanks!
};

void outputLine(int cols) { //perhaps add a second argument for double lines?
    unsigned short i;
    for ( i = 0 ; i<cols ; i++ ) {
        printf("─");
    }
    printf("\n");
};

int *inputRow(int cols) {
    unsigned short j, *row;
    printf("|│")
    for (j=0 ; j<cols ; j++) {
        printf(" ")
        scanf(" %2u ", row[j])
        printf(" │")
    };
    printf("|")
    return row;
};

void outputSuduku (int* suduko, int rows, int cols) {
    unsigned short i;
    outputLine(cols);
    for ( i=0 ; i<rows ; i++ ) {
        outputRow(suduku+i, cols);
        outputLine(cols);
    };
};

void outputRow(int* row, int cols) {
    unsigned short j;
    printf("||")
    for (j=0 ; j<cols ; j++) {
            printf(" %u |",row[j])
        };
    printf("|")
};
