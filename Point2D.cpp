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
void Point2D::initArrRowCol() {
	 _count++;
	_arrRowCol = new short* [_count];
	short arr[2]{};

	for (short i = 0; i < _count; i++)
		_arrRowCol[i] = arr;
}
;
void Point2D::fillArrRowCol() 
{
	initArrRowCol();

	for (short i = 0; i < _count; i++){
		_arrRowCol[i][0] = _row;
		_arrRowCol[i][1] = _col;
	}
}
;