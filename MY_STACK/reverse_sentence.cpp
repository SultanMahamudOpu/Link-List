#include <bits/stdc++.h>
#include "STACK_1.h"
using namespace std;

void reverse_sentence(string check)
{
    MyStack<string> st;
    for (int i = 0; i < check.length(); i++)
    {
        string word = "";
        while (i < check.length() && check[i] != ' ')
        {
            word += check[i];
            i++;
        }
        st.push(word);
    }
    while (!st.empty())
    {
        cout << st.TOP() << " ";
        st.pop();
    }
}

int main()
{
    string s = "I am Sultan";
    reverse_sentence(s);
    return 0;
}