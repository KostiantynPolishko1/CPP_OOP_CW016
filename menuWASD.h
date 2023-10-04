#pragma once
#ifndef MENUWASD_H
#define MENUWASD_H

#include <iostream>

using std::cout;
using std::cin;

short indexMenu(short& indMenu, const short size);

void printMenu(std::string* const arr, const short size, std::string nameMenu, const short& indMenu);

void selectMenu(std::string* const arr, const short size, std::string nameMenu, short& indMenu);

#endif // !MENUWASD_H