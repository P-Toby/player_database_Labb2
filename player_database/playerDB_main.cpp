//Created by Peyman Torabi

#include <iostream> //c++
#include <string>
#include <crtdbg.h>
#include <fstream>
#include "Player.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	string fileName;
	
	cout << "What is the name of the file?:\n";
	cin >> fileName;

	ifstream dataIn;
	dataIn.open(fileName.c_str());

	if (dataIn.is_open())
	{
		string aLine;
		dataIn >> aLine;
		while (!dataIn.eof())
		{
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