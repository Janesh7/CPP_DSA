// 1190. Reverse Substrings Between Each Pair of Parentheses
// Medium

// You are given a string s that consists of lower case English letters and brackets.

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any brackets.

 

// Example 1:

// Input: s = "(abcd)"
// Output: "dcba"
// Example 2:

// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is reversed.
// Example 3:

// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 

// Constraints:

// 1 <= s.length <= 2000
// s only contains lower case English characters and parentheses.
// It is guaranteed that all parentheses are balanced.


class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string ans,temp;
        stack<char>stack;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=')')
            {
                stack.push(s[i]);
            }
            else
            {
                temp="";
                while(stack.top()!='(')
                {
                    temp+=stack.top();
                    stack.pop();
                }
                stack.pop();
                for(int j=0;j<temp.size();j++)
                {
                    stack.push(temp[j]);
                }
            }
        }
        ans="";
        while(!stack.empty())
        {
            ans+=stack.top();
            stack.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};