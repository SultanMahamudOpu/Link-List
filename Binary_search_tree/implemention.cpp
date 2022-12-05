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

void in_oder_traversal(tree_node *root, string &check) // '&' mean's we take this string's address not value
{
    /*
    left child
    root
    right child
    */
    if (root == NULL) // case 0
    {
        return;
    }

    in_oder_traversal(root->left_child, check);  // left child
    check += to_string(root->data) + " ";        // root
    in_oder_traversal(root->right_child, check); // right child
}

tree_node *insertion_at_BST(tree_node *root, int value) // node type use korla pointer use kora laga.
{
    tree_node *new_node = new tree_node(value);
    if (root == NULL)
    {
        root = new_node;
        return root;
    }

    // value < root->data
    if (value < root->data)
    {
        root->left_child = insertion_at_BST(root->left_child, value);
    }
    // value > root->data
    else if (value > root->data)
    {
        root->right_child = insertion_at_BST(root->right_child, value);
    }

    return root;
}

int main()
{
    int n;
    cin >> n;

    tree_node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = insertion_at_BST(root, value);
    }

    string traversal = "";
    in_oder_traversal(root, traversal);

    cout << traversal;
}