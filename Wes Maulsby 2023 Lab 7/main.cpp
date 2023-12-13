/************************
Wesly Maulsby
C++
Fall 2023
Lab 7 - Battleship
Violent curse words cannot express the depth of my suffering
*************************/

/*Yes I know I spelled cruiser wrong, but it appears so many times, that I am not gonna take the time to respell all of themand risk a cascade of errors
becuase I missed one*/

//In showBoards() in game.cpp there is a commented out series of code that will output the enemies board for testing



// includes needed libraries
#include <iostream>	//for input and output
#include <ctime>	//for random number generator
#include "game.h"



//main game function calls using functions from game class "game.h" using object "Steve"
int main()
{
	Game Steve;
	srand(time(0)); //seed random number generator

	//creates boards and gives introduction
	Steve.createBoards();
	Steve.introduction();

	//enemy places ships
	Steve.placeEnemyCarrier();
	Steve.placeEnemyBattleship();
	Steve.placeEnemyCruizer();
	Steve.placeEnemyCruizer();
	Steve.placeEnemyDestroyer();

	//player places ships
	Steve.placeCarrier();
	Steve.showBoards();
	Steve.placeBattleship();
	Steve.showBoards();
	Steve.placeCruizer();
	Steve.showBoards();
	Steve.placeSubmarine();
	Steve.showBoards();
	Steve.placeDestroyer();
	Steve.showBoards();

	//main game
	Steve.game();


	//fin
	return 0;
}


// this lab was so much fun that I shipped my pants