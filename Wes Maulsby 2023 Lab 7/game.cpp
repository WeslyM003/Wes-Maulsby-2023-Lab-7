// includes needed libraries
#include <iostream>	//for input and output
#include <ctime>	//for random number generator
#include "game.h"
using namespace std;
//constructor
Game::Game()
{
}

//destructor
Game::~Game()
{
}

void Game::createBoards()		//creates boards
{
	//runs through every coordinate on the top board and sets it to the water symbol by default
	for (int x = 0; x < rows; x++)	//for every x in the top board loop
	{
		for (int y = 0; y < elements; y++)		//for every y in the top board loop
		{
			topBoard[x][y] = "~";	//sets the coordinate to the water symbol by default
		}
	}

	//runs through every coordinate on the bottom board and sets it to the water symbol by default
	for (int x = 0; x < rows; x++)		//for every x in the bottom board loop
	{
		for (int y = 0; y < elements; y++)	//for every y in the bottom board loop
		{
			bottomBoard[x][y] = "~";		//sets the coordinate to the water symbol by default
		}
	}

	//runs through every coordinate on the enemy bottom board and sets it to the water symbol by default
	for (int x = 0; x < rows; x++)		//for every x in the enemy board loop
	{
		for (int y = 0; y < elements; y++)		//for every y in the enemy board loop
		{
			enemyBoard[x][y] = "~";		//sets the coordinate to the water symbol by default
		}
	}

	//runs through every coordinate on the top board and sets it to the water symbol by default
	for (int x = 0; x < rows; x++)		//for every x in the enemy board loop
	{
		for (int y = 0; y < elements; y++)		//for every y in the enemy board loop
		{
			enemyTopBoard[x][y] = "~";		//sets the coordinate to the water symbol by default
		}
	}
}

void Game::showBoards()		//shows boards
{
	std::cout << endl << endl << "   1 2 3 4 5 6 7 8 9 10" << endl;		// prints the top numbers to show the x
	for (int x = 1; x < rows + 1; x++)	//for every x in the board loop
	{
		//prints the side numbers to show the y 
		if (x < 10)	//formats the numbers less than 10 so the board isn't mis-aligned
		{
			std::cout << " " << x << " ";
		}
		else if (x == 10)	//formats the numbers more than 10 so the board isn't mis-aligned
		{
			std::cout << x << " ";
		}

		//
		for (int y = 0; y < elements; y++)		//for every y in the board loop
		{
			std::cout << topBoard[x - 1][y] << " ";
		}
		std::cout << endl;	//goes to next row

	}


	std::cout << endl << endl << "   1 2 3 4 5 6 7 8 9 10" << endl;		// prints the top numbers to show the x
	for (int x = 1; x < rows + 1; x++)		//for every x in the board loop
	{
		//prints the side numbers to show the y 
		if (x < 10)		//formats the numbers less than 10 so the board isn't mis-aligned
		{
			std::cout << " " << x << " ";
		}
		else if (x == 10)	//formats the numbers more than 10 so the board isn't mis-aligned
		{
			std::cout << x << " ";
		}


		for (int y = 0; y < elements; y++)		//for every y in the board loop
		{
			std::cout << bottomBoard[x - 1][y] << " ";
		}
		std::cout << endl;		//goes to next row
	}

	//Uncomment to view enemy board
	std::cout << endl << endl << "   1 2 3 4 5 6 7 8 9 10" << endl;		// prints the top numbers to show the x
	for (int x = 1; x < rows + 1; x++)		//for every x in the board loop
	{
		//prints the side numbers to show the y
		if (x < 10)		//formats the numbers less than 10 so the board isn't mis-aligned
		{
			std::cout << " " << x << " ";
		}
		else if (x == 10)	//formats the numbers more than 10 so the board isn't mis-aligned
		{
			std::cout << x << " ";
		}


		for (int y = 0; y < elements; y++)		//for every y in the board loop
		{
			std::cout << enemyTopBoard[x - 1][y] << " ";
		}
		std::cout << endl;		//goes to next row
	}
	std::cout << endl << endl << "   1 2 3 4 5 6 7 8 9 10" << endl;		// prints the top numbers to show the x
	for (int x = 1; x < rows + 1; x++)		//for every x in the board loop
	{
		//prints the side numbers to show the y
		if (x < 10)		//formats the numbers less than 10 so the board isn't mis-aligned
		{
			std::cout << " " << x << " ";
		}
		else if (x == 10)	//formats the numbers more than 10 so the board isn't mis-aligned
		{
			std::cout << x << " ";
		}


		for (int y = 0; y < elements; y++)		//for every y in the board loop
		{
			std::cout << enemyBoard[x - 1][y] << " ";
		}
		std::cout << endl;		//goes to next row
	} 
}


