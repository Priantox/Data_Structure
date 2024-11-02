#include <iostream>
#include <vector>
using namespace std;

void print(int n, vector<int> adj[])
{
    for (int i = 1; i <= n; i++)
    {
        cout<<i<<" -> ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";

        cout << endl;
    }
}

void adjacency_list(int n, int m)
{

    vector<int> adj[n + 1];
    int u, v;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << endl
         << endl;
    print(n, adj);
}

int main()
{

    int nodes, edges;
    cin >> nodes >> edges;

    adjacency_list(nodes, edges);
}