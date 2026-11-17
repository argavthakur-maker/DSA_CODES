#include <iostream>
using namespace std;

void merge(int arr[] , int low ,int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= high)
    { 
          if(arr[i] < arr[j])
          {
                temp[k] = arr[i];
                i++;
                k++;
          }
          else{
                temp[k] = arr[j];
                j++;
                k++;
          }
        //   k++;
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }


    while(j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;

    }

    for(int i = 0; i<k; i++)
    {
        arr[low + i] = temp[i];

    }
}
void Mergesort(int arr[] , int low , int high)
{

    if(low < high)
    {

        int mid = (low + high) / 2;
    
        Mergesort(arr , low , mid);
        Mergesort(arr , mid + 1, high);
        merge(arr , low , mid , high);
    }
}
int main()
{

    int num;
    cout << "Enter the size of array = ";
    cin >> num;


    int arr[num];

    cout << "Enter the array elements = \n";
    for(int i = 0; i<num; i++)
    {
        cin >> arr[i];
    }

    Mergesort(arr , 0 , num-1);

    cout << "Sorted array = " << endl;
    for(int i = 0; i<num; i++)
    {
        cout << arr[i] << ' ';
    }

    
}