#include <bits/stdc++.h>
using namespace std;

template <typename T>
T my_max(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    // founction_name<Date_type>(parameter)
    cout << my_max<int>(3, 7) << endl;
    cout << my_max<float>(3.26, 7.98) << endl;
    cout << my_max<char>('a', 'g') << endl;
}