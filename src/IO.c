//These functions read in and output suduku files to/from BASH.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned short US;

static bool validateInput(US *ptr, US size);
static void outputLine(US size);
static void outputRow (US* row, US size);
static void outputPartSuduku (US *suduku, US size, US currentRow, US currentCol);


#include "../include/IO.h"
#include "../include/textybits.h"

void inputSuduku (US *suduku, US size) {
    US row, col;;
    for ( row = 0 ; row < size ; row++ ) {
        for (col = 0 ; col < size ; col++) {
            do {
		system("clear");
		intro();
		printf("Please enter your suduku puzzle below, with 0 for spaces. Press <ENTER> after each number.\n");
		outputPartSuduku(suduku, size, row, col);
	    } while (validateInput(&(suduku[row*size+col]),size) == false);;
	};
    };
    printf("Thanks!");
}


void inputSize (US *size) {
    do {
	system("clear");
	intro();
	printf("What size is the suduku?? ");
    } while (validateInput(size,100) == false);   
}

static bool validateInput(US *ptr, US max) {
    int c;
    bool valid = false;
    if (scanf("%2hu", ptr) != 1 || *ptr > max) {
	while((c = getchar()) != '\n'); //flush input stream	
	printf("\n\n            That was not a valid input. Press <ENTER> to try again.");
	getchar(); //wait for <ENTER>
    } else {
	valid = true;
	while((c = getchar()) != '\n'); //flush input stream	
    };
    return valid;
}


static void outputLine (US size) { //perhaps add a second argument for double lines?
    US i;
    printf("\n");
    for ( i = 0 ; i<size*5; i++ ) {
        printf("─");
    }
    printf("\n");
}


static void outputPartSuduku (US *suduku, US size, US currentRow, US currentCol) {
    US i;
    outputLine(size);
    for ( i=0 ; i < currentRow ; i++ ) {
	 outputRow(&(suduku[i*size]), size);
	 printf("\b");
	 outputLine(size);
    };
    outputRow(&(suduku[currentRow*size]), currentCol);
}
       
        
void outputSuduku (US* suduku, US size) {
    US row;
    outputLine(size);
    for ( row = 0 ; row < size ; row++ ) {
        outputRow(&suduku[row*size], size);
        outputLine(size);
    };
}


static void outputRow (US*row, US size) {
    US cell;
    printf("|");
    for ( cell = 0 ; cell < size ; cell++) {
            printf(" %hu |",row[cell]);
        };
}
