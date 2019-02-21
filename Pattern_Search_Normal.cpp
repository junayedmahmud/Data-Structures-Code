#include<bits/stdc++.h>

using namespace std;

bool native_matching(string text,string pattern)
{
    for(int i=0;i<text.size();i++)
    {
        int j=0;

        for(j=0;j<pattern.size() && i+j<text.size();j++)
        {
            if(text[i+j]!=pattern[j])
            {
                cout<<text[i+j]<<" "<<pattern[j]<<endl;
                break;
            }
            else
            {
                cout<<text[i+j]<<" "<<pattern[j]<<endl;
            }
        }

        cout<<endl;

        if(j==pattern.size())
        {
            return true;
        }
    }

    return false;
}

int main()
{
    bool t=native_matching("abababacd","ababac");

    if(t==true)
    {
        cout<<"That is Matched"<<endl;
    }
    else
    {
        cout<<"That is not Matched"<<endl;
    }

    return 0;
}
