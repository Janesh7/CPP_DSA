#include <iostream>
using namespace std;

int main()
{
    int rs100, rs50, rs20, rs1;
    int n, x = 1;
    cin >> n;
    switch (x)
    {
    case 1:
        cout << "Number of 100 rupee notes:" << n / 100 << endl;
        n = n % 100;
    case 2:
        cout << "Number of 50 rupee notes:" << n / 50 << endl;
        n %= 50;
    case 3:
        cout << "Number of 20 rupee notes:" << n / 20 << endl;
        n %= 20;
    case 4:
        cout << "Number of 1 rupee coins:" << n / 1 << endl;
        n %= 1;
    }
    return 0;
}