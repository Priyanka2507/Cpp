#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

class graph
{
    unordered_map<int, vector<pp>> mp; //vrtx-dest , wt(10) , bidir/not
public:
    void addEdge(int vtx, int nbr, bool bidir, int wt)
    {
        mp[vtx].push_back(make_pair(nbr, wt));
        if (bidir)
            mp[nbr].push_back(make_pair(vtx, wt));
    }

    void print()
    {
        //iterate over all elements of map
        for (auto i : mp)
        {
            int vtx = i.first;         //vertex
            vector<pp> nbr = i.second; //neighbour details
            cout << vtx << " -> ";
            for (auto j : nbr)
            {
                int dest = j.first;
                int wt = j.second;
                cout << dest << " (" << wt << ") , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g;
    g.addEdge(0, 1, true, 10);
    g.addEdge(0, 3, true, 10);
    g.addEdge(1, 2, true, 10);
    g.addEdge(2, 3, true, 10);
    g.addEdge(0, 2, false, 5);
    g.print();
    return 0;
}