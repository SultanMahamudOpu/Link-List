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
void in_oder(tree_node *root,string &chk);
void pre_oder(tree_node *root,string &chk);
void post_oder(tree_node *root,string &chk);

void print_tree(tree_node *root, int level)
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

void print_space(int level)
{
    for(int i=0;i<level;i++)
    {
        cout<<"   ";
    }
}

void in_oder(tree_node *root,string &chk)
{
    if(root==NULL)
    {
        return;
    }
    in_oder(root->left_child,chk);
    chk+=to_string(root->data);
    in_oder(root->right_child,chk);
}

void pre_oder(tree_node *root,string &chk)
{
    if(root==NULL)
    {
        return;
    }
    chk+=to_string(root->data);
    pre_oder(root->left_child,chk);
    in_oder(root->right_child,chk);
}

void post_oder(tree_node *root,string &chk)
{
    if(root==NULL)
    {
        return;
    }
    post_oder(root->left_child,chk);
    post_oder(root->right_child,chk);
    chk+=to_string(root->data);
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
    print_tree(all_node[0], 0);

    string in_oder_traversal=" ";
    string pre_oder_traversal=" ";
    string post_oder_traversal=" ";
    string lever_oder_traversal_value=" ";

    in_oder(all_node[0],in_oder_traversal);
    pre_oder(all_node[0],pre_oder_traversal);
    post_oder(all_node[0],post_oder_traversal);

    cout<<"in_oder_traversal: "<<in_oder_traversal<<endl;
    cout<<"pre_oder_traversal: "<<pre_oder_traversal<<endl;
    cout<<"post_oder_traversal: "<<post_oder_traversal<<endl;

    cout<<endl<<endl<<endl;
}