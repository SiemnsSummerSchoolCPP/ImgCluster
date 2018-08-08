#include "Coord.h"

Coord::Coord(const int x, const int y) : x(x), y(y)
{
}

std::ostream& operator << (std::ostream& o, const Coord& target)
{
	o << "[" << target.x << ", " << target.y << "]";
	return o;
}
