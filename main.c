/* A suduku solver program in C
 * input as much of a suduku as possible, and then the program will atempt to solve.
 * a work in progress by Luke Storry
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned short US;

void inputSize(US *rows, US *cols);
void inputSuduku(US *suduku, US rows, US cols);
void inputRow(US *row, US cols);
void outputSuduku (US* suduku, US rows, US cols);
void outputLine(US cols); 
void outputRow(US* row, US cols);

int main (void) {
    US rows, cols, *suduku;
    inputSize(&rows,&cols);
    suduku = malloc(rows*cols*sizeof(US));
    inputSuduku(suduku,rows, cols);
    printf("\n\n\n TestL: is this it? \n\n");
    outputSuduku(suduku,rows,cols);
    return 0;
}

void inputSize(US *rows, US *cols) {
    printf("How many rows does the suduku have? ");
    scanf("%hu",rows);
    printf("How many columns does the suduku have? ");
    scanf("%hu",cols);
    printf("\n");
};

void inputSuduku(US *suduku, US rows, US cols) {
    US i;
    printf("Please enter your suduku puzzle below, hitting <ENTER> after each number:\n");
    outputLine(cols);
    for ( i=0 ; i<rows ; i++ ) {
        inputRow(&(suduku[i*rows]),cols);
        outputLine(cols);
    };
    printf("Thanks!");
};

void inputRow (US *row, US cols) {
    US j, c, chars;
    for (j=0 ; j<cols ; j++) {
        outputRow(row,j);
        chars = scanf(" %hu ", &(row[j]));
        printf("\33[2K\r"); //VT100 code to erase previous line
    };
};

void outputSuduku (US* suduku, US rows, US cols) {
    US i;
    outputLine(cols);
    for ( i=0 ; i<rows ; i++ ) {
        outputRow(suduku+i, cols);
        outputLine(cols);
    };
};

void outputLine (US cols) { //perhaps add a second argument for double lines?
    US i;
    for ( i = 0 ; i<cols*4 ; i++ ) {
        printf("─");
    }
    printf("\n");
};

void outputRow (US* row, US cols) {
    US j;
    printf("||");
    for (j=0 ; j<cols ; j++) {
            printf(" %u |",row[j]);
        };
    printf("|");
};
