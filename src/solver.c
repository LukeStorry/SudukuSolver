/* This file contains all the functions related to the actual solving of the suduku
 */

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
#include <math.h> 

typedef unsigned short int US; // to save typing it out every time.
typedef enum poss {NOTPOSSIBLE, POSSIBLE, DEFINITE} Poss;


static void initialise (Poss **arrayOfPoss, US *input, US size);

static void checkRowDuplicates(Poss **arrayOfPoss, US size);
static bool numIsInRow(US num, US row, Poss** arrayOfPoss, US size);
static void removeNumFromRow(US num, US row, Poss** arrayOfPoss, US size);

static void checkColDuplicates(Poss **arrayOfPoss, US size);
static bool numIsInCol(US num, US col, Poss** arrayOfPoss, US size);
static void removeNumFromCol(US num, US col, Poss** arrayOfPoss, US size);


static void checkBoxDuplicates(Poss **arrayOfPoss, US size);
static bool numIsInBox(US num, US box, Poss** arrayOfPoss, US size);
static void removeNumFromBox(US num, US box, Poss** arrayOfPoss, US size);



// This will be the main, and probably the only public, function.
int solveSuduku(US *input, US size) {
    int errornum = 0;
    Poss **arrayOfPoss = malloc(size*size*sizeof(Poss*)); //mallocs a pointer per cell.
    initialise(arrayOfPoss, input, size);
    checkRowDuplicates(arrayOfPoss, size);

    //call other solving functions.


    return errornum;
}


// This uses the input to initialise a 3d Poss Array of all the possibilities
static void initialise(Poss **arrayOfPoss, US *input, US size) {
    US i, j;
    for( i=0 ; i < size*size ; i++ ) {
	arrayOfPoss[i] = malloc(size*sizeof(Poss)); //each cell pointer points to an array of Posss
	if (input[i] == 0) { //if input was blank
	    for( j=0 ; j < size ; j++ ) {
		arrayOfPoss[i][j] = POSSIBLE; //all numbers are possible
	    };
	} else {
	    for( j=0 ; j < size ; j++ ) {
		arrayOfPoss[i][j] = (input[i] = j+1) ? DEFINITE : NOTPOSSIBLE; //the input number is definite, the rest aren't possible.
	    };
	};
    };
}

// This checks each row and changes the Poss possibility tag 
static void checkRowDuplicates(Poss **arrayOfPoss, US size) {
    US num, row;
    for ( row = 0 ; row < size ; row++ ) {//in each row,
	for ( num = 0 ; num < size ; num++ ) { //for each number,
	    if (numIsInRow(num, row, arrayOfPoss, size)) {
		removeNumFromRow(num, row, arrayOfPoss, size);
	    };
	};
    };
}


//This checks a row for a number, returning true or false.	    
static bool numIsInRow(US num, US row, Poss** arrayOfPoss, US size) {
    US cell;
    bool taken = false;
    for ( cell = 0 ; cell < size ; cell++ ) { //for each cell in row,
	if (arrayOfPoss[row*size+cell][num] == DEFINITE ) { //if thenum is taken by that cell
	    taken = true;
	};
    };
    return taken;
}

static void removeNumFromRow(US num, US row, Poss** arrayOfPoss, US size) {
    US cell;
    for ( cell = 0 ; cell < size ; cell++ ) { //for each cell in row,
	if (arrayOfPoss[row*size+cell][num] != DEFINITE) {
	    arrayOfPoss[row*size+cell][num] = NOTPOSSIBLE;
	};
    };
}



// This checks each column and changes the Poss possibility tag 
static void checkColDuplicates(Poss **arrayOfPoss, US size) {
    US num, col;
    for ( col = 0 ; col < size ; col++ ) {//in each col,
	for ( num = 0 ; num < size ; num++ ) { //for each number,
	    if (numIsInCol(num, col, arrayOfPoss, size)) {
		removeNumFromCol(num, col, arrayOfPoss, size);
	    };
	};
    };
}

//This checks a col for a number, returning true or false.	    
static bool numIsInCol(US num, US col, Poss** arrayOfPoss, US size) {
    US cell;
    bool taken = false;
    for ( cell = 0 ; cell < size ; cell++ ) { //for each cell in row,
	if (arrayOfPoss[col+cell*size][num] == DEFINITE ) { //if thenum is taken by that cell
	    taken = true;
	};
    };
    return taken;
}

static void removeNumFromCol(US num, US col, Poss** arrayOfPoss, US size) {
    US cell;
    for ( cell = 0 ; cell < size ; cell++ ) { //for each cell in row,
	if (arrayOfPoss[col+cell*size][num] != DEFINITE) {
	    arrayOfPoss[col+cell*size][num] = NOTPOSSIBLE;
	};
    };
}

// This checks each box and changes the Poss possibility tag 
static void checkBoxDuplicates(Poss **arrayOfPoss, US size) {
    US num, box;
    for ( box = 0 ; box < size ; box ++) { //there are 'size' number of boxes. Check them all.
	for ( num = 0 ; num < size ; num++ ) { //for each number,
	    if (numIsInBox(num, box, arrayOfPoss, size)) {
		removeNumFromBox(num, box, arrayOfPoss, size);
	    };
	};
    };



}

//This checks a Box for a number, returning true or false.	    
static bool numIsInBox(US num, US box, Poss** arrayOfPoss, US size) {
    US rowNum, colNum;		//iteration counters
    US rows = sqrt(size);	//number of rows in each box
    US cols = (rows*rows == size ? sqrt(size) : (sqrt(size)+1;	//number of cols in each box. test required for odd shaped sudukus
    if 
    bool taken = false;
    for ( row = 0 ; row < size/3 ; row++ ) { //for each cell in row,
	if (arrayOfPoss[box+cell*size][num] == DEFINITE ) { //if thenum is taken by that cell
	    taken = true;
	};
    };
    return taken;
}

static void removeNumFromBox (US num, US box, Poss** arrayOfPoss, US size) {
    US cell;
    for ( cell = 0 ; cell < size ; cell++ ) { //for each cell in row,
	if (arrayOfPoss[col+cell*size][num] != DEFINITE) {
	    arrayOfPoss[col+cell*size][num] = NOTPOSSIBLE;
	};
    };
}

