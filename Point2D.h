#pragma once

#ifndef POIN2D_H
#define POINT2D_H

class Point2D final
{
private:
	short _row;
	short _col;

public:
	Point2D() : _row(0), _col(0) {}
	Point2D(short Row, short Col) : _row(Row), _col(Col) {}
	Point2D(const Point2D &p2D) : _row(p2D._row), _col(p2D._col) {}

	short getRow() const;
	short getCol() const;

	void setRow(short Row);
	void setCol(short Col);
}
;
#endif