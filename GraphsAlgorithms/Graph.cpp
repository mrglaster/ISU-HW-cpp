#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include "Graph.h"
#include "Node.h"
#include "BFS.h"
using namespace std;



/**Builds the graph by data from the file
    if mode = 0: format of lines in the file: start-end
    if mode = 1: contains header, points are separated by space/tab/other stuff
*/
Graph::Graph(char* file_name, int mode) {
    if (mode){
        std::ifstream file(file_name);
        if (!file.is_open())
            exit(-1);
        file.ignore(100, '\n');
        Node* temp_nodes[1000] = {};
        std::string line;
        while (getline(file, line)) {
            std::regex rgx(R"(\d+)");
            std::string str_source = "";
            std::string str_target = "";
            for (std::sregex_token_iterator it{ line.begin(), line.end(), rgx, 0 }, end;
                it != end;) {
                str_source = *it++;
                str_target = *it++;
            }

            if (temp_nodes[std::stoi(str_source)] == 0) {
                temp_nodes[std::stoi(str_source)] = new Node(std::stoi(str_source));
                addNode(temp_nodes[std::stoi(str_source)]);
            }

            if (temp_nodes[std::stoi(str_target)] == 0) {
                temp_nodes[std::stoi(str_target)] = new Node(std::stoi(str_target));
                addNode(temp_nodes[std::stoi(str_target)]);
            }

            addEdge(temp_nodes[std::stoi(str_source)], temp_nodes[std::stoi(str_target)]);
        }

	file.close();

    }

    else {
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
}





/**Add Node to Graph*/
void Graph::addNode(Node* node){
    if (nodes.find(node) != nodes.end() || !node) throw GraphException();
    nodes.insert(node);

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
    if (id < 0 || id > nodes.size()) throw std::invalid_argument( "Unavailable index: "+to_string(id));
    Node* x = *std::next(nodes.begin(), id);
    return x;
}

/**Selects non-intersecting graphs in the source graph and writes information about them to a text file*/
void Graph::graphSplitter() {
	BFS bfs(*this);
	std::ofstream file;
	std::set<Node*> visited_nodes;
	int c = 1;
	while (visited_nodes.size() < nodes.size()) {
		file.open("outgraph" + std::to_string(c++) + ".txt");
		if (!file.is_open()){
            cout<<"Unable to open file!"<<endl;
            exit(-1);
		}
		cout<<"New Graph was found"<<endl;
		file << "Source Target\n";
		for (std::set<Node*>::iterator it = nodes.begin(), last_it = nodes.end(); it != nodes.end(); it++) {
			if (visited_nodes.find(*it) == visited_nodes.end() && (last_it == nodes.end()
				|| bfs.connected(*it, *last_it))) {
				for (node_iterator nb_it = (*it)->nb_begin(); nb_it != (*it)->nb_end(); nb_it++) {
					if (visited_nodes.find(*nb_it) == visited_nodes.end()){
						file << (*it)->getName() << " " << (*nb_it)->getName() << std::endl;
					}
				}
				visited_nodes.insert(*it);
				last_it = it;
			}
		}

		file.close();
	}
	cout<<"Process is done!"<<endl;
}




