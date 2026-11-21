#include <iostream>
using namespace std;

int partition(int arr[] , int low , int high)
{
    int piviot = arr[high];
    int st = low - 1;

    for(int j = low; j<high; j++)
    {
        if(arr[j] <= piviot)
        {
            st++;
            swap(arr[st] , arr[j]);

        }
    }
    st++;
    swap(arr[high] , arr[st]);

    return st;
}
void quick_sort(int arr[] , int low , int high)
{
    if(low < high)
    {
        int pivot = partition(arr , low , high);


        quick_sort(arr , low , pivot-1);
        quick_sort(arr , pivot + 1 , high);

    }
}
int main()
{
    
    int arr[5] = {23,2,4,56,77};
    
    quick_sort(arr , 0 , 4);
    
    for(int i = 0; i<5; i++)
    {
        cout << arr[i] << ' ';
    }
}