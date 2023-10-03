#pragma once
#ifndef MENUWASD_H
#define MENUWASD_H

#include <iostream>
using std::cout;
using std::cin;

short indexMenu(short& indMenu, const short size) {

    short indMin = 0;
    char direct = ' ';

    cout << " w|a|s|d|z -> ";
    direct = cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    system("CLS");

    while (true) {

        if (direct == 'e' || direct == 'E')
            indMenu = EXIT;
        else if (direct == 'w' || direct == 'W')
            indMenu = W;
        else if (direct == 'a' || direct == 'A')
            indMenu = A;
        else if (direct == 's' || direct == 'S')
            indMenu = S;
        else if (direct == 'd' || direct == 'D')
            indMenu = D;
        else if (direct == 'z' || direct == 'Z')
            indMenu = Z;
        else
        {
            cout << "\n\tERROR!";
            cout << "\n\t\"w\" - Down, \"a\" - Left, \"s\" - Up: ->, \"d\" - Right, \"z\" - Undo";
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