#include<iostream>

using namespace std;

void RecursiveInsertionSort(int arr[],int item)
{
    if(item<=1)
    {
        return;
    }

    cout<<item<<endl;

    RecursiveInsertionSort(arr,item-1);

    int items=arr[item-1];

    int i=item-2;

    while(i>=0 && arr[i]>items)
    {
        arr[i+1]=arr[i];

        i--;
    }

    arr[i+1]=items;
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

    RecursiveInsertionSort(num,items);

    cout<<"Sorted Array: \n";

    ShowArray(num,items);

    return 0;
}
