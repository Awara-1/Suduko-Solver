#include <iostream> //Library with standerd input out stream objects.
#include <string> //Library to allow use of strings.
#include <cstdlib>//To allow us to exit files opened.
#include <fstream>//Allow us to read/wrie data from files.
#include <stdio.h>//Standerd input output library (allow programme interaction with physical objects e.g keyboards)
#include <stdlib.h> //General purpose functions.
#include <windows.h>// These two libraries are for timing how long the solve function takes to complete solving the incomplete sudoku code.
#include <ctime>

using namespace std;
using std::string;

#include "printfromfile.h" //Module that contains function that allows us to print from input file.

#include "printsudoku.h" //This module contains function that prints the sudoku when called. (Can be used for debugging also)

#include "checkError.h" //Module with function that checks the row, collumn and grid that a given point is in to see if there are any conflicts i.e same number as it.

#include "Unfilledfinder.h" //Module with function that finds the next 0/empty space from the current posiotion of grid i.e current row&col.

#include "Solvesudoku.h" //This module contains the function that carrys out the backtracking so that we can solve the sudoku.

int main ()
{

    clock_t t;


	const int rownum = 9, collumnum = 9; //Giving the Sudoku square its parameters. (This program solves 9x9 grids)
	int sudoku[rownum][collumnum]; //2-D array that will hold the numbers of the sudoku from the file.


	int grid = 1; //Initialise the grid to start with value/position 1. Grid goes from 1-->9.

	string filename; //Filename is the string variable which user will intialise with the name of a file.

    int Run = 1; //Run will keep the loop running if User enters YES for 1 as shown.

//While loop to keep program running until user chooses to terminate it.
while (Run != 0){
    cout <<"Would you like to run the sudoku solver? (YES-->1/No-->0)" << endl;
    cin >> Run;

//Terminate the program if user enters the 0 for No.
    if(Run == 0){
    exit(1);
    }

    cout <<"Please enter the name of your file (include .txt extension)." << endl;
    cin >> filename;

//.c_str() converts string into array of characters which is what is needed as infile takes characters as its variable rather than strings.
    ifstream infile(filename.c_str());
    //check to see if file opened correctly/ at all.
	if(!infile.is_open()){
  		cout <<"Your file failed to open!" << endl;
		exit(1);
 	}

//Print from file to show we have obtained the data from file correctly.
    cout << "Printing INCOMPLETE Sudoku from file" << endl;
	printFromFile(infile, sudoku);
	cout<<endl;

//Once we're done with program we need to close it.
	infile.close();

//THE CODE BELOW WAS USED TO TEST THE FUNCTIONS MADE & FOR DEBUGGING.

//The first was to check if checkerror was working correctly and by trying different inputs I could see by checking the incomplete puzzle manually
//if checkerror was working correctly or not.

//	if(!checkError(9, 1, 0, 1, sudoku))
//		printf("Cannot place 9 in this position.\n");

//	if(!checkError(7, 2, 0, 1, sudoku))
//		printf("Cannot place 7 in this position.\n");

//THIS FINDS THE ZERO'S AND PRINTS THEIR LOCATION IN TERMS OF GRID, ROW AND COL. (CHECKS IF UNFILLEDCHCKER IS OK)

/*	for(i = 0; i < 81; i++) {
		if(unfilledChecker(grid, row, col, sudoku, first))
			printf("Found %d in grid %d row:%d col:%d\n", sudoku[row][col], grid, row, col);
	}

*/


t = clock(); //This returns the processor time taken by program up till now.
//Call the solve function to carry out the backtracking to solve our Sudoku.
    if(Solve(grid, sudoku)){
t = clock() - t; //This will give the time taken to carry out the Solve function as can be seen.
        cout << "Sudoku solved in " << (float(t)/CLOCKS_PER_SEC) << "s!" << endl;
        cout<<"The Sudoku has been solved!" << endl;
        //prints complete sudoku puzzle
		printSudoku(sudoku);
    }
//If Sudoku is incorrect/can not be sovled tell user so.
	else {
		cout<<"Cannot Solve Sudoku\n";
		printSudoku(sudoku);
	}
	}

	return 0;
}













