/************************
Wesly Maulsby
C++
Fall 2023
Lab 7 - Battleship
Violent curse words cannot express the depth of my suffering
*************************/

/*Yes I know I spelled cruiser wrong, but it appears so many times, that I am not gonna take the time to respell all of themand risk a cascade of errors
becuase I missed one*/




// includes needed libraries
#include <iostream>	//for input and output
#include <ctime>	//for random number generator
#include "game.h"



/*main game function calls using functions from game class "game.h" using object c because I still cant come up with a better object name besides
some kind of curse word*/ 
int main()
{
	Game c;
	srand(time(0)); //seed random number generator

	//creates boards and gives introduction
	c.createBoards();
	c.introduction();

	//enemy places ships
	c.placeEnemyCarrier();
	c.placeEnemyBattleship();
	c.placeEnemyCruizer();
	c.placeEnemyCruizer();
	c.placeEnemyDestroyer();

	//player places ships
	c.placeCarrier();
	c.showBoards();
	c.placeBattleship();
	c.showBoards();
	c.placeCruizer();
	c.showBoards();
	c.placeSubmarine();
	c.showBoards();
	c.placeDestroyer();
	c.showBoards();

	//main game
	c.game();


	//fin
	return 0;
}
