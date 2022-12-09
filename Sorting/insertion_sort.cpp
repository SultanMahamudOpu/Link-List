#include <bits/stdc++.h>
using namespace std;

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "Before sort: ";
    PrintArray(array, size);
    cout << endl;

    // start sortiong
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        cout << endl
             << "i-" << i << " Key: " << key << endl;
        int j = i - 1;
        while (array[j] > key && j >= 0)
        {
            array[j + 1] = array[j];
            PrintArray(array, size);
            j--;
        }
        array[j + 1] = key;
        PrintArray(array, size);
    }
    cout << endl;

    cout << "Afert sorting: ";
    PrintArray(array, size);
    cout << endl;
}