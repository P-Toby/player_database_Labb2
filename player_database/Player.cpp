#include <iostream> 
#include <string>
#include <fstream>
#include "player.h"
#include <sstream>

using namespace std;

Player::Player()
{
	firstName = "John";
	lastName = "Doe";
	birthYear = 1993;
	numberOfMatches = 0;
	matchDates = nullptr;
}

Player::Player(string firstNameIn, string lastNameIn, int birthYearIn)
{
	firstName = firstNameIn;
	lastName = lastNameIn;
	birthYear = birthYearIn;
	numberOfMatches = 0;
	matchDates = nullptr;
}


Player::Player(const Player& other)
{
	//This is the copy constructor
	firstName = other.firstName;
	lastName = other.lastName;
	birthYear = other.birthYear;
	numberOfMatches = other.numberOfMatches;
	//Copy string array
	matchDates = new string[numberOfMatches];

	for (int i = 0; i < numberOfMatches; ++i)
	{
		matchDates[i] = other.matchDates[i];
	}

}

void Player::operator=(const Player& other)
{
	//This is the assignment operator
	firstName = other.firstName;
	lastName = other.lastName;
	birthYear = other.birthYear;
	numberOfMatches = other.numberOfMatches;
	//Copy string array
	matchDates = new string[numberOfMatches];

	for (int i = 0; i < numberOfMatches; ++i)
	{
		matchDates[i] = other.matchDates[i];
	}
}

string Player::toString()
{
	//In this function we create a string that we can use to easily print out all of the relevant data about a player
	string birthyearAsString;
	ostringstream convert;
	convert << birthYear;
	birthyearAsString = convert.str();

	//We will loop through the array and build a string with all of the match dates and add commasa inbetween
	string matches;
	
	if (numberOfMatches != 1)
	{
		for (int i = 0; i < numberOfMatches - 1; ++i)
		{
			matches = matches + matchDates[i] + ", ";
		}
	}
	
	if (numberOfMatches > 0)
	{
		matches = matches + matchDates[numberOfMatches - 1]; //Append the very last match.
	}
	
	string result = "Name: " + firstName + " " + lastName + "\nBirthyear: " + birthyearAsString + "\nMatchdates: " + matches + "\n";

	return result; //We resturn the completed string so that I may be printed out
}

void Player::addMatchDate(string date)
{
	
	if (matchDates == nullptr)
	{
		//If the current player has zero matches we will create an initial array that has room for 1 element
		matchDates = new string[1];
		matchDates[0] = date;
		numberOfMatches = numberOfMatches + 1; //We will also increment the number of games by one
	}
	else
	{
		//If we already have an initial array

		string* tmp = new string[numberOfMatches + 1]; //Make a new array that is 1 element larger

		for (int i = 0; i < numberOfMatches; ++i)
		{
			//We now copy all of the elements to the temporary pointer array
			tmp[i] = matchDates[i];
		}

		numberOfMatches = numberOfMatches + 1; //We increase the number of matches held in the array by 1

		delete[] matchDates;

		matchDates = tmp; //Set the old matchDates pointer to be equal the new array that was created with tmp

		matchDates[numberOfMatches - 1] = date; //Finally we add the new match date to the new, larger, array
	}
}

Player::~Player()
{
	//Destructor
	delete[] matchDates;
}

void Player::save(ofstream& out)
{
		//We now write back all of the data to the file, including modifications
		out << firstName << endl;
		out << lastName << endl;
		out << birthYear << endl;
		out << numberOfMatches << endl;

		for (int j = 0; j < numberOfMatches; ++j)
		{
			out << matchDates[j] << endl;
		}
}

