#include<iostream>
using namespace std;
#define MAX 3

int stack_arr[MAX];
int first_data = -1;

bool isEmpty(){
    if(first_data == -1){
        cout<<"Stack underflow";
        return 1;
    }
    else{
        return 0;
    }
}

bool isFull(){
    if(first_data == MAX - 1){
        cout<<"Stack overflow";
        return 1;
    }
    else{
        return 0;
    }
}

int peek(){
    if(isEmpty){
        return -1;
    }
    return stack_arr[0];
}

void push(int data){
    first_data++;

    for(int i = first_data; i > 0; i--){
        stack_arr[i] = stack_arr[i - 1];
    }
    stack_arr[0] = data;
}

void pop(){
    if(isEmpty){
        cout<<"Stack underflow";
        return;
    }

    for(int i = 0; i < first_data; i++){
        stack_arr[i] = stack_arr[i + 1];
    }
    first_data--;
}

void print(){
    if(isEmpty()){
        return;
    }

    for(int i = 0; i <= first_data; i++){
        cout<<stack_arr[i]<<endl;
    }
}

int main(){

    int n,data;
    while (1)
    {

        cout << "1. Push data" << endl
             << "2. Pop data" << endl
             << "3. Inform the first eliment" << endl
             << "4. Print all data"
             << "5. Quit";

        cin >> n;

        if (n == 1)
        {
            cin >> data;
            push(data);
        }
        else if (n == 2)
        {
            pop();
        }
        else if (n == 3)
        {
            peek();
        }
        else if(n == 4){
            print();
        }
        else if(n == 5){
            break;
        }
    }
}