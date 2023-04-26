#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        // print numbers
        int num = 1;
        while (num <= n - row + 1)
        {
            cout << num;
            num++;
        }
        
        //print stars in twos
        int star = 1;
        while (star < row)
        {
            cout << "**";
            star++;
        }

        //print numbers in reverse
        int num2 = n - row + 1;
        while (num2 > 0)
        {
            cout << num2--;
        }
        cout << endl;
        row++;
    }
    return 0;
}
// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1