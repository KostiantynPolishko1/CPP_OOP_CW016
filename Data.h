#pragma once

#ifndef DATA_H
#define DATA_H

enum WASD {
    W,
    A,
    S,
    D,
    EXIT
}
;
short ind(0), Row(0), Col(0), sizeGrid(10);
char symbol('x'), empty('-');
std::string arrWASD[] = { "w - Down", "a - Left", "s - Up", "d - Right", "e - EXIT" };

#endif