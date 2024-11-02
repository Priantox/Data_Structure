#include<bits/stdc++.h>
using namespace std;

int vertex,edges;

struct Edge{
    int u;
    int v;
    int weight;
};

bool cmp(Edge a,Edge b){
    return a.weight < b.weight;
}

void connect_vertex(vector<Edge> &edgeList){
    for(int i = 0; i < edges; i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        edgeList.push_back({u,v,weight});
    }
}

void make_set(vector<int> &parent,vector<int> &ranks){
    for(int i = 0; i < vertex; i++){
        parent[i] = i;
        ranks[i] = 0;
    }
}

int find_parent(vector<int> &parent,int node)
{
    if (parent[node] == node)
        return parent[node];
    else
        return parent[node] = find_parent(parent,parent[node]);
}

void union_set(int u, int v,vector<int> &parent,vector<int> &ranks)
{
    if (ranks[u] < ranks[v])
        parent[u] = v;
    else if (ranks[u] > ranks[v])
        parent[v] = u;
    else{
        parent[u] = v; 
        ranks[u]++;
    }
}

int kruskal(vector<int> &parent,vector<int> &ranks,vector<Edge> &edgeList){
    int min_weight = 0;

    for(int i = 0; i < edges; i++){
        int u = find_parent(parent,edgeList[i].u);
        int v = find_parent(parent,edgeList[i].v);

        int wht = edgeList[i].weight;

        if(u != v){
            union_set(u,v,parent,ranks);
            min_weight += wht;
        }
    }
    return min_weight;
}

int main(){
    cout<<"Vertex: ";
    cin>>vertex;
    cout<<"Edges: ";
    cin>>edges;

    vector<Edge> edgeList;
    connect_vertex(edgeList);

    sort(edgeList.begin(),edgeList.end(),cmp);

    vector<int> parent(vertex);
    vector<int> ranks(vertex);

    make_set(parent,ranks);

    int minweight = kruskal(parent,ranks,edgeList);

    cout<<minweight;
}