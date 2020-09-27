#ifndef CHECKERROR_H_INCLUDED
#define CHECKERROR_H_INCLUDED

bool checkError(int num, int grid, int row, int col, int thesudoku[][9]) {
    //These two algorithms finds the starting row and starting collumn inside a given grid respectively from the row and col number/position of where the zero is at that gets passed in the function.
    //As can be seen on right (in greyed out code), I initially used an algorhtm that uses the grid number however despite it working seperatly when implemneted in solve function
    //it didn't allow for the Sudoku to be solved properly so used a different algorithm for it.
	int startingRow = row - row%3;  //((grid - 1) / 3) * 3;
  	int startingCol =  col - col%3; //((grid - 1) * 3) % 9;

	int tempRow = row; //Takes the value of row from the input. Using the value of row, we'll be able to check the whole row that this given point in sudoku is.
	int tempCol = col; //Takes value of col from input. Using the value of col, we'll be able to check the whole collumn that thr given point is in by incremnering the row number that point is in
	//as show in the for loop.

	//Row Checker
	for(col=0; col < 9; col++)
  	{
		if(thesudoku[tempRow][col] == num)
           		return false;
  	}


	//column checker
  	for(row = 0; row < 9; row++)
  	{

		if(thesudoku[row][tempCol] == num)
		   return false;
  	}


  	//grid checker (using the startingRow and startingCol we can increment from these to check the hole grid that the given positon is in.
  	for(row = 0; row < 3; row++) {
		for(col = 0; col < 3; col++) {
            if(thesudoku[row+startingRow][col+startingCol] == num)
               			return false;
     	  	}

  	}
	//If no conflicts are found with the inputted num i.e function finds no number equal to the num in row, col and grid for a given position, return a true.
	return true;
}

#endif // CHECKERROR_H_INCLUDED
