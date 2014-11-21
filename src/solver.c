/* This file contains all the functions related to the actual solving of the suduku
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned short int US; // to save typing it out every time.
typedef enum poss {NOTPOSSIBLE, POSSIBLE, DEFINITE} Poss;


static void initialise (Poss **possibles, US *input, US size);
static void checkRowDuplicates(Poss **possibles, US size);
static void checkColDuplicates(Poss **possibles, US size);
static void checkBoxDuplicates(Poss **possibles, US size);


// This will be the main, and probably the only public, function.
int solveSuduku(US *input, US size) {
    int errornum = 0;
    Poss **possibles = malloc(size*size*sizeof(Poss*)); //mallocs a pointer per cell.
    initialise(possibles, input, size);
    checkRowDuplicates(possibles, size);

    //call other solving functions.



    return errornum;
}


// This uses the input to initialise a 3d Poss Array of all the possibilities
static void initialise(Poss **possibles, US *input, US size) {
    US i, j;
    for( i=0 ; i < size*size ; i++ ) {
	possibles[i] = malloc(size*sizeof(Poss)); //each cell pointer points to an array of Posss
	if (input[i] == 0) { //if input was blank
	    for( j=0 ; j < size ; j++ ) {
		possibles[i][j] = POSSIBLE; //all numbers are possible
	    };
	} else {
	    for( j=0 ; j < size ; j++ ) {
		possibles[i][j] = (input[i] = j+1) ? DEFINITE : NOTPOSSIBLE; //the input number is definite, the rest aren't possible.
	    };
	};
    };
}

// This checks each row and changes the Poss possibility tag 
static void checkRowDuplicates(Poss **possibles, US size) {
    US num, row;
    for ( row = 0 ; row < size ; row++ ) {//in each row,
	for ( num = 0 ; num < size ; num++ ) { //for each number,
	    if (numIsInRow(num, row, suduku, size)) {
		removeNumFromRow(num, row, suduku, size);
	    };
	};
    };
}


//This checks a row for a number, returning true or false.	    
static bool numIsInRow(US num, US row, US** suduku, US size) {
    US cell;
    bool taken = false;
    for ( cell = 0 ; cell < size ; cell++ ) { //for each cell in row,
	if (possibilities[row*size+cell][num] == DEFINITE ) { //if thenum is taken by that cell
	    taken = true;
	};
    };
    return taken;
}

static void removeNumFromRow(US num, US row, US** suduku, US size) {
    US cell;
    bool taken = false;
    for ( cell = 0 ; cell < size ; cell++ ) { //for each cell in row,
	possibilities[row*size+cell][num] = NOTPOSSIBLE;
    };
}



// This checks each column and changes the Poss possibility tag 
static void checkColDuplicates(Poss **possibles, US size) {
    ;
}



// This checks each box and changes the Poss possibility tag 
static void checkBoxDuplicates(Poss **possibles, US size) {
    ;
}
