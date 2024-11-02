#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *top1 = NULL;
struct node *top2 = NULL;
int count = 0;

void push1(int data)
{

    struct node *temp = new node();
    temp->data = data;
    temp->next = NULL;

    top1->next = temp;
    top1 = temp;
}

void push2(int data)
{
    struct node *temp = new node();
    temp->data = data;
    temp->next = NULL;

    top2->next = temp;
    top2 = temp;
}

int pop1(){

    return top1 -> data;
    top1 = top1 -> next;
}

int pop2(){

    return top2 -> data;
    top2 = top2 -> next;
}

void enqueue(int data)
{
    push1(data);
    count++;
}

void dequeue()
{
    if (top1 == NULL)
        cout << "Empty";
    else
    {
        for (int i = 0; i < count; i++)
            push2(pop1());

        cout << "Dequeue value is " << pop2() << endl;
        count--;

        for (int i = 0; i < count; i++)
            push1(pop2());
    }
}
void display(){
    if(top1 == NULL)
    cout<<"Empty";
    else{

        struct node* temp = top1;

        while(temp != NULL){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
    }
}

int main()
{

    enqueue(5);
    enqueue(6);
    enqueue(7);
    dequeue();
    display();
}