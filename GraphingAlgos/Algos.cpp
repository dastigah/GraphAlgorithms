#pragma once

#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "Algos.h"

template <class Type>
void cleanup(std::unordered_map<Type, Type *> & nodeList) {
	for (auto it = nodeList.begin(); it != nodeList.end(); it++) {
		delete it->second;
	}
}

template <class Vertex>
bool isCyclicDirect(const std::vector<std::vector<Vertex>>& edges) {
	bool result = false;

	std::unordered_map<Vertex, Vertex*> nodeList;

	std::unordered_set<Vertex *> nodesLeft;
	std::unordered_map<Vertex *, std::vector<Vertex *>> adjList;
	std::unordered_set<Vertex *> visited;

	//setup adjList and numnodes to eliminate to traverse
	for (int i = 0; i < edges.size(); i++) {
		if (nodeList.find(edges[i][0]) == nodeList.end()) nodeList[edges[i][0]] = new Vertex(edges[i][0]);
		if (nodeList.find(edges[i][1]) == nodeList.end()) nodeList[edges[i][1]] = new Vertex(edges[i][0]);


		adjList[nodeList[edges[i][0]]].push_back(nodeList[edges[i][1]]);
		nodesLeft.insert(nodeList[edges[i][0]]);
		nodesLeft.insert(nodeList[edges[i][1]]);
	}

	while (nodesLeft.size() > 0) {
		Vertex * curr = *nodesLeft.begin();
		if (isCyclicDirectHelper<Vertex>(nodesLeft, adjList, visited, curr)) {
			result = true;
			break;
		}
	}

	cleanup(nodeList);

	return result;
}

template <class Vertex>
bool isCyclicDirectHelper(std::unordered_set<Vertex *> & nodesLeft, const std::unordered_map<Vertex *,std::vector<Vertex *>> & adjList, 
								std::unordered_set<Vertex * >& visited, Vertex * curr) {

	//remove from list
	if (nodesLeft.find(curr) != nodesLeft.end()) nodesLeft.erase(curr);

	if (visited.find(curr) != visited.end()) return true;

	visited.insert(curr);
	for (int i = 0; i < adjList.at(curr).size(); i++) {
		if (isCyclicDirectHelper<Vertex>(nodesLeft, adjList, visited, adjList.at(curr)[i])) return true;
	}
	visited.erase(curr);

	return false;
}


template <class Vertex>
bool isCyclicUndirect(const std::vector<std::vector<Vertex>>& edges) {
	bool result = false;

	std::unordered_map<Vertex, Vertex *> nodeList;
	std::unordered_set<Vertex*> nodesLeft;
	std::unordered_set<Vertex*> visited;
	std::unordered_map<Vertex *, std::vector<Vertex *>> adjList;

	for (int i = 0; i < edges.size(); i++) {
		if (nodeList.find(edges[i][0]) == nodeList.end()) nodeList[edges[i][0]] = new Vertex(edges[i][0]);
		if (nodeList.find(edges[i][1]) == nodeList.end()) nodeList[edges[i][1]] = new Vertex(edges[i][1]);

		adjList[nodeList[edges[i][0]]].emplace_back(nodeList[edges[i][1]]);
		adjList[nodeList[edges[i][1]]].emplace_back(nodeList[edges[i][0]]);

		nodesLeft.insert(nodeList[edges[i][0]]);
		nodesLeft.insert(nodeList[edges[i][1]]);
	}

	while (nodesLeft.size() > 0) {
		Vertex * curr = *nodesLeft.begin();
		if (isCyclicUndirectHelper<Vertex>(nodesLeft,adjList,visited,nullptr, curr)) {
			result = true;
			break;
		}
	}
	
	cleanup(nodeList);

	return result;
}


template <class Vertex>
bool isCyclicUndirectHelper(std::unordered_set<Vertex*>& nodesLeft, const std::unordered_map<Vertex*, std::vector<Vertex*>>& adjList,
							std::unordered_set<Vertex*>& visited, Vertex* prev, Vertex* curr) {
	if (visited.find(curr) != visited.end()) return true;

	visited.insert(curr);
	nodesLeft.erase(curr);

	for (int i = 0; i < adjList.at(curr).size(); i++) {
		Vertex* next = adjList.at(curr)[i];
		if (prev == next) continue;
		if (isCyclicUndirectHelper(nodesLeft, adjList, visited, curr, next)) return true;
	}

	return false;
}

template bool isCyclicDirect<int>(const std::vector<std::vector<int>>& edges);
template bool isCyclicUndirect<int>(const std::vector<std::vector<int>>& edges);