#include <iostream>
#include "Node.h"
#include "Graph.h"
#include "BFS.h"
using namespace std;

int main(){
    char filename[] = "test_graph_data.txt";
    Graph baron(filename);
    //baron.print_graph();
    //cout<<baron.get_nodes_amount()<<endl;
    BFS beef(baron);
    cout<<beef.connected(beef.get_graph().get_node_bid(1), beef.get_graph().get_node_bid(4) )<<endl;
}
