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
void Point2D::incrementCount() {
	_count++;
}
;
short** Point2D::initArrRowCol()
{
	short** arr = new short* [_count];

	for (short i = 0; i < _count; i++)
		arr[i] = new short[2];

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
		delete[] arr[i];
		arr[i] = nullptr;
	}

	delete[] arr;
	arr = nullptr;
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
;