void Game::introduction()		//prints the introduction for the player
{
	std::cout << "Welcome to Battleship, The classic sinking game made in C++ because my suffering knows no bounds\nTo get started, why not show you the ropes?\nYou will have two boards, a top and a bottom:\n";
	showBoards();		//shows the boards as an example for the player
	std::cout << "\nThe top board tracks your guesses and is used when taking your turn\n";
	std::cout << "The bottom board tracks the enemy's guesses and will show you where your ships are in relation to their guesses\n"; 
	std::cout << "The boards use symbols to designate Ships (#), water(~), hits (H) or misses (M)\n";
	std::cout << "You will have 5 ships, a Carrier (5 spaces), a Battleship (4 spaces), a Cruizer (3 Spaces), a Submarine (3 spaces), and a Destroyer (2 spaces).\n"; 
	std::cout << "After this intro, a series of prompts will help you place your ships, follow their directions to create your fleet.\n";
	std::cout << "Once the game starts, you will enter a coordinate each turn to fire, try to hit the enemy by guessing their location.";
	std::cout << "\nThe first person to sink all their enemies ships wins, Good Luck!\n";
}


void Game::placeCarrier()		//allows user to place carrier
{
	for (int l = 0; l == 0; l++)	//1 time loop so the loop can break and recursion can work properly
	{
		int inX;	//the x coord inputed by the user
		int inY;	//the y coord inputed by the user
		int inD;	//the direction inputed by the user


		std::cout << "Please enter the first X Coordinate of your Carrier: ";
		std::cin >> inX;		//gets the users input for the x coord
		if (inX < 1 || inX > 10)	//makes sure that the user chose a number between 1 and 10 inclusive
		{
			std::cout << "Invalid Coordinate" << endl;	//informs the player they entered an invalid coordinate if they did
			placeCarrier();		//calls the function again
			break;		//breaks so the current instance of the function ends once the next one is called
		}

		std::cout << "Please enter the first Y Coordinate of your Carrier: ";
		std::cin >> inY;		//gets the users input for the y coord
		if (inY < 1 || inY > 10)	//makes sure that the user chose a number between 1 and 10 inclusive
		{
			std::cout << "Invalid Coordinate" << endl;		//informs the player they entered an invalid coordinate if they did
			placeCarrier();		//calls the function again
			break;		//breaks so the current instance of the function ends once the next one is called
		}

		std::cout << "Please enter 1 for the ship to go up, 2 for it to go down, 3 for the ship to go left, and 4 to go right: ";
		std::cin >> inD;		//gets the users input for the direction
		if (inD == 1 && inY < 5)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			std::cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeCarrier();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 1 && inY >= 5)	//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 2][inX - 1] != "#" && bottomBoard[inY - 3][inX - 1] != "#" && bottomBoard[inY - 4][inX - 1] != "#" && bottomBoard[inY - 5][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going up
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 2][inX - 1] = "#";
				bottomBoard[inY - 3][inX - 1] = "#";
				bottomBoard[inY - 4][inX - 1] = "#";
				bottomBoard[inY - 5][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				std::cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeCarrier();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 2 && inY > 6)		//if the ship would go out of bounds by placing it here it will recall the function
		{
			std::cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeCarrier();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 2 && inY <= 6)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY][inX - 1] != "#" && bottomBoard[inY + 1][inX - 1] != "#" && bottomBoard[inY + 2][inX - 1] != "#" && bottomBoard[inY + 3][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going down
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY][inX - 1] = "#";
				bottomBoard[inY + 1][inX - 1] = "#";
				bottomBoard[inY + 2][inX - 1] = "#";
				bottomBoard[inY + 3][inX - 1] = "#";
			}
			else	//if the boat will overlap
			{
				std::cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeCarrier();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 3 && inX < 5)		//if the ship would go out of bounds by placing it here it will recall the function
		{
			std::cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeCarrier();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 3 && inX >= 5)	//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 1][inX - 2] != "#" && bottomBoard[inY - 1][inX - 3] != "#" && bottomBoard[inY - 1][inX - 4] != "#" && bottomBoard[inY - 1][inX - 5] != "#")
			{
				// outputs a ship symbol at the coordinates going left
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 1][inX - 2] = "#";
				bottomBoard[inY - 1][inX - 3] = "#";
				bottomBoard[inY - 1][inX - 4] = "#";
				bottomBoard[inY - 1][inX - 5] = "#";
			}
			else     //if the boat will overlap
			{
				std::cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeCarrier();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX > 6)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			std::cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeCarrier();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 4 && inX <= 6)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 1][inX] != "#" && bottomBoard[inY - 1][inX + 1] != "#" && bottomBoard[inY - 1][inX + 2] != "#" && bottomBoard[inY - 1][inX + 3] != "#")
			{
				// outputs a ship symbol at the coordinates going right
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 1][inX] = "#";
				bottomBoard[inY - 1][inX + 1] = "#";
				bottomBoard[inY - 1][inX + 2] = "#";
				bottomBoard[inY - 1][inX + 3] = "#";
			}
			else     //if the boat will overlap
			{
				std::cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeCarrier();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD < 1 || inD > 4)	//if the direction isnt valid
		{
		std::cout << "Invalid Input" << endl;	//informs the player they entered an invalid direction
			placeCarrier();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
	}
}

