/* Samuel H Cho -- Lab #5 -- (.h file) -- Fundamentals of Computing II
Defines the functions used in this program to create a templated sudoku puzzle */

#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
template <typename T>

class sudoku
{
	public:
		//Constructor
		sudoku( string );
		//Member Functions
		void play();
		int win();
		void input();
		int valid( int, int, T );

	private:
		//Data Members
		vector<vector<T> > puzzle;
};

template <typename T>
sudoku<T>::sudoku( string filename )
{
	int i, j;
	vector<T> tempVec;
	T tempVar;
	
	//opens file name hard-coded into the constructor in the main file
	ifstream infile;
	infile.open (filename.c_str());
	
	//reads through the file and pushes back into the vector
	while( !infile.eof() )
	{
		for( int i = 0; i < 9; i++ )
		{
			infile >> tempVar;
			tempVec.push_back( tempVar );
		}
		puzzle.push_back( tempVec );
		tempVec.clear();
	}
	
	cout << endl;
	
	//prints out the puzzles
	for( i=0; i<9; i++ )
	{
		for( j=0; j<9; j++ )
		{
			cout << puzzle[i][j] << " ";
		}
		cout << endl;
	}
}

template <typename T>
void sudoku<T>::input()
{
	int column, row;
	T value;
	
	//asks the user where they would like to input values in the puzzle
	cout << endl << "Input column number: ";
	cin >> column;
	cout << endl << "Input row number: ";
	cin >> row;
	cout << endl << "Input desired value: ";
	cin >> value;
	cout << endl;
	
	//checks to see if user input is a valid input
	if( valid( row, column, value ) == 27 )
	{
		puzzle[row-1][column-1] = value;
	}
	else
	{
		cout << endl << "Sorry please enter a valid input" << endl << endl;
	}
}

template <typename T>
int sudoku<T>::valid( int rowInput, int columnInput, T valueInput )
{
	int rowCheck = 0, columnCheck = 0, gridCheck = 0, i, j, k;
	
	//Check grids 1-3
	if( rowInput <= 3 && rowInput >=1 )
	{
		//check grid 1
		if( columnInput <= 3 && columnInput >= 1 )
		{
			for( j=0; j<3; j++ )
			{
				for( k=0; k<3; k++ )
				{
					if( puzzle[j][k] != valueInput )
					{
						gridCheck+=1;
					}
					
				}
			}
		}
		//check grid 2
		if( columnInput <= 6 && columnInput >= 4 )
		{
			for( j=0; j<3; j++ )
			{
				for( k=3; k<6; k++ )
				{
					if( puzzle[j][k] != valueInput )
					{
						gridCheck+=1;
					}
					
				}
			}
		}
		//check grid 3
		if( columnInput <= 9 && columnInput >= 7 )
		{
			for( j=0; j<3; j++ )
			{
				for( k=6; k<9; k++ )
				{
					if( puzzle[j][k] != valueInput )
					{
						gridCheck+=1;
					}
					
				}
			}
		}
	}
	
	//check grids 4-6
	if( rowInput <= 6 && rowInput >=4 )
	{
		//check grid 4
		if( columnInput <= 3 && columnInput >= 1 )
		{
			for( j=3; j<6; j++ )
			{
				for( k=0; k<3; k++ )
				{
					if( puzzle[j][k] != valueInput )
					{
						gridCheck+=1;
					}
					
				}
			}
		}
		//check grid 5
		if( columnInput <= 6 && columnInput >= 4 )
		{
			for( j=3; j<6; j++ )
			{
				for( k=3; k<6; k++ )
				{
					if( puzzle[j][k] != valueInput )
					{
						gridCheck+=1;
					}
					
				}
			}
		}
		//check grid 6
		if( columnInput <= 9 && columnInput >= 7 )
		{
			for( j=3; j<6; j++ )
			{
				for( k=6; k<9; k++ )
				{
					if( puzzle[j][k] != valueInput )
					{
						gridCheck+=1;
					}
					
				}
			}
		}
	}
	
	//check grids 7-9
	if( rowInput <= 9 && rowInput >=7 )
	{
		//check grid 7
		if( columnInput <= 3 && columnInput >=1 )
		{
			for( j=6; j<9; j++ )
			{
				for( k=0; k<3; k++ )
				{
					if( puzzle[j][k] != valueInput )
					{
						gridCheck+=1;
					}
					
				}
			}
		}
		//check grid 8
		if( columnInput <= 6 && columnInput >= 4 )
		{
			for( j=6; j<9; j++ )
			{
				for( k=3; k<6; k++ )
				{
					if( puzzle[j][k] != valueInput )
					{
						gridCheck+=1;
					}
					
				}
			}
		}
		//check grid 9
		if( columnInput <= 9 && columnInput >= 7 )
		{
			for( j=6; j<9; j++ )
			{
				for( k=6; k<9; k++ )
				{
					if( puzzle[j][k] != valueInput )
					{
						gridCheck+=1;
					}
					
				}
			}
		}
	}
	
	for( i=0; i<9; i++ )
	{
		//Checks rows
		if( puzzle[rowInput-1][i] != valueInput )
		{
			rowCheck+=1;
		}
		
		//Checks columns
		if( puzzle[i][columnInput-1] != valueInput )
		{
			columnCheck+=1;
		}
	}

	return rowCheck+columnCheck+gridCheck;
}

template <typename T>
int sudoku<T>::win()
{
	//since win function is after valid function in play function, all this function needs to do is make sure there are no more zero's on the puzzle board
	int winCount = 0;
	for( int i=0; i<9; i++ )
	{
		for( int j=0; j<9; j++ )
		{
			if( puzzle[i][j] != 0 )
			{
				winCount+1;
			}
		}
	}
	//since there are 81 spots on the board, if all 81 spots are occuppied by a number or letter other than 0, 81 will be returned
	return winCount;
}

template <typename T>
void sudoku<T>::play()
{
	while( win() != 81 )
	{
		input();
		//prints out the puzzle after every input
		for( int i=0; i<9; i++ )
		{
			for( int j=0; j<9; j++ )
			{
				cout << puzzle[i][j] << " ";
			}
			cout << endl;
		}
	}
	cout << endl << "You won the game!" << endl;
}

#endif
