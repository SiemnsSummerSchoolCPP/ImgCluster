#pragma once

#include <ostream>

struct Coord
{
	int x;
	int y;

	Coord(int x = 0, int y = 0);
//	size_t operator () 
	
	friend std::ostream& operator << (std::ostream& o, const Coord& target);
};

//namespace std
//{
//	template <>
//	struct hash<Coord>
//	{
//		std::size_t operator() (const Coord& k)
//		{
//			return
//				std::hash<int>()(k.x) ^
//				std::hash<int>()(k.y);
//		}
//	};
//}
