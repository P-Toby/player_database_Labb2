//Created by Peyman Torabi

#include <iostream> 
#include <string>
#include <crtdbg.h>
#include <fstream>
#include "Player.h"
#include "DB_functions.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	string fileName = "playerDB_list.txt";
	
	//cout << "What is the name of the file?:\n";
	//cin >> fileName;

	
	string readFirstName;
	string readLastName;
	int readBirthyear = 0;
	int readNumOfMatches = 0;

	int numOfPlayersFromFile;

	ifstream dataIn;
	dataIn.open(fileName.c_str());

	
	
	//We read the very first line and convert it to an int
	//that way we know how many players there are in the file
	string aLine;
	dataIn >> aLine;
	numOfPlayersFromFile = stoi(aLine); //Now we have the amount of players from the file as an int

	Player* playerArr;
	playerArr = new Player[numOfPlayersFromFile]; //Create an array to hold all of the players

	/*
	1. read number of structures from file, create array with n structures for players
	2. start read loop for n structures(function?)
		1. read first name
		2. read last name
		3. read birth year
		4. read number of matches. 
		5. use number of matches to read x lines, place each in array of matches in player structures
	*/

	//We will now read from the rest of the file and store all of the players found
	int matchDatesNum = 0; //Temp variable that holds an int representing the amount of dates
	if (dataIn.is_open())
	{
		for (int i = 0; i < numOfPlayersFromFile && !dataIn.eof(); ++i)
		{

			matchDatesNum = 0; //Reset the number of match dates found every time we loop

			//cout << "FOR LOOPING" << endl;
			dataIn >> aLine;
			playerArr[i].firstName = aLine;
			dataIn >> aLine;
			playerArr[i].lastName = aLine;
			dataIn >> aLine;
			playerArr[i].birthYear = stoi(aLine);
			dataIn >> aLine; //We now read the number of match dates
			matchDatesNum= stoi(aLine);

			//cout << "DATE: " << endl;
			for (int j = 0; j < matchDatesNum; ++j)
			{
				//Loop the amount of match dates found
				dataIn >> aLine;
				playerArr[i].addMatchDate(aLine);
			}
		}
	}
	else
	{
		cout << "Cannot open file" << endl;
	}
	

	int quit = 0;
	int choice = 0; //Variable that is altered by user to decide which function to run.

	while (quit != 1)
	{
		choice = menu();

		if (choice == 1)
		{
			//delete[] playerArr;
			quit = 1;
		}
		else if (choice == 2)
		{
			//We print out all of the players stats using the toString function
			for (int i = 0; i < numOfPlayersFromFile; ++i)
			{
				cout << "#" << i+1 << " " << playerArr[i].toString() << endl;
			}
		}
		else if (choice == 3)
		{
			//This is the choice the user selects to add new dates to the players
			int playerChoice = 0;
			string newDate;
			cout << "\nWhich player would you like to add a date for?" << "\nUse function number 2 to see the numbers associated with each player." << endl;
		
			cin >> playerChoice;

			while (!(playerChoice <= numOfPlayersFromFile && playerChoice >= 1))
			{
				//The player enters the number of the player that they wish to add a date for
				cout << "Invalid input!\n" << "Enter a number between 1 and " << numOfPlayersFromFile << endl;
				cin >> playerChoice;
			}

			cout << "Enter the new date that you wish to add, in the format YYYYMMDD: ";
			cin >> newDate;
			playerArr[playerChoice - 1].addMatchDate(newDate);
			
		}
		else if (choice == 4)
		{
			//We will now save any changes made to the txt file
		}

	}

	
	



	system("PAUSE");

	return 0;
}