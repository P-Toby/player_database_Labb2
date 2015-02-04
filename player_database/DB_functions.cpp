#include <iostream> 
#include <string>
#include <fstream>
#include "Player.h"

using namespace std;

int menu()
{
	int inputId = 0;
	int input = 0;
	int isValid = 0;


	cout << "Main menu:" << endl;
	cout << "\n1. Quit" << "\n2. Show all players" << "\n3. Add date" << "\n4. Save to file" << endl;

	while (isValid != 1)
	{
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