#pragma once

#ifndef DB_FUNCTIONS_H
#define DB_FUNCTIONS_H

#include <string>

int menu();
Player* getTeam(int& nrOfPlayers, std::string fileName);

#endif