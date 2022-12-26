#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "Node.h"
#include <iostream>
#include <set>

typedef std::set<Node*>::const_iterator node_iterator;

class GraphException{};
typedef std::set<Node*>::const_iterator node_iterator;
class Graph {
   private:
    std::set<Node*> nodes;
   public:

        Graph(char* file_name, int mode);

        Node* get_node_bid(int id);

        void addNode(Node* node);
        void removeNode(Node* node);
        void addEdge(Node* begin, Node* end);
        void removeEdge(Node* begin, Node* end);
        node_iterator begin() const {
            return nodes.begin();
        }

        node_iterator end() const {
             return nodes.end();
        }


        void print_graph();

        std::set<Node*>getNodes();
        int get_nodes_amount();
        void graphSplitter();
};

#endif // GRAPH_H_INCLUDED
