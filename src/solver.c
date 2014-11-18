/* This file contains all the functions related to the actual solving of the suduku
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int US; // to save typing it out every time.

void initialise (US **possibles, US *input, US size);

// This will be the main, and probably the only public, function.
int solveSuduku(US *input, US size) {
    int errornum = 0;
    US **possibles;
    initialise(possibles, input, size);

    //call other solving functions.



    return errornum;
}



void initialise(US **possibles, US *input, US size) {
    US i;
    for( i=0 ; i < size ; i++


}
