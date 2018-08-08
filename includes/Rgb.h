#pragma once

#include <ostream>

struct Rgb
{
	int r;
	int g;
	int b;

	Rgb(int r = 0, int g = 0, int b = 0);
	friend std::ostream& operator << (std::ostream& o, const Rgb& target);
};

namespace std
{
	template <>
	struct hash<Rgb>
	{
		std::size_t operator()(const Rgb& k) const
		{
			return
				std::hash<int>()(k.r) ^
				std::hash<int>()(k.g) ^
				std::hash<int>()(k.b);
		}
	};
}
