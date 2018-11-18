#include<iostream>

using namespace std;

int main()
{
    int T;

    cin>>T;

    for(int i=0;i<T;i++)
    {
        int Argentina,Brazil;

        cin>>Argentina>>Brazil;

        if(Argentina>Brazil)
        {
            cout<<"Argentina "<<Argentina<<" - "<<Brazil<<" Brazil"<<endl;
        }
        else
        {
            cout<<"Brazil "<<Brazil<<" - "<<Argentina<<" Argentina"<<endl;
        }
    }

    return 0;
}
