#include <iostream>
using namespace std;
#define N 50

int visited_arr[N];
int visited_seq = -1;
int stack[N];
int top = -1;

int a[N][N];
int no_of_vertex;
int number;

bool isEmpty()
{
    if (top == -1)
        return true;

    return false;
}

void push(int ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    int c = stack[top];
    top--;
    return c;
}

void visit(char ch)
{
    visited_seq++;
    visited_arr[visited_seq] = ch;
}

bool is_visited(int ch)
{
    for (int i = 0; i <= visited_seq; i++)
    {
        if (visited_arr[i] == ch)
            return true;
    }
    return false;
}

void find_adjacency(int ch)
{
    for (int i = 0; i < no_of_vertex; i++)
    {
        if (ch == i)
        {
            for (int j = 0; j < no_of_vertex; j++)
            {

                if (a[i][j] == 1)
                {

                    if (is_visited(j) == false)
                        push(j);
                }
            }
        }
    }
}

void DFS()
{
    push(number);
    while (!isEmpty())
    {
        int ch = pop();
        find_adjacency(ch);

        if (!is_visited(ch))
            visit(ch);
    }
}

void create_graph()
{
    cout << "Enter  the number of vertices: ";
    cin >> no_of_vertex;

    cout << "Enter start state: ";
    cin >> number;

    for (int i = 0; i < no_of_vertex; i++)
    {
        for (int j = i + 1; j < no_of_vertex; j++)
        {
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < no_of_vertex; i++)
    {
        for (int j = i + 1; j < no_of_vertex; j++)
        {
            cout << i << "-" << j << ": ";
            cin >> a[i][j];

            if (a[i][j] == 1)
                a[j][i] = 1;
        }
    }

}

void print()
{
    for (int i = 0; i <= visited_seq; i++)
    {
        cout << visited_arr[i] << " ";
    }
}

int main()
{
    create_graph();
    DFS();
    print();
}