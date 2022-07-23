#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int V;
    // Array of vectors //Adjacency List
    vector<int> *l;

    graph(int V) // constructor
    {
        this->V = V;
        l = new vector<int>[V];
    }
    void addEdge(int x, int y)
    {
        l[y].push_back(x); // edge from y to x
        l[x].push_back(y); // edge from x to y
    }
    // Printing adjacency list
    void printList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "vertex " << i << "->";
            for (auto x : l[i])
            {
                cout << x << " , ";
            }
            cout << endl;
        }
    }
    // bfs using queue
    void bfs(int src)
    {
        int visited[V] = {0};
        queue<int> q;

        q.push(src);
        visited[src] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " , ";
            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }
        }
    }
    // dfs using recursion
    void dfsUtil(int src, int *vis)
    {
        cout << src << " , ";
        vis[src] = 1;
        for (auto i : l[src])
        {
            if (!vis[i])
                dfsUtil(i, vis);
        }
        return;
    }

    void dfsRecur(int src)
    {
        int visited[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsUtil(src, visited);
            }
        }
    }
    
    // Cycle detection in undirected graph using bfs
    bool isCycleBfs()
    {
        return false;
    }
    // Cycle detection in undirected graph using dfs
    bool isCycleDfs()
    {
        return false;
    }
    // Check Bipartite using BFS
    bool isbiparBfs(int src, int *color)
    {
        queue<int> q;
        color[src] = 1;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto i : l[node])
            {
                if (color[i] == -1)
                {
                    color[i] = 1 - color[node];
                    q.push(i);
                }
                else if (color[i] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartiteBFS()
    {
        int color[V] = {-1};
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!isbiparBfs(i, color))
                    return false;
            }
        }
        return true;
    }
    // Check Bipartite using DFS
    bool isbiparDfs(int src, int *color)
    {
        color[src] = 1;
        for (auto i : l[src])
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[src];
                isbiparDfs(i, color);
                if (!isbiparDfs(i, color))
                    return false;
            }
            else if (color[i] == color[src])
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartiteDFS()
    {
        int color[V] = {-1};
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!isbiparDfs(i, color))
                    return false;
            }
        }
        return true;
    }
    // Topological sort using dfs : for Directed Acyclic Graph
    void topoDfs(int src, int *vis, stack<int> &st)
    {
        vis[src] = 1;
        for (auto i : l[src])
        {
            if (!vis[i])
                topoDfs(i, vis, st);
        }
        st.push(src);
    }
    void topoSort()
    {
        int vis[V] = {0};
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                topoDfs(i, vis, st);
            }
        }

        while (!st.empty())
        {
            cout << st.top() << " , ";
            st.pop();
        }
        return;
    }
    // Topological sort using bfs : Kahn's Algorithm : for Directed Acyclic Graph
    void topoBfs()
    {
        int indeg[V];
        // calculate indegree of nodes
        for (int i = 0; i < V; i++)
        {
            for (auto it : l[i])
            {
                indeg[it]++; // indeg[0]++ for 5->0,2 => ideg = {2,2,1,1,0,0}
            }
        }
        queue<int> q;
        // push in nodes with zero indegree
        for (int i = 0; i < V; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }
        // while q is not empty dec  indegree of adjcent nodes and push nodes with indegree 0 in queue
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " , ";
            for (auto i : l[node])
            {
                indeg[i]--;
                if (indeg[i] == 0)
                    q.push(i);
            }
        }
    }
};

int main()
{
    graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.printList();
    g.bfs(0);
    g.dfsRecur(0);
    cout << "\n Topological Sort : ";
    g.topoSort();
    cout << "\n Topological Sort (Kahn's Algorithm) : ";
    g.topoBfs();
    return 0;
}