#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED


#include <string>
#include <set>
#include <queue>


using namespace std;

class Node {
    typedef std::set<Node*>::const_iterator node_iterator;
    int name;
    std::set<Node*> neighbours;
    void addNeighbour(Node* neighbour);
    void removeNeighbour(Node* neighbour);
    public:
        Node(const int& aname) : name(aname) {}

        const int& getName() const {
             return name;
        }

        node_iterator nb_begin()const{
            return neighbours.begin();
        }

        node_iterator nb_end() const {
             return neighbours.end();
        }

        friend class Graph;
};



#endif // NODE_H_INCLUDED
