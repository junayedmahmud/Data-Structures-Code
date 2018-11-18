#include<bits/stdc++.h>

using namespace std;

int left(int item)
{
    return 2*item;
}
int right(int item)
{
    return 2*item+1;
}
int parent(int item)
{
    return item/2;
}

void max_heap(int H[],int heap_size,int index)
{
    int L=left(index);
    int R=right(index);
    int largest;

    if(L<=heap_size && H[L]>H[index])
    {
        largest=L;
    }
    else
    {
        largest=index;
    }

    if(R<=heap_size && H[R]>H[largest])
    {
        largest=R;
    }

    if(largest!=index)
    {
        swap(H[largest],H[index]);
    }
}

void build_max_heap(int H[],int heap_size)
{
    for(int i=heap_size/2;i>=1;i--)
    {
        max_heap(H,heap_size,i);
    }
}

void show_heap(int H[],int heap_size)
{
    for(int i=1;i<=heap_size;i++)
    {
        cout<<H[i]<<" ";
    }

    cout<<endl;
}

void extract_main(int H[],int heap_size)
{
    int max_item=H[1];

    H[1]=H[heap_size];

    heap_size=heap_size-1;

    max_heap(H,heap_size,1);
}

int insert_node(int H[],int heap_size,int item)
{
    int i,p;

    heap_size=heap_size+1;

    H[heap_size]=item;

    i=heap_size;

    while(i>1 && H[i]>H[parent(i)])
    {
        p=parent(i);

        swap(H[i],H[p]);

        i=p;
    }

    return heap_size;
}

int main()
{
    int items,new_item;

    cin>>items;

    int num[items+1];

    num[0]=0;

    for(int i=1;i<=items;i++)
    {
        cin>>num[i];
    }

    build_max_heap(num,items);

    extract_main(num,items);

    items=items-1;

    show_heap(num,items);

    cin>>new_item;

    int heap_size=insert_node(num,items,new_item);

    show_heap(num,heap_size);

    return 0;
}
