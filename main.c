/* A suduku solver program in C
 * input as much of a suduku as possible, and then the program will atempt to solve.
 * a work in progress by Luke Storry
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef unsigned short US;

void inputSize (US *rows, US *cols);
void inputSuduku (US *suduku, US rows, US cols);
void inputRow (US *row, US cols);
void outputSuduku (US* suduku, US rows, US cols);
void outputLine(US cols); 
void outputRow (US* row, US cols);
void outputPartSuduku (US *suduku, US cols, US currentRow, US currentCol);


int main (void) {
    US rows, cols, *suduku;
    inputSize(&rows,&cols);
    suduku = malloc(rows*cols*sizeof(US));
    inputSuduku(suduku,rows, cols);
    printf("\n\n\n TestL: is this it? \n\n");
    outputSuduku(suduku,rows,cols);
    return 0;
}

void inputSize (US *rows, US *cols) {
    printf("How many rows does the suduku have? ");
    scanf("%hu",rows);
    printf("How many columns does the suduku have? ");
    scanf("%hu",cols);
    printf("\n");
};


void inputSuduku (US *suduku, US rows, US cols) {
    US i, j;
    outputLine(cols);
    for ( i=0 ; i<rows ; i++ ) {
        for (j=0 ; j<cols ; j++) {
            system("clear");
            printf("Please enter your suduku puzzle below, hitting <ENTER> after each number:\n");
	    outputPartSuduku(suduku,cols, i, j);
	    scanf("%hu", &(suduku[i*cols+j]));
	};
    };
    printf("Thanks!");
};


void outputPartSuduku (US *suduku, US cols, US currentRow, US currentCol) {
    US k;
    outputLine(cols);
    for ( k=0 ; k < currentRow ; k++) {
	 outputRow(&(suduku[k*cols]), cols);
	 outputLine(cols);
    };
    outputRow(&(suduku[currentRow*cols]), currentCol);
};
       
        
void outputSuduku (US* suduku, US rows, US cols) {
    US i;
    outputLine(cols);
    for ( i=0 ; i<rows ; i++ ) {
        outputRow(&suduku[i*cols], cols);
        outputLine(cols);
    };
};


void outputLine (US cols) { //perhaps add a second argument for double lines?
    US i;
    printf("\n");
    for ( i = 0 ; i<cols*4 ; i++ ) {
        printf("─");
    }
    printf("\n");
};


void outputRow (US* row, US cols) {
    US j;
    printf("||");
    for (j=0 ; j<cols ; j++) {
            printf(" %hu |",row[j]);
        };
};
