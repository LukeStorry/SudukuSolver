/* A suduku solver program in C
 * input as much of a suduku as possible, and then the program will atempt to solve.
 * a work in progress by Luke Storry
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;; //because I dont want to type the std99 gcc tag every time

typedef unsigned short US;

void intro (void);

void inputSize (US *rows, US *cols);
void inputSuduku (US *suduku, US rows, US cols);
void inputRow (US *row, US cols);

bool validateInput(US *ptr, US cols, US rows);

void outputSuduku (US* suduku, US rows, US cols);
void outputLine(US cols); 
void outputRow (US* row, US cols);
void outputPartSuduku (US *suduku, US cols, US currentRow, US currentCol);


int main (void) {
    US rows, cols, *suduku;
    intro();
    printf("Hit <ENTER> to begin!"); getchar(); //getchar captures the enter>
    inputSize(&rows, &cols);
    suduku = malloc(rows*cols*sizeof(US));
    inputSuduku(suduku,rows, cols);
    printf("\n\n\n    Output:n\n");
    outputSuduku(suduku,rows,cols);
    return 0;
}


void intro (void) {
    system("clear");
//Thanks to http://patorjk.com/software/taag/ for this awesome ASCII art.
//Font: Mega-relief by Nick Bryant 12/9
    printf("______/\\\\\\\\\\\\\\\\\\\\\\____/\\\\\\________/\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\\\_____/\\\\\\________/\\\\\\__/\\\\\\________/\\\\\\__/\\\\\\________/\\\\\\_        \n");
    printf(" ____/\\\\\\/////////\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\////////\\\\\\__\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_____/\\\\\\//__\\/\\\\\\_______\\/\\\\\\_       \n");
    printf("   __\\//\\\\\\______\\///__\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\______\\//\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\__/\\\\\\//_____\\/\\\\\\_______\\/\\\\\\_      \n");
    printf("    ___\\////\\\\\\_________\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\\\\\\\//\\\\\\_____\\/\\\\\\_______\\/\\\\\\_     \n");
    printf("     ______\\////\\\\\\______\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\//_\\//\\\\\\____\\/\\\\\\_______\\/\\\\\\_    \n");
    printf("      _________\\////\\\\\\___\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\____\\//\\\\\\___\\/\\\\\\_______\\/\\\\\\_   \n");   
    printf("       __/\\\\\\______\\//\\\\\\__\\//\\\\\\______/\\\\\\__\\/\\\\\\_______/\\\\\\__\\//\\\\\\______/\\\\\\__\\/\\\\\\_____\\//\\\\\\__\\//\\\\\\______/\\\\\\__  \n");
    printf("        _\\///\\\\\\\\\\\\\\\\\\\\\\/____\\///\\\\\\\\\\\\\\\\\\/___\\/\\\\\\\\\\\\\\\\\\\\\\\\/____\\///\\\\\\\\\\\\\\\\\\/___\\/\\\\\\______\\//\\\\\\__\\///\\\\\\\\\\\\\\\\\\/___ \n");
    printf("         ___\\///////////________\\/////////_____\\////////////________\\/////////_____\\///________\\///_____\\/////////_____\n");
    
    
    printf("\n\n  A work in progress... \n\n         Written by Luke Storry\n\n\n\n");
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


void inputSuduku (US *suduku, US rows, US cols) {
    US i, j;
    outputLine(cols);
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


void outputLine (US cols) { //perhaps add a second argument for double lines?
    US i;
    printf("\n");
    for ( i = 0 ; i<cols*5 ; i++ ) {
        printf("─");
    }
    printf("\n");
};


void outputRow (US* row, US cols) {
    US j;
    printf("|");
    for (j=0 ; j<cols ; j++) {
            printf(" %hu |",row[j]);
        };
};
