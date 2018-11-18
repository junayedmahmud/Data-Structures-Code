#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *left;
    Node *right;
};

Node *create_node(Node *head,int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        cout<<"Failed to create Node"<<endl;
        exit(1);
    }

    new_node->data=item;
    new_node->left=NULL;
    new_node->right=NULL;

    if(head==NULL)
    {
        head=new_node;

        return head;
    }

    Node *traversal=head;
    Node *current_node=NULL;

    while(traversal!=NULL)
    {
        current_node=traversal;

        if(traversal->data>new_node->data)
        {
            traversal=traversal->left;
        }
        else
        {
            traversal=traversal->right;
        }
    }

    if(current_node->data>new_node->data)
    {
        current_node->left=new_node;
    }
    else
    {
        current_node->right=new_node;
    }

    return head;
}

Node *search_item(Node *head,int data1)
{
    Node *new_node=head;

    while(new_node!=NULL)
    {
        if(new_node->data==data1)
        {
            return new_node;
        }
        if(new_node->data>data1)
        {
            new_node=new_node->left;
        }
        else
        {
            new_node=new_node->right;
        }
    }

    return new_node;
}

int main()
{
    Node *head=NULL;

    int item,number,search;

    cout<<"How many items: ";
    cin>>item;

    cout<<"Enter numbers: "<<endl;

    for(int i=0;i<item;i++)
    {
        cin>>number;

        head=create_node(head,number);
    }

    cout<<"Which number do you want to search: ";
    cin>>search;

    Node *Find_Item=search_item(head,search);

    if(Find_Item!=NULL)
    {
        cout<<"Number found"<<endl;
    }
    else
    {
        cout<<"Number not found"<<endl;
    }

    return 0;
}
