#include <iostream>

#include "Graph.h"

using namespace std;

/*
Graphs
A Graph is a set of nodes that can connect to any number of other nodes
	and have cycles and loops
A cycle is when you can end up back at the node you started from
A loop is when a node has a connection to itself
A tree is a specialized version of a graph that has no cycles or loops
A Dense Graph has many connections
	A Complete Graph has all possible connections
A sparse graph doesn't have a lot of connections
An island is a node that can't be reached from other nodes
Directional Graph: Can only go one direction along each path
	Bidirectional Graph: can go either direction along a specific path
Node ~ Vertex
Connection ~ Edge is a valid path between two Nodes/Vertices
Weighted Graph: Each edge/connection has a certain weight, like the distance between cities,
	or the roughness of terrain between them, etc.
	Weight indicates the cost of going down that path.
Bipartite graph - just a graph with 2 rows of vertices

Vertex	1: Huntington
		2: Barboursville
		3: Ashland
		4: Portsmouth
		5: Chesapeake

2 Represenations for Graphs
	Adjacency Matrix (table)
	1	2	3	4	5
1	-1	1	1	0	1
2	1	-1	1	1	1
3	0	0	-1	0	0
4	0	1	0	-1	0
5	

	Adjacency List
	Every vertex has a list/vector of its neighbors

	Uses of graphs: maps, pathfinding/navigation in games, 
		the internet is a 'graph' of devices connected together,
		or they can represent more abstract things like the different
		possibilities of a chess board
*/

int main()
{
	Graph roadMap;
	roadMap.AddVertex("Huntington");//0
	roadMap.AddVertex("Barboursville");//1
	roadMap.AddVertex("Chesapeake");//2
	roadMap.AddVertex("Ashland");//3
	roadMap.AddVertex("Isengard");//4
	roadMap.AddVertex("Asgard");//5
	roadMap.AddVertex("Beckley");//6
	roadMap.AddVertex("Mordor");//7
	roadMap.AddVertex("Martinsburg");//8
	roadMap.AddVertex("Charleston");//9

	roadMap.AddEdge(roadMap[0], roadMap[1], 4);
	roadMap.AddEdge(roadMap[0], roadMap[2], 2);
	roadMap.AddEdge(roadMap[0], roadMap[3], 15);
	roadMap.AddEdge(roadMap[0], roadMap[9], 40);

	roadMap.AddEdge(roadMap[1], roadMap[6], 90);

	roadMap.AddEdge(roadMap[2], roadMap[6], 100);

	roadMap.AddEdge(roadMap[3], roadMap[7], 100);
	roadMap.AddEdge(roadMap[5], roadMap[7], 1000);

	roadMap.AddEdge(roadMap[6], roadMap[4], 4, false);

	roadMap.AddEdge(roadMap[8], roadMap[9], 200);

	roadMap.DisplayGraph();
	cout << endl << endl;

	cout << "Testing DFS Huntington -> Barboursville" << endl;
	roadMap.DepthFirstSearch(roadMap[0], "Barboursville");
	cout << endl << endl;

	cout << "Testing BFS Huntington -> Barboursville" << endl;
	roadMap.BreadthFirstSearch(roadMap[0], "Barboursville");
	cout << endl << endl;


	return 0;
}