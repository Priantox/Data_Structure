#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;

struct node* create(){
    
    int data;
    struct node* ptr = new node();

    cout<<"Enter data: "<<endl;
    cin>>data;

    if(data == -1)
    return NULL;

    ptr -> data = data;
    cout<<"Enter left child of "<<data<<endl;
    ptr -> left = create();

    cout<<"Enter right child of "<<data<<endl;
    ptr -> right = create();

    return ptr;
}

int main(){

    root = create();
}