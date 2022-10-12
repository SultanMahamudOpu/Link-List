#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

int precision_cal(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infix_to_prefix(string check)
{
    reverse(check.begin(), check.end());

    MyStack<char> st;
    string result;

    for (int i = 0; i < check.length(); i++)
    {
        if (check[i] >= '0' && check[i] <= '9')
        {
            result += check[i];
        }
        else if (check[i] == ')')
        {
            st.push(check[i]);
        }
        else if (check[i] == '(')
        {
            while (!st.empty() && st.TOP() != ')')
            {
                result += st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precision_cal(st.TOP()) >= precision_cal(check[i]))
            {
                result += st.pop();
            }
            st.push(check[i]);
        }
    }
    while(!st.empty())
    {
        result+=st.pop();
    }
    reverse(result.begin(),result.end());
    return result;
}

int prefix_evaluate(string check)
{
    MyStack<int> st;

    for (int i = check.length() - 1; i >= 0; i--)
    {
        if (check[i] >= '0' && check[i] <= '9') // if check is 0-9
        {
            st.push(check[i] - '0'); // eai ta ASCI man neba;tai ASCI man thake '0' er man bad
        }
        else // if check is "+-*/"
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
    string infix="(7+(4*5))-(2+0)";
    string prefix;
    prefix=infix_to_prefix(infix);
    cout<<endl<<prefix<<endl<<prefix_evaluate(prefix)<<endl;
}