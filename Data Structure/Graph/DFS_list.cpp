#include <iostream>
using namespace std;
#define N 50

int visited_arr[N];
int visited_seq = -1;
int stack[N];
int top = -1;
int number;

struct node{
    int data;
    struct node* next;
};
struct node* adj[N] = {NULL};

bool isEmpty()
{
    if (top == -1)
        return true;

    return false;
}

void push(int ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    int c = stack[top];
    top--;
    return c;
}

void visit(char ch)
{
    visited_seq++;
    visited_arr[visited_seq] = ch;
}



bool is_visited(int ch)
{

    for (int i = 0; i <= visited_seq; i++)
    {
        if (visited_arr[i] == ch)
            return true;
    }
    return false;
}

void find_adjacency(int ch)
{
    struct node* temp = adj[ch];

    while(temp){
        if(is_visited(temp -> data) == false)
        push(temp -> data);

        temp = temp -> next;
    }
}

void DFS()
{
    push(number);
    while (!isEmpty())
    {
        int ch = pop();
        find_adjacency(ch);

        if (is_visited(ch) == false)
            visit(ch);
    }
}

void addEdges(int u, int v){
    struct node* newNode = new node();
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
  
    newNode = new node();
    newNode->data = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void create_graph(){

    int size,edges;

    cout << "Enter number of vertices: ";
    cin >> size;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout<<"Enter start state: ";
    cin>>number;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdges(u, v);
    }
    
}

void print()
{
    for (int i = 0; i <= visited_seq; i++)
    {
        cout << visited_arr[i] << " ";
    }
}

int main()
{
    create_graph();
    DFS();
    print();
}