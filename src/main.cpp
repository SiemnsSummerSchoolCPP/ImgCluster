#include "Coord.h"
#include "Rgb.h"
#include "Img.hpp"
#include <unordered_map>
#include <map>
#include <iostream>

int main(const int argc, const char* const* const argv)
{
	if (argc < 3)
	{
		std::cerr << "2 arguments are required: file and number of clusters\n";
		exit(EXIT_FAILURE);
	}

	const char* const file = argv[1];
//	const auto nbOfClusters = atoi(argv[2]);

	auto initialClusterGroups = std::vector<Rgb>() =
	{
		{ 0,	0,		255 },
		{ 0,	255,	0 },
		{ 255,	0,		0 },
	};

	auto img = Img(file);
	const auto result = img.makeAllClusters(initialClusterGroups);
	
	printf("%d, %d\n", img.getWidth(), img.getHeight());
	for (const auto& cluster : result)
	{
		for (const auto& coord : cluster.coords)
		{
			const auto& color = cluster.center;
			printf("[ %d,%d ] = [ %d,%d,%d ]\n",
				coord.x, coord.y,
				color.r, color.g, color.b);
		}
	}
	
	return 0;
}
