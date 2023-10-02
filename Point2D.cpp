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