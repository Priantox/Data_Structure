#include<iostream>
using namespace std;
#define N 100

int visited_arr[N];
int visited_seq = -1;
int front = -1;
int rear = -1;
int queue[N];


int number;
int a[N][N];
int no_of_vertex;

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

    for(int i = 0; i < no_of_vertex; i++){

        if(ch == i){

            for(int j = 0; j < no_of_vertex; j++){

                if(a[i][j] == 1){

                    if(is_visit(j) == false)
                    enqueue(j);
                }
            }
        }
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

        if(!is_visit(ch))
        visit(ch);
    }
  
}

void create_graph(){

    cout<<"Enter  the number of vertices: ";
    cin>>no_of_vertex;

    cout<<"Enter start state number: ";
    cin>>number;

    for (int i = 0; i < no_of_vertex; i++)
    {
        for (int j = i + 1; j < no_of_vertex; j++)
           a[i][j] = 0; 
    }

    for (int i = 0; i < no_of_vertex; i++)
    {
        for (int j = i + 1; j < no_of_vertex; j++)
        {
            cout << i << "-" << j <<": ";
            cin >> a[i][j];

            a[j][i] = a[i][j];
        }
    }
}

int main(){

    create_graph();
    BFS();
    print();
}