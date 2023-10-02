#pragma once

#ifndef POIN2D_H
#define POINT2D_H

class Point2D final
{
private:
	int _x;
	int _y;

public:
	Point2D() : _x(0), _y(0) {}
	Point2D(int x, int y) : _x(x), _y(y) {}
	Point2D(const Point2D &p2D) : _x(p2D._x), _y(p2D._y) {}

	int getX() const;
	int getY() const;

	inline void setX(int x);
	inline void setY(int y);
}
;
#endif