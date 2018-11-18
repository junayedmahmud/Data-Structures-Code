#include<iostream>
#include<vector>

using namespace std;

void bubblesort(vector<int>a)
{
    int count=0;

    int *arr=a.data();

    cout<<a.size()<<endl;

    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size()-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                count++;
            }
        }
    }

    int first_number=arr[0];
    int last_number=arr[a.size()-1];

    cout<<count<<" "<<first_number<<" "<<last_number<<endl;

}

int main()
{
    int n,number;

    cout<<"How many numbers: ";
    cin>>n;

    vector<int>a;

    for(int i=0;i<n;i++)
    {
        cin>>number;
        a.push_back(number);
    }

    bubblesort(a);

    return 0;
}
