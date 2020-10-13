#pragma once
#include <vector>
#include <unordered_set>
#include <unordered_map>

//Detect Cycle

template <class Vertex>
bool isCyclicDirect(const std::vector<std::vector<Vertex>>& edges);

template <class Vertex>
bool isCyclicDirectHelper(std::unordered_set<Vertex>& nodesLeft, std::unordered_map<Vertex, std::vector<Vertex>>& adjList,
	std::unordered_set<Vertex>& visited, const Vertex curr);

template <class Vertex>
bool isCyclicUndirect(const std::vector<std::vector<Vertex>>& edges);

//Hamiltonian Cycle ( Visit each vertices exactly once)


//Eulerian Cycle (Visit Each edge exactly once)


//Kruskals (Minimum Spanning Tree)


//Djikstra's Algorithm (only works for non-negative weights)


//Floyd Warshall Algorithm (Works for negative weights)


//Detect if graph can be a tree


