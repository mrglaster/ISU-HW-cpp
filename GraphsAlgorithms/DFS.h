#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED

#include "Graph.h"

class DFS {
    const Graph& graph;
    std::set<Node*> visited;
    bool connected(Node* begin, Node* end, int depth);

    public:
        DFS(const Graph& agraph) : graph(agraph) {}
        bool connected(Node* begin, Node* end);
};

#endif // DFS_H_INCLUDED
