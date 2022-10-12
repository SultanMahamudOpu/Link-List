#include <bits/stdc++.h>
using namespace std;

template <typename N>
class Node // Single Linked List
{
public:
    N value;
    Node *Next;

    Node(N val)
    {
        value = val;
        Next = NULL;
    }
};

template <typename Q>
class Queue
{
    Node<Q> *front;
    Node<Q> *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // ENQUEUE -->PUSH(VAL)
    void push(Q val)
    {
        Node<Q> *new_created_node = new Node<Q>(val);

        if (front == NULL)
        {
            front = new_created_node;
            rear = new_created_node;
            return;
        }
        rear->Next = new_created_node;
        rear = new_created_node;
    }

    // DEQUEUE -->POP()
    Q pop()
    {
        Node<Q> *del_node = front;
        Q check;
        if (rear == NULL)
        {
            cout << "Queue is under flow";
            return check;
        }
        front = front->Next;
        if (front == NULL)
        {
            rear = NULL;
        }
        check = del_node->value;
        delete del_node;
        return check;
    }

    // PEEK -->FRONT()  &&  REAR()
    Q FRONT()
    {
        Q check;
        check = front->value;
        return check;
    }

    Q BACK()
    {
        Q check;
        check = rear->value;
        return check;
    }
    // EMPTY
    bool empty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};