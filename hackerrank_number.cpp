#include<bits/stdc++.h>

using namespace std;

int migratoryBirds(vector<int>arr) {

    int *ar=arr.data();

    int one[2],count_one=0;
    one[0]=0;
    one[1]=1;

    int two[2],count_two=0;
    two[0]=0;
    two[1]=2;

    int three[2],count_three=0;
    three[0]=0;
    three[1]=3;

    int four[2],count_four=0;
    four[0]=0;
    four[1]=4;

    int five[2],count_five=0;
    five[0]=0;
    five[1]=5;

    for(int i=0;i<arr.size();i++)
    {
        if(ar[i]==1)
        {
            count_one=count_one+1;
            one[0]=count_one;

            continue;
        }
        if(ar[i]==2)
        {
            count_two=count_two+1;
            two[0]=count_two;
            continue;
        }
        if(ar[i]==3)
        {
            count_three=count_three+1;
            three[0]=count_three;
            continue;
        }
        if(ar[i]==4)
        {
            count_four=count_four+1;
            four[0]=count_four;
            continue;
        }
        if(ar[i]==5)
        {
            count_five=count_five+1;
            five[0]=count_five;
            continue;
        }
    }

    if(one[0]>two[0] && one[0]>three[0] && one[0]>four[0] && one[0]>five[0])
    {
        int item=one[1];

        cout<<item;
    }

    else if(two[0]>one[0] && two[0]>three[0] && two[0]>four[0] && two[0]>five[0])
    {
        return two[1];
    }

    else if(three[0]>two[0] && three[0]>one[0] && three[0]>four[0] && three[0]>five[0])
    {
        return three[1];
    }

    else if(four[0]>two[0] && four[0]>three[0] && four[0]>one[0] && four[0]>five[0])
    {
        return four[1];
    }

    else if(five[0]>two[0] && five[0]>three[0] && five[0]>four[0] && five[0]>one[0])
    {
        return five[1];
    }
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

    int num=migratoryBirds(p);

    cout<<num<<endl;

    return 0;
}
