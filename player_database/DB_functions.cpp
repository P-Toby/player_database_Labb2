#include <iostream> 

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