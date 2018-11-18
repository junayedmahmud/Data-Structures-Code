//Binary search tree

#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

Node *create_node(int item)
{
    Node *new_node=new Node;

    if(new_node==NULL)
    {
        cout<<"Cant create Node";

        exit(1);
    }

    new_node->data=item;
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->parent=NULL;

    return new_node;
}

void add_left_child(Node *node,Node *child)
{
    node->left=child;

    if(child!=NULL)
    {
        child->parent=node;
    }
}

void add_right_child(Node *node,Node *child)
{
    node->right=child;

    if(child!=NULL)
    {
        child->parent=node;
    }
}

Node *create_BST(Node *root,Node *child)
{
    if(root==NULL)
    {
        root=child;

        return root;
    }

    Node *current_node=root;
    Node *parent_node=NULL;

    while(current_node!=NULL)
    {
        parent_node=current_node;

        if(child->data < current_node->data)
        {
            current_node=current_node->left;
        }
        else
        {
            current_node=current_node->right;
        }
    }

    if(parent_node->data > child->data)
    {
        add_left_child(parent_node,child);
    }
    else
    {
        add_right_child(parent_node,child);
    }

    return root;

}

void show_BST(Node *root)
{
    cout<<root->data<<" ";

    if(root->left!=NULL)
    {
        show_BST(root->left);
    }

    if(root->right!=NULL)
    {
        show_BST(root->right);
    }
}


int main()
{
    int count,search;

    Node *root;

    cout<<"How many numbers: ";
    cin>>count;

    int number;

    for(int i=0;i<count;i++)
    {
        cin>>number;

        if(i==0)
        {
            root=create_node(number);

            continue;
        }

        Node *insert_item=create_node(number);

        root=create_BST(root,insert_item);
    }

    return 0;
}
