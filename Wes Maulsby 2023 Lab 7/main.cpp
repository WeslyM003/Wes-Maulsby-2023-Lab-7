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
#include "game.cpp"


using namespace std;
	
//initialization statements
const int rows = 10;	//sets rows to always be 10
const int elements = 10;	//sets elements (columns) to always be 10
const int enemyHitPoints = 17;	// sets enemy hitpoints to always be 17
const int playerHitPoints = 17;	// sets player hitpoints to always be 17
int hits;	// makes hits a global int since it is used in multiple functions and needs to have the same value throughout them, also counts the amount of hits the player has made
int enemyHits;	// makes enemyHits a global int since it is used in multiple functions and needs to have the same value throughout them, also counts the amount of hits the enemy has made
string topBoard[rows][elements];
string bottomBoard[rows][elements];
string enemyBoard[rows][elements];

//function prototypes
void createBoards();	//creates boards
void showBoards();		//shows boards
void introduction();	//prints the introduction for the player
void placeEnemyCarrier();	//randomly places enemy carrier
void placeEnemyBattleship();	//randomly places enemy battleship
void placeEnemyCruizer();	//randomly places enemy cruiser
void placeEnemyDestroyer();		//randomly places enemy destroyer
void placeCarrier();	//has player place their carrier
void placeBattleship();		//has player place their battleship
void placeCruizer();	//has player place their cruiser
void placeSubmarine();	//has player place their submarine
void placeDestroyer();	//has player place their destroyer
void playerTurn();	//the set of actions that makeup the players turn
void game();	//the main game





int main()
{
	Game c;
	srand(time(0)); //seed random number generator

	//creates boards and gives introduction
	createBoards();
	introduction();

	//enemy places ships
	placeEnemyCarrier();
	placeEnemyBattleship();
	placeEnemyCruizer();
	placeEnemyCruizer();
	placeEnemyDestroyer();

	//player places ships
	placeCarrier();
	showBoards();
	placeBattleship();
	showBoards();
	placeCruizer();
	showBoards();
	placeSubmarine();
	showBoards();
	placeDestroyer();
	showBoards();

	//main game
	game();


	//fin
	return 0;
}
