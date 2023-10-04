#pragma once

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <time.h>
using std::cout;

enum WASD {
    W,
    A,
    S,
    D,
	Z,
    EXIT
}
;
inline void checkRAM(char** arr) {
	if (!arr) {
		throw new std::runtime_error("no RAM available");
		exit(-1);
	}
}
;
inline void checkRAM(char* arr) {
	if (!arr) {
		throw new std::runtime_error("no RAM available");
		exit(-1);
	}
}
;
char** createGrid(short size){
    char** arr = new char* [size];
	checkRAM(arr);

	for (short i = 0; i < size; i++) {
        arr[i] = new char[size];
		checkRAM(arr[i]);
	}

    return arr;
}
;
void fillGrid(char** arr, short size, char empty = ' ') {
    for (short i = 0; i < size; i++)
        for (short j = 0; j < size; j++)
            arr[i][j] = empty;
}
;
void showGrid(char **arr, int size, char empty) {
    for (short i = 0; i < size; i++) {
        for (short j = 0; j < size; j++) {
            if (arr[i][j] !=  empty ) 
            {
                cout << arr[i][j] << " ";
                continue;
            }
            cout << empty << " ";
        }
        cout << "\n";
    }
}
;
void deleteGrid(char** arr, short size) {
    for (short i = 0; i < size; i++){
		if (arr[i]) {
			delete[] arr[i];
			arr[i] = nullptr;
		}
    }
	if (arr) {
		delete[] arr;
		arr = nullptr;
	}
}
;
inline bool checkGrid(short value, short sizeGrid){

    if (value >= sizeGrid || value < 0)
        return true;
    return false;
}
;
bool stepByGrid(short ind, char** arrGrid, const short sizeGrid, short& Row, short& Col,
const char symbol, const char empty, char& step, Point2D& p2d)
{

	switch (ind) 
	{
	case W:
		if (checkGrid(Row + 1, sizeGrid)) {
			cout << "\n\tERROR!\n";
			return false;
		}
		arrGrid[Row][Col] = empty;
		Row++;
		step = arrGrid[Row][Col];
		arrGrid[Row][Col] = symbol;
		return true;
	case A:
		if (checkGrid(Col - 1, sizeGrid)) {
			cout << "\n\tERROR!\n";
			return false;
		}
		arrGrid[Row][Col] = empty;
		Col--;
		step = arrGrid[Row][Col];
		arrGrid[Row][Col] = symbol;
		return true;
	case S:
		if (checkGrid(Row - 1, sizeGrid)) {
			cout << "\n\tERROR!\n";
			return false;
		}
		arrGrid[Row][Col] = empty;
		Row--;
		step = arrGrid[Row][Col];
		arrGrid[Row][Col] = symbol;
		return true;
	case D:
		if (checkGrid(Col + 1, sizeGrid)) {
			cout << "\n\tERROR!\n";
			return false;
		}
		arrGrid[Row][Col] = empty;
		Col++;
		step = arrGrid[Row][Col];
		arrGrid[Row][Col] = symbol;
		return true;
	case Z:
		arrGrid[p2d.getRow()][p2d.getCol()] = empty;
		p2d.decreaseArrRowCol();
		arrGrid[p2d.getRow()][p2d.getCol()] = symbol;
		return true;
	default:
		cout << "\n\tEXIT\n";
		return true;
	}
}
;
short randomCell(const short sizeGrid, const short sizeOffset) {
	srand(time(NULL));
	return sizeOffset + rand() % (sizeGrid - sizeOffset * 2);
}
;
#endif