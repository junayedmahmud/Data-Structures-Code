#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *left,*right,*parent;
};

Node *create_node(int node_data)
{
    Node *New_Node=new Node;

    if(New_Node==NULL)
    {
        cout<<"Failed to create new Node";

        exit(1);
    }

    New_Node->left=NULL;
    New_Node->right=NULL;
    New_Node->parent=NULL;
    New_Node->data=node_data;

    return New_Node;
}

void add_left_child(Node *root,Node *child)
{
    root->left=child;

    if(child!=NULL)
    {
        child->parent=root;
    }
}

void add_right_child(Node *root,Node *child)
{
    root->right=child;

    if(child!=NULL)
    {
        child->parent=root;
    }
}

Node *Create_BST(Node *root,Node *new_node)
{
    if(root==NULL)
    {
        root=new_node;

        return root;
    }

    Node *current_node=root;
    Node *parent_node=NULL;

    while(current_node!=NULL)
    {
        parent_node=current_node;

        if(current_node->data>new_node->data)
        {
            current_node=current_node->left;
        }
        else
        {
            current_node=current_node->right;
        }
    }

    if(parent_node->data>new_node->data)
    {
        add_left_child(parent_node,new_node);
    }
    else
    {
        add_right_child(parent_node,new_node);
    }

    return root;
}

void InOrder(Node *root)
{
    if(root->left!=NULL)
    {
        InOrder(root->left);
    }

    cout<<root->data<<" ";

    if(root->right!=NULL)
    {
        InOrder(root->right);
    }
}

void PreOrder(Node *root)
{
    cout<<root->data<<" ";

    if(root->left!=NULL)
    {
        PreOrder(root->left);
    }

    if(root->right!=NULL)
    {
        PreOrder(root->right);
    }
}

void PostOrder(Node *root)
{
    if(root->left!=NULL)
    {
        PostOrder(root->left);
    }

    if(root->right!=NULL)
    {
        PostOrder(root->right);
    }

    cout<<root->data<<" ";
}

Node *search_node(Node *root,int item)
{
    Node *clone_root=root;

    while(clone_root!=NULL)
    {
        if(clone_root->data>item)
        {
            clone_root=clone_root->left;
        }
        else if(clone_root->data<item)
        {
            clone_root=clone_root->right;
        }
        else
        {
            return clone_root;
        }
    }

    return clone_root;
}

Node *Last_Left_Child(Node *root)
{
    Node *clone_root=root;

    while(clone_root->left!=NULL)
    {
        clone_root=clone_root->left;
    }

    return clone_root;
}

Node *BST_transplant(Node *root,Node *parent_node,Node *child_node)
{
    if(root==parent_node)
    {
        root=child_node;
    }
    else if(child_node==child_node->parent->left)
    {
        add_left_child(parent_node->parent,child_node);
    }
    else
    {
        add_right_child(parent_node->parent,child_node);
    }

    return root;
}

Node *Delete_Node(Node *root,Node *delete_item)
{
    Node *small_node;

    if(delete_item->left==NULL)
    {
        root=BST_transplant(root,delete_item,delete_item->right);
    }
    else if(delete_item->right==NULL)
    {
        root=BST_transplant(root,delete_item,delete_item->left);
    }
    else
    {
        small_node=Last_Left_Child(delete_item->right);

        if(small_node->parent!=delete_item)
        {
            root=BST_transplant(root,small_node,small_node->right);
            add_right_child(small_node,delete_item->right);
        }

        root=BST_transplant(root,delete_item,small_node);

        add_left_child(small_node,delete_item->left);

    }

    return root;
}

int main()
{
    Node *root=NULL;
    int numbers,input_numbers,search_number;

    cout<<"How many numbers: ";
    cin>>numbers;

    for(int i=0;i<numbers;i++)
    {
        cin>>input_numbers;

        Node *Create_Node=create_node(input_numbers);

        root=Create_BST(root,Create_Node);
    }

    cout<<"Inorder Traversal: "<<endl;

    InOrder(root);

    cout<<endl;

    cout<<"Prorder Traversal: "<<endl;

    PreOrder(root);

    cout<<endl;

    cout<<"Postorder Traversal: "<<endl;

    PostOrder(root);

    cout<<endl;

    cout<<"Which number do you want to Delete: ";
    cin>>search_number;

    Node *Search_Node=search_node(root,search_number);

    if(Search_Node==NULL)
    {
        cout<<"Did not found this item"<<endl;
    }
    else
    {
        root=Delete_Node(root,Search_Node);
    }

    cout<<"Inorder Traversal: "<<endl;

    InOrder(root);

    cout<<endl;

    cout<<"Prorder Traversal: "<<endl;

    PreOrder(root);

    cout<<endl;

    cout<<"Postorder Traversal: "<<endl;

    PostOrder(root);

    cout<<endl;

    return 0;
}
