#include "Img.hpp"
#include "Cluster.h"
#include <fstream>
#include <iostream>
#include <cmath>

Img::Img(const char* const inputFile)
{
	std::ifstream fileStream;
	
	fileStream.open(inputFile);
	if (!fileStream.is_open())
	{
		std::cerr << inputFile << ": " << strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}
	
	std::string buf;
	std::getline(fileStream, buf);
	std::sscanf(buf.c_str(), "%d , %d", &m_width, &m_height);
	
	for (int i = 0; i < m_width * m_height; i++)
	{
		auto coord = Coord();
		auto rgb = Rgb();

		std::getline(fileStream, buf);
		std::sscanf(
			buf.c_str(),
			"[ %d , %d ] = [ %d , %d , %d ]",
			&coord.x, &coord.y,
			&rgb.r, &rgb.g, &rgb.b);
		
		
//		m_colorMap[coord] = rgb;
//		m_colorMap.emplace(coord, rgb);
//		m_colorMap.insert(std::make_pair(coord, rgb));
	}
	
	std::cout << *this;
}

/*
** Public methods.
*/

void Img::printClusters(const int nbOfClusters) const
{
	
}

/*
** Private methods.
*/

//double Img::computeColorDistance(const Rgb& a, const Rgb& b)
//{
//	return std::sqrt(
//		std::pow(a.r - b.r, 2) +
//		std::pow(a.g - b.g, 2) +
//		std::pow(a.b - b.b, 2)
//	);
//}
//
//Rgb Img::getCenter(const std::vector<Coord>& coords) const
//{
//	Rgb result(0, 0, 0);
//	
//	for (const auto& coord : coords)
//	{
//		const auto& color = m_colorMap.at(coord);
//		result.r += color.r;
//		result.g += color.g;
//		result.b += color.b;
//	}
//	
//	result.r /= coords.size();
//	result.g /= coords.size();
//	result.b /= coords.size();
//	return result;
//}
//
//static Cluster& getClosestCluster(
//	std::vector<Cluster>& clusters,
//	const Rgb& color)
//{
//	Cluster* minCluster = nullptr;
//	double minDist = std::numeric_limits<double>::max();
//	
//	for (auto& cluster : clusters)
//	{
//		const auto dist = Img::computeColorDistance(cluster.center, color);
//		if (dist < minDist)
//		{
//			minDist = dist;
//			minCluster = &cluster;
//		}
//	}
//	
//	return *minCluster;
//}
//
//std::vector<Cluster> Img::makeACluster(std::vector<Rgb> clusterGroups) const
//{
//	std::vector<Cluster> clusters;
//	
//	for (const auto& clusterGroup : clusterGroups)
//	{
//		auto cluster = Cluster();
//		cluster.center = clusterGroup;
//		
//		clusters.push_back(cluster);
//	}
//	
//	for (const auto& coordAndRgb : m_colorMap)
//	{
//		const auto& coord = coordAndRgb.first;
//		const auto& color = coordAndRgb.second;
//	
//		auto& closestCluster = getClosestCluster(clusters, color);
//		
//		closestCluster.coords.push_back(coord);
//		closestCluster.center = getCenter(closestCluster.coords);
//	}
//	
//	return clusters;
//}

/*
** Operators.
*/

std::ostream& operator << (std::ostream& o, const Img& target)
{
//	for (const auto& pair : target.m_colorMap)
//	{
//		std::cout << pair.first << ": " << pair.second << std::endl;
//	}
	return o;
}
