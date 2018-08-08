#pragma once

#include "Rgb.h"
#include "Coord.h"
#include <vector>

struct Cluster
{
	Rgb center;
	std::vector<Coord> coords;
};
