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

string infix_to_postfix(string check)
{
    MyStack<char> st;
    string result;
    for (int i = 0; i < check.length(); i++)
    {
        // S1:
        if (check[i] >= '0' && check[i] <= '9')
        {
            result += check[i];
        }
        // s2:
        else if (check[i] == '(')
        {
            st.push(check[i]);
        }
        // s3:
        else if (check[i] == ')')
        {
            while (!st.empty() && st.TOP() != '(')
            {
                result += st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        // s4:
        else
        {
            while (!st.empty() && precision_cal(st.TOP()) >= precision_cal(check[i]))
            {
                result += st.pop();
            }
            st.push(check[i]);
        }
    }
    while (!st.empty())
    {
        result += st.pop();
    }
    return result;
}

int postfix_evaluation(string check)
{
    MyStack<int> st;

    for (int i = 0; i < check.length(); i++)
    {
        if (check[i] >= '0' && check[i] <= '9')
        {
            st.push(check[i] - '0');
        }
        else
        {
            int a = st.pop();
            int b = st.pop();

            switch (check[i])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                if (a > b)
                {
                    st.push(a - b);
                    break;
                }
                else
                {
                    st.push(b-a);
                    break;
                }

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
    string infix = "(4*(3+5))-(2+0)";
    string postfix;
    postfix = infix_to_postfix(infix);
    cout << endl
         << postfix << endl
         << postfix_evaluation(postfix) << endl;
}