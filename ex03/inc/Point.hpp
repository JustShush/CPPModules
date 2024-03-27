#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float a, const float b);
		Point(const Point &n);

		Point& operator=(const Point &n);

		~Point();

		Fixed	getX() const;
		Fixed	getY() const;
};

#endif