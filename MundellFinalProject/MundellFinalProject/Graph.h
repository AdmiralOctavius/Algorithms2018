#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
public:
	struct Vertex;//Forward Declaration 

	struct Edge//aka Connection
	{
		Edge(Vertex* n, double w)
			: neighbor(n), weight(w)
		{

		}

		double weight;
		Vertex* neighbor;
	};

	struct Vertex//aka Node
	{
		Vertex(string n)//Conversion Constructor
			: cityName(n), hasBeenChecked(false), hasBeenPushed(false)
		{

		}

		vector<Edge> neighbors;
		string cityName;

		//int x, y;
		bool hasBeenPushed;
		bool hasBeenChecked;
		Vertex* visitingVertex;//which vertex we were on when this one was pushed to the stack/queue
	};
	
	/*For up to 10% extra credit on A7, submit this (graph.h) file through course messages by wednesday's class
	Set visitingVertex of each vertex as you push them on the stack/queue
	Write a function PrintPath that prints the path to walk from Start node to end node
		Start at the end node and then reverse the order of the path
	*/


	void AddVertex(string &name)//Uses this one if you pass in a variable (AddVertex(city))
	{
		vertices.push_back(name);
	}

	void AddVertex(string name)//Uses this one if you hardcode a value (AddVertex("Mordor"))
	{
		vertices.push_back(name);
	}

	//void AddEdge(string &name1, string &name2, double weight)
	//{
	//	//If we pass in strings, we'd have to search the vector for the matching vertex
	//}

	void AddEdge(Vertex *v1, Vertex *v2, double weight, bool bothWays = true)
	{
		v1->neighbors.push_back(Edge(v2, weight));
		if (bothWays)
			v2->neighbors.push_back(Edge(v1, weight));
	}

	Vertex* GetVertex(int index)
	{
		return &vertices[index];
	}

	Vertex* operator[](int index)
	{
		return &vertices[index];
	}

	void DisplayGraph()
	{
		for (auto val : vertices)
		{
			cout << val.cityName << " has neighbors: " << endl;
			for (auto neighbor : val.neighbors)
			{
				cout << "\t" << neighbor.neighbor->cityName << " with distance " << neighbor.weight << endl;
			}
		}
	}

	void ResetVertices()
	{
		for (auto& val : vertices)
			val.hasBeenChecked = val.hasBeenPushed = false;
	}

	void BreadthFirstSearch(Vertex* start, string goalCity)
	{
		ResetVertices();

		//Initialization
		queue<Vertex*> nodes;
		nodes.push(start);
		Vertex* current;
		Vertex* result = nullptr;

		//Search
		while (nodes.size())
		{
			current = nodes.front();
			cout << "Checking " << current->cityName << endl;
			nodes.pop();
			current->hasBeenChecked = true;

			//check if we found the goal
			if (current->cityName == goalCity)
			{
				result = current;
				break;
			}

			//Check the current nodes neighbors
			for (auto edge : current->neighbors)
			{
				if (!edge.neighbor->hasBeenChecked && !edge.neighbor->hasBeenPushed)
				{
					nodes.push(edge.neighbor);
					edge.neighbor->hasBeenPushed = true;
					cout << "\tPushing " << edge.neighbor->cityName << endl;
				}
			}
		}

		//Finished Searching
		if (result)
			cout << "Found city " << result->cityName << endl;
		else//result is nullptr
			cout << "Could not find city " << goalCity << endl;
	}

	void DepthFirstSearch(Vertex* start, string goalCity)
	{
		ResetVertices();

		//Initialization
		stack<Vertex*> nodes;
		nodes.push(start);
		Vertex* current;
		Vertex* result = nullptr;

		//Search
		while (nodes.size())
		{
			current = nodes.top();
			cout << "Checking " << current->cityName << endl;
			nodes.pop();
			current->hasBeenChecked = true;

			//check if we found the goal
			if (current->cityName == goalCity)
			{
				result = current;
				break;
			}

			//Check the current nodes neighbors
			for (auto edge : current->neighbors)
			{
				if (!edge.neighbor->hasBeenChecked && !edge.neighbor->hasBeenPushed)
				{
					nodes.push(edge.neighbor);
					edge.neighbor->hasBeenPushed = true;
					cout << "\tPushing " << edge.neighbor->cityName << endl;
				}
			}
		}

		//Finished Searching
		if (result)
			cout << "Found city " << result->cityName << endl;
		else//result is nullptr
			cout << "Could not find city " << goalCity << endl;
	}


	void GenerateGraph(int x, int y) {

		//Create the verticies first
		//Then add the connections
		vector<Vertex> nodes;
		int totalVert = x * y;
		int count = 0;
		while (count < totalVert) {
			Vertex point("Nope");
			nodes.push_back(point);
		}
		//Going row by row
		for (int i = 0; i < y; i++) {
			if (i == y - 1) {
				//Need to generate the final rows
			}
			//Rows from
			for (int j = 0; j < y; i++) {
				
			}
		}

	}
private:
	vector<Vertex> vertices;

};