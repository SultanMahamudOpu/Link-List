#include <bits/stdc++.h>
using namespace std;

int binarySearch(int array[], int x, int lb, int ub)
{
    if (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (x == array[mid])
        {
            return mid;
        }
        else if (x > array[mid])
        {
            binarySearch(array, x, mid + 1, ub);
        }
        else
        {
            return -1;
        }
    }
    else
    {
        cout << "Value Not found!" << endl;
    }
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
    int checkValue;
    cout << "Please Enter the value you want to search: ";
    cin >> checkValue;
    int indexNumber;
    indexNumber = binarySearch(array, checkValue, 0, size - 1);

    if (indexNumber != -1)
    {
        cout << "Index No: " << indexNumber << endl
             << "Position no: " << indexNumber + 1 << endl;
    }
    return 0;
}