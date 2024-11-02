#include<bits/stdc++.h>
using namespace std;

int vertex,edges;
int key[1000];
int parent[1000];
int mst[1000];

struct Edge{
    int u;
    int v;
    int weight;
};

void connect_vertex(vector<Edge> &edgeList){
    for(int i = 0; i < edges; i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        edgeList.push_back({u,v,weight});
    }
}

void setup(){
    for(int i = 0; i < vertex; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
}

int prims(vector<Edge> &edgeList){
    int min_weight = 0;
    key[0] = 0;

    for(int i = 0; i < vertex; i++){
        int min = INT_MAX;
        int u;

        for(int j = 0; j < vertex; j++){
            if(mst[j] == false && key[j] < min){ 
                u = j;
                min = key[j];
            }
        }

        mst[u] = true;

        for (auto &edge : edgeList)
        {
            if (edge.u == u)
            {
                int v = edge.v;
                int weight = edge.weight;

                if (mst[v] == false && weight < key[v])
                {
                    key[v] = weight; 
                    parent[v] = u;
                    min_weight += weight;
                }
            }
            else if (edge.v == u)
            {
                int v = edge.u;
                int weight = edge.weight;

                if (mst[v] == false && weight < key[v])
                {
                    key[v] = weight;
                    parent[u] = v;
                    min_weight += weight;
                }
            }
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
    setup();

    int min_weight = prims(edgeList);
    cout<<min_weight;
}