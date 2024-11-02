#include <iostream>
using namespace std;
#define MAX 5

int front = -1;
int rear = -1;
int queue_arr[MAX];

void enqueue(int data)
{

    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue_arr[rear] = data;
    }
    else if ((rear + 1) % MAX == front)
        cout << "Queue is full";
    else
    {
        rear = (rear + 1) % MAX;
        queue_arr[rear] = data;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout<<"No data";
    }
    else
    {
        int x = queue_arr[front];
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "No data";
    }
    else
    {
        int i = front;

        while (i != rear)
        {
            cout << queue_arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout<<queue_arr[rear];
    }
}

int main()
{

    enqueue(4);
    enqueue(3);
    enqueue(1);
    enqueue(9);
    enqueue(3);
    dequeue();
    display();
}