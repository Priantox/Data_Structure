#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <sstream>
#define MAX 100
using namespace std;

string infix[MAX];
string infix2;
string stack[MAX];
string postfix[MAX];
int top = -1;
int count = 0;

bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void push(string symbol)
{
    top++;
    stack[top] = symbol;
}

string peek()
{
    if (top == -1)
        return nullptr;
    return stack[top];
}

string pop()
{
    if (top == -1)
    {
        return nullptr;
    }

    string symbol;
    symbol = stack[top];
    top--;

    return symbol;
}

int precedence(string symbol)
{
    if (symbol == "^")
        return 3;
    else if (symbol == "*" || symbol == "/")
        return 2;
    else if (symbol == "+" || symbol == "-")
        return 1;
    return 0;
}

bool isSymbol(string symbol)
{
    return symbol == "^" || symbol == "/" || symbol == "*" || symbol == "+" || symbol == "-";
}

void InToPost()
{
    int l = 0;
    string symbol;

    for (int i = 0; i < count; i++)
    {
        symbol = infix[i];

        if (symbol == "(")
            push(symbol);
        else if (symbol == ")")
        {
            while (peek() != "(")
            {
                postfix[l++] = pop();
            }
            pop();
        }
        else if (isSymbol(symbol))
        {
            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                postfix[l++] = pop();
            push(symbol);
        }
        else
            postfix[l++] = symbol;
    }

    while (!isEmpty())
    {
        postfix[l++] = pop();
    }
}

double post_eval()
{
    double a, b;

    for (int i = 0; i < MAX; i++)
    {
        if (postfix[i] == "")
            break;
        if (isSymbol(postfix[i]))
        {
            a = stod(pop());
            b = stod(pop());

            string symbol;
            symbol = postfix[i];
            string s;

            if (symbol == "+")
                s = to_string(b + a);
            else if (symbol == "-")
                s = to_string(b - a);
            else if (symbol == "*")
                s = to_string(b * a);
            else if (symbol == "/")
                s = to_string(b / a);
            else
                s = to_string(pow(b, a));

            push(s);
        }
        else
        {
            push(postfix[i]);
        }
    }
    return stod(pop());
}

void calculation()
{
    InToPost();

    double result = post_eval();
    cout << endl;

    cout << "The Result: " << result;
    cout << endl
         << endl;
}

void tokenize()
{
    istringstream ss(infix2);
    string token;

    while (getline(ss, token, ' ') && count < MAX)
    {
        infix[count++] = token;
    }
}

void print()
{
    cout << "The postfix expression is: ";
    for (int i = 0; i < MAX; i++)
    {
        if (postfix[i] == "")
            break;
        cout << postfix[i] << " ";
    }
}

int main()
{
    cout << "Enter your infix expression:" << endl;
    getline(cin, infix2);

    tokenize();
    InToPost();
    print();
    calculation();
    
    return 0;
}