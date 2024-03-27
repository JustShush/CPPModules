#include "../inc/Point.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Point::Point() : x(0), y(0) {}

Point::Point(const Point &copy)  : x(copy.x), y(copy.y) {
	*this = copy;
}

Point& Point::operator=(const Point &copy_a) {
	(void)copy_a;
	return (*this);
}

Point::~Point() {}
// ---------------------- Orthodox Canonical Form -----------------------------

Point::Point(const float a, const float b) : x(a), y(b) {}

Fixed Point::getX() const {
	return (x);
}

Fixed Point::getY() const {
	return (y);
}