void Game::placeBattleship()		//lets the player place their battleship
{
	for (int l = 0; l == 0; l++)
	{
		int inX;	//initializes the users x coord input
		int inY;	//initializes the users y coord input
		int inD;	//initializes the users direction input


		std::cout << "Please enter the first X Coordinate of your Battleship: ";
		std::cin >> inX;		//gets the users input for the x coord
		if (inX < 1 || inX > 10)	//makes sure that the user chose a number between 1 and 10 inclusive
		{
			std::cout << "Invalid Coordinate" << endl;		//informs the player they entered an invalid coordinate
			placeBattleship();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}

		std::cout << "Please enter the first Y Coordinate of your Battleship: ";
		std::cin >> inY;		//gets the users input for the y coord
		if (inY < 1 || inY > 10)	//makes sure that the user chose a number between 1 and 10 inclusive
		{
			std::cout << "Invalid Coordinate" << endl;	//informs the player they entered an invalid coordinate
			placeBattleship();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}

		std::cout << "Please enter 1 for the ship to go up, 2 for it to go down, 3 for the ship to go left, and 4 to go right: ";
		std::cin >> inD;		//gets the users input for the direction
		if (inD == 1 && inY < 4)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			std::cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeBattleship();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 1 && inY >= 4)	//if the ship will be in bounds
		{

			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 2][inX - 1] != "#" && bottomBoard[inY - 3][inX - 1] != "#" && bottomBoard[inY - 4][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going up
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 2][inX - 1] = "#";
				bottomBoard[inY - 3][inX - 1] = "#";
				bottomBoard[inY - 4][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";     //informs the user they cannot overlap ships
				placeBattleship();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 2 && inY > 7)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeBattleship();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 2 && inY <= 7)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY][inX - 1] != "#" && bottomBoard[inY + 1][inX - 1] != "#" && bottomBoard[inY + 2][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going down
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY][inX - 1] = "#";
				bottomBoard[inY + 1][inX - 1] = "#";
				bottomBoard[inY + 2][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";
				placeBattleship();
				break;
			}
		}
		else if (inD == 3 && inX < 4)
		{
			cout << "\nCannot place ships out of bounds!\n";	//informs the user they cannot overlap ships
			placeBattleship();		//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 3 && inX >= 4)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 1][inX - 2] != "#" && bottomBoard[inY - 1][inX - 3] != "#" && bottomBoard[inY - 1][inX - 4] != "#")
			{
				// outputs a ship symbol at the coordinates going left
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 1][inX - 2] = "#";
				bottomBoard[inY - 1][inX - 3] = "#";
				bottomBoard[inY - 1][inX - 4] = "#";
			}
			else    //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeBattleship();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX > 7)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeBattleship();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 4 && inX <= 7)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 1][inX] != "#" && bottomBoard[inY - 1][inX + 1] != "#" && bottomBoard[inY - 1][inX + 2] != "#")
			{
				// outputs a ship symbol at the coordinates going right
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 1][inX] = "#";
				bottomBoard[inY - 1][inX + 1] = "#";
				bottomBoard[inY - 1][inX + 2] = "#";
			}
			else	//if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeBattleship();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD < 1 || inD > 4)	//if the direction isnt valid
		{
			cout << "Invalid Input" << endl;	//informs the player they entered an invalid direction
			placeBattleship();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
	}
}

