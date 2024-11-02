#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void addEdge(Node* adjList[], int u, int v)
{
  
    Node* newNode = new Node();
    newNode->data = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
  
    newNode = new Node();
    newNode->data = u;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}


void print(Node* adjList[], int size)
{
    for (int i = 0; i < size; i++)
    {
        Node* temp = adjList[i];
        cout << "Adjacency list of vertex " << i << ": ";
        while (temp)
        {
            cout << temp->data;
            temp = temp->next;

            if(temp)
            cout<<" -> ";
        }
        cout << endl;
    }
}

int main()
{
    int size;
    cout << "Enter number of vertices: ";
    cin >> size;

   
    Node* adjList[size] = {NULL};

    int edge;
    cout << "Enter number of edges: ";
    cin >> edge;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

 
    print(adjList, size);
    
}
