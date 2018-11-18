#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *left,*right,*parent;
};

Node *create_node(Node *root,int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));

    if(new_node==NULL)
    {
        cout<<"Cant create node"<<endl;
        exit(1);
    }

    new_node->data=item;
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->parent=NULL;

    if(root==NULL)
    {
        root=new_node;

        return root;
    }

    Node *traversal=root;
    Node *next=NULL;

    while(traversal!=NULL)
    {
        next=traversal;

        if(traversal->data>new_node->data)
        {
            traversal=traversal->left;
        }
        else
        {
            traversal=traversal->right;
        }
    }

    if(next->data>new_node->data)
    {
        next->left=new_node;
        new_node->parent=next;
    }
    else
    {
        next->right=new_node;
        new_node->parent=next;
    }

    return root;
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

Node *Search(Node *head,int item)
{
    Node *search_items=head;

    while(search_items!=NULL)
    {
        if(search_items->data==item)
        {
            return search_items;
        }
        if(search_items->data>item)
        {
            search_items=search_items->left;
        }
        else
        {
            search_items=search_items->right;
        }
    }

    return search_items;
}

Node *in_order(Node *head)
{
    if(head->left!=NULL)
    {
        in_order(head->left);
    }

    cout<<head->data<<" ";

    if(head->right!=NULL)
    {
        in_order(head->right);
    }
}

Node *bst_minimum(Node *root)
{
    Node *node=root;

    while(node->left!=NULL)
    {
        node=node->left;
    }

    return node;
}

Node *bst_transplant(Node *root,Node *current_node,Node *new_node)
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

Node *bst_delete(Node *head,Node *target)
{
    Node *smallest_node;

    if(target->left==NULL)
    {
        head=bst_transplant(head,target,target->right);
    }
    else if(target->right==NULL)
    {
        head=bst_transplant(head,target,target->left);
    }
    else
    {
        smallest_node=bst_minimum(target->right);

        if(smallest_node->parent!=target)
        {
            head=bst_transplant(head,smallest_node,smallest_node->right);

            add_right_child(smallest_node,target->right);
        }

        head=bst_transplant(head,target,smallest_node);

        add_left_child(smallest_node,target->left);
    }

    free(target);

    return head;
}

int main()
{
    Node *head=NULL;

    int count1,search,number;

    cout<<"How many numbers: ";
    cin>>count1;

    for(int i=0;i<count1;i++)
    {
        cin>>number;

        head=create_node(head,number);
    }

    cout<<"Which number do you want to delete: ";
    cin>>search;

    Node *find=Search(head,search);

    if(find!=NULL)
    {
        cout<<"Will delete "<<find->data<<endl;

        head=bst_delete(head,find);

        cout<<"BST: ";

        in_order(head);

        cout<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }

    return 0;
}
