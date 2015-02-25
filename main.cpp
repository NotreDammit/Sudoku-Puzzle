/* Samuel H Cho -- Lab #5 -- (.h file) -- Fundamentals of Computing II
Defines the functions used in this program to create a templated sudoku puzzle */

#include "sudoku.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//First instantiate a sudoku object that will make a puzzle comprised of numbers
	sudoku<int> number( "numbers.txt" );
	number.play();
	
	//Once you win the number sudoku, you can play the wordoku version
	sudoku<char> word( "words.txt" );
	word.play();
	
	//After you beat both games, the program ends
	return 0;
};