void Game::placeCruizer()			//lets the player place their cruiser
{
	for (int l = 0; l == 0; l++)
	{
		int inX;	//initializes the users x coord input
		int inY;	//initializes the users y coord input
		int inD;	//initializes the users direction input


		cout << "Please enter the first X Coordinate of your Cruiser: ";
		cin >> inX;		//gets the users input for the x coord
		if (inX < 1 || inX > 10)	//makes sure that the user chose a number between 1 and 10 inclusive
		{
			cout << "Invalid Coordinate" << endl;		//informs the player they entered an invalid coordinate
			placeCruizer();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}

		cout << "Please enter the first Y Coordinate of your Cruiser: ";
		cin >> inY;		//gets the users input for the y coord
		if (inY < 1 || inY > 10)	//makes sure that the user chose a number between 1 and 10 inclusive
		{
			cout << "Invalid Coordinate" << endl;	//informs the player they entered an invalid coordinate
			placeCruizer();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}

		cout << "Please enter 1 for the ship to go up, 2 for it to go down, 3 for the ship to go left, and 4 to go right: ";
		cin >> inD;		//gets the users input for the direction
		if (inD == 1 && inY < 3)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeCruizer();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 1 && inY >= 3)	//if the ship will be in bounds
		{

			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 2][inX - 1] != "#" && bottomBoard[inY - 3][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going up
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 2][inX - 1] = "#";
				bottomBoard[inY - 3][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";     //informs the user they cannot overlap ships
				placeCruizer();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 2 && inY > 8)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeCruizer();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 2 && inY <= 8)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY][inX - 1] != "#" && bottomBoard[inY + 1][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going down
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY][inX - 1] = "#";
				bottomBoard[inY + 1][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";
				placeCruizer();
				break;
			}
		}
		else if (inD == 3 && inX < 3)
		{
			cout << "\nCannot place ships out of bounds!\n";	//informs the user they cannot overlap ships
			placeCruizer();		//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 3 && inX >= 3)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 1][inX - 2] != "#" && bottomBoard[inY - 1][inX - 3] != "#")
			{
				// outputs a ship symbol at the coordinates going left
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 1][inX - 2] = "#";
				bottomBoard[inY - 1][inX - 3] = "#";
			}
			else    //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeCruizer();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX > 8)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeCruizer();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 4 && inX <= 8)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 1][inX] != "#" && bottomBoard[inY - 1][inX + 1] != "#")
			{
				// outputs a ship symbol at the coordinates going right
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 1][inX] = "#";
				bottomBoard[inY - 1][inX + 1] = "#";
			}
			else	//if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeCruizer();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD < 1 || inD > 4)	//if the direction isnt valid
		{
			cout << "Invalid Input" << endl;	//informs the player they entered an invalid direction
			placeCruizer();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
	}
}

