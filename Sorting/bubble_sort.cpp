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

    // start buble sort
    for (int i = 1; i < n; i++)
    {
        cout << "Insertion No: " << i << endl;
        for (int j = 0; j < n - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
            PrintArray(array, n);
        }
    }

    cout << "Array after sort: ";
    PrintArray(array, n);
}