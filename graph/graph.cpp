#include <bits\stdc++.h>
using namespace std;

// adjacency list implementation
class edge
{
public:
    int src;
    int nbr;
    int wt;

    edge()
    {
        src = 0;
        nbr = 0;
        wt = 0;
    }
    edge(int src, int nbr, int wt)
    {
        src = src;
        nbr = nbr;
        wt = wt;
    }
};

int main()
{
    int n = 0;
    cin >> n;
    edge *graph[n];
    for (int i = 0; i < n; i++)
    {
        int src, nbr, wt;
        cin >> src >> nbr >> wt;
        graph[i] = new edge(src, nbr, wt);
    }
    for(int i=0;i<n;i++){
        cout<<graph[i]<<", ";
    }

    return 0;
}