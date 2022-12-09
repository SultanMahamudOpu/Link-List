#include <bits/stdc++.h>
using namespace std;

void PrintArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Array before sort: ";
    PrintArray(array, n);
    cout << endl;

    // start bubble sort
    for (int i = 1; i < n; i++)
    {
        int flag = 0;
        cout << "Insertion No: " << i << endl;
        for (int j = 0; j < n - i; j++) // remove redundrion problem
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                flag = 1;
            }
            PrintArray(array, n);
        }
        cout << endl;
        if (flag == 0)
        {
            break;
        }
    }

    cout << "Array after sort: ";
    PrintArray(array, n);
    cout << endl;
}