#ifndef CONNECTIONSGRAPH_H_INCLUDED
#define CONNECTIONSGRAPH_H_INCLUDED

#include <vector>
using namespace std;

class ConnectionsGraph{
    private:
        int maxPoints;
        vector<int> *adj;
    public:
        ConnectionsGraph(int points);
        void addEdge(int v, int w);
        bool areConnected(int s, int d);

};
#endif // CONNECTIONSGRAPH_H_INCLUDED
