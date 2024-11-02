#include <iostream>
using namespace std;

void countSort(int arr[], int n, int k)
{

    int count[k + 1] = {0};
    int b[n + 1];

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        b[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = b[i];
    }
}

int maximum_value(int arr[], int n)
{

    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 50;
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    int k = maximum_value(arr, n);
    countSort(arr, n, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}