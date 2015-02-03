#include <iostream> //c++
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

string Player::toString()
{
	//In this function we create a string that we can use to easily print out all of the relevant data about a player

	string birthyearAsString;
	ostringstream convert;
	convert << birthYear;
	birthyearAsString = convert.str();

	//We will loop through the array and build a string with all of the match dates and add commasa inbetween
	string matches;
	
	
	for (int i = 0; i < numberOfMatches - 1; ++i)
	{
		matches = matches + matchDates[i] + ", ";
	}

	matches = matches + matchDates[numberOfMatches]; //Append the very last match.
	

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

	}
}

Player::~Player()
{
	//Deconstructor
}

void save(ofstream* out)
{

}