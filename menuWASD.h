#pragma once
#ifndef MENUWASD_H
#define MENUWASD_H

#include <iostream>
using std::cout;
using std::cin;

short indexMenu(short& indMenu, const short size) {

    short indMin = 0;
    char direct = ' ';

    cout << " w|a|s|d -> ";
    direct = cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    system("CLS");

    while (true) {

        if (direct == '\n')
            return static_cast<int>(direct);
        else if (direct == 'w' || direct == 'W')
            indMenu = 0;
        else if (direct == 'a' || direct == 'A')
            indMenu = 1;
        else if (direct == 's' || direct == 'S')
            indMenu = 2;
        else if (direct == 'd' || direct == 'D')
            indMenu = 3;
        else
        {
            cout << "\n\tERROR!";
            cout << "\n\t\"w\" - Down, \"a\" - Left, \"s\" - Up: ->, \"d\" - Right, ";
        }

        //reload index menu
        if (indMenu < indMin)
            indMenu = size - 1;
        else if (indMenu > size - 1)
            indMenu = indMin;

        return indMenu;
    }
}
;
void printMenu(std::string* const arr, const short size, std::string nameMenu, const short& indMenu) {

    cout << "\n MENU: " << nameMenu << "\n";

    for (short i = 0; i < size; i++) {
        if (indMenu == i) {
            cout << " -> " << *(arr + i) << "\n";
            continue;
        }
        cout << "    " << *(arr + i) << "\n";
    }
}
;
void selectMenu(std::string* const arr, const short size, std::string nameMenu, short& indMenu) {
    do {
        printMenu(arr, size, nameMenu, indMenu);

    } while (static_cast<char>(indexMenu(indMenu, size)) != '\n');
}
;
#endif // !MENUWASD_H