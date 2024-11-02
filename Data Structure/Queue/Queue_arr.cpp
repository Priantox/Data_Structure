#include<iostream>
using namespace std;
#define MAX 4

int queue_arr[MAX];
int front = -1;
int rear = -1;

void enqueue(int data){
    if(rear == MAX - 1){
        cout<<"Queue_overflow";
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue_arr[rear] = data;
    }
    else {
        rear++;
        queue_arr[rear] = data;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        cout<<"Queue underflow";
    }
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else {
        front++;
    }
}

void print(){

    if(front == -1 && rear == -1){
        cout<<"No data";
    }
    else{
        for(int i = front; i <= rear; i++){
            cout<<queue_arr[i]<<endl;
        }
    }
}

int main(){

    enqueue(9);
    enqueue(10);
    print();
    cout<<endl;
    dequeue();
    print();
}