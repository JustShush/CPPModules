#include "../inc/Point.hpp"

Fixed	abs(Fixed f) {
	if (f < 0)
		return (f * (-1));
	return (f);
}

Fixed	area(Point const a, Point const b, Point const c) {
	Fixed A, B, C;
	A = a.getX() * (b.getY() - c.getY());
	B = b.getX() * (c.getY() - a.getY());
	C = c.getX() * (a.getY() - b.getY());
	return(abs((A + B + C)/2));
}

bool	checkTriangle(Point const a, Point const b, Point const c) {
	if (area(a, b, c) == 0)
		return (1);
	return (0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed A = area(a, b ,c);
	if (A == 0)
		return (0);

	Fixed PAB = area(point, a, b);
	Fixed PAC = area(point, a ,c);
	Fixed PBC = area(point, b, c);

	if (PAB == 0 || PAC == 0 || PBC == 0)
		return (0);

	if (A == (PAB + PAC + PBC))
		return (1);
	return (0);
}
