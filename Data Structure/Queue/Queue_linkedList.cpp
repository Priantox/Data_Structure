#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

bool isEmpty()
{
    if (front == NULL && rear == NULL)
    {
        cout << "No data";
        return 1;
    }
    else
        return 0;
}

void enqueue(int data)
{
    struct node *temp = new node();
    temp->data = data;
    temp->next = NULL;

    if (isEmpty())
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        return;
    }

    struct node *temp = front;
    front = front->next;
    free(temp);
    temp = NULL;
}

void peek()
{
    if (isEmpty())
    {
        return;
    }

    cout<<front -> data;
}

void display()
{
    if (isEmpty())
    {
        return;
    }

    struct node *temp = front;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    enqueue(5);
    enqueue(8);
    display();
    dequeue();
    cout << endl;
    display();
}