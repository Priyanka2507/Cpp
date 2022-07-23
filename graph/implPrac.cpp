#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    // 01-04 : Graph implementation
    //  no. of nodes
    int v;
    // adjacency list : array of vectors
    vector<int> *l; // vector of pointers
    graph(int V)
    {
        v = V;
        l = new vector<int>[v];
        // for weighted graph
        // declaration of l
        // vector<pair<int,int>> *l;
        // l = new vector<pair<int,int>>[v];
    }
    void addEdge(int src, int des)
    {
        l[src].push_back(des);
        l[des].push_back(src);
        // for weighted graph and directed src->des with w = weight
        // l[src].push_back({des,w});
    }
    void printList()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex " << i << " -> ";
            for (auto x : l[i])
            {
                cout << x << " , ";
            }
            cout << "\n";
        }
    }
    // 05. no. of connected components
    int connnectedComp()
    {
        int cnt = 0;
        int vis[v] = {0};
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                bfs(i, vis);
                cnt++;
            }
        }
        return cnt;
    }
    // 06.BFS :  using queue T:O(v+e) S:O(v+e)+O(n)+O(n)
    void bfs(int u, int *vis)
    {
        queue<int> q;
        q.push(u);
        vis[u] = 1;
        while (!q.empty())
        {
            int node = q.front();
            cout << node << " , ";
            q.pop();
            for (auto x : l[node])
            {
                if (!vis[x])
                {
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        cout << endl;
    }
    // 07. DFS
    void dfsutil(int u, int *vis)
    {
        cout << u << " , ";
        vis[u] = 1;
        for (auto x : l[u])
        {
            if (!vis[x])
                dfsutil(x, vis);
        }
    }
    void dfs(int u, int *vis)
    {
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfsutil(i, vis);
            }
        }
    }
    // 08. Cycle detection in undirected graph using bfs
    bool icbfs(int u, int *vis)
    {
        queue<pair<int, int>> q;
        q.push({u, -1});
        vis[u] = 1;
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto x : l[node])
            {
                if (!vis[x])
                {
                    q.push({x, node});
                }
                else if (x != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycleBfs()
    {
        int vis[v] = {0};
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                return icbfs(i, vis);
            }
        }
        return false;
    }
    // 09. Cycle detection in undirected graph using dfs
    bool icdfs(int u, int parent, int *vis)
    {
        vis[u] = 1;
        for (auto i : l[u])
        {
            if (!vis[i])
            {
                if (icdfs(i, u, vis))
                    return true;
            }
            else if (i != parent)
                return true;
        }
        return false;
    }
    bool isCycleDfs()
    {
        int vis[v] = {0};
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                return icdfs(i, -1, vis);
            }
        }
        return false;
    }
    // 10. Check Bipartite using BFS : bipartite graph which can be coloured with 2 colours
    // no graph with odd cycle can be a bipartite graph
    bool ibBFS(int u, int *col)
    {
        queue<int> q;
        q.push(u);
        while (!q.empty())
        {
            int node = q.front();
            col[node] = 1;
            q.pop();
            for (auto i : l[node])
            {
                if (col[i] == -1)
                {
                    q.push(i);
                    col[i] = col[node] - 1;
                }
                else if (col[i] == col[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkBipartiteBFS()
    {
        int col[v] = {-1};
        for (int i = 0; i < v; i++)
        {
            if (col[i] == -1)
            {
                return ibBFS(i, col);
            }
        }
        return false;
    }
    // 11. Check Bipartite using DFST
    bool ibDFS(int u, int parent, int *col)
    {
        col[u] = 1;
        for (auto i : l[u])
        {
            if (col[i] == -1)
            {
                col[i] = col[u] - 1;
                if (!ibDFS(i, u, col))
                    return false;
            }
            else if (col[i] == col[u])
                return false;
        }
        return true;
    }
    bool checkBipartiteDFS()
    {
        int col[v] = {-1};
        for (int i = 0; i < v; i++)
        {
            if (col[i] == -1)
            {
                return ibDFS(i, -1, col);
            }
        }
        return true;
    }
    // 12. Cycle detection in directed graph using DFS
    bool isCycleDirected()
    {
        return false;
    }
    // 15. Kahn's algorithm : Cycle detection in directed graph using BFS
    bool isCycleDirectedBFS()
    {
        return false;
    }
    // Topological Sort is only for DAG
    //  13. Topological Sort DFS : after traversing all the neighbours push node in stack
    void dfsTopo(int u, int *vis, stack<int> &st)
    {
        vis[u] = 1;
        for (auto i : l[u])
        {
            if (!vis[i])
            {
                dfsTopo(i, vis, st);
            }
        }
        st.push(u);
    }
    void topologicalSortDFS()
    {
        stack<int> st;
        int vis[v] = {0};
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfsTopo(i, vis, st);
            }
        }
        while (!st.empty())
        {
            cout << st.top() << " -> ";
            st.pop();
        }
        return;
    }
    // 14. Topological Sort BFS : Kahn's algorithm
    void topologicalSortBFS()
    {
        // calc indegree
        int indeg[v] = {0};
        for (int i = 0; i < v; i++)
        {
            for (auto x : l[i])
            {
                indeg[i]++;
            }
        }
        // add nodes with indeg = 0 to queue
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        // traverse nodes and dec indeg until all nodes are not traversed
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " -> ";
            for (auto x : l[node])
            {
                indeg[x]--;
                if (indeg[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        return;
    }
    // 16. Shortest distance in undirected graph with unit weights
    // update distance in distance array of each node wrt u/src node using bfs
    void shortestDistance(int u)
    {
        // tc : O(v+e) sc : O(v)
        int distance[v] = {INT_MAX};
        queue<int> q;
        q.push(u);
        distance[u] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto i : l[node])
            {
                distance[i] = min(distance[i], 1 + distance[node]);
                q.push(i);
            }
        }
        for (int i = 0; i < v; i++)
        {
            cout << i << " : distance from source is " << distance[i] << endl;
        }
    }
    // 17. Shortest path in weighted DAG
    void shortestDistanceDAG()
    {
        // step 1. find topo sort dfs method
        stack<int> st;
        int vis[v] = {0};
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfsTopo(i, vis, st);
            }
        }
        // step 2. take distance array and update ditance of each node from stack
        int distance[v] = {INT_MAX};
        distance[0] = 0; // 0 is source
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (distance[node] != INT_MAX)
            {
                for (auto i : l[node])
                {
                    distance[i] = min(distance[i], distance[node] + 1);
                    // add weight here as auto i : i.first = node and i.second = weight
                    // dis[i.first] = min(dis[i.first], distance[i.first]+i.second);
                }
            }
        }
        for (int i = 0; i < v; i++)
        {
            cout << i << " : distance from source is " << distance[i] << endl;
        }
    }
};

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

