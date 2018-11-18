// C++ program for implementation of Heap Sort
#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    do
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && arr[l] > arr[largest])
        {
            largest = l;
        }

        if (r < n && arr[r] > arr[largest])
         {
             largest = r;
         }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
        }

        i--;

    }while(-1<i);
}

void max_heap(int arr[],int heap_size)
{
    for(int i=(heap_size/2)-1;i>=0;i--)
    {
        heapify(arr,heap_size,i);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void heapsort(int arr[],int n)
{
    while(n!=0)
    {
        max_heap(arr,n);
        swap(arr[0],arr[n-1]);
        n=n-1;
    }
}

int main()
{
    int n;

    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    heapsort(arr,n);

    cout << "Sorted array is \n";

    printArray(arr, n);
}
