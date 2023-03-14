#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{

    // Write your code here

    int n, step;
    cin >> n;
    int arr[n], ar[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> step;

    // reverse the array

    for (int i = 0; i < n - step; i++)

    {
        ar[i] = arr[step + i];
    }

    for (int i = 0; i < step; i++)

    {
        ar[n + i - step] = arr[i];
    }

    for (int i = 0; i < n; i++)

    {
        cout << ar[i] << " ";
    }

    cout << endl;

    return 0;
}
