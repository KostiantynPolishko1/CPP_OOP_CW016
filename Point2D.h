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
	void incrementCount();
	void decreaseCount();
	void resetRow();
	void resetCol();
	short** initArrRowCol();
	void copyArrRowCol(short** arr, short** arr2, short count);

public:
	Point2D() : _row(0), _col(0), _count(1)
	{
		_arrRowCol = new short* [_count];
		_arrRowCol[0] = new short[2];

		_arrRowCol[0][0] = _row;
		_arrRowCol[0][1] = _col;
	}
	Point2D(short row, short col) : _row(row), _col(col), _count(1)
	{
		_arrRowCol = new short* [_count];
		_arrRowCol[0] = new short[2];

		_arrRowCol[0][0] = _row;
		_arrRowCol[0][1] = _col;
	}

	Point2D(const Point2D& p2D) : _row(p2D._row), _col(p2D._col), _count(p2D._count)
	{
		_arrRowCol = new short* [_count];
		_arrRowCol[0] = new short[2];

		_arrRowCol[0][0] = p2D._row;
		_arrRowCol[0][1] = p2D._col;
	}

	/*~Point2D() 
	{
		for (short i = 0; i < _count; i++) {
			delete[] _arrRowCol[i];
			_arrRowCol[i] = nullptr;
		}
		delete[] _arrRowCol;
		_arrRowCol = nullptr;
	}*/

	short getRow() const;
	short getCol() const;
	short getCount() const;
	short** getArrRowCol() const;

	void setRow();
	void setCol();

	void dsetRow();
	void dsetCol();

	void deleteArrRowCol(short** arr, short count);
	void increaseArrRowCol();
	void decreaseArrRowCol();
}
;
#endif