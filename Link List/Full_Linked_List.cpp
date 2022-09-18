#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    // constructer creation
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

struct Test
{
    int position[1000];
};

void inserAtTAil(Node *&head, int val);
void insertAtHead(Node *&head, int val);
void display(Node *address);
int countOfLength(Node *&head);
void insertionAtSpecificPosition(Node *&head, int pos, int val);
int searchByValueUniqe(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
Test searchByValueDuplicateReturn(Node *&head, int key);
void searchByValueUnique(Node *&head, int searchValue, int value);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpecificPosition(Node *&head, int position);
void deletionByValueUniqe(Node *&head, int value);
Node *reverseNonRecursive(Node *&head);
Node *reverse_recursive(Node *&head);

void inserAtTAil(Node *&head, int val)
{
    Node *newcreatedNode = new Node(val);
    if (head == NULL)
    {
        head = newcreatedNode;
        return;
    }
    Node *temp = head;

    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newcreatedNode;
}

void insertAtHead(Node *&head, int val)
{
    // s1:NewNode creation
    Node *newNode = new Node(val);
    // s2:Update of newNode->Next
    newNode->Next = head;
    // s3:update of head
    head = newNode;
}

void display(Node *address)
{
    while (address != NULL)
    {
        cout << address->value;
        if (address->Next != NULL)
        {
            cout << "->";
        }
        address = address->Next;
    }
    cout << endl;
}

int countOfLength(Node *&head)
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }
    return count;
}

void insertionAtSpecificPosition(Node *&head, int pos, int val)
{
    int i = 0;
    Node *temp = head;

    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }

    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int searchByValueUniqe(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    if (temp->Next == NULL)
    {
        return -1;
    }

    while (temp->value != key)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }

        temp = temp->Next;
        count++;
    }

    return count;
}

void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int size;
    size = countOfLength(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            position[k] == count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }

    cout << endl;
    if (flag == 0)
    {
        cout << "The Searched Value is not yet in the List" << endl;
    }
    else
    {
        position[0] = k;
        cout << "The value is found at Position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
            {
                cout << ",";
            }
        }
    }
}

Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            T.position[k] == count;
            k++;
        }
        temp = temp->Next;
        count++;
    }

    T.position[0] = k;
    return T;
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
        cout << "There is no Value in the Linked List" << endl;
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *deletingNode = temp->Next;
        temp->Next = NULL;
        delete deletingNode;
    }

    else
    {
        // Head is NULL
        if (temp == NULL)
        {
            cout << "There is No Value in the Linked List" << endl;
        }
        // Head is Tail
        deletionAtHead(head);
    }
}

void searchByValueUnique(Node *&head, int searchValue, int value)
{
    // step 1:search the position of the searchValue
    int position;
    position = searchByValueUniqe(head, searchValue);

    // step 2:Insert the valur at the Position+1
    insertionAtSpecificPosition(head, position + 1, value);
}

void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    if (temp != NULL && position <= countOfLength(head))
    {
        if (position == 1)
        {
            deletionAtHead(head);
        }

        else if (position == countOfLength(head))
        {
            deletionAtTail(head);
        }

        else
        {
            int i = 1;
            while (i < position - 1)
            {
                temp = temp->Next;
                i++;
            }

            Node *deletiongNode = temp->Next;
            temp->Next = deletiongNode->Next;
            delete deletiongNode;
        }
    }
    else
    {
        cout << "Position Out of Bound";
    }
}

void deletionByValueUniqe(Node *&head, int value)
{
    // Find the Position of the Value
    int position;
    position = searchByValueUniqe(head, value);

    // Delete the Node at the Position
    if (position == -1)
    {
        cout << "Value not Found in the Linked List" << endl;
    }
    else
    {
        deletionAtSpecificPosition(head, position);
    }
}

Node *reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (head == NULL)
    {
        cout << "The Linked List is Empty" << endl;
        return head;
    }
    Node *next = head->Next;

    while (true)
    {
        current->Next = prev;
        prev = current;
        current = next;
        if (current == NULL)
        {
            break;
        }
        next = next->Next;
    }
    return prev;
}

Node *reverse_recursive(Node *&head)
{
    // Base Call
    if (head == NULL || head->Next == NULL)
    {
        if (head == NULL)
        {
            cout << "The Linked List is Empty" << endl;
        }

        return head;
    }

    // Recursive Call
    Node *newHead = reverse_recursive(head->Next);
    head->Next->Next = head;
    head->Next = NULL;

    return newHead;
}

int main()
{
    Node *head = NULL;

    int value, position;
    // choice 1:Insertion at Head
    // choice 2:Insertion at tail
    // choice 3:Insertion at a certain position
    cout << "choice 1:Insertion at Head" << endl
         << "choice 2:Insertion at tail" << endl
         << "choice 3:Insertion at Specific Position" << endl
         << "choice 4:Search a value(uniqe List)" << endl
         << "choice 5:Search a value(Dublicate Enable Link List)" << endl
         << "choice 6:Insertion after a specific value(uniqe List)" << endl
         << "choice 8:Deletion at Head" << endl
         << "choice 9:Deletion at Tail" << endl
         << "choice 10:Deletion at Specific Position" << endl
         << "choice 11:Deletion by Value(Uniqe Linked List)" << endl
         << "choice 13:Reversal of List Non-Recursive" << endl
         << "choice 14:Reversal of List Recursive" << endl
         << "choice 0:Exit" << endl;

    cout << "Next Choice: ";
    int choice;
    cin >> choice;

    while (choice != 0)
    {

        switch (choice)
        {
        case 1:
            cout << "Enter the Value: ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 2:
            cout << "Enter the Value: ";
            cin >> value;
            inserAtTAil(head, value);
            break;

        case 3:
            cout << "Enter the Desited Position: ";
            cin >> position;
            cout << "ENter the Value: ";
            cin >> value;
            insertionAtSpecificPosition(head, position, value);
            break;

        case 4:
            cout << "Enter the Value to Search: ";
            cin >> value;
            position = searchByValueUniqe(head, value);
            if (position != -1)
            {
                cout << "The number is at Position " << position << endl;
            }
            else
            {
                cout << "The number is not yet in the List" << endl;
            }

        case 5:
            cout << "Enter the Value to Search: ";
            cin >> value;
            // searchByValueDuplicate(head, value);
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if (T.position[0] == 1)
            {
                cout << "The Searched Value is not yet in the List" << endl;
            }
            else
            {
                int size = T.position[0];
                cout << "The value is found at Position: ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i];
                    if (i < size - 1)
                    {
                        cout << ",";
                    }
                }
                cout << endl;
            }
            break;

        case 6:
            cout << "Enter the value to search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            searchByValueUnique(head, searchValue, value);
            break;

        case 8:
            deletionAtHead(head);
            break;

        case 9:
            deletionAtTail(head);

        case 10:
            if (head == NULL)
            {
                cout << "There is No Value in the Linked List" << endl;
                break;
            }
            cout << "Enter the Desited Position: ";
            cin >> position;

            deletionAtSpecificPosition(head, position);
            display(head);
            break;

        case 11:
            cout << "Enter the value to Delete: ";
            int deletion_value;
            cin >> deletion_value;
            deletionAtSpecificPosition(head, deletion_value);
            break;

        case 13:
            head = reverseNonRecursive(head);
            break;

        case 14:
            head = reverse_recursive(head);
            break;
        default:
            break;
        }

        cout << "Next Choice: ";
        cin >> choice;
    }

    cout << "Linked List: ";
    display(head);
    cout << "Length of the List: " << countOfLength(head) << endl;

    return 0;
}
