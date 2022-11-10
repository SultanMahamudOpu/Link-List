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
void kth_level_max_value(tree_node *root, string &check);

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

int kth_level_max_value(tree_node *root, string &check, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    int level = 0;
    queue<tree_node *> q;
    q.push(root);
    q.push(NULL);
    int max = INT_MIN;

    while (!q.empty())
    {
        tree_node *check_node = q.front();
        q.pop();

        if (check_node != NULL)
        {
            if (check_node != NULL)
            {
                if (level == k)
                {
                    if (max < check_node->data)
                    {
                        max = check_node->data;
                    }
                }
            }
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
                level++;
            }
        }
    }
    return max;
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

    int max_value_at_k = kth_level_max_value(all_node[0], level_oder_traversal_value, 2);

    cout << endl
         << "Max value at 2 level:"
         << max_value_at_k << endl
         << endl;
}