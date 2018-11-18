#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

Node *create_node(Node *head,int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        cout<<"Cant create a new node"<<endl;
        exit(1);
    }

    new_node->data=item;
    new_node->next=NULL;

    if(head==NULL)
    {
        head=new_node;

        return head;
    }

    Node *traverse=head;

    while(traverse->next!=NULL)
    {
        traverse=traverse->next;
    }

    traverse->next=new_node;

    return head;
}

Node *delete_nth_node(Node *head,int index);
{
    Node *new_node=*head,*prev;

    if(head!=NULL)
    {

    }
}

void show_node(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";

        head=head->next;
    }

    cout<<endl;
}

int main()
{
    Node *head=NULL;

    int number,num,index;

    cin>>number;

    for(int i=0;i<number;i++)
    {
        cin>>num;
        head=create_node(head,num);
    }

    cout<<"Show linked list: \n";
    show_node(head);

    cout<<"Which index do you want to delete: ";
    cin>>index;

    head=delete_nth_node(head,index);

    cout<<"After deleting node: ";
    show_node(head);

    return 0;
}
