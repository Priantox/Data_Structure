#include <iostream>
using namespace std;
#include <string.h>
#define N 20

int top = -1;
char stack[N];

bool isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

bool match(char a,char b){
    if(a == '[' && b == ']')
    return 1;
    
    if(a == '{' && b == '}')
    return 1;

    if(a == '(' && b == ')')
    return 1;

    return 0;
}

void push(char brac){

    top++;
    stack[top] = brac;
}

char pop(){
    char x = stack[top];
    top--;
    return x;
}

void check_expression(char infix[])
{
    for (int i = 0; i < strlen(infix); i++)
    {

        if (infix[i] == '[' || infix[i] == '{' || infix[i] == '(')
            push(infix[i]);

        if (infix[i] == ']' || infix[i] == '}' || infix[i] == ')')
        {

            if (isEmpty())
            {
                cout << "Right bracket are more than left bracket" << endl;
                return;
            }
            else
            {
                char temp = pop();

                if (!match(temp,infix[i])) 
                {
                    cout << "Mismatch bracket" << endl;
                    return;
                }
            }
        }
    }

    if (isEmpty())
        cout << "Bracket are balanced";
    else
        cout << "Left bracket are more than right bracket";
}

int main()
{

    char infix[N];

    cout << "Enter expression" << endl;
    gets(infix);

    check_expression(infix);
}