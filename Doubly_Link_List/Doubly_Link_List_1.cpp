#include <bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode *Next;
    doublyNode *prev;

    doublyNode(int val)
    {
        value = val;
        Next = NULL;
        prev = NULL;
    }
};

struct Test
{
    int position[1000];
};

void insertion_at_tail(doublyNode *&head, int val);
void display(doublyNode *address);
void insertion_at_head(doublyNode *&head, int val);
int count_of_lenght(doublyNode *&head);
void insertion_at_specific_position(doublyNode *&head, int pos, int val);
int search_by_value_uniqe(doublyNode *&head, int given_value);
Test search_by_value_duplicate(doublyNode *&head, int given_value);
void deletiong_at_head(doublyNode *&head);
void deletiong_at_tail(doublyNode *&head);
void insertion_after_specific_position(doublyNode *&head, int searchValue, int val);
void insertion_befor_specific_position(doublyNode *&head, int search_by_value, int val);
void deletiong_at_specific_position(doublyNode *&head, int pos);
void delete_by_value(doublyNode *&head, int val);

void insertion_at_tail(doublyNode *&head, int val)
{
    doublyNode *new_created_node = new doublyNode(val);

    if (head == NULL)
    {
        head = new_created_node;
        return;
    }

    doublyNode *temp = head;

    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = new_created_node;
    new_created_node->prev = temp;
}

void display(doublyNode *address)
{
    while (address != NULL)
    {
        cout << address->value;
        if (address->Next != NULL)
        {
            cout << "=>";
        }
        address = address->Next;
    }
    cout << endl;
}

void insertion_at_head(doublyNode *&head, int val)
{
    doublyNode *new_created_node = new doublyNode(val);

    if (head == NULL)
    {
        head = new_created_node;
        return;
    }
    head->prev = new_created_node;
    new_created_node->Next = head;
    head = new_created_node;
}

int count_of_lenght(doublyNode *&head)
{
    doublyNode *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }

    return count;
}

void insertion_at_specific_position(doublyNode *&head, int pos, int val)
{
    int i = 0;
    doublyNode *temp = head;

    doublyNode *new_created_node = new doublyNode(val);
    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }

    new_created_node->prev = temp;
    new_created_node->Next = temp->Next;
    temp->Next = new_created_node;
    new_created_node->Next->prev = new_created_node;
}

int search_by_value_uniqe(doublyNode *&head, int given_value)
{
    doublyNode *temp = head;
    int count = 1;

    while (temp->value != given_value)
    {

        if (temp->Next == NULL) // If value is not found
        {
            return -1;
        }
        count++;
        temp = temp->Next;
    }
    return count;
}

