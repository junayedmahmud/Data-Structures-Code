#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *left,*right,*parent;
};

Node *create_node(int child_data)
{
    Node *create_node=new Node;

    if(create_node==NULL)
    {
        cout<<"Failed to create Node"<<endl;
        exit(1);
    }

    create_node->data=child_data;
    create_node->left=NULL;
    create_node->right=NULL;
    create_node->parent=NULL;

    return create_node;
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

        if(current_node->data>child->data)
        {
            current_node=current_node->left;
        }
        else
        {
            current_node=current_node->right;
        }
    }

    if(parent_node->data>child->data)
    {
        add_left_child(parent_node,child);
    }
    else
    {
        add_right_child(parent_node,child);
    }

    return root;
}

void preorder(Node *root)
{
    cout<<root->data<<" ";

    if(root->left!=NULL)
    {
        preorder(root->left);
    }

    if(root->right!=NULL)
    {
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if(root->left!=NULL)
    {
        inorder(root->left);
    }

    cout<<root->data<<" ";

    if(root->right!=NULL)
    {
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if(root->left!=NULL)
    {
        postorder(root->left);
    }

    if(root->right!=NULL)
    {
        postorder(root->right);
    }

    cout<<root->data<<" ";
}

Node *searching(Node *root,int item)
{
    while(root!=NULL)
    {
        if(root->data>item)
        {
            root=root->left;
        }
        else if(root->data<item)
        {
            root=root->right;
        }
        else
        {
            return root;
        }
    }

    return root;
}

Node *minimum(Node *root)
{
    Node *node=root;

    while(node->left!=NULL)
    {
        node=node->left;
    }

    return node;

}

Node *BST_transplant(Node *root,Node *current_node,Node *new_node)
{
    if(current_node==root)
    {
        root=new_node;
    }
    else if(current_node==current_node->parent->right)
    {
        add_right_child(current_node->parent,new_node);
    }
    else
    {
        add_left_child(current_node->parent,new_node);
    }

    return root;
}

Node *bst_delete(Node *root,Node *target)
{
    Node *smallest_node;

    if(target->left==NULL)
    {
        root=BST_transplant(root,target,target->right);
    }
    else if(target->right==NULL)
    {
        root=BST_transplant(root,target,target->left);
    }
    else
    {
        smallest_node=minimum(target->right);

        if(smallest_node->parent!=target)
        {
            root=BST_transplant(root,smallest_node,smallest_node->right);

            add_right_child(smallest_node,target->right);
        }

        root=BST_transplant(root,target,smallest_node);

        add_left_child(smallest_node,target->left);
    }

    free(target);

    return root;
}

int main()
{
    int number,num,searching_number,delete_node;

    Node *root,*new_node,*del;

    cin>>number;

    for(int i=0;i<number;i++)
    {
        cin>>num;

        if(i==0)
        {
            root=create_node(num);

            continue;
        }
        new_node=create_node(num);

        root=create_BST(root,new_node);
    }

    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;

    cout<<"Which number:";
    cin>>searching_number;

    Node *search=searching(root,searching_number);

    if(search==NULL)
    {
        cout<<"Not Found"<<endl;
    }
    else
    {
        cout<<"Found"<<endl;
    }

    cout<<search->data;

    cout<<"Do you want to delete any node: ";
    cin>>delete_node;

    del=searching(root,delete_node);

    if(del!=NULL)
    {
        cout<<"We will delete this node: "<<del->data<<endl;
        root=bst_delete(root,del);

        inorder(root);

        cout<<endl;
    }
    else
    {
        cout<<"Node not found"<<endl;
    }

    return 0;
}
