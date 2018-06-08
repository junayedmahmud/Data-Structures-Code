#include<iostream>

using namespace std;

int main()
{
    int number;

    cout<<"Enter numbers: ";
    cin>>number;

    int num[number];

    cout<<"Enter numbers: \n";

    for(int i=0;i<number;i++)
    {
        cin>>num[i];
    }

    for(int i=1;i<number;i++)
    {
        int item=num[i];

        int j=i-1;

        while(j>=0 && num[j]>item)
        {
            num[j+1]=num[j];
            j--;
        }

        num[j+1]=item;
    }

    for(int i=0;i<number;i++)
    {
        cout<<num[i]<<" ";
    }

    return 0;
}
