#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

int isEmpty(){
    if(top == NULL){
        cout<<"Stack underflow";
        return 1;
    }
    else 
    {
        return 0;
    }
}

int peek(){
    if(isEmpty()){
        return -1;
    }

    return top -> data;
}

void push(int data)
{
    struct node *ptr = new node();
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = top;
    top = ptr;
}

void pop(){
    if(isEmpty()){
        return;
    }

    struct node* ptr = top;
    top = top -> next;
    free(ptr);
    ptr = NULL;
}

void print()
{
    if (isEmpty())
    {
        return;
    }

    struct node *ptr = top;

    while (ptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    int n, data;

    while (1)
    {
        cout << "1. Push" << endl
             << "2. Print" << endl
             << "3. Pop" << endl
             <<"4. Peek"<<endl;

        cin >> n;
        if (n == 1)
        {
            cin >> data;
            push(data);
            print();
            cout << endl;
        }
        else if(n == 2){
            print();
            cout<<endl;
        }
        else if(n == 3){
            pop();
            print();
            cout<<endl;
        }
        else if(n == 4){
            int v = peek();
            cout<<v;
        }
    }
}