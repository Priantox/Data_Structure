#include <iostream>
using namespace std;
#define N 100

char visited_arr[N];
int visited_seq = -1;
int front = -1;
int rear = -1;
int queue[N];

char alphabate;
char vertex[N];
int a[N][N];
int no_of_vertex;

void enqueue(char ch)
{
    rear = (rear + 1) % N;
    queue[rear] = ch;
}

char dequeue()
{
    front = (front + 1) % N;
    return queue[front];
}

void visit(char ch)
{

    visited_seq++;
    visited_arr[visited_seq] = ch;
}

bool is_visit(char ch)
{

    for (int i = 0; i <= visited_seq; i++)
    {

        if (visited_arr[i] == ch)
            return true;
    }
    return false;
}

void find_adjacency(char ch)
{
    for (int i = 0; i < no_of_vertex; i++)
    {
        if (ch == vertex[i])
        {
            for (int j = 0; j < no_of_vertex; j++)
            {
                if (a[i][j] == 1)
                {
                    if (is_visit(vertex[j]) == false)
                        enqueue(vertex[j]);
                }
            }
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

void BFS()
{

    int x = alphabate;

    enqueue(vertex[x - 65]);
    while (front != rear)
    {
        char ch = dequeue();
        find_adjacency(ch);

        if (!is_visit(ch))
            visit(ch);
    }
}

void create_graph()
{

    for (int i = 0; i < 26; i++)
        vertex[i] = 65 + i;

    cout << "Enter  the number of vertices: ";
    cin >> no_of_vertex;

    cout << "Enter start state: ";
    cin >> alphabate;

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
            cout << vertex[i] << "-" << vertex[j] << ": ";
            cin >> a[i][j];

            if (a[i][j] == 1)
                a[j][i] = 1;
        }
    }
}

int main()
{

    create_graph();
    BFS();
    print();
}