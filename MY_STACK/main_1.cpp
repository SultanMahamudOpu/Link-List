#include <bits/stdc++.h>
#include "STACK_1.h"
using namespace std;

int main()
{
    MyStack<string> st;

    st.push("Sultan Mahamud");
    st.push("Shakhar Mahmud");
    st.push("Shakil Mahmud");

    while (!st.empty())
    {
        cout << st.pop() << endl;
    }

    cout << st.size() << endl;
    if (!st.empty())
    {
        cout << st.TOP() << endl;
    }
    return 0;
}