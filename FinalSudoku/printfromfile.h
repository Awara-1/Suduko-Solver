#ifndef PRINTFROMFILE_H_INCLUDED
#define PRINTFROMFILE_H_INCLUDED

//Function parameters are is the inputfile passed through it and the 2-D array also.
void printFromFile(ifstream &input, int thesudoku[][9])
{
    int j=0, i=0;

//This for loop will scan through the whole row (starting at top left of file) by incrementing j and once j reaches 8 we increament i so that we move onto next row line.
//This ensures that whole sudoku data is read from file.

    for(i=0;i < 9; i++) {
		for(j=0; j < 9; j++) {
		    //Take each integer in the file one by one starting from top left and going right.
	   		input>>thesudoku[i][j];
	   		cout<<" "<<thesudoku[i][j];
        }

        cout<<endl;
    }
}

#endif // PRINTFROMFILE_H_INCLUDED
