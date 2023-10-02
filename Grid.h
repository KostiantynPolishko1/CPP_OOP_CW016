#pragma once

#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
using std::cout;

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
#endif