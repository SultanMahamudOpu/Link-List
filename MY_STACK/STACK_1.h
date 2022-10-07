#include <bits/stdc++.h>
using namespace std;

template <typename N>
class Node
{
public:
    N value;
    Node *Next;
    Node *prev;

    Node(N val)
    {
        value = val;
        Next = NULL;
        prev = NULL;
    }
};

template <typename S>
class MyStack
{
    Node<S> *head;
    Node<S> *top;

    int count = 0;

public:
    MyStack()
    {
        head = NULL;
        top = NULL;
    }

    // PUSH
    void push(S val)
    {
        Node<S> *new_created_node = new Node<S>(val);

        if (head == NULL) // stack is EMPTY
        {
            head = top = new_created_node;
            count++;
            return;
        }

        else
        {
            top->Next = new_created_node;
            new_created_node->prev = top;
            top = new_created_node;
            count++;
        }
    }
    // POP
    S pop()
    {
        Node<S> *deletiong_node = top;
        S check;
        if (head == NULL) // There is no Value
        {
            cout << "Stack UnderFlow!!!" << endl;
        }
        if (top == head) // Only 1 element
        {
            head = top = NULL;
        }
        else
        {
            top = deletiong_node->prev;
            top->Next = NULL;
        }
        check = deletiong_node->value;
        delete deletiong_node;
        count--;
        return check;
    }
    // EMPTY
    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // SIZE
    int size()
    {
        return count;
    }
    // TOP
    S TOP()
    {
        S chk;
        if (top == NULL)
        {
            cout << "Stack UnderFlow||There is No Element in Top" << endl;
        }
        else
        {
            chk = top->value;
        }

        return chk;
    }
};