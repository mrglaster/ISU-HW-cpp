#include "Node.h"

/**Adds a neighbor to the point*/
void Node::addNeighbour(Node* neighbour){
    //check by name in neighbours
    neighbours.insert(neighbour);
}

/**Removes a neighbor of the point*/
void Node::removeNeighbour(Node* neighbour){
    neighbours.erase(neighbour);
}
