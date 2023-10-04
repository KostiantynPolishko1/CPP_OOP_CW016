#include "Point2D.h"
#include <iostream>

inline void checkRAM(short** arr) {
	if (!arr) {
		throw new std::runtime_error("no RAM available");
		exit(-1);
	}
}
;
inline void checkRAM(short* arr) {
	if (!arr) {
		throw new std::runtime_error("no RAM available");
		exit(-1);
	}
}
;
short Point2D::getRow() const {
	return _row;
}
;
short Point2D::getCol() const {
	return _col;
}
;
void Point2D::setRow() {
	_row++;
}
;
void Point2D::setCol() {
	_col++;
}
;
void Point2D::dsetRow() {
	_row--;
}
;
void Point2D::dsetCol() {
	_col--;
}
;
void Point2D::resetRow() {
	_row = _arrRowCol[_count - 1][0];
}
;
void Point2D::resetCol() {
	_col = _arrRowCol[_count - 1][1];
}
;
short Point2D::getCount() const {
	return _count;
}
;
short** Point2D::getArrRowCol() const {
	return _arrRowCol;
}
;
void Point2D::incrementCount() {
	_count++;
}
;
void Point2D::decreaseCount() {
	_count--;
}
;
short** Point2D::initArrRowCol()
{
	short** arr = new short* [_count];
	checkRAM(arr);

	for (short i = 0; i < _count; i++) {
		arr[i] = new short[2];
		checkRAM(arr[i]);
	}

	return arr;
}
;
void Point2D::copyArrRowCol(short** arr, short** arr2, short count)
{
	for (short i = 0; i < count; i++) {
		arr[i][0] = arr2[i][0];
		arr[i][1] = arr2[i][1];
	}
}
;
void Point2D::deleteArrRowCol(short** arr, short count)
{
	for (short i = 0; i < count; i++) {
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
void Point2D::increaseArrRowCol() {

	short** arrTemp = initArrRowCol();

	copyArrRowCol(arrTemp, _arrRowCol, _count);

	deleteArrRowCol(_arrRowCol, _count);

	incrementCount();
	_arrRowCol = initArrRowCol();

	copyArrRowCol(_arrRowCol, arrTemp, _count-1);
	_arrRowCol[_count - 1][0] = _row;
	_arrRowCol[_count - 1][1] = _col;

	deleteArrRowCol(arrTemp, _count - 1);
}
void Point2D::decreaseArrRowCol()
{
	if (_count > 1)
	{
		decreaseCount();

		short** arrTemp = initArrRowCol();

		copyArrRowCol(arrTemp, _arrRowCol, _count);

		deleteArrRowCol(_arrRowCol, _count + 1);

		_arrRowCol = initArrRowCol();

		copyArrRowCol(_arrRowCol, arrTemp, _count);
		resetRow();
		resetCol();

		deleteArrRowCol(arrTemp, _count);
	}
}
;
