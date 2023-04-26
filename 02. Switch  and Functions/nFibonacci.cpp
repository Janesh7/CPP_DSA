#include <iostream>
using namespace std;

int fib(int n)
{
    int a = 0, b = 1, sum;
    if (n == 1)
        return a;
    if (n == 2)
        return b;
    for (int i = 3; i <= n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

int main()
{
    int n, ans;
    cout << "Enter a number: ";
    cin >> n;
    ans = fib(n);
    cout << "The fibonacci term at " << n << " is " << ans;
    return 0;
}