#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int ans = 0;
    int i = 0;
    if (n > 0)   // For positive number
    {
        while (n != 0)
        {

            int bit = n & 1;

            ans = (bit * pow(10, i)) + ans;

            n = n >> 1;
            i++;
        }
        cout << "Answer is " << ans << endl;
        return 0;
    }
    else    //For negative numbers
    {
        n = -n; // Convert the number to positive
        int ans = 0;
        int ar[32]= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; //Initialize the array representing the 32 bit signed int, initialize with 1's coz we know its -ve
        int flag = 1; // Used to find the first 1 in the binary
        int j=31;   // Length of the array
        while (n != 0)
        {
            // 2's comp- From lsb take 0's as it is till the first 1, after that invert every bit
            int bit = n & 1;
            int nbit = bit^1;  // XOR Operation to NEGATE the bit
            if (nbit && flag)   // Runs each time till the bits from LSB are 0's 
            {
                ans = (bit * pow(10, i)) + ans;
                n = n >> 1;
                i++;
                ar[j--] = 0;    // Add them as it is ie add 0's
                continue;
            }
            if (bit && flag)    // To catch the first 1 bit from the LSB
            {
                flag=0;
                ans = (bit * pow(10, i)) + ans;
                n = n >> 1;
                i++;
                ar[j--] = 1;    // Add as it is ie. 1 
                continue;
            }
            // From Now onwards Invert the bits till the rest. Also, since the loop runs till the lenght of the converted int only rest of the bits in the array remains 1 as should be for a -ve number
            ans = (bit * pow(10, i)) + ans;
            ar[j] = ar[j]&nbit; // Inverted bit
            j--;
            n = n >> 1;
            i++;
        }
        cout << "Answer is -" << ans << endl;
        for (int i =0;i<32;i++){
            cout<<ar[i];
        }
        return 0;
    }
}