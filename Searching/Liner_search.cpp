// cheak one by one
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++) // take input
    {
        cin >> array[i];
    }

    char c;
    cout << "Do you want to search (Y/N) ";
    cin >> c;
    while (toupper(c) == 'Y')
    {
        int CheakValue;
        cout << "Please enter the value that you want to search: " << endl;
        cin >> CheakValue;
        int flag = 0;
        for (int i = 0; i < size; i++) // liner search start
        {
            if (array[i] == CheakValue)
            {
                flag = 1;
                cout << "Index no:" << i << endl
                     << "Position no:" << i + 1 << endl;
            }
        }
        if (flag == 0)
        {
            cout << "Value not found" << endl;
        }

        cout << "Do you want to continue (Y/N) ";
        cin >> c;
    }
    return 0;
}