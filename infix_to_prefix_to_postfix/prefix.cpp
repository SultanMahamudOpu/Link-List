#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

int prefix(string check)
{
    MyStack<int> st;

    for (int i = check.length() - 1; i >= 0; i--)
    {
        if (check[i] >= '0' && check[i] <= '9')//if check is 0-9
        {
            st.push(check[i] - '0');//eai ta ASCI man neba;tai ASCI man thake '0' er man bad
        }
        else//if check is "+-*/"
        {
            int a = st.pop();
            int b = st.pop();

            switch (check[i])
            {
            case '+':
                st.push(a + b);
                break;

            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '^':
                st.push(pow(a, b));
                break;

            default:
                break;
            }
        }
    }
    return st.TOP();
}

int main()
{
    string s;
    cin>>s;
    cout << prefix(s);
}