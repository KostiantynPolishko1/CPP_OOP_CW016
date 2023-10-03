#pragma once

#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
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
char** createGrid(short size){
    char** arr = new char* [size];
    for (short i = 0; i < size; i++)
        arr[i] = new char[size];

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
        delete[] arr[i];
        arr[i] = nullptr;
    }
    delete[] arr;
    arr = nullptr;
}
;
inline bool checkGrid(short value, short sizeGrid){

    if (value >= sizeGrid || value < 0)
        return true;
    return false;
}
;
bool stepByGrid(short ind, char** arrGrid, const short sizeGrid, short& Row, short& Col,
const char symbol, const char empty)
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
		arrGrid[Row][Col] = symbol;
		return true;
	case A:
		if (checkGrid(Col - 1, sizeGrid)) {
			cout << "\n\tERROR!\n";
			return false;
		}
		arrGrid[Row][Col] = empty;
		Col--;
		arrGrid[Row][Col] = symbol;
		return true;
	case S:
		if (checkGrid(Row - 1, sizeGrid)) {
			cout << "\n\tERROR!\n";
			return false;
		}
		arrGrid[Row][Col] = empty;
		Row--;
		arrGrid[Row][Col] = symbol;
		return true;
	case D:
		if (checkGrid(Col + 1, sizeGrid)) {
			cout << "\n\tERROR!\n";
			return false;
		}
		arrGrid[Row][Col] = empty;
		Col++;
		arrGrid[Row][Col] = symbol;
		return true;
	case Z:
		return true;
	default:
		cout << "\n\tEXIT\n";
		exit(0);
	}
}
;
#endif