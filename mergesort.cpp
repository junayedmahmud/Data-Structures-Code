#include<iostream>

using namespace std;

void merge(long long int arr[],long long int left,long long int mid,long long int right)
{

    long long int left_size=mid-left+1;
    long long int right_size=right-mid;

    long long int L[left_size],R[right_size];

    for(long long int i=0;i<left_size;i++)
    {
        L[i]=arr[left+i];
    }
    for(long long int i=0;i<right_size;i++)
    {
        R[i]=arr[mid+1+i];
    }

    long long int left_array=0;
    long long int right_array=0;
    long long int index_a;

    for(index_a=left;left_array<left_size && right_array<right_size;index_a++)
    {
        if(L[left_array]<R[right_array])
        {
            arr[index_a]=L[left_array];
            left_array++;
        }
        else
        {
            arr[index_a]=R[right_array];
            right_array++;
        }
    }

    while(left_array<left_size)
    {
        arr[index_a]=L[left_array];
        index_a++;
        left_array++;
    }
    while(right_array<right_size)
    {
        arr[index_a]=R[right_array];
        index_a++;
        right_array++;
    }

}

void mergesort(long long int arr[],long long int left,long long int right)
{
    if(left>=right)
    {
        return;
    }

    long long int mid=left+(right-left)/2;

    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);

    merge(arr,left,mid,right);
}

int main()
{
    long long int n;

    cin>>n;

    long long int a[n],day[n],month[n],year[n];

    long long int position[100];

    for(long long int i=0;i<n;i++)
    {
        cin>>day[i]>>month[i]>>year[i];
        a[i]=365*year[i]+30*month[i]+day[i];
        position[a[i]]=i+1;
        cout<<a[i]<<endl;
    }

    mergesort(a,0,n-1);

    for(long long int i=0;i<n;i++)
    {
        long long int x,Date,Month,Year;

        x=a[i];
        Year=x/365;
        x=x%365;
        Month=x/30;
        Date=x%30;

        cout<<"Days: "<<Date<<" Months: "<<Month<<" Years: "<<Year<<" Position: "<<position[a[i]];
    }

    return 0;
}
