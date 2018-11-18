#include<iostream>

using namespace std;

int partition(int A[],int low,int high,int count)
{
    int pivot,i,j;

    pivot=A[high];

    cout<<pivot<<endl;

    for(i=low-1,j=low;j<high;j++)
    {
        if(A[j]<pivot)
        {
            cout<<A[j]<<" "<<pivot<<endl;

            i=i+1;

            cout<<"i: "<<i<<endl;

            cout<<"1 Before Swapping: "<<A[j]<<" "<<A[i]<<endl;

            swap(A[j],A[i]);

            cout<<"1 After swapping: "<<A[j]<<" "<<A[i]<<endl;
        }
    }

    cout<<"2 Before Swapping: "<<A[high]<<" "<<A[i+1]<<endl;

    swap(A[high],A[i+1]);

    cout<<"2 After swapping: "<<A[high]<<" "<<A[i+1]<<endl;

    for(int k=0;k<count;k++)
    {
        cout<<A[k]<<" ";
    }

    cout<<endl;

    cout<<i+1<<endl<<endl;

    return i+1;
}

void quick_sort(int A[],int low,int high,int count)
{
    if(low>=high)
    {
        return;
    }

    int p;

    p=partition(A,low,high,count);

    cout<<"low: "<<low<<" "<<"p-1: "<<p-1<<endl;

    quick_sort(A,low,p-1,count);

    cout<<"p+1: "<<p+1<<" "<<"high: "<<high<<endl;

    quick_sort(A,p+1,high,count);
}

int main()
{
    int count;

    cin>>count;

    int num[count];

    for(int i=0;i<count;i++)
    {
        cin>>num[i];
    }

    quick_sort(num,0,count-1,count);

    for(int i=0;i<count;i++)
    {
        cout<<num[i]<<" ";
    }

    return 0;
}
