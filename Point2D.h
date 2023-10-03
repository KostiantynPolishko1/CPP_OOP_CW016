#pragma once

#ifndef POIN2D_H
#define POINT2D_H

class Point2D final
{
private:
	short _row;
	short _col;
	short _count;
	short** _arrRowCol;

protected:
	void initArrRowCol(short** arr);
	void copyArrRowCol(short** arr, short** arr2);
	void deleteArrRowCol(short** arr);

public:
	Point2D() : _row(0), _col(0), _count(0)
	{
		_arrRowCol = new short* [1];
		_arrRowCol[0] = new short[2];
		_arrRowCol[0][0] = _row;
		_arrRowCol[0][1] = _col;
	}
	Point2D(short Row, short Col) : _row(Row), _col(Col), _count(0)
	{
		_arrRowCol = new short* [1];
		_arrRowCol[0] = new short[2];
		_arrRowCol[0][0] = _row;
		_arrRowCol[0][1] = _col;
	}

	Point2D(const Point2D& p2D) : _row(p2D._row), _col(p2D._col), _count(p2D._count)
	{
		_arrRowCol = new short* [1];
		_arrRowCol[0] = new short[2];
		_arrRowCol[0][0] = p2D._row;
		_arrRowCol[0][1] = p2D._col;
	}

	~Point2D() {
		delete[] _arrRowCol;
		_arrRowCol = nullptr;
	}

	short getRow() const;
	short getCol() const;

	void setRow(short Row);
	void setCol(short Col);

	void increaseArrRowCol();
}
;
#endif