#include "Rgb.h"

Rgb::Rgb(const int r, const int g, const int b) : r(r), g(g), b(b)
{
}

std::ostream& operator << (std::ostream& o, const Rgb& target)
{
	o << "[" << target.r << ", " << target.g << ", " << target.b << "]";
	return o;
}
