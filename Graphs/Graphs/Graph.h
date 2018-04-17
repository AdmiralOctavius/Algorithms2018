#pragma once
#include <vector>
using namespace std;

class Graph {

public:

	struct Vertex;//Forward declaration

	struct Edge {
		Edge() :weight(w), neighbor(n) {

		}
		double weight;
		Vertex* neighbor;
	};

	struct Vertex {//aka vertex
		Vertex(string n) : cityName(n) {

		}
		vector<Edge> neighbors;
		string cityName;

	//	int x, y;
//		bool hasBeenChecked;
	};

	void AddVertex(string name) {
		vertices.push_back(name);
	}

	void AddEdge(Vertex *v1, Vertex *v2, double weight, bool bothWays = true) {
		//v1->neighbors.push_back({ weight, v2 });
		v1->neighbors.push_back(Edge(v2, weight ));
		if (bothWays) {
			v2->neighbors.push_back(Edge(v1, weight));
		}
	}

	Vertex* GetVertex(int index) {
		return &vertices[index];
	}

	Vertex* operator[](int index) {
		return &vertices[index];
	}
		
private:
	vector<Vertex> vertices;
};