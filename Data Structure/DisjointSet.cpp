#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int ranked[1000];

void make_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        ranked[i] = 0;
    }
}

int find_parent(int node)
{
    if (parent[node] == node)
        return parent[node];
    else
        return parent[node] = find_parent(parent[node]);
}

void union_set(int u, int v)
{
    u = find_parent(u);
    v = find_parent(v);

    if (ranked[u] < ranked[v])
        parent[u] = v;
    else if (ranked[u] > ranked[v])
        parent[v] = u;
    else{
        parent[u] = v;
        ranked[u]++;
    }
}

int main()
{
    int n;
    cin >> n;
    make_set(n);

    while (--n)
    {
        int u, v;
        cin >> u >> v;
        union_set(u, v);
    }
}