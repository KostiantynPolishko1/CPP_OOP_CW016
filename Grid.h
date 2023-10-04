#pragma once

#ifndef GRID_H
#define GRID_H

#include "Point2D.h"
#include <iostream>
#include <time.h>

using std::cout;


inline bool modifyCell(char** arrGrid, Point2D& p2d, char& step, const char& symbol);

inline void checkRAM(char** arr);

inline void checkRAM(char* arr);

char** createGrid(short size);

void fillGrid(char** arr, short size, char empty = ' ');

void showGrid(char** arr, int size, char empty);

void deleteGrid(char** arr, short size);

inline bool checkGrid(short value, short sizeGrid);

bool stepByGrid(short ind, char** arrGrid, const short sizeGrid, const char symbol, const char empty, char& step, Point2D& p2d);

short randomCell(const short sizeGrid, const short sizeOffset);

#endif