#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int i = s.length() - 1, j = 0;
        string r, temp;
        while (i >= 0)
        {
            if (i >= 0 && s[i] == ' ')
            {
                i--;
                continue;
            }
            j = i;
            while (j >= 0 && s[j] != ' ')
                j--;
            for (int k = ++j; k <= i; k++)
                temp += s[k];
            i = j - 1;
            temp += ' ';
            r += temp;
            temp.clear();
        }
        r.pop_back();
        return r;
    }
};
