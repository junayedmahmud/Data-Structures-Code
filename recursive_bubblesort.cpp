#include<iostream>

using namespace std;

void RecursiveBubbleSort(int arr[],int items)
{
    if(items==1)
    {
        return;
    }

    for(int i=0;i<items-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }

    RecursiveBubbleSort(arr,items-1);
}

void ShowArray(int arr[],int items)
{
    for(int i=0;i<items;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int main()
{
    int items;

    cout<<"Enter number of items: ";

    cin>>items;

    int arr[items];

    cout<<"Enter numbers: \n";

    for(int i=0;i<items;i++)
    {
        cin>>arr[i];
    }

    RecursiveBubbleSort(arr,items);

    cout<<"After Sorting: \n";

    ShowArray(arr,items);

    return 0;
}

