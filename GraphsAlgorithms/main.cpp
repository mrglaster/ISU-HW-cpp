#include <iostream>
#include "Node.h"
#include "Graph.h"
#include "BFS.h"
using namespace std;

void bfs_demo(){
    char filename[] = "testgraph.txt";
    int nodeOneID = 0;
    int nodeTwoID = 47;
    Graph baron(filename, 1);
    BFS beef(baron);
    int result = beef.connected(beef.get_graph().get_node_bid(nodeOneID), beef.get_graph().get_node_bid(nodeTwoID) );
    cout<<result<<endl;
    if (result){
        cout<<"Nodes "<<nodeOneID<<" and "<<nodeTwoID<<" are connected!"<<endl;
    }
    else {
        cout<<"Nodes "<<nodeOneID<<" and "<<nodeTwoID<<" aren't connected!"<<endl;
    }
}

void testgraphOneSplitter(){
    char filename[] = "testgraph.txt";
    Graph testnameGraph(filename, 1);
    testnameGraph.graphSplitter();
}

void testgraphTwoSplitter(){
    char filename[] = "testgraph2.txt";
    Graph testnameGraph(filename, 1);
    testnameGraph.graphSplitter();
}

void tousandcsvSplit(){
    char filename[] = "1000.csv";
    Graph testnameGraph(filename, 1);
    testnameGraph.graphSplitter();

}

int main(){
   tousandcsvSplit();
}
