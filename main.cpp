#include <iostream>
#include <vector>
#include <utility>

// Undirected Graph implemented using an adjacency list
class Graph
{
public:
	Graph(int SIZE);

	void addEdge(int p1, int p2, int weight);

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

	Graph graph = Graph(10);

	graph.addEdge(0,1,100);
	graph.addEdge(0,2,200);
	graph.addEdge(1,2,100);
	graph.addEdge(0,5,500);
	graph.addEdge(5,2,300);

	graph.print();

	return 0;
}