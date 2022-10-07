#include <bits/stdc++.h>
#include "STACK_1.h"
using namespace std;

void insertion_at_bottom(MyStack<int> &check, int check_element)
{
    if (check.empty())
    {
        check.push(check_element);
        return;
    }

    int top_element = check.TOP();
    check.pop();
    insertion_at_bottom(check, check_element);

    check.push(top_element);
}

void revers_stack(MyStack<int> &check)
{
    if (check.empty())
    {
        return;
    }
    int top_element = check.TOP();
    check.pop();
    revers_stack(check);
    insertion_at_bottom(check, top_element);
}

int main()
{
    MyStack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    revers_stack(st);

    while (!st.empty())
    {
        cout << st.pop() << endl;
    }
    return 0;
}