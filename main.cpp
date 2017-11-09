#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <list>
#include <algorithm>

// Undirected Graph implemented using an adjacency list
class Graph
{
public:
	Graph(int SIZE);

	void addEdge(int p1, int p2, int weight);
	std::vector<int> BFS(int start);
	void print();
	bool __sortbysec(const std::pair<int,int> &a,
          		const std::pair<int,int> &b);	
private:

	void __sortAdjEdges();

	std::vector< std::pair<int, int> > *adj;
	int SIZE;
};

Graph::Graph(int SIZE) {
	this->SIZE = SIZE;
	adj = new std::vector< std::pair<int, int> >[SIZE];
}

void Graph::addEdge(int p1, int p2, int weight) {
	adj[p1].push_back(std::make_pair(p2, weight));
	adj[p2].push_back(std::make_pair(p1, weight));
	__sortAdjEdges();
}

// Sort adjacent edges by weight
void Graph::__sortAdjEdges() {
	for(int i = 0; i < this->SIZE; i++) {
		std::sort(adj[i].begin(), adj[i].end(),
		// sort by second value
		 [](const std::pair<int,int> &a, const std::pair<int,int> &b) {
		 	return a.second < b.second;
		 });
	}
}

std::vector<int> Graph::BFS(int start) {
	// return vector
	std::vector<int> bfs_order;

	// array for visted vertices
	bool *visted = new bool[this->SIZE];
	// set all vertices to not-visted
	for(int i = 0; i < this->SIZE; i++) {
		visted[i] = false;
	}

	// create queue
	std::list<int> queue;

	// starting node is visted and enqueued
	visted[start] = true;
	queue.push_back(start);

	// iterator to visit adjacent vertices
	std::vector< std::pair<int, int> >::iterator i;
	while(!queue.empty()) {
		// print when dequeing 
		start = queue.front();
		bfs_order.push_back(start);
		queue.pop_front();

		// visit all adjacent nodes of vertex start.
		// mark visited, and enqueue.
		for(i = this->adj[start].begin(); i != this->adj[start].end(); ++i) {
			if(!visted[i->first])
			{
				visted[i->first] = true;
				queue.push_back(i->first);
			}
		}
	}
	return bfs_order;
}

void Graph::print() {
	for(int i = 0; i < this->SIZE; i++) {
		std::cout << "Vertex " << i << std::endl;
		for(int j = 0; j < adj[i].size(); j++) {
			std::cout << adj[i][j].first << " " << adj[i][j].second << std::endl;
		}
		std::cout << " ======== " << std::endl;
	}
}

int main() {

	std::map<std::string, int> cities;

	cities["Los Angeles"] = 0;
	cities["San Francisico"] = 1;
	cities["Seattle"] = 2;
	cities["Denver"] = 3;
	cities["Chicago"] = 4;
	cities["Kansas City"] = 5;
	cities["Dallas"] = 6;
	cities["Houston"] = 7;
	cities["Boston"] = 8;
	cities["New York"] = 9;
	cities["Atlanta"] = 10;
	cities["Miami"] = 11;

	std::vector<std::string> cityVec = {
		"Los Angeles",
		"San Francisico",
		"Seattle",
		"Denver",
		"Chicago",
		"Kansas City",
		"Dallas",
		"Houston",
		"Boston",
		"New York",
		"Atlanta",
		"Miami"
	};

	Graph graph = Graph(12);

	graph.addEdge(cities["Los Angeles"],cities["San Francisico"], 381);
	graph.addEdge(cities["Los Angeles"],cities["Denver"], 1015);
	graph.addEdge(cities["Los Angeles"],cities["Kansas City"], 1663);
	graph.addEdge(cities["Los Angeles"],cities["Dallas"], 1435);

	graph.addEdge(cities["San Francisico"],cities["Denver"], 1267);
	graph.addEdge(cities["San Francisico"],cities["Seattle"], 807);

	graph.addEdge(cities["Seattle"],cities["Denver"], 1331);
	graph.addEdge(cities["Seattle"],cities["Chicago"], 2097);

	graph.addEdge(cities["Denver"],cities["Kansas City"], 599);
	graph.addEdge(cities["Denver"],cities["Chicago"], 1003);

	graph.addEdge(cities["Chicago"],cities["Kansas City"], 533);
	graph.addEdge(cities["Chicago"],cities["Boston"], 983);
	graph.addEdge(cities["Chicago"],cities["New York"], 787);

	graph.addEdge(cities["Kansas City"],cities["Dallas"], 496);
	graph.addEdge(cities["Kansas City"],cities["Atlanta"], 864);
	graph.addEdge(cities["Kansas City"],cities["New York"], 1260);

	graph.addEdge(cities["Dallas"],cities["Atlanta"], 781);
	graph.addEdge(cities["Dallas"],cities["Houston"], 239);

	graph.addEdge(cities["Houston"],cities["Atlanta"], 810);
	graph.addEdge(cities["Houston"],cities["Miami"], 1187);

	graph.addEdge(cities["Miami"],cities["Atlanta"], 661);
	graph.addEdge(cities["Atlanta"],cities["New York"], 888);
	graph.addEdge(cities["Boston"],cities["New York"], 214);

	std::vector<int> bfs_order = graph.BFS(cities["Los Angeles"]);

	for(auto i : bfs_order) {
		std::cout << cityVec[i] << std::endl;
	}

	return 0;
}