Test search_by_value_duplicate(doublyNode *&head, int given_value)
{
    doublyNode *temp = head;
    Test srtucter;
    int k = 1, count = 1;

    while (temp != NULL)
    {
        if (temp->value == given_value)
        {
            srtucter.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    srtucter.position[0] = k;
    return srtucter;
}

void deletiong_at_head(doublyNode *&head)
{
    doublyNode *temp = head;
    if (temp != NULL)
    {
        head->Next->prev = NULL;
        head = head->Next;
        delete temp;
    }

    else
    {
        cout << "There is no value in this Linked List" << endl;
    }
}

void deletiong_at_tail(doublyNode *&head)
{
    doublyNode *temp = head;

    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        doublyNode *deletiong_node = temp->Next;
        temp->Next = NULL;
        delete deletiong_node;
    }

    else
    {
        // Head is NULl
        if (temp == NULL)
        {
            cout << "Link List is Empty!!!" << endl;
        }
        else
        {
            // Head is Tail means have only 1 element
            deletiong_at_head(head);
        }
    }
}

void insertion_after_specific_position(doublyNode *&head, int searchValue, int val)
{
    int pos;
    pos = search_by_value_uniqe(head, searchValue);

    insertion_at_specific_position(head, pos + 1, val);
}

void insertion_befor_specific_position(doublyNode *&head, int searchValue, int val)
{
    int pos;
    pos = search_by_value_uniqe(head, searchValue);

    insertion_at_specific_position(head, pos - 1, val);
}

void deletiong_at_specific_position(doublyNode *&head, int pos)
{
    doublyNode *temp = head;
    doublyNode *deletiong_node = head;

    if (temp != NULL && pos <= count_of_lenght(head))
    {
        if (pos == 1)
        {
            deletiong_at_head(head);
        }
        else if (pos == count_of_lenght(head))
        {
            deletiong_at_tail(head);
        }
        else
        {
            int i = 1;
            while (i < pos - 1)
            {
                temp = temp->Next;
                i++;
            }
            deletiong_node = temp->Next;
            temp->Next = deletiong_node->Next;
            deletiong_node->Next->prev = temp;
            deletiong_node->Next = NULL;
            deletiong_node->prev = NULL;

            delete deletiong_node;
        }
    }

    else
    {
        cout << "Position out of Bound!!" << endl;
    }
}

void delete_by_value(doublyNode *&head, int val)
{
    // Find the position of the value
    int pos;
    pos = search_by_value_uniqe(head, val);

    // Delet the position of the value
    if (pos == -1)
    {
        cout << "Value not Fond in this Link List!!!";
    }

    else
    {
        deletiong_at_specific_position(head, pos);
    }
}

void reverse_print(doublyNode *&head)
{
    doublyNode *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }

    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->prev != NULL)
        {
            cout << "=>";
        }
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    doublyNode *head = NULL;

    int value, position, choice;
    cout << "Choice 1:Insertion at Tail" << endl
         << "Choice 2:Insertion at Head" << endl
         << "Choice 3:Insertion at a specific Position" << endl
         << "Choice 4:Search by Value Uniqe" << endl
         << "Choice 5:Search by Value Duplicate Enable Link List" << endl
         << "Choice 6:Deletiong at Head" << endl
         << "Choice 7:Deletiong at Tail" << endl
         << "Choice 8:Insertion after a specific position" << endl
         << "Choice 9:Insertion befor a specific position" << endl
         << "Choice 10:Deletiong at specific Position" << endl
         << "Choice 11:Deletiong by Value Uniqe" << endl
         << "Choice 12:Reverse Print the Linked List" << endl
         << "Choice 99:Displey" << endl
         << "Choice 0:Exit" << endl;

    cout << "Choice: ";
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the Value: ";
            cin >> value;
            insertion_at_tail(head, value);
            break;

        case 2:
            cout << "Enter the Value: ";
            cin >> value;
            insertion_at_head(head, value);
            break;

        case 3:
            cout << "Enter the Desird Position: ";
            cin >> position;
            cout << "Enter the Value: ";
            cin >> value;
            insertion_at_specific_position(head, position, value);
            break;

        case 4:
            if (head == NULL) // If Linked List is empty
            {
                cout << "Linked List is Empty" << endl;
                break;
            }
            cout << "Enter the Search Value: ";
            int search_value;
            cin >> search_value;
            position = search_by_value_uniqe(head, search_value);

            if (position == -1)
            {
                cout << "Value is not in this Linked List" << endl;
            }
            else
            {
                cout << "Value is in Position: " << position << endl;
            }
            break;

        case 5:
            cout << "Enter the Search Value: ";
            cin >> value;
            Test structer;
            structer = search_by_value_duplicate(head, value);
            if (structer.position[0] == 1)
            {
                cout << "The search value in not yet in this List" << endl;
            }
            else
            {
                int size = structer.position[0];
                cout << "The value is found at Postion: ";
                for (int i = 1; i < size; i++)
                {
                    cout << structer.position[i];
                    if (i < size - 1)
                    {
                        cout << ",";
                    }
                }
                cout << endl;
            }
            break;

        case 6:
            deletiong_at_head(head);
            break;

        case 7:
            deletiong_at_tail(head);
            break;

        case 8:
            cout << "Enter the value to Search: ";
            cin >> search_value;
            cout << "Enter the value to insert: ";
            cin >> value;
            insertion_after_specific_position(head, search_value, value);
            break;

        case 9:
            cout << "Enter the value to Search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            insertion_befor_specific_position(head, searchValue, value);
            break;

        case 10:
            cout << "Enter the Position: ";
            cin >> position;
            deletiong_at_specific_position(head, position);
            break;

        case 11:
            cout << "Enter the Value to Delete: ";
            cin >> value;
            delete_by_value(head, value);
            break;

        case 12:
            reverse_print(head);
            break;
        case 99:
            display(head);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << endl;
    cout << "Doubly Link List: ";
    display(head);
    cout << "Lenght of Doubly Link List: " << count_of_lenght(head) << endl
         << endl;
}