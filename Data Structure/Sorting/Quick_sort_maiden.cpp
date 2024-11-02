#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high)
{

    int start = low - 1;
    int end = high + 1;
    int mid = (low + high) / 2;

    int pivot = arr[mid];

    while (1)
    {

        do
        {
            start++;
        } while (arr[start] < pivot);

        do
        {
            end--;
        } while (arr[end] > pivot);

        if (end <= start)
            return end;

        swap(arr, start, end);
    }
}

void quicksort(int arr[], int low, int high)
{

    if (low < high)
    {

        int loc = partition(arr, low, high);
        quicksort(arr, low, loc);
        quicksort(arr, loc + 1, high);
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

    quicksort(arr, 0, n - 1);

    cout << "After sort:" << endl;
    for (int i = 0; i < n; i++)

        cout << arr[i] << " ";
}