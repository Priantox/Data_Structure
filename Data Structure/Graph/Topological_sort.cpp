#include <iostream>
#include <vector>
#define N 50
using namespace std;

bool vis[N] = {false};
vector<int> adj[N];
int top = -1;
int stack[N];

int peek()
{
    return stack[top];
}

void push(int node)
{
    top++;
    stack[top] = node;
}

void pop()
{
    top--;
}

void dfs(int node)
{
    vis[node] = true;
    for (int i = 0; i < adj[node].size(); i++)
    {
        int next_node = adj[node][i];
        if (!vis[next_node])
        {
            dfs(next_node);
        }
    }
    push(node);
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
        adj[u].push_back(v);
    }
}

void print()
{
    while (top != -1)
    {
        cout << peek() << " ";
        pop();
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    create_graph(edges);

    check(nodes);

    print();

    return 0;
}
