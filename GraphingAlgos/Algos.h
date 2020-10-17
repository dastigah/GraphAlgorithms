#pragma once
#include <vector>
#include <unordered_set>
#include <unordered_map>


template <class Type>
void cleanup(std::unordered_map<Type, Type *> & adjList);

//Create Pointers to given objects
//Detect Cycle

template <class Vertex>
bool isCyclicDirect(const std::vector<std::vector<Vertex>>& edges);

template <class Vertex>
bool isCyclicDirectHelper(std::unordered_set<Vertex *>& nodesLeft, const std::unordered_map<Vertex *, std::vector<Vertex *>>& adjList,
	std::unordered_set<Vertex *>& visited, Vertex * curr);

template <class Vertex>
bool isCyclicUndirect(const std::vector<std::vector<Vertex>>& edges);

template <class Vertex>
bool isCyclicUndirectHelper(std::unordered_set<Vertex*>& nodesLeft, const std::unordered_map<Vertex*, std::vector<Vertex*>>& adjList,
	std::unordered_set<Vertex*>& visited, Vertex* prev,Vertex* curr);
//Hamiltonian Cycle ( Visit each vertices exactly once)


//Eulerian Cycle (Visit Each edge exactly once)


//Kruskals (Minimum Spanning Tree)


//Djikstra's Algorithm (only works for non-negative weights)


//Floyd Warshall Algorithm (Works for negative weights)


//Detect if graph can be a tree


