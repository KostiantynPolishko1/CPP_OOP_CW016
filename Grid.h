#pragma once

#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
using std::cout;

void createGrid(char** arr, short size){
    arr = new char* [size];
    for (short i = 0; i < size; i++)
        arr[i] = new char[size];
}
;
void showGrid(char **arr, int size) {
    for (short i = 0; i < size; i++) {
        for (short j = 0; j < size; j++) {
            if (arr[i][j]) {
                cout << arr[i][j] << " ";
                continue;
            }
            cout << "-" << " ";
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