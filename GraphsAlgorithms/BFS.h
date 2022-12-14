#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED

#include "Graph.h"

class BFS {
	const Graph& graph;
public:
	BFS(const Graph& agraph) : graph(agraph) {}
	void graphResearch();
	bool connected(Node* begin, Node* end);
	Graph get_graph();

};


#endif // BFS_H_INCLUDED
