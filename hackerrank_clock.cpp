#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {

    string new_string;
    int i;

    if(s[8]=='P' && s[9]=='M')
    {

        for(i=0;i<s.length()-2;i++)
        {
            if(i==0)
            {
               new_string[i]=s[i]+1;
            }
            else if(i==1)
            {
                new_string[i]=s[i]+2;
            }
            else
            {
                new_string[i]=s[i];
            }
        }

        new_string[i]='\0';

        return new_string;
    }
    else if(s[8]=='A' && s[9]=='M')
    {
        for(i=0;i<s.length()-2;i++)
        {
           new_string[i]=s[i];
        }

        new_string[i]='\0';

        return new_string;
    }
}

int main()
{
    string get;

    getline(cin,get);

    string result=timeConversion(get);

    for(int i=0;result[i]!='\0';i++)
    {
        cout<<result[i];
    }

    cout<<endl;

    return 0;
}
