#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int n, v;
    vector<pair<int, int>> *adj;
    int *visited;
    vector<pair<int, int>> MST;
    Graph(int n, int v)
    {
        this->n = n;
        this->v = v;
        adj = new vector<pair<int, int>>[n];
        visited = new int[n];
        for (int i = 0; i < n; i++)
            visited[i] = 0;
    }
    void addEdge(int v, int u, int w)
    {
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }
    int prims()
    {
        int sum = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({-1, {0, -1}});
        //{{weight,node},parent}
        visited[0] = 1;
        while (!pq.empty())
        {
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            int w = pq.top().first;
            pq.pop();
            if (w != -1)
            {
                if (visited[node])
                    continue;
                visited[node] = 1;
                sum += w;
                MST.push_back({node, parent});
            }
            for (auto it : adj[node])
            {
                if (!visited[it.first])
                {
                    pq.push({it.second, {it.first, node}});
                }
            }
        }
        return sum;
    }
};
main()
{
    int n, v;
    cout << "Enter the Nodes : " << endl;
    cin >> n;
    cout << "Enter the Vertices : " << endl;
    cin >> v;
    Graph g(n, v);
    for (int i = 0; i < v; i++)
    {
        cout << "Enter the Edge : " << endl;
        int a, b;
        cin >> a >> b;
        cout << "Enter the Weight : " << endl;
        int w;
        cin >> w;
        g.addEdge(a, b, w);
    }
    cout << "Cost of MST : " << g.prims() << endl;
    for (auto it : g.MST)
    {
        cout << it.first << " " << it.second << endl;
    }
}
