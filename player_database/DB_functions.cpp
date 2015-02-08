#include <iostream> 
#include "player.h"
#include <string>
#include <fstream>
#include "DB_functions.h"

using namespace std;

int menu()
{
	//A basic menu system that we can use to access various functions
	int inputId = 0;
	int input = 0;
	int isValid = 0;

	while (isValid != 1)
	{
		cout << "Main menu:" << endl;
		cout << "\n1. Quit" << "\n2. Show all players" << "\n3. Add date" << "\n4. Save to file" << endl;

		printf("\nChoose which function to run: ");
		cin >> inputId;

		if (inputId >= 1 && inputId <= 4)
		{
			isValid = 1;
		}
		else
		{
			cout << "\nInvalid input";
		}
	}

	input = inputId;

	return input;
} 

Player* getTeam(int& nrOfPlayers, string fileName)
{
	string aLine;
	ifstream dataIn;
	dataIn.open(fileName.c_str());

	dataIn >> aLine;
	nrOfPlayers = stoi(aLine); //Now we have the amount of players from the file as an int

	//Now that we know the number of players, we create an array to store them
	Player* team = nullptr;
	team = new Player[nrOfPlayers];

	int matchDatesNum = 0; //Temp variable that holds an int representing the amount of dates
	if (dataIn.is_open())
	{
		for (int i = 0; i < nrOfPlayers && !dataIn.eof(); ++i)
		{

			matchDatesNum = 0; //Reset the number of match dates found every time we loop

			//We now read from the file and store the data in a player object
			dataIn >> aLine;
			team[i].firstName = aLine;
			dataIn >> aLine;
			team[i].lastName = aLine;
			dataIn >> aLine;
			team[i].birthYear = stoi(aLine);
			dataIn >> aLine; //We now read the number of match dates
			matchDatesNum = stoi(aLine);

			for (int j = 0; j < matchDatesNum; ++j)
			{
				//Loop the amount of match dates found
				dataIn >> aLine;
				team[i].addMatchDate(aLine);
			}
		}
	}
	else
	{
		cout << "Cannot open file" << endl;
	}

	return team;
}