void Game::placeSubmarine()		//lets the player place their submarine
{
	for (int l = 0; l == 0; l++)
	{
		int inX;	//initializes the users x coord input
		int inY;	//initializes the users y coord input
		int inD;	//initializes the users direction input


		cout << "Please enter the first X Coordinate of your Submarine: ";
		cin >> inX;		//gets the users input for the x coord
		if (inX < 1 || inX > 10)	//makes sure that the user chose a number between 1 and 10 inclusive
		{
			cout << "Invalid Coordinate" << endl;		//informs the player they entered an invalid coordinate
			placeSubmarine();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}

		cout << "Please enter the first Y Coordinate of your Submarine: ";
		cin >> inY;		//gets the users input for the y coord
		if (inY < 1 || inY > 10)	//makes sure that the user chose a number between 1 and 10 inclusive
		{
			cout << "Invalid Coordinate" << endl;	//informs the player they entered an invalid coordinate
			placeSubmarine();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}

		cout << "Please enter 1 for the ship to go up, 2 for it to go down, 3 for the ship to go left, and 4 to go right: ";
		cin >> inD;		//gets the users input for the direction
		if (inD == 1 && inY < 3)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeSubmarine();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 1 && inY >= 3)	//if the ship will be in bounds
		{

			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 2][inX - 1] != "#" && bottomBoard[inY - 3][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going up
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 2][inX - 1] = "#";
				bottomBoard[inY - 3][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";     //informs the user they cannot overlap ships
				placeSubmarine();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 2 && inY > 8)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeSubmarine();	//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 2 && inY <= 8)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY][inX - 1] != "#" && bottomBoard[inY + 1][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going down
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY][inX - 1] = "#";
				bottomBoard[inY + 1][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";
				placeSubmarine();
				break;
			}
		}
		else if (inD == 3 && inX < 3)
		{
			cout << "\nCannot place ships out of bounds!\n";	//informs the user they cannot overlap ships
			placeSubmarine();		//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 3 && inX >= 3)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 1][inX - 2] != "#" && bottomBoard[inY - 1][inX - 3] != "#")
			{
				// outputs a ship symbol at the coordinates going left
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 1][inX - 2] = "#";
				bottomBoard[inY - 1][inX - 3] = "#";
			}
			else    //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeSubmarine();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX > 8)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeSubmarine();;		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 4 && inX <= 8)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 1][inX] != "#" && bottomBoard[inY - 1][inX + 1] != "#")
			{
				// outputs a ship symbol at the coordinates going right
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 1][inX] = "#";
				bottomBoard[inY - 1][inX + 1] = "#";
			}
			else	//if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeSubmarine();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD < 1 || inD > 4)	//if the direction isnt valid
		{
			cout << "Invalid Input" << endl;	//informs the player they entered an invalid direction
			placeSubmarine();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
	}
}

void Game::placeDestroyer()		//lets the player place their destroyer
{
	for (int l = 0; l == 0; l++)
	{
		int inX;	//initializes the users x coord input
		int inY;	//initializes the users y coord input
		int inD;	//initializes the users direction input


		cout << "Please enter the first X Coordinate of your Destroyer: ";
		cin >> inX;		//gets the users input for the x coord
		if (inX < 1 || inX > 10)	//makes sure that the user chose a number between 1 and 10 inclusive
		{
			cout << "Invalid Coordinate" << endl;		//informs the player they entered an invalid coordinate
			placeDestroyer();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}

		cout << "Please enter the first Y Coordinate of your Destroyer: ";
		cin >> inY;		//gets the users input for the y coord
		if (inY < 1 || inY > 10)	//makes sure that the user chose a number between 1 and 10 inclusive
		{
			cout << "Invalid Coordinate" << endl;	//informs the player they entered an invalid coordinate
			placeDestroyer();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}

		cout << "Please enter 1 for the ship to go up, 2 for it to go down, 3 for the ship to go left, and 4 to go right: ";
		cin >> inD;		//gets the users input for the direction
		if (inD == 1 && inY < 3)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeDestroyer();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 1 && inY >= 2)	//if the ship will be in bounds
		{

			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 2][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going up
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 2][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";     //informs the user they cannot overlap ships
				placeDestroyer();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 2 && inY > 9)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeDestroyer();	//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 2 && inY <= 9)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going down
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";
				placeDestroyer();
				break;
			}
		}
		else if (inD == 3 && inX < 2)
		{
			cout << "\nCannot place ships out of bounds!\n";	//informs the user they cannot overlap ships
			placeDestroyer();		//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 3 && inX >= 2)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 1][inX - 2] != "#")
			{
				// outputs a ship symbol at the coordinates going left
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 1][inX - 2] = "#";
			}
			else    //if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeDestroyer();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX > 8)	//if the ship would go out of bounds by placing it here it will recall the function
		{
			cout << "\nCannot place ships out of bounds!\n";	//tells the player they cannot place the ship there
			placeDestroyer();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 4 && inX <= 8)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (bottomBoard[inY - 1][inX - 1] != "#" && bottomBoard[inY - 1][inX] != "#" && bottomBoard[inY - 1][inX + 1] != "#")
			{
				// outputs a ship symbol at the coordinates going right
				bottomBoard[inY - 1][inX - 1] = "#";
				bottomBoard[inY - 1][inX] = "#";
			}
			else	//if the boat will overlap
			{
				cout << "\nCannot Overlap Ships!\n";	//informs the user they cannot overlap ships
				placeSubmarine();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD < 1 || inD > 4)	//if the direction isnt valid
		{
			cout << "Invalid Input" << endl;	//informs the player they entered an invalid direction
			placeSubmarine();		//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
	}
}


