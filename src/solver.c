/* This file contains all the functions related to the actual solving of the suduku
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned short int US; // to save typing it out every time.
void initialise (bool **possibles, US *input, US size);
void removeRowDuplicates(bool **possibles, US size);
void removeColDuplicates(bool **possibles, US size);
void removeBoxDuplicates(bool **possibles, US size);


// This will be the main, and probably the only public, function.
int solveSuduku(US *input, US size) {
    int errornum = 0;
    bool **possibles = malloc(size*size*sizeof(bool*)); //mallocs a pointer per cell.
    initialise(possibles, input, size);
void removeRowDuplicates(bool **possibles, US size);

    //call other solving functions.



    return errornum;
}


// This uses the input to initialise a 3d bool Array of all the possibilities
void initialise(bool **possibles, US *input, US size) {
    US i, j;
    for( i=0 ; i < size*size ; i++ ) {
	possibles[i] = malloc(size*sizeof(bool)); //each cell pointer points to an array of bools
	if (input[i] == 0) { //if input was blank
	    for( j=0 ; j < size ; j++ ) {
		possibles[i][j] = true; //all numbers are possible
	    };
	} else {
	    for( j=0 ; j < size ; j++ ) {
		possibles[i][j] = (input[i] = j+1) ? true : false; //only the input number is possible.
	    };
	};
    };
}

// This checks each row and changes the bool possibility tag 
void removeRowDuplicates(bool **possibles, US size) {
    int row;
    for ( row = 0 ; row < size ; row++ ) {


// This checks each column and changes the bool possibility tag 
void removeColDuplicates(bool **possibles, US size);



// This checks each box and changes the bool possibility tag 
void removeBoxDuplicates(bool **possibles, US size);
