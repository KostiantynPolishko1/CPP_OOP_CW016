#include "Point2D.h"

short Point2D::getRow() const {
	return _row;
}
;
short Point2D::getCol() const {
	return _col;
}
;
void Point2D::setRow(short Row) {
	_row = Row;
}
;
void Point2D::setCol(short Col) {
	_col = Col;
}
;
void Point2D::initArrRowCol(short** arr)
{
	_count++;
	arr = new short* [_count];

	for (short i = 0; i < _count; i++)
		arr[i] = new short[2];
}
;
void Point2D::copyArrRowCol(short** arr, short** arr2)
{
	for (short i = 0; i < _count; i++) {
		arr[i][0] = arr2[i][0];
		arr[i][1] = arr2[i][1];
	}
}
;
void Point2D::deleteArrRowCol(short** arr)
{
	for (short i = 0; i < _count; i++) {
		delete[] arr[i];
		arr[i] = nullptr;
	}

	delete[] _arrRowCol;
	_arrRowCol = nullptr;
}
;
void Point2D::increaseArrRowCol() {

	short** arrTemp = nullptr;
	initArrRowCol(arrTemp);

	copyArrRowCol(arrTemp, _arrRowCol);

	deleteArrRowCol(_arrRowCol);

	initArrRowCol(_arrRowCol);

	copyArrRowCol(_arrRowCol, arrTemp);
	_arrRowCol[_count - 1][0] = _row;
	_arrRowCol[_count - 1][1] = _col;

	deleteArrRowCol(arrTemp);
}
;