// 23.Disjoint Set
class disjointSet
{
    int v;
    int *rank; // rank array : stores rank of node eg root node at level = rank[root]
    int *par;  // parent array
    disjointSet(int V)
    {
        int v = V;
        for (int i = 0; i < v; i++)
        {
            // initially every node is its own parent
            par[i] = i;
            // 0 : leaf node , initially every node is leaf node so rank = 0
            rank[i] = 0;
        }
    }
    int findParent(int u)
    {
        if (par[u] = u)
        {
            // if node is root return itself
            return u;
        }
        // else find the root of node and return it
        //  eg 1<-2<-3<-7   is chain for 2,3,7 parent is 1
        return par[u] = findParent(par[u]);
    }

    void FindUnion(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (rank[u] < rank[v]) // 1<-2<-3 7
        {
            par[u] = v; // path compression 7 can directly attach to root node 1
            // path compression is imp to minimize the depth / movement down the tree
        }
        else if (rank[u] > rank[v])
        {
            par[v] = u; // similar to above
        }
        else
        {
            // both are at same level => anyone can be anyone's parent
            par[v] = u;
            rank[v]++; // inc level once node is made parent
        }
    }
};

// 24.Kruskal's Algorithm : To find minimum spanning tree
void kruskal()
{
    int v, m;
    cin >> v >> m;
    vector<node> edge; // list of nodes
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back(node(u, v, w));
    }
    // Sorting edges acc to weights
    sort(edge.begin(), edge.end(), comp);
    // sort
    for(int i = 0; i < v; i++){

    }
}
// 18. Dijkstra Algorithm : shortest path in undirected graph
void dijkstra()
{

    // priority_queue<pair<int, int>> pq;
    // int distance[v] = {INT_MAX};
    // pq.push({0, 1});
    // while (!pq.empty())
    // {
    //     auto it = pq.top();
    //     pq.pop();
    //     for (auto i : l[it.first])
    //     {
    //         distance[i] = min(distance[i], distance[it.first] + it.second);
    //     }
    // }
}

int main()
{
    graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.printList();
    g.shortestDistance(0);
    return 0;
}

// Tarjan's algorithm