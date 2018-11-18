#include<bits/stdc++.h>
#define Q_SIZE 5

using namespace std;

typedef struct
{
    int data[Q_SIZE+1];
    int head,tail;
}Queue;

void enqueue(Queue *q,int item)
{
    if((q->tail+1)%(Q_SIZE+1)==q->head)
    {
        cout<<"Queue is full"<<endl;
        return;
    }

    q->data[q->tail]=item;
    q->tail=(q->tail+1)%(Q_SIZE+1);
}

void dequeue(Queue *q)
{
    int item;

    if(q->tail==q->head)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    cout<<q->data[q->head]<<" ";

    q->head=(q->head+1)%(Q_SIZE+1);
}

int main()
{
    Queue my_q;
    int item;

    my_q.head=0;
    my_q.tail=0;

    enqueue(&my_q,1);
    enqueue(&my_q,2);
    enqueue(&my_q,3);
    enqueue(&my_q,4);
    enqueue(&my_q,5);

    dequeue(&my_q);
    dequeue(&my_q);
    dequeue(&my_q);
    dequeue(&my_q);
    dequeue(&my_q);

    return 0;
}
