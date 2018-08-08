#pragma once

#include <ostream>

struct Coord
{
	int x;
	int y;

	Coord(int x = 0, int y = 0);
	
	friend bool operator == (const Coord& lhs, const Coord& rhs)
	{
		return (lhs.x == rhs.x) && (lhs.y == rhs.y);
	}
	
	friend std::ostream& operator << (std::ostream& o, const Coord& target);
};

namespace std
{
	template<>
	struct hash<Coord>
	{
		size_t operator() (const Coord& k) const
		{
			return
				std::hash<int>()(k.x) ^
				std::hash<int>()(k.y);
		}
	};
}
