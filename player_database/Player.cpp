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
	matchDates = NULL;
}

Player::Player(string firstNameIn, string lastNameIn, int birthYearIn)
{
	firstName = firstNameIn;
	lastName = lastNameIn;
	birthYear = birthYearIn;
	numberOfMatches = 0;
	matchDates = NULL;
}

Player::~Player()
{
	//Deconstructor
}

void save(ofstream* out)
{

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
	/*
	
	for (int i = 0; i < numberOfMatches - 1; ++i)
	{
		matches = matches + matchDates[i] + ", ";
	}

	matches = matches + matchDates[numberOfMatches]; //Append the very last match.
	*/

	string result = "Name: " + firstName + " " + lastName + "\nBirthyear: " + birthyearAsString + "\nMatchdates: " + matches + "\n";

	return result; //We resturn the completed string so that I may be printed out
}