void Game::placeEnemyCarrier()		//randomly places the enemy carrier
{
	for (int l = 0; l == 0; l++)
	{
		int inX = rand() % 10 + 1;		//initializes the enemy x coord randomly
		int inY = rand() % 10 + 1;		//initializes the enemy y coord randomly

		int inD = rand() % 4 + 1;		//initializes the enemy direction randomly

		if (inD == 1 && inY >= 5)	//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 2][inX - 1] != "#" && enemyBoard[inY - 3][inX - 1] != "#" && enemyBoard[inY - 4][inX - 1] != "#" && enemyBoard[inY - 5][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going up
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 2][inX - 1] = "#";
				enemyBoard[inY - 3][inX - 1] = "#";
				enemyBoard[inY - 4][inX - 1] = "#";
				enemyBoard[inY - 5][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				placeEnemyCarrier();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 2 && inY > 5)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyCarrier();	//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 2 && inY <= 6)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY][inX - 1] != "#" && enemyBoard[inY + 1][inX - 1] != "#" && enemyBoard[inY + 2][inX - 1] != "#" && enemyBoard[inY + 3][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going down
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY][inX - 1] = "#";
				enemyBoard[inY + 1][inX - 1] = "#";
				enemyBoard[inY + 2][inX - 1] = "#";
				enemyBoard[inY + 3][inX - 1] = "#";
			}
			else
			{
				placeEnemyCarrier();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 3 && inY < 6)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyCarrier();	//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 3 && inX >= 5)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 1][inX - 2] != "#" && enemyBoard[inY - 1][inX - 3] != "#" && enemyBoard[inY - 1][inX - 4] != "#" && enemyBoard[inY - 1][inX - 5] != "#")
			{
				// outputs a ship symbol at the coordinates going left
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 1][inX - 2] = "#";
				enemyBoard[inY - 1][inX - 3] = "#";
				enemyBoard[inY - 1][inX - 4] = "#";
				enemyBoard[inY - 1][inX - 5] = "#";
			}
			else     //if the boat will overlap
			{
				placeEnemyCarrier();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX > 5)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyCarrier();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 4 && inX <= 6)	//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 1][inX] != "#" && enemyBoard[inY - 1][inX + 1] != "#" && enemyBoard[inY - 1][inX + 2] != "#" && enemyBoard[inY - 1][inX + 3] != "#")
			{
				// outputs a ship symbol at the coordinates going right
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 1][inX] = "#";
				enemyBoard[inY - 1][inX + 1] = "#";
				enemyBoard[inY - 1][inX + 2] = "#";
				enemyBoard[inY - 1][inX + 3] = "#";
			}
			else     //if the boat will overlap
			{
				placeEnemyCarrier();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX < 6)		//if the ship would go out of bounds by placing it here
		{
			placeEnemyCarrier();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
	}
}

void Game::placeEnemyBattleship()			//randomly places the enemy battleship
{
	for (int l = 0; l == 0; l++)
	{
		int inX = rand() % 10 + 1;		//initializes the enemy x coord randomly
		int inY = rand() % 10 + 1;		//initializes the enemy y coord randomly

		int inD = rand() % 4 + 1;		//initializes the enemy direction randomly

		if (inD == 1 && inY >= 4)	//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 2][inX - 1] != "#" && enemyBoard[inY - 3][inX - 1] != "#" && enemyBoard[inY - 4][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going up
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 2][inX - 1] = "#";
				enemyBoard[inY - 3][inX - 1] = "#";
				enemyBoard[inY - 4][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				placeEnemyBattleship();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 2 && inY > 4)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyBattleship();	//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 2 && inY <= 7)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY][inX - 1] != "#" && enemyBoard[inY + 1][inX - 1] != "#" && enemyBoard[inY + 2][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going down
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY][inX - 1] = "#";
				enemyBoard[inY + 1][inX - 1] = "#";
				enemyBoard[inY + 2][inX - 1] = "#";
			}
			else
			{
				placeEnemyBattleship();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 3 && inY < 7)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyBattleship();	//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 3 && inX >= 4)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 1][inX - 2] != "#" && enemyBoard[inY - 1][inX - 3] != "#" && enemyBoard[inY - 1][inX - 4] != "#")
			{
				// outputs a ship symbol at the coordinates going left
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 1][inX - 2] = "#";
				enemyBoard[inY - 1][inX - 3] = "#";
				enemyBoard[inY - 1][inX - 4] = "#";

			}
			else     //if the boat will overlap
			{
				placeEnemyBattleship();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX > 4)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyBattleship();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 4 && inX <= 7)	//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 1][inX] != "#" && enemyBoard[inY - 1][inX + 1] != "#" && enemyBoard[inY - 1][inX + 2] != "#")
			{
				// outputs a ship symbol at the coordinates going right
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 1][inX] = "#";
				enemyBoard[inY - 1][inX + 1] = "#";
				enemyBoard[inY - 1][inX + 2] = "#";
			}
			else     //if the boat will overlap
			{
				placeEnemyBattleship();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX < 7)		//if the ship would go out of bounds by placing it here
		{
			placeEnemyBattleship();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
	}
}

void Game::placeEnemyCruizer()		//randomly places the enemy cruizer / submarine
{
	for (int l = 0; l == 0; l++)
	{
		int inX = rand() % 10 + 1;		//initializes the enemy x coord randomly
		int inY = rand() % 10 + 1;		//initializes the enemy y coord randomly

		int inD = rand() % 4 + 1;		//initializes the enemy direction randomly

		if (inD == 1 && inY >= 3)	//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 2][inX - 1] != "#" && enemyBoard[inY - 3][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going up
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 2][inX - 1] = "#";
				enemyBoard[inY - 3][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				placeEnemyCruizer();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 2 && inY > 3)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyCruizer();	//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 2 && inY <= 8)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY][inX - 1] != "#" && enemyBoard[inY + 1][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going down
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY][inX - 1] = "#";
				enemyBoard[inY + 1][inX - 1] = "#";
			}
			else
			{
				placeEnemyCruizer();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 3 && inY < 8)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyCruizer();	//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 3 && inX >= 3)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 1][inX - 2] != "#" && enemyBoard[inY - 1][inX - 3] != "#")
			{
				// outputs a ship symbol at the coordinates going left
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 1][inX - 2] = "#";
				enemyBoard[inY - 1][inX - 3] = "#";

			}
			else     //if the boat will overlap
			{
				placeEnemyCruizer();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX > 3)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyCruizer();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 4 && inX <= 8)	//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 1][inX] != "#" && enemyBoard[inY - 1][inX + 1] != "#")
			{
				// outputs a ship symbol at the coordinates going right
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 1][inX] = "#";
				enemyBoard[inY - 1][inX + 1] = "#";
			}
			else     //if the boat will overlap
			{
				placeEnemyCruizer();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX < 8)		//if the ship would go out of bounds by placing it here
		{
			placeEnemyCruizer();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
	}
}


void Game::placeEnemyDestroyer()		//randomly places the enemy destroyer
{
	for (int l = 0; l == 0; l++)
	{
		int inX = rand() % 10 + 1;		//initializes the enemy x coord randomly
		int inY = rand() % 10 + 1;		//initializes the enemy y coord randomly

		int inD = rand() % 4 + 1;		//initializes the enemy direction randomly

		if (inD == 1 && inY >= 2)	//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 2][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going up
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 2][inX - 1] = "#";
			}
			else     //if the boat will overlap
			{
				placeEnemyDestroyer();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 2 && inY > 2)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyDestroyer();	//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 2 && inY <= 9)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY][inX - 1] != "#")
			{
				// outputs a ship symbol at the coordinates going down
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY][inX - 1] = "#";
			}
			else
			{
				placeEnemyDestroyer();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 3 && inY < 9)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyDestroyer();	//recalls the function
			break;		//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 3 && inX >= 2)		//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 1][inX - 2] != "#")
			{
				// outputs a ship symbol at the coordinates going left
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 1][inX - 2] = "#";
			}
			else     //if the boat will overlap
			{
				placeEnemyDestroyer();		//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX > 2)	//if the ship would go out of bounds by placing it here
		{
			placeEnemyDestroyer();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
		else if (inD == 4 && inX <= 9)	//if the ship will be in bounds
		{
			//make sure no part of where the boat will be placed is already in use
			if (enemyBoard[inY - 1][inX - 1] != "#" && enemyBoard[inY - 1][inX] != "#")
			{
				// outputs a ship symbol at the coordinates going right
				enemyBoard[inY - 1][inX - 1] = "#";
				enemyBoard[inY - 1][inX] = "#";
			}
			else     //if the boat will overlap
			{
				placeEnemyDestroyer();	//recalls the function
				break;		//breaks so the current instance of the function ends once the new one starts
			}
		}
		else if (inD == 4 && inX < 9)		//if the ship would go out of bounds by placing it here
		{
			placeEnemyDestroyer();	//recalls the function
			break;	//breaks so the current instance of the function ends once the new one starts
		}
	}
}

