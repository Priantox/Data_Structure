#include<iostream>
using namespace std;
#define N 100

int visited_arr[N];
int visited_seq = -1;
int front = -1;
int rear = -1;
int queue[N];
int number;

struct node{
    int data;
    struct node* next;
};
struct node* adj[N] = {NULL};

void enqueue(int ch){

    rear = (rear + 1) % N;
    queue[rear] = ch;
}

char dequeue(){

    front = (front + 1) % N;
    return queue[front];
}

void visit(int ch){

    visited_seq++;
    visited_arr[visited_seq] = ch;
}

bool is_visit(int ch){
    
    for(int i = 0; i <= visited_seq; i++){
        
        if(visited_arr[i] == ch)
        return true;
    }
    return false;
}

void find_adjacency(int ch){

    struct node* temp = adj[ch];

    while(temp){
        if(!is_visit(temp -> data))
        enqueue(temp -> data);

        temp = temp -> next;
    }
}

void print(){
    for(int i = 0; i <= visited_seq; i++){
        cout<<visited_arr[i]<<" ";
    }
}

void BFS(){

    enqueue(number);
    while(front != rear){
        int ch = dequeue();
        find_adjacency(ch);

        if(is_visit(ch) == false)
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

int main(){

    create_graph();
    BFS();
    print();
}