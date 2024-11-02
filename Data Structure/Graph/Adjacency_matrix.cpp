#include <iostream>
using namespace std;

void adjacency_matrix(int n, int m)
{
    int adj[n + 1][n + 1];
    int u, v;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            adj[i][j] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    //print
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << adj[i][j] << " ";

        cout << endl;
    }
}

int main()
{

    int nodes, edges;
    cin >> nodes >> edges;

    adjacency_matrix(nodes, edges);
}