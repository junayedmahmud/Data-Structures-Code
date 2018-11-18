#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *next;
    Node *prev;
};

Node *create_node(Node *next,Node *prev,int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        cout<<"cant create a new node"<<endl;
        exit(1);
    }

    new_node->data=item;
    new_node->next=next;
    new_node->prev=prev;

    return new_node;
}

Node *prepend(Node *head,int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        cout<<"Cant create a new node"<<endl;
        exit(1);
    }

    new_node->prev=NULL;
    new_node->data=item;
    new_node->next=head;
    new_node->next->prev=new_node;

    return new_node;
}

Node *append(Node *head,int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        cout<<"Cant create node"<<endl;
        exit(1);
    }

    new_node->data=item;
    new_node->next=NULL;
    new_node->prev=NULL;

    if(head==NULL)
    {
        return new_node;
    }

    Node *traverse=head;

    while(traverse->next!=NULL)
    {
        traverse=traverse->next;
    }

    traverse->next=new_node;
    new_node->prev=traverse;

    return head;
}

Node *DeleteLinkedList(Node *head,Node *node)
{
    if(head=node)
    {
        head=node->next;
        node->prev=NULL;

        free(node);

        return head;
    }

    Node *node_prev=node->prev;
    Node *node_next=node->next;

    node_prev->next=node_next;
    node_next->prev=node_prev;

    free(node);

    return head;
}

void ShowLinkedList(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }

    cout<<endl;
}

int main()
{
    Node *head=create_node(NULL,NULL,20);

    ShowLinkedList(head);

    Node *prepend_func=prepend(head,10);
    head=prepend_func;

    ShowLinkedList(prepend_func);

    Node *append_func=append(prepend_func,5);
    head=append_func;

    ShowLinkedList(append_func);

    Node *delete_=DeleteLinkedList(head,append_func);

    ShowLinkedList(delete_);

    return 0;
}
