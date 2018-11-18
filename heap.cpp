#include<bits/stdc++.h>

using namespace std;

int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
int parent(int i)
{
    return i/2;
}

void max_heapify(int H[],int heap_size,int i)
{
    int l,r,largest,t;

    l=left(i);
    r=right(i);

    if(l<=heap_size && H[l]>H[i])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }

    if(r<=heap_size && H[r]>H[largest])
    {
        largest=r;
    }

    if(largest!=i)
    {
        swap(H[largest],H[i]);
    }
}

void print_heap(int H[],int heap_size)
{
    for(int i=1;i<heap_size;i++)
    {
        cout<<H[i]<<" ";
    }

    cout<<endl;
}

void build_max_heap(int H[],int heap_size)
{
    int i;

    for(i=heap_size/2;i>=1;i--)
    {
        max_heapify(H,heap_size,i);
    }
}

int main()
{
    int heap_size=9;
    int i,actual=9;

    int H[]={0,19,7,12,3,5,17,10,1,2};

    //print_heap(H,heap_size);

    build_max_heap(H,heap_size);

    //print_heap(H,heap_size);

    for(i=actual;i>1;i--)
    {
        swap(H[1],H[i]);

        actual=actual-1;

        build_max_heap(H,actual);
    }

    print_heap(H,heap_size);

    return 0;
}
