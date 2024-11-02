#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data)
{
    struct node *temp = new node();
    temp->data = data;
    temp->next = NULL;

    if (rear == NULL && front == NULL)
    {
        front = temp;
        rear = temp;
        rear->next = front;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

void dequeue()
{

    struct node *temp = front;

    if (front == NULL && rear == NULL)
        cout << "Empty";
    else if (front == rear)
    {
        front == NULL;
        rear = NULL;
        free(temp);
    }
    else
    {
        front = front -> next;
        rear -> next = front;
        free(temp);
    }
}

void display(){
    struct node* temp = front;

    if(front == NULL && rear == NULL){
        cout<<"Empty"<<endl;
    }
    else{

        while(temp -> next != front){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<temp -> data;
    }
}

int main()
{

    enqueue(4);
    enqueue(3);
    enqueue(1);
    enqueue(9);
    display();
    cout << endl;
    dequeue();
    display();
}