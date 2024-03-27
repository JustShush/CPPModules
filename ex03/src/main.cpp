#include "../inc/Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);
bool	checkTriangle(Point const a, Point const b, Point const c);

int	main(void) {
	Point a(2.5f, 3.5f);
	Point b(1.2f, 2.2f);
	Point c(5.4f, 3.0f);

	if (checkTriangle(a, b, c)) {
		std::cout << "Not a Valid Triangle!\n";
		return (1);
	}

	Point p[] = {
		Point(1.0, 1.0),
		Point(2.5f, 3.5f),
		Point(3.0, 3.0),
		Point(5.0, 3.0)
	};
	
	int size = sizeof(p) / 8;
	for (int i = 0; i < size; i++) {
		if (bsp(a, b, c, p[i])) {
			std::cout << "Point (" << p[i].getX() << ", ";
			std::cout << p[i].getY() << ") IS inside the triangle\n";
		} else {
			std::cout << "Point (" << p[i].getX() << ", ";
			std::cout << p[i].getY() << ") is NOT inside the triangle\n";
		}
	}
}