void Game::playerTurn()		//the set of actions that makeup the players turn
{
	int inX;
	int inY;

	for (int l = 0; l == 0; l++)
	{
		cout << "\nEnter the X coordintate of where you want to attack: ";
		cin >> inX;		//takes in the players x input
		if (inX > 10 || inX < 1)	//checks to make sure its a valid input
		{
			cout << "\nInvalid Input\n";	// tells the user their input is invalid
			playerTurn();	//recalls the function
			break;		//breaks so the current iteration of the function ends once the new one starts
		}

		cout << "\nEnter the Y coordinate of where you want to attack: ";
		cin >> inY;		//takes in the players y input
		if (inY > 10 || inY < 1)	//checks to make sure its a valid input
		{
			cout << "\nInvalid Input\n";		// tells the user their input is invalid
			playerTurn();		//recalls the function
			break;		//breaks so the current iteration of the function ends once the new one starts
		}

		//outputs if the input is a hit or miss and updates the board acordingly
		if (enemyBoard[inY - 1][inX - 1] == "#")
		{
			cout << "HIT!!!\n";		//outputs hit
			hits = hits + 1;		//increases player hit count
			enemyBoard[inY - 1][inX - 1] = "H";		//updates the enemy board with a hit
			topBoard[inY - 1][inX - 1] = "H";		//updates the top board with a hit
		}
		else
		{
			cout << "Miss\n";		//outputs miss
			enemyBoard[inY - 1][inX - 1] = "M";		//updates the enemy board with a miss
			topBoard[inY - 1][inX - 1] = "M";		//updates the top board with a miss
		}


	}

}

void Game::game()		//main game loop
{
	bool surrender = false;		//used to determine if the player surrenders or not
	while (surrender == false)
	{
		string turnStat;		//variable used to determine if the player plays or not
		int inX;		//used for enemy input
		int inY;		//used for enemy input


		cout << "\nDo you want to keep playing? (Y/N): ";
		cin >> turnStat;	//finds out if the player wants to play or surrender

		if (turnStat == "y")	//if yes then run player turn
		{
			playerTurn();
		}
		else if (turnStat == "n")		//if no, end game
		{
			surrender = true;
		}
		else if (turnStat != "y" && "n")
		{
			cout << "Invalid input \n";
			game();
		}

		if (hits == enemyHitPoints)		//if player has made 17 hits then player wins	
		{
			cout << "You Win, you sunk all enemy ships!";
			break;
		}

		//enemy randomly selects position to fire
		inX = rand() % 10 + 1;
		inY = rand() % 10 + 1;

		// if enemy hits cout hit and alter boards accordingly and adds to enemy hit count
		if (bottomBoard[inY - 1][inX - 1] == "#")
		{
			cout << "Enemy got a Hit!!!\n";
			enemyTopBoard[inY - 1][inX - 1] = "H";
			bottomBoard[inY - 1][inX - 1] = "H";
		}
		else     // if enemy hits cout miss and alter boards accordingly and adds to enemy hit count
		{
			cout << "Enemy missed.\n";
			enemyTopBoard[inY - 1][inX - 1] = "M";
			bottomBoard[inY - 1][inX - 1] = "M";
		}

		//if enemy hit all of players points then player loses
		if (enemyHits == playerHitPoints)
		{
			cout << "The enemy sunk your fleet, you lose.";
			break;
		}

		showBoards();
	}
}