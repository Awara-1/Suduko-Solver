#ifndef UNFILLEDFINDER_H_INCLUDED
#define UNFILLEDFINDER_H_INCLUDED

//Pass by refrence the grid, row and col variables so that their values get updated outside function also. (As I am passing the adresses of grid, row and col)
bool unfilledChecker(int &grid, int &row, int &col, int thesudoku[][9])
{

//THIS WAS THE FIRST FUNCTION I MADE TO FIND 0'S, FOUND THAT USING TWO FOR LOOPS WOULD BE BETTER BECAUSE IT'S A LOT SIMPLAR AND HENCE LESS PRONE TO MAKE ERRORS.

/*	//row = 0;
	//col = 0;	//grid = 0;
	  do {

     		if(row == 8 && col == 8)
         		return false;
			if(first) {
				row = 0;
				col = 0;
				first = 0;
			} else
				col++;

			first = 0;


			//after the do function, col could be greater than 8 after 'do while' so we want to increment the row to move onto row.
  			if(col >= 9)
   				row++;

			//these are to reset the values of col and row to 0 because they can't be greater than 8.
  			col = col % 9;
  			row = row % 9;

 		} while(thesudoku[row][col] != 0);
		grid =  3*(row/3) + col / 3 + 1;
 		return true;
*/

//
	int i, j;
	//used a for loop to scan for the zeros in the grid.
	for(i = 0; i<9; i++) {
		for(j=0; j<9;j++){
			if(thesudoku[i][j] == 0) {
                row = i;
				col = j;
				grid = (3*(row/3) + col / 3) + 1; //Algorithm that tells us the grid position from the row and col number/position where the 0 is situated.
				return true;
			}
		}
	}
	return false; // Return a false if function finds no zeros.
}

#endif // UNFILLEDFINDER_H_INCLUDED
