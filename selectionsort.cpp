#include<iostream>

using namespace std;

void SelectionSort(int arr[],int items)
{
    for(int i=0;i<items-1;i++)
    {
        int index=i;

        for(int j=i+1;j<items;j++)
        {
            if(arr[index]>arr[j])
            {
                index=j;
            }
        }

        if(index!=i)
        {
            swap(arr[index],arr[i]);
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

    cout<<"Enter number of items: ";

    cin>>items;

    int arr[items];

    cout<<"Enter numbers: \n";

    for(int i=0;i<items;i++)
    {
        cin>>arr[i];
    }

    SelectionSort(arr,items);

    cout<<"After Sorting: \n";

    ShowArray(arr,items);

    return 0;
}
