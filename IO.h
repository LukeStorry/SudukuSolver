//header file for the functions that input and output sudukus from BASH* 

void inputSize (US *rows, US *cols);
void inputSuduku (US *suduku, US rows, US cols);
void inputRow (US *row, US cols);

bool validateInput(US *ptr, US cols, US rows);

void outputSuduku (US* suduku, US rows, US cols);
void outputLine(US cols); 
void outputRow (US* row, US cols);
void outputPartSuduku (US *suduku, US cols, US currentRow, US currentCol);
