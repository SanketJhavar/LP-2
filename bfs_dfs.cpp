#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Graph
{
public:
    void DFS(vector<int> adj[], vector<int> &visited, int v)
    {
        visited[v] = true;
        cout << v << " ";
        for (auto &i : adj[v])
        {
            if (visited[i] == false)
            {
                DFS(adj, visited, i);
            }
        }
    }
    void BFS(vector<int> adj[], queue<int> &q, vector<int> &visited)
    {
        if (q.empty())
        {
            return;
        }
        int v = q.front();
        q.pop();
        cout << v << " ";
        visited[v] = true;
        for (auto &u : adj[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
            }
        }
        BFS(adj, q, visited);
    }
};
int main()
{
    int N;
    cout << "Enter the Number of Nodes - ";
    cin >> N;
    vector<int> adj[N];
    int e;
    cout << "\nEnter the Number of Edges - ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "\nEnter the Vertex v1 and v2 - ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "\nGraph Created Successfully!" << endl;
    int ch;
    Graph g;
    queue<int> q;
    vector<int> visited(N, false);
    while (1)
    {

        cout << "\n1.Show Graph representation - ";
        cout << "\n2.Depth First Search - " << endl;
        cout << "3.Breath First Search - " << endl;
        cout << "\nEnter the Choice - ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            // g.display();
            break;
        case 2:
            for (int i = 0; i < N; i++)
            {
                visited[i] = false;
            }
            g.DFS(adj, visited, 0);

            break;
        case 3:
            for (int i = 0; i < N; i++)
            {
                visited[i] = false;
            }
            q.push(0);
            g.BFS(adj, q, visited);
            break;
        default:
            break;
        }
    }
    return 0;
}
