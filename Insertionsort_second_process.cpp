#include<iostream>

using namespace std;

void InsertionSort(int arr[],int items)
{
    for(int i=1;i<items;i++)
    {
        int item=arr[i];

        int j=i-1;

        while(j>=0 && arr[j]>item)
        {
            swap(arr[j],arr[j+1]);

            j--;
        }
    }
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

    cout<<"Enter Items Quantity: ";

    cin>>items;

    int num[items];

    cout<<"Enter Items: \n";

    for(int i=0;i<items;i++)
    {
        cin>>num[i];
    }

    InsertionSort(num,items);

    cout<<"Sorted Array: \n";

    ShowArray(num,items);

    return 0;
}


