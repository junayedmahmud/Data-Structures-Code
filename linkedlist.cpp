#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

Node *create_node(Node *next,int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        exit(1);
    }

    new_node->data=item;
    new_node->next=next;

    return new_node;
}

void ShowLinkedList(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }

    cout<<endl;
}

Node *append(Node *head,int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        cout<<"Failed to create node"<<endl;
        exit(1);
    }

    new_node->data=item;
    new_node->next=NULL;

    Node *traverse=head;

    while(traverse->next!=NULL)
    {
        traverse=traverse->next;
    }

    traverse->next=new_node;

    return head;
}

Node *prepend(Node *head,int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        cout<<"Cant create a new node"<<endl;
        exit(1);
    }

    new_node->data=item;
    new_node->next=head;

    return new_node;
}

Node *Nth(Node *head,int position,int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    Node *traverse=head;

    if(new_node==NULL)
    {
        cout<<"Cant create node"<<endl;

        exit(1);
    }

    new_node->data=item;

    int count=0;

    if(head==NULL)
    {
        if(count==position)
        {
            new_node->next=NULL;

            return new_node;
        }
        else
        {
            exit(1);
        }
    }
    else if(count==position)
    {
        new_node->next=head;

        return new_node;
    }

    while(count!=position)
    {
        traverse=traverse->next;
        count=count+1;
    }

    new_node->next=traverse;

    traverse=new_node;


    return head;
}

int main()
{
    Node *head=create_node(NULL,10);

    ShowLinkedList(head);

    head=append(head,20);

    ShowLinkedList(head);

    head=prepend(head,5);

    ShowLinkedList(head);

    head=Nth(head,1,34);

    ShowLinkedList(head);

    return 0;
}
