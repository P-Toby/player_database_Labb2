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
	std::string* matchDates; //Points to an array holding dates

	//Functions
	std::string toString();
	Player();
	Player(std::string firstName, std::string lastName, int birthYear);
	~Player(); //Deconstructor
	Player(const Player& other); //cctor
	void operator=(const Player& other);
	void addMatchDate(std::string date);
	void save(std::ofstream& out);

private:
	int numberOfMatches;
};

#endif