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
    int largest = current;            // first value tai prothome largest dhora then compire korbo
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

void heap_sort(int array[], int size)
{
    for (int i = size - 1; i >= 0; i--) // last thake shusu
    {
        swap(array[0], array[i]); // swap hosche root er shata i er
        heapify(array, i, 0);     // ekhana i=size ;karon ekhane array er size 1 kore komytea hora.ar i 1 kora komtasa,tai size=i diya hoise && "0" means root
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

    // heapify start
    int non_leaf_start = (n / 2) - 1;         // left_child=2*i+1 &&right_child=2*i+2 && non_left_child=(n/2)-1;
    for (int i = non_leaf_start; i >= 0; i--) // last thake input kora lagba
    {
        heapify(array, n, i);
    }

    cout << "After Heapiy: ";
    display(array, n);

    heap_sort(array, n);
    cout << "After Heap Sort: ";
    display(array, n);
}

/*
9
2 10 1 5 4 8 3 8 7
*/