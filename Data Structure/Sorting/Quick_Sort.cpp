#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high)
{
    int start = low;
    int end = high;

    int pivot = arr[low];

    while (start < end)
    {
        while (arr[start] <= pivot)

            start++;

        while (arr[end] > pivot)

            end--;

        if (start < end)

            swap(arr, start, end);
    }
    swap(arr, low, end);
    return end;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int loc = partition(arr, low, high);
        quickSort(arr, low, loc);
        quickSort(arr, loc + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    cout << "Before sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    quickSort(arr, 0, n - 1);

    cout << "After sort:" << endl;
    for (int i = 0; i < n; i++)

        cout << arr[i] << " ";
}