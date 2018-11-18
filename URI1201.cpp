#include<bits/stdc++.h>

using namespace std;

static long int x=0;

typedef struct node Node;

struct node
{
    long int data;
    Node *left,*right,*parent;
};

Node *create_node(long int item)
{
    Node *new_node=new Node;

    if(new_node==NULL)
    {
        exit(1);
    }

    new_node->data=item;
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->parent=NULL;

    return new_node;
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

void inorder(Node *root)
{
    if(root->left!=NULL)
    {
        inorder(root->left);
    }

    if(x>0)
    {
        cout<<" ";
    }

    x++;

    cout<<root->data;

    if(root->right!=NULL)
    {
        inorder(root->right);
    }
}

void preorder(Node *root)
{

    if(x>0)
    {
        cout<<" ";
    }

    x++;

    cout<<root->data;

    if(root->left!=NULL)
    {
        preorder(root->left);
    }

    if(root->right!=NULL)
    {
        preorder(root->right);
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

    if(x>0)
    {
        cout<<" ";
    }

    x++;

    cout<<root->data;
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

Node *node_searching(Node *root,long int item)
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

Node *BST_transplant(Node *root,Node *current_node,Node *new_node)
{
    if(current_node==root)
    {
        root=new_node;
    }
    else if(current_node==current_node->parent->left)
    {
        add_left_child(current_node->parent,new_node);
    }
    else
    {
        add_right_child(current_node->parent,new_node);
    }

    return root;
}

Node *delete_node(Node *root,Node *item)
{
    Node *small_node;

    if(item->left==NULL)
    {
        root=BST_transplant(root,item,item->right);
    }
    else if(item->right==NULL)
    {
        root=BST_transplant(root,item,item->left);
    }
    else
    {
        if (root-> left == NULL && root-> right == NULL)
        {
            delete root;
            return NULL;
        }

        if (root-> left != NULL && root-> right != NULL)
        {
            small_node=minimum(item->right);

            if(small_node->parent!=item)
            {
                root=BST_transplant(root,small_node,small_node->right);
                add_right_child(small_node,item->right);
            }

            root=BST_transplant(root,item,small_node);

            add_left_child(small_node,item->left);
        }
    }

    free(item);

    return root;
}

Node *Delete_Node(Node *root)
{
    long int number;

    cin>>number;

    if(root==NULL)
    {
        return root;
    }

    Node *search_node=node_searching(root,number);

    if(search_node!=NULL)
    {
        root=delete_node(root,search_node);
    }

    return root;
}

void searching(Node *root)
{
    long int search_number;

    cin>>search_number;

    Node *search_node=node_searching(root,search_number);

    if(search_node==NULL)
    {
        cout<<search_number<<" nao existe"<<endl;
    }
    else
    {
        cout<<search_number<<" existe"<<endl;
    }
}

Node *add_node(Node *root)
{

    Node *new_node;
    long int item;

    cin>>item;

        if(root==NULL)
        {
            root=create_node(item);

            return root;
        }

        new_node=create_node(item);

        root=create_BST(root,new_node);

    return root;
}

int main()
{
    string input;
    Node *root=NULL;

    while(cin>>input)
    {
        if(input.compare("I")==0)
        {
            root=add_node(root);
            continue;
        }
        else if(input.compare("PREFIXA")==0)
        {
            preorder(root);
            cout<<endl;
            x=0;
            continue;
        }
        else if(input.compare("INFIXA")==0)
        {
            inorder(root);
            cout<<endl;
            x=0;
            continue;
        }
        else if(input.compare("POSFIXA")==0)
        {
            postorder(root);
            cout<<endl;
            x=0;
            continue;
        }
        else if(input.compare("P")==0)
        {
            searching(root);
            continue;
        }
        else if(input.compare("R")==0)
        {
            root=Delete_Node(root);
            continue;
        }

        getchar();
    }

    return 0;
}
