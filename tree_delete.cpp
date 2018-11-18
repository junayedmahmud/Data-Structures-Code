#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int key;
    Node *left,*right;
};

Node *create_node(int key)
{
    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        cout<<"Cant create node"<<endl;
        exit(1);
    }

    new_node->key=key;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void in_order(Node *head)
{
    if(head->left!=NULL)
    {
        in_order(head->left);
    }

    cout<<head->key<<" ";

    if(head->right!=NULL)
    {
        in_order(head->right);
    }
}

void delete_Deepest(Node *root,Node *node)
{
    queue<Node*>q;

    q.push(root);

    Node *temp;

    while(!q.empty())
    {
        temp=q.front();
        q.pop();

        if(temp->right)
        {
            if(temp->right==node)
            {
                temp->right=NULL;
                delete(node);
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }

        if(temp->left)
        {
            if(temp->left==node)
            {
                temp->left=NULL;
                delete(node);
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }

    }
}

void deletion(Node *root,int key)
{
    queue<Node*>q;
    q.push(root);

    Node *temp;
    Node *key_node=NULL;

    while(!q.empty())
    {
        temp=q.front();

        q.pop();

        if(temp->key==key)
        {
            key_node=temp;
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }

    int x=temp->key;

    delete_Deepest(root,temp);

    key_node->key=x;
}

int main()
{
    Node *root=create_node(10);
    root->left=create_node(11);
    root->left->left=create_node(7);
    root->left->right=create_node(12);
    root->right=create_node(9);
    root->right->left=create_node(15);
    root->right->right=create_node(8);

    cout<<"In order traversal : ";
    in_order(root);

    cout<<endl;

    int key=11;

    cout<<"In order traversal : ";
    deletion(root,key);

    in_order(root);

    cout<<endl;

    return 0;
}
