#include <bits/stdc++.h>
#include "MYQUEUE.h"
using namespace std;

typedef pair<char, int> mytype;

int main()
{
    Queue<mytype> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c1;
        int c2;
        cin >> c1 >> c2;
        q.push(make_pair(c1, c2));
    }

    while(!q.empty())
    {
        mytype check;
        check=q.pop();
        cout<<check.first<<" | "<<check.second<<endl;
    }

    cout << endl
         << endl;

    if (!q.empty())
    {
        mytype check;
        check = q.FRONT();
        cout << check.first << " | " << check.second << endl;
    }
    if (!q.empty())
    {
        mytype check;
        check = q.BACK();
        cout << check.first << " | " << check.second << endl;
    }
}