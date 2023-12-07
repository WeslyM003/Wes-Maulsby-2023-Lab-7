#ifndef game_H
#define game_H

#include <string>
using namespace std;
//Game class used to create and run game
class Game
{
private:


public:
	//constructor
	Game();
	//destructor
	~Game();

	//initialization statements
	const int rows = 10;	//sets rows to always be 10
	const int elements = 10;	//sets elements (columns) to always be 10
	const int enemyHitPoints = 17;	// sets enemy hitpoints to always be 17
	const int playerHitPoints = 17;	// sets player hitpoints to always be 17
	int hits;	// makes hits a global int since it is used in multiple functions and needs to have the same value throughout them, also counts the amount of hits the player has made
	int enemyHits;	// makes enemyHits a global int since it is used in multiple functions and needs to have the same value throughout them, also counts the amount of hits the enemy has made
	std::string topBoard[10][10];
	std::string bottomBoard[10][10];
	std::string enemyBoard[10][10];
	std::string enemyTopBoard[10][10];

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
};


#endif game_H