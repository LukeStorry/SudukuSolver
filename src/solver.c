/* This file contains all the functions related to the actual solving of the suduku
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int US; // to save typing it out every time.
typedef enum e {good, bad} Error;



static Error checkRow(US num, US *row, US size);


// This will be the main, and probably the only public, function.
int solveSuduku(US *suduku, US size) {
    int errornum = 0;


    //call other solving functions.
    checkRow(1,suduku,size);


    return errornum;
}



static Error checkRow(US num, US *row, US size) {
    
    Error a = good;
    
    return a;
}
