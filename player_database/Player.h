#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <fstream>

//this is the class declaration
class Player
{

public:
	std::string firstName;
	std::string lastName;
	int birthYear;
	std::string* matchDates;

	//Functions
	std::string toString();
	void addMatchDate(std::string date);
	Player();
	Player(std::string firstName, std::string lastName, int birthYear);
	~Player();
	void save(std::ofstream* out);

private:
	int numberOfMatches;
};


#endif