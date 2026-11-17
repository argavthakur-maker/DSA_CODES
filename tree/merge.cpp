#include <iostream>
using namespace std;

// Purpose: Merges two sorted halves of an array into one sorted section.
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        arr[low + i] = temp[i];
    }
}

// Purpose: Recursively splits the array into halves and sorts each half using merge sort.
void Mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        Mergesort(arr, low, mid);
        Mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Purpose: Reads an array, sorts it using merge sort, and prints the result.
int main()
{
    int num;
    cout << "Enter the size of array = ";
    cin >> num;

    int arr[num];

    cout << "Enter the array elements = \n";
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    Mergesort(arr, 0, num - 1);

    cout << "Sorted array = " << endl;
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}