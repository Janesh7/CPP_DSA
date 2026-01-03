#include <iostream>
using namespace std;

int setbit(int a)
{
    int n = 0;
    if (a == 0)
    {
        return 1;
    }
    while (a != 0)
    {
        if (a & 1)
            n++;
        a = a >> 1;
    }
    return n;
}

int setbits(int n1, int n2)
{
    int res1, res2;
    res1 = setbit(n1);
    cout << "Number of bits in " << n1 << " is " << res1 << endl;
    res2 = setbit(n2);
    cout << "Number of bits in " << n2 << " is " << res2 << endl;
    return res1 + res2;
}

int main()
{
    int num1, num2, setb;
    cout << "Enter two numbers:";
    cin >> num1 >> num2;
    setb = setbits(num1, num2);
    cout << "Total number of set bits are :" << setb;
    return 0;
}
