#include<bits/stdc++.h>

using namespace std;

int sockMerchant(int n, vector<int> ar) {

    int pair=0;

    int *arr=ar.data();

    for(int i=0;i<ar.size()-1;i++)
    {
        for(int j=i+1;j<ar.size();j++)
        {
            if(arr[j]==0)
            {
                continue;
            }
            else if(arr[i]==arr[j])
            {
                cout<<i<<" "<<j<<endl;
                arr[j]=0;
                pair=pair+1;
                break;
            }
        }

        while(arr[i+1]==0)
        {
            i=i+1;
        }
    }

    return pair;
}

int main()
{
    int count,number;

    cin>>count;

    vector<int>p;

    for(int i=0;i<count;i++)
    {
        cin>>number;

        p.push_back(number);
    }

    int maximum=sockMerchant(count,p);

    cout<<maximum<<endl;
}
