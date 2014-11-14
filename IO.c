//These functions read in and output suduku files to/from BASH.

#include <stdio.h>
#include <stdlib.h>


typedef enum { false, true } bool;; //because I dont want to type the std99 gcc tag every time

typedef unsigned short US;

#include "IO.h"

void inputSuduku (US *suduku, US rows, US cols) {
    US i, j;
    inputSize(&rows, &cols);
    suduku = malloc(rows*cols*sizeof(US));
    for ( i=0 ; i<rows ; i++ ) {
        for (j=0 ; j<cols ; j++) {
            do {
		system("clear");
		intro();
		printf("Please enter your suduku puzzle below, hitting <ENTER> after each number:\n");
		outputPartSuduku(suduku,cols, i, j);

	    } while (validateInput(&(suduku[i*cols+j]),rows,cols) == false);;
	};
    };
    printf("Thanks!");
};


void inputSize (US *rows, US *cols) {
    do {
	system("clear");
	intro();
	printf("How may rows does the suduku have? ");
    } while (validateInput(rows,100,100) == false);
    
    do {
	system("clear");
	intro();
	printf("How may rows does the suduku have? %hu\n", *rows);
	printf("How many columns does the suduku have? ");
    } while (validateInput(cols,100,100) == false); 
    printf("\n");
};


bool validateInput(US *ptr, US rows, US cols) {
    int c;
    bool valid = false;
    if (scanf("%2hu", ptr) != 1 || *ptr < 0 || (*ptr > rows && *ptr > cols)) {
	while((c = getchar()) != '\n'); //flush input stream	
	printf("\n\n            That was not a valid input. Press <ENTER> to try again.");
	getchar(); //wait for <ENTER>
    } else {
	valid = true;
	while((c = getchar()) != '\n'); //flush input stream	
    };
    return valid;
};


void outputLine (US cols) { //perhaps add a second argument for double lines?
    US i;
    printf("\n");
    for ( i = 0 ; i<cols*5; i++ ) {
        printf("─");
    }
    printf("\n");
};


void outputPartSuduku (US *suduku, US cols, US currentRow, US currentCol) {
    US k;
    outputLine(cols);
    for ( k=0 ; k < currentRow ; k++) {
	 outputRow(&(suduku[k*cols]), cols);
	 printf("\b");
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


void outputRow (US* row, US cols) {
    US j;
    printf("|");
    for (j=0 ; j<cols ; j++) {
            printf(" %hu |",row[j]);
        };
};
