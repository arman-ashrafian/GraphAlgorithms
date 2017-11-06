#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <list>

// Undirected Graph implemented using an adjacency list
class Graph
{
public:
	Graph(int SIZE);

	void addEdge(int p1, int p2, int weight);
	void BFS(int start);
	void print();
private:
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
}

void Graph::BFS(int start) {
	// array for visted vertices
	bool *visted = new bool[this->SIZE];
	// set all vertices to not visted
	for(int i = 0; i < this->SIZE; i++) {
		visted[i] = false;
	}

	// create queue
	// using list because vector has no pop_front()
	std::list<int> queue;

	// starting node is visted, and enqueue to queue
	visted[start] = true;
	queue.push_back(start);

	// iterator to visit adjacent vertices
	std::vector< std::pair<int, int> >::iterator i;
	while(!queue.empty()) {
		// print when dequeing 
		start = queue.front();
		std::cout << start << " ";
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

	Graph graph = Graph(4);

	graph.addEdge(0,1,100);
	graph.addEdge(0,2,200);
	graph.addEdge(1,2,100);
	graph.addEdge(2,0,500);
	graph.addEdge(2,3,300);
	graph.addEdge(3,3,300);

	graph.BFS(2);

	return 0;
}