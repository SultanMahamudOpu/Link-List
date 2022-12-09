#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PAIR;
int main()
{
    int k;
    cin >> k;
    vector<vector<int>> all_values(k);

    // Input
    for (int i = 0; i < k; i++)
    {
        int size;
        cin >> size;
        all_values[i] = vector<int>(size);

        for (int k = 0; k < size; k++)
        {
            cin >> all_values[i][k];
        }
    }

    vector<int> index_traker(k, 0);
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;

    // Initialisation of pq
    for (int i = 0; i < k; i++)
    {
        pq.push(make_pair(all_values[i][0], i));
    }

    vector<int> ans;
    // Main Lofic of Heap
    while (!pq.empty())
    {
        PAIR x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        if (index_traker[x.second] + 1 < all_values[x.second].size())
        {
            pq.push(make_pair(all_values[x.second][index_traker[x.second] + 1], x.second));
            // We are Creating a pair: (increment position value,increment position array indentiry)
            // Then push in pq
        }
        index_traker[x.second] += 1;
    }

    // Print pq
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    return 0;
}

/*
3
3
1 4 7
2
3 5
3
2 6 7
*/