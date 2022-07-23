#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

class graph
{
    unordered_map<int, int> mp; //vrtx-dest , wt(10) , bidir/not
public:
    void addEdge(int vtx, int nbr)
    {
        mp[vtx] = nbr;
        mp[nbr] = vtx;
    }

    void print()
    {
        //iterate over all elements of map
        for (auto i : mp)
        {
            int vtx = i.first; //vertex
            cout << vtx << " -> ";
            int nbr = i.second;
            cout << nbr << endl;
        }
    }
};

int main()
{
    int t, n, a;
    cin >> t >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    int u, v;
    vector<pp> ar;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        ar.push_back(make_pair(u, v));
    }
    graph g;
    for (int i = 0; i < ar.size(); i++)
    {
        g.addEdge(arr[ar[i].first - 1], arr[ar[i].second - 1]);
    }
    
    g.print();
    return 0;
}