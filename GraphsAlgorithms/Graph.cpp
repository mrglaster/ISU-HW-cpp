#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Graph.h"
#include "Node.h"
using namespace std;



/**Builds the graph by data from the file
    format of lines in the file: start-end
*/
Graph::Graph(char* file_name) {
    Node* temp_nodes[1000] = { 0 };
    char separator;
    string current_line;
    ifstream file(file_name);
    while(getline(file, current_line)){
         stringstream s_stream(current_line);
         int e_start, e_end;
         s_stream >> e_start >> separator >> e_end;
         if (e_start < 0 || e_end < 0  || e_start > 1000 || e_end > 1000) {
            cout<<"This graph node values are not supported by the utility: "<<e_start<<" and/or "<<e_end<<endl;
            break;
         }

         if ((e_start != 0 || e_end != 0) && e_start != e_end){

            int index;
            if (temp_nodes[e_start] == 0) index = e_start;
            else index = e_end;
            temp_nodes[index] = new Node(index);
            addNode(temp_nodes[index]);
            addEdge(temp_nodes[e_start], temp_nodes[e_end]);
         }
    }

}



/**Add Node to Graph*/
void Graph::addNode(Node* node){
    nodes.insert(node);
	for (set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) (*it)->addNeighbour(node);
}

/**Remove node from the graph by it's pointer*/
void Graph::removeNode(Node* node){
    nodes.erase(node);
	for (set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) (*it)->removeNeighbour(node);
}


/**Adds edge between two points*/
void Graph::addEdge(Node* begin, Node* end) {
   //Add name check
   if (nodes.find(begin) == nodes.end() || nodes.find(end) == nodes.end()) return;
   begin->addNeighbour(end);
   end->addNeighbour(begin);
}

/**Removes edge between two nodes*/
void Graph::removeEdge(Node* begin, Node* end ){
    if (nodes.find(begin) == nodes.end() || nodes.find(end) == nodes.end()) return;
    begin->removeNeighbour(end);
    end->removeNeighbour(begin);
}

/**Returns nodes of the graph*/
std::set<Node*> Graph::getNodes(){
    return nodes;
}


/**Prints names of the graph's points*/
void Graph::print_graph(){
    cout << "Amount of nodes: " << nodes.size() << endl << endl;
    for (node_iterator it = begin(); it != end(); it++) cout << "Name: " << (*it)->name << endl;
}

/**Returns amount of Nodes of the Graph*/
int Graph::get_nodes_amount(){
    return nodes.size();
}

/**Get pointer to the point by it's name*/
Node* Graph::get_node_bid(int id){
    if (id < 0 || id > nodes.size()) {
        throw std::invalid_argument( "Unavailable index: "+to_string(id));
    }
    Node* x = *std::next(nodes.begin(), id);
    return x;
}



