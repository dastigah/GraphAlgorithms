#pragma once

#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "Algos.h"

template <class Vertex>
bool isCyclicDirect(const std::vector<std::vector<Vertex>>& edges) {
	std::unordered_set<Vertex> nodesLeft;
	std::unordered_map<Vertex, std::vector<Vertex>> adjList;
	std::unordered_set<Vertex> visited;

	//setup adjList and numnodes to eliminate to traverse
	for (int i = 0; i < edges.size(); i++) {
		adjList[edges[i][0]].push_back(edges[i][1]);
		nodesLeft.insert(edges[i][0]);
		nodesLeft.insert(edges[i][1]);
	}

	while (nodesLeft.size() > 0) {
		if (isCyclicDirectHelper<Vertex>(nodesLeft, adjList, visited, *(nodesLeft.begin()))) return true;
	}

	return false;
}

template <class Vertex>
bool isCyclicDirectHelper(std::unordered_set<Vertex>& nodesLeft, std::unordered_map<Vertex, std::vector<Vertex>> & adjList, 
								std::unordered_set<Vertex>& visited, const Vertex curr) {
	
	//remove from list
	if (nodesLeft.find(curr) != nodesLeft.end()) nodesLeft.erase(curr);

	if (visited.find(curr) != visited.end()) return true;

	visited.insert(curr);
	for (int i = 0; i < adjList[curr].size(); i++) {
		if (isCyclicDirectHelper(nodesLeft, adjList, visited, adjList[curr][i])) return true;
	}
	visited.erase(curr);

	return false;
}

template <class Vertex>
bool isCyclicUndirect(const std::vector<std::vector<Vertex>>& edges) {
	std::unordered_set<Vertex> nodesList;
	std::unordered_map<Vertex, std::vector<Vertex, Vertex>> adjList;

	while (nodesList.size() > 0) {
	}
}

template <class Vertex>
bool isCyclicUndirectHelper(const std::unordered_map<) {

}

template bool isCyclicDirect(const std::vector<std::vector<int>>& edges);