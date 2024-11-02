#include <iostream>
using namespace std;
#define N 4

int s1[N];
int s2[N];
int top1 = -1;
int top2 = -1;
int count = 0;

void push1(int data)
{
    if (top1 == N - 1)
        cout << "Full";
    else
    {
        top1++;
        s1[top1] = data;
    }
}

void push2(int data)
{
    if (top2 == N - 1)
        cout << "Full";
    else{
        top2++;
        s2[top2] = data;
    }
}

int pop1()
{
    return s1[top1--];
    //s1[top1];
    // top1--;
}

int pop2()
{
    return s2[top2--];
}

void enqueue(int data)
{
    push1(data);
    count++;
}

void dequeue()
{
    if (top1 == -1)
        cout << "Queue is empty";
    else
    {
        for (int i = 0; i < count; i++)
        {
            push2(pop1());
        }
        cout << "Dequeue value is " << pop2() << endl;
        count--;

        for (int i = 0; i < count; i++)
        {
            push1(pop2());
        }
    }
}

void display()
{
    for (int i = 0; i <= top1; i++)
        cout << s1[i]<<" ";
}

int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    dequeue();
    display();
}