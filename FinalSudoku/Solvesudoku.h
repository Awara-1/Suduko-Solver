#ifndef SOLVESUDOKU_H_INCLUDED
#define SOLVESUDOKU_H_INCLUDED
//Pass grid by refrence as we want the value of grid to 'update outside' function.
bool Solve(int &grid, int thesudoku[][9])
{

	int row, col;
	//row = 0;
	//col = 0;

// The if here will return true if unfilledchecker is false meaning that we no longer have any 0's and Sudoku puzzle has been solved.
	if(!unfilledChecker(grid, row, col, thesudoku))
		return true;
//THIS IS FOR DEBUGGING.
	//printf("row = %d, col = %d, \n", row, col);

//This goes from 1-->9 to try each number in the sudoku one-unit square.
	for(int num = 1; num <=9; num++) {

//FOR DEBUGGING (prints the Sudoku everytime to check its progress.
		//printSudoku(thesudoku);
		//cout<<endl;
		//printf("num = %d\n", num);

		if(checkError(num, grid, row, col, thesudoku)) {
//PRINTF FOR DEBUGGING ALSO TO SEE IF WHEN PROGRAM SAID IT WORKS IT ACTUALLY WORKED.
			//printf("num %d WORKS!\n", num);

//If checkerror is true than there are no conflicts hence we can place the number in that area.
			thesudoku[row][col] = num;

//AGAIN THIS WAS FOR DEBUGGING.
			//printf("row = %d, col = %d\n\n", row, col);
			//if((row == 4 && col == 1))
				//printSudoku(thesudoku);

//This triggers the recursive backtracking and essentially makes program keep correcting itself by changing the values of num until it finds the perfect match. keeps stacking until
//all Solve functions called are true henece puzzle has been solved.
			if(Solve(grid, thesudoku))
				return true;
//For now if it couldnt find any match leave the 0 as a 0, eventually function will come back to this spot and try to change it again.
			thesudoku[row][col] = 0;
		}
	}
	return false;
}


#endif // SOLVESUDOKU_H_INCLUDED
