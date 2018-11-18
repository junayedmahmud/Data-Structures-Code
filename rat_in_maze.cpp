#include<iostream>
#define N 4

using namespace std;


bool isTrue(int arr[N][N],int x,int y)
{
    if(x>=0 && x<N && y>=0 & y<N && arr[x][y]==1)
    {
        return true;
    }

    return false;
}

void show_result(int rat[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<rat[i][j]<<" ";
        }

        cout<<endl;
    }
}

bool testing_rat(int rat[N][N],int x,int y,int bad_rat[N][N])
{
    if(x==N-1 && y==N-1)
    {
        bad_rat[x][y]=1;

        return true;
    }

    if(isTrue(rat,x,y)==true)
    {
        bad_rat[x][y]=1;

        if(testing_rat(rat,x+1,y,bad_rat)==true)
        {
            return true;
        }

        if(testing_rat(rat,x,y+1,bad_rat)==true)
        {
            return true;
        }

        bad_rat[x][y]=0;

        return false;
    }

    return false;
}

void rat_in_maze(int rat[N][N])
{
    int bad_rat[N][N];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            bad_rat[i][j]=0;
        }
    }

    if(testing_rat(rat,0,0,bad_rat)==true)
    {
        cout<<"Mouse path in maze: "<<endl;

        show_result(bad_rat);
    }
    else
    {
        cout<<"Not found"<<endl;
    }
}

int main()
{
    int rat[N][N];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>rat[i][j];
        }
    }

    rat_in_maze(rat);

    return 0;
}
