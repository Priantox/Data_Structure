#include <iostream>
using namespace std;
#define MAX 3

int stack_arr[MAX];
int top = -1;

bool isFull()
{

    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isEmpty()
{
    if (top == -1)
        return 1;
    
    else
        return 0;
    
}

void push(int data)
{

    if (isFull())
    {
        cout << "Stack overflow" << endl;
        return;
    }

    top++;
    stack_arr[top] = data;
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
    int value = stack_arr[top];
    top--;
    return value;
}

int peek()
{
    if (isEmpty)
        return -1;

    int data = stack_arr[top];
    return data;
}

void print()
{

    if (isEmpty())
    {
        cout << "Stack underflow";
        return;
    }

    for (int i = top; i >= 0; i--)
        cout << stack_arr[i] << endl;
}

int main()
{

    push(2);
    push(3);
    push(4);
    // int data = pop();
    print();
}