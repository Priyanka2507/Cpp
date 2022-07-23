#include <bits/stdc++.h>
using namespace std;


// graph implementation using list and unordered_map
class graph
{
    unordered_map<string, list<pair<string, int>>> l;

public:
    void addEdge(string x, string y, int wt, bool bidir)
    {
        l[x].push_back(make_pair(y, wt));
        if (bidir)
        {
            l[y].push_back(make_pair(x, wt));
        }
    }

    void printGraph()
    {
        for (auto i : l)
        {
            string src = i.first;
            cout << "Source " << src << " -> ";
            list<pair<string, int>> nbr = i.second;
            for (auto j : nbr)
            {
                string des = j.first;
                int dist = j.second;
                cout << " nbr : " << des << " weight : " << dist << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g;
    g.addEdge("A", "B", 10, true);
    g.addEdge("A", "C", 10, false);
    g.addEdge("B", "D", 10, true);
    g.addEdge("C", "D", 10, false);
    g.printGraph();
    return 0;
}