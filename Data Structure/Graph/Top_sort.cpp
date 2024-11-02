#include <iostream>
#define N 50
using namespace std;

bool vis[N] = {false};
int adj[N][N];  // Adjacency matrix to store the graph
int adj_size[N] = {0};  // Array to store the size of adjacency lists
int result[N];  // Array to store the result of topological sorting
int result_index = 0;  // Index to keep track of the position in result array

void dfs(int node)
{
    vis[node] = true;
    for (int i = 0; i < adj_size[node]; i++)
    {
        int next_node = adj[node][i];
        if (!vis[next_node])
        {
            dfs(next_node);
        }
    }
    result[result_index++] = node;  // Add node to result after exploring all its adjacent nodes
}

void check(int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}

void create_graph(int m)
{
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u][adj_size[u]++] = v;  // Add edge u -> v
    }
}

void print(int nodes)
{
    for (int i = result_index - 1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    create_graph(edges);

    check(nodes);

    print(nodes);

    return 0;
}
