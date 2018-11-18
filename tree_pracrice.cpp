#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *left,*right;
};

Node *create_node(Node *head,int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        cout<<"Failed to create node"<<endl;
        exit(1);
    }

    new_node->left=NULL;
    new_node->right=NULL;
    new_node->data=item;

    if(head==NULL)
    {
        head=new_node;
        return head;
    }

    Node *traverse=head;
    Node *create=NULL;

    while(traverse!=NULL)
    {
        create=traverse;

        if(traverse->data>new_node->data)
        {
            traverse=traverse->left;
        }
        else
        {
            traverse=traverse->right;
        }
    }

    if(create->data>new_node->data)
    {
        create->left=new_node;
    }
    else
    {
        create->right=new_node;
    }

    return head;
}

Node *search_item(Node *head,int item)
{
    Node *search_num=head;

    while(search_num!=NULL)
    {
        if(search_num->data==item)
        {
            return search_num;
        }
        if(search_num->data>item)
        {
            search_num=search_num->left;
        }
        else
        {
            search_num=search_num->right;
        }
    }

    return search_num;
}

int main()
{
    Node *head=NULL,*Search;

    int items,number,search;

    cout<<"How many items you want for input: ";
    cin>>items;

    for(int i=0;i<items;i++)
    {
        cin>>number;

        head=create_node(head,number);
    }

    cout<<"Which number do you want to search: ";
    cin>>search;

    Search=search_item(head,search);

    if(Search!=NULL)
    {
        cout<<"Number Found"<<endl;
    }
    else
    {
        cout<<"Number not found"<<endl;
    }

    return 0;
}
