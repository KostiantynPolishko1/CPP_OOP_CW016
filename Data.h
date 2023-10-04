#pragma once

#ifndef DATA_H
#define DATA_H

enum WASD {
	W,
	A,
	S,
	D,
	Z,
	EXIT
}
;
short ind(0), sizeGrid(10), sizeOffset(3);
char symbolPlayer('x'), symbolCell('-'), symbolPrize('&'), symbolStep{};
std::string arrWASD[] = { "w - Down", "a - Left", "s - Up", "d - Right", "z - Undo", "e - EXIT" };

#endif