#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{

    if (arr[mid] < arr[mid + 1])
        return;

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left_array[n1];
    int right_array[n2];

    for (int i = 0; i < n1; i++)
    {
        left_array[i] = arr[low + i];
    }

    for (int i = 0; i < n2; i++)
    {
        right_array[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        if (left_array[i] < right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    cout << "Original Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl
         << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After array:" << endl for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}