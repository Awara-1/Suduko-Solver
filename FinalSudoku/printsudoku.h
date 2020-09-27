#ifndef PRINTSUDOKU_H_INCLUDED
#define PRINTSUDOKU_H_INCLUDED

void printSudoku(int thesudoku[][9])
{
	int j, i;
	j = 0;
	i = 0;

//Prints whole Sudoku. Can be called at any given time.
    for(i=0;i < 9; i++) {
		for(j=0; j < 9; j++) {
	   		cout<<" "<<thesudoku[i][j];
        }

        cout<<endl;
    }
}

#endif // PRINTSUDOKU_H_INCLUDED
