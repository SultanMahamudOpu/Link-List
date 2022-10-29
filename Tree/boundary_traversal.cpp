#include <bits/stdc++.h>
using namespace std;

class tree_node
{
public:
    int data;
    tree_node *left_child;
    tree_node *right_child;

    tree_node(int val)
    {
        data = val;
        left_child = NULL;
        right_child = NULL;
    }
};

void print_tree(tree_node *root, int level);
void print_space(int level);
void print_leaves(tree_node *root);
void print_left_non_leaves(tree_node *root);
void print_right_non_leaves(tree_node *root);
void boundary_traversal(tree_node *root);

void print_tree(tree_node *root, int level)//print main tree
{
    if(root==NULL)
    {
        return;
    }
    if(root->left_child==NULL&&root->right_child==NULL)
    {
        cout<<root->data<<endl;
        return;
    }
    else
    {
        cout<<endl;
        print_space(level);
        cout<<"Root: "<<root->data<<endl;
    }

    if(root->left_child!=NULL)
    {
        print_space(level);
        cout<<"Left: ";
        print_tree(root->left_child,level+1);
    }
    if(root->right_child!=NULL)
    {
        print_space(level);
        cout<<"Right: ";
        print_tree(root->right_child,level+1);
    }

}

void print_space(int level)//print space
{
    for(int i=0;i<level;i++)
    {
        cout<<"   ";
    }
}


void print_leaves(tree_node *root)//print leaves..you can print only leaves by this
{
    if(root==NULL)
    {
        return;
    }
    if(root->left_child==NULL&&root->right_child==NULL)
    {
        cout<<root->data<<" ";
        return;
    }
    print_leaves(root->left_child);
    print_leaves(root->right_child);
}

void print_left_non_leaves(tree_node *root)//print left side..you can print only left side of tree by this
{
    if(root==NULL)
    {
        return;
    }
    if(root->left_child!=NULL)
    {
        cout<<root->data<<" ";
        print_left_non_leaves(root->left_child);
    }
    else if(root->right_child!=NULL)
    {
        cout<<root->data<<" ";
        print_right_non_leaves(root->right_child);
    }
}

void print_right_non_leaves(tree_node *root)//print right side..you can print only right side of tree by this
{ 
    if(root==NULL)
    {
        return;
    }
    if(root->right_child!=NULL)
    {
        cout<<root->data<<" ";
        print_right_non_leaves(root->right_child);
    }
    else if(root->left_child!=NULL)
    {
        cout<<root->data<<" ";
        print_right_non_leaves(root->left_child);
    }
}

void boundary_traversal(tree_node *root)//print whole boundary value
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";

    //LB Non-Leaves
    print_left_non_leaves(root->left_child);
    //LB Leaves
    print_leaves(root->left_child);
    //RB Leaves
    print_leaves(root->right_child);
    //RB Leaves
    print_right_non_leaves(root->right_child);
}

int main()
{
    int n;
    cin >> n;
    tree_node *all_node[n];

    for (int i = 0; i < n; i++)
    {
        all_node[i] = new tree_node(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;
        all_node[i]->data = value;

        if (left != -1)
        {
            all_node[i]->left_child = all_node[left];
        }
        if (right != -1)
        {
            all_node[i]->right_child = all_node[right];
        }
    }
   
    boundary_traversal(all_node[0]);

    cout<<endl<<endl<<endl;
}
