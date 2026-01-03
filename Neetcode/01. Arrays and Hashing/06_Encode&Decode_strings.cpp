// Encode and Decode Strings

// Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

// Please implement encode and decode

// Example 1:

// Input: ["neet","code","love","you"]

// Output:["neet","code","love","you"]
// Example 2:

// Input: ["we","say",":","yes"]

// Output: ["we","say",":","yes"]
// Constraints:

// 0 <= strs.length < 100
// 0 <= strs[i].length < 200
// strs[i] contains only UTF-8 characters.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {

        string enc;
        for (const string &i : strs)
        {
            enc += to_string(i.size()) + ";" + i;
        }

        return enc;
    }

    vector<string> decode(string s)
    {

        vector<string> ans;

        int n = s.length();
        int i = 0;
        int j;

        while (i < n)
        {

            j = i;
            while (s[j] != ';')
            {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            string str;
            i = j + 1;
            while (len)
            {
                str += s[i++];
                len--;
            }

            ans.emplace_back(str);
        }
        return ans;
    }
    // time complexity: O(n)
    // space complexity: O(n)
};
