/* This file contains all the functions related to the actual solving of the suduku
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned short int US; // to save typing it out every time.
void initialise (char **possibles, US *input, US size);


// This will be the main, and probably the only public, function.
int solveSuduku(US *input, US size) {
    int errornum = 0;
    char **possibles = malloc(size*size*sizeof(*char)); //mallocs a pointer per cell.
    initialise(possibles, input, size);

    //call other solving functions.



    return errornum;
}



void initialise(char **possibles, US *input, US size) {
    US i, j;
    for( i=0 ; i < size*size ; i++ ) {
	possibles[i] = malloc(size*sizeof(char)); //each cell pointer points to an array of bools
	if (input[i] == 0) { //if input was blank
	    for( j=0 ; j < size ; j++ ) {
		possibles[i][j] = 1; //all numbers are possible
	    };
	} else {
	    for( j=0 ; j < size ; j++ ) {
		possibles[i][j] = (input[i] = j+1) ? 1 : 0; //only the input number is possible.
	    };
	};
    };
}
