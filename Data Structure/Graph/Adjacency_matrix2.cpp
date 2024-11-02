#include <iostream>
#define N 50
using namespace std;

char vertex[26];
int no_of_vertex;
int a[N][N];

void adjacency_matrix()
{
    for (int i = 0; i < 26; i++)
        vertex[i] = 65 + i;

    for (int i = 0; i < no_of_vertex; i++)
    {
        for (int j = 0; j < no_of_vertex; j++)
            a[i][j] = 0;
    }

    for (int i = 0; i < no_of_vertex; i++)
    {
        for (int j = i + 1; j < no_of_vertex; j++)
        {
            cout << vertex[i] << "-" << vertex[j] << ": ";

            cin >> a[i][j];

            a[j][i] = a[i][j];
        }
    }
}

void print()
{
    for (int i = 0; i < no_of_vertex; i++)
    {
        for (int j = 0; j < no_of_vertex; j++)
            cout << a[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    cout << "Enter the number of vertex: ";
    cin >> no_of_vertex;

    adjacency_matrix();
    print();
}