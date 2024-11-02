#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX 100
using namespace std;

char infix[MAX];
int stack[MAX];
char postfix[MAX];
int top = -1;

bool isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(char symbol)
{
    top++;
    stack[top] = symbol;
}

int pop()
{
    int symbol = stack[top];
    top--;
    return symbol;
}

int precedence(char symbol)
{
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

void InToPost()
{
    int l = 0;
    char symbol;
    char next;

    for (int i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];

        if (symbol == '(')
            push(symbol);
        else if (symbol == ')')
        {
            next = pop();
            while (next != '(')
            {
                postfix[l] = next;
                l++;
                next = pop();
            }
        }
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
        {
            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                postfix[l++] = pop();

            push(symbol);
        }
        else
            postfix[l++] = symbol;
    }
    while (!isEmpty())
        postfix[l++] = pop();
    postfix[l] = '\0';
}

int post_eval(){

    int a,b;

    for(int i = 0; i < strlen(postfix); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9')
        push(postfix[i] - '0');
        else{
            a = pop();
            b = pop();

            int symbol = postfix[i];

            if(symbol == '+')
            push(b+a);
            else if(symbol == '-')
            push(b-a);
            else if(symbol == '*')
            push(b*a);
            else if(symbol == '/')
            push(b/a);
            else if(symbol == '^')
            push(pow(b,a));
        }
    }
    return pop();
}

void print()
{

    int i = 0;
    cout << "The posfix expression is: ";
    while (postfix[i])
        cout << postfix[i++];
}

int main()
{
    cout << "Enter your infix expression:" << endl;
    gets(infix);

    InToPost();
    int result = post_eval();
    cout<<endl;
    print();
    cout<<endl;
    cout<<"The Result: "<<result;
    cout<<endl<<endl;
}