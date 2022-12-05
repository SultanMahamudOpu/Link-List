#include <bits/stdc++.h>
using namespace std;

void swap(int *current, int *largest)
{
    int temp = *current;
    *current = *largest;
    *largest = temp;
}

void heapify(int array[], int size, int current)
{
    int largest = current;
    int left_child = 2 * current + 1; // ekhana current == i
    int right_child = 2 * current + 2;

    if (left_child < size && array[left_child] > array[largest])
    {
        largest = left_child;
    }

    if (right_child < size && array[right_child] > array[largest])
    {
        largest = right_child;
    }

    if (current != largest)
    {
        swap(array[current], array[largest]);
        heapify(array, size, largest);
    }
}

void display(int array[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
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

    cout << "Before Heapify: ";
    display(array, n);

    int non_leaf_start = (n / 2) - 1;

    for (int i = non_leaf_start; i >= 0; i--)
    {
        heapify(array, n, i);
    }

    cout << "After Heapiy: ";
    display(array, n);
}