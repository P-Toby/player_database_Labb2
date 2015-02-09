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
	
	string readFirstName;
	string readLastName;
	int readBirthyear = 0;
	int readNumOfMatches = 0;
	int numOfPlayersFromFile = 0;

	Player* playerArr = nullptr;
	playerArr = getTeam(numOfPlayersFromFile, fileName); //Call the function that fetches all the players from the file
	

	int quit = 0;
	int choice = 0; //Variable that is altered by user to decide which function to run.

	while (quit != 1)
	{
		
		choice = menu();

		if (choice == 1)
		{
			//When we delete the playerArr the delete command will 
			//first trigger each objects destructor which deletes 
			//their respective dynamic arrays
			delete[] playerArr;
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
			ofstream dataOut;
			dataOut.open("playerDB_list.txt");

			if (dataOut.is_open())
			{
				dataOut << numOfPlayersFromFile << endl; //Write number of players first

				for (int i = 0; i < numOfPlayersFromFile; ++i)
				{
					//We now write back all of the data to the file, including modifications using the save function
					playerArr[i].save(dataOut);
				}

				dataOut.close();
			}
			else
			{
				cout << "Error, could not open file!";
			}
		}
		else if (choice == 5)
		{
			//Not part of the main program!
			cout << "\nSECRET FUNCTION!" << endl;

			Player newPlayer = playerArr[0];
			cout << playerArr[0].toString();
			//Change the name
			newPlayer.firstName = "Kalle";
			cout << "Name changed" << endl;
			newPlayer.lastName = "Svensson";
			cout << "Lastname changed" << endl;
			newPlayer.birthYear = 1929;
			cout << "Birthyear changed" << endl;
			cout << newPlayer.toString();
			//add new matchdate
			newPlayer.addMatchDate("tst"); //BREAKS ORIGINAL
			cout << newPlayer.toString();
			cout << playerArr[0].toString() << endl; 
			/*If we do not have a copy constructor and we add a date 
			to the newPlayer, the addMatchDate function will create a new array and delete the old one,
			however, the original object will still be referencing the old allocated space that no longer exists.
			This is the cause of the error. But now that we copy the arrays properly, that issue no longer occurs,
			since they have their own respective matchDate arrays.
			*/
		}

	}

	return 0;
}