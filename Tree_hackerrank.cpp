#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *left;
    Node *right;
};

void add_left_child(Node *parent,Node *child)
{
    parent->left=child;
}

void add_right_child(Node *parent,Node *child)
{
    parent->right=child;
}

Node * insert(Node * root, int data1) {

    Node *current_node,*check;

    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        cout<<"Cant create a new node"<<endl;
        exit(1);
    }

    new_node->data=data1;
    new_node->left=NULL;
    new_node->right=NULL;

    if(root==NULL)
    {
        cout<<"i am on here "<<endl;

        root=new_node;

        return root;
    }

    current_node=root;
    check=NULL;

    while(current_node!=NULL)
    {
        check=current_node;

        if(current_node->data>new_node->data)
        {
            current_node=current_node->left;
        }
        else
        {
            current_node=current_node->right;
        }
    }

    if(check->data>new_node->data)
    {
        add_left_child(check,new_node);
    }
    else
    {
        add_right_child(check,new_node);
    }

    return root;
}

void preOrder(Node *root)
{
    if( root == NULL )
    {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

int main() {

    Node* root = NULL;

    int t;
    int data;

    cin >> t;

    while(t-- > 0) {
        cin >> data;
        root = insert(root, data);
    }

    preOrder(root);

    return 0;
}

