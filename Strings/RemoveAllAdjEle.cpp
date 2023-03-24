#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        int i =0;
        while (i<s.length())
        {
            if (s[i] == s[i+1])
            {
                s.erase(i,2);
                if (i>0)
                    i--;
                continue;
            }
            i++;
        }   
        return s;
    }
};
int main()
{
    // cout<<removeDuplicates("aaaaaaaa");
    return 0;
}