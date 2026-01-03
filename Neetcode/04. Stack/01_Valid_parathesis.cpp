// 20. Valid Parentheses

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        // Create a stack to store the opening brackets
        stack<char> para_stk;

        for (char i : s)
        {
            // If the character is an opening bracket, push it onto the stack
            if (i == '(' || i == '{' || i == '[')
            {

                para_stk.push(i);

            } else { // If the character is a closing bracket

                char c = para_stk.top();

                // Check if the stack is empty or if the top of the stack does not match the closing bracket
                if (para_stk.empty() || ((c == '(' && i != ')') || (c == '{' && i != '}') || (c == '[' && i != ']')))
                {
                    return false;
                }
                // If it matches, pop the opening bracket from the stack
                para_stk.pop();
            }
        }
        // If the stack is empty at the end, all brackets were matched correctly
        return para_stk.empty();
    }
    // Time Complexity: O(n), where n is the length of the input string s.
    // Space Complexity: O(n), in the worst case, all characters are opening brackets and are stored in the stack.
};