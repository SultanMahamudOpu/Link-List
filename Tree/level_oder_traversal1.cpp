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
void space_print(int level);
void level_oder_traversal(tree_node *root, string &check);

void print_tree(tree_node *root, int level)
{
    if (root == NULL) // case 0 when tree are empty
    {
        return;
    }

    if (root->left_child == NULL && root->right_child == NULL) // case 1 when tree only have root value
    {
        cout << root->data << endl;
        return;
    }

    else // case 2 when tree have all value
    /*
    st1:print a new line
    st2:print space
    st3:print root
    */
    {
        cout << endl;
        space_print(level);
        cout << "Root: " << root->data << endl;
    }

    if (root->left_child != NULL)
    {
        space_print(level);
        cout << "Left: ";
        print_tree(root->left_child, level + 1);
    }
    if (root->right_child != NULL)
    {
        space_print(level);
        cout << "Right: ";
        print_tree(root->right_child, level + 1);
    }
}

void space_print(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "   ";
    }
}

void level_oder_traversal(tree_node *root, string &check)
{
    if (root == NULL)
    {
        return;
    }

    queue<tree_node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        tree_node *check_node = q.front();
        q.pop();

        if (check_node != NULL)
        {
            cout << check_node->data << " ";
            check += to_string(check_node->data);
            if (check_node->left_child != NULL)
            {
                q.push(check_node->left_child);
            }
            if (check_node->right_child != NULL)
            {
                q.push(check_node->right_child);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    tree_node *all_node[n]; // pointer type value

    for (int i = 0; i < n; i++)
    {
        all_node[i] = new tree_node(-1); // all value inisilizion to -1
    }

    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;

        all_node[i]->data = value; // insert root value

        if (left != -1)
        {
            all_node[i]->left_child = all_node[left]; // insert left child value
        }
        if (right != -1)
        {
            all_node[i]->right_child = all_node[right]; // insert right child value
        }
    }

    print_tree(all_node[0], 0); //[0]mean's root value,0 mean's level value

    string level_oder_traversal_value = "";

    level_oder_traversal(all_node[0], level_oder_traversal_value);
}