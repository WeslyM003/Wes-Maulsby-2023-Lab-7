/************************
Wesly Maulsby
C++
Fall 2023
Lab 7 - Battleship
Violent curse words cannot express the depth of my suffering
*************************/



// includes needed libraries
#include <iostream>	//for input and output
#include <ctime>	//for random number generator
#include "game.h"




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
