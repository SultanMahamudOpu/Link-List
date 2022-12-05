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

// tree_node *search_BST(tree_node *root, int search_value)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }

//     if (root->data == search_value)
//     {
//         cout << root->data;
//         return root;
//     }
//     else if (search_value < root->data)
//     {
//         cout << root->data << "->";
//         search_BST(root->left_child, search_value);
//     }
//     else
//     {
//         cout << root->data << "->";
//         search_BST(root->right_child, search_value);
//     }
// }

tree_node *in_oder_succ(tree_node *root)
{
    tree_node *curr = root;
    while (curr->left_child != NULL)
    {
        curr = curr->left_child;
    }
    return curr;
}

tree_node *deletionBST(tree_node *root, int value)
{
    if (value < root->data)
    {
        root->left_child = deletionBST(root->left_child, value);
    }
    else if (value > root->data)
    {
        root->right_child = deletionBST(root->right_child, value);
    }

    else
    {
        // Implementation of 3 case
        if (root->left_child == NULL) // case 1||case 2
        {
            tree_node *temp = root->right_child;
            free(root);
            return temp;
        }
        else if (root->right_child == NULL) // case 2
        {
            tree_node *temp = root->left_child;
            free(root);
            return temp;
        }
        else
        {
            // case 3
            tree_node *temp = in_oder_succ(root->right_child);
            root->data = temp->data;
            root->right_child = deletionBST(root->right_child, temp->data);
        }
        return root;
    }
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

    // cout << endl;
    // cout << "Enter the search value: ";
    // int search_data;
    // cin >> search_data;
    // if (search_BST(root, search_data) == NULL)
    // {
    //     cout << endl
    //          << "Value not found!" << endl;
    // }
    // else
    // {
    //     cout << endl
    //          << "Value exit..." << endl;
    // }

    int key;
    cin >> key;
    root = deletionBST(root, key);
    string after = "";
    in_oder_traversal(root, after);
    cout << after << endl;

    cout << endl;
}

/*
9
11 5 9 43 34 1 2 7 21
*/