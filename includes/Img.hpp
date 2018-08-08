#pragma once

#include "Coord.h"
#include "Rgb.h"
#include "Cluster.h"
#include <unordered_map>
#include <vector>
#include <ostream>

class Img
{
public:
	Img(const char* inputFile);

	static double computeColorDistance(const Rgb& a, const Rgb& b);

	void printClusters(int nbOfClusters) const;
	std::vector<Cluster> makeACluster(std::vector<Rgb> clusterGroups) const;
	
	friend std::ostream& operator << (std::ostream& o, const Img& target);

private:
	int m_width = 0;
	int m_height = 0;
	
//	std::unordered_map<Coord, Rgb> m_colorMap;
	
	Rgb getCenter(const std::vector<Coord>& coords) const;
	
};
