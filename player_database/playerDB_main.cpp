//Created by Peyman Torabi

#include <iostream> 
#include <string>
#include <crtdbg.h>
#include <fstream>
#include "Player.h"

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

	ifstream dataIn;
	dataIn.open(fileName.c_str());

	
	
	//We read the very first line and convert it to an int
	//that way we know how many players there are in the file
	string aLine;
	dataIn >> aLine;
	//cout << "AS STRING " << aLine << endl;
	readBirthyear = stoi(aLine);
	//cout << "AS INT " << readBirthyear << endl;


	//We will now read from the rest of the file
	if (dataIn.is_open())
	{
		dataIn >> aLine;

		while (!dataIn.eof())
		{
			//This currently prints out all of the lines
			cout << aLine << endl;
			dataIn >> aLine;
		}
		
	}
	else
	{
		cout << "Cannot open file" << endl;
	}
	

	system("PAUSE");

	return 0;
}