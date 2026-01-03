// 125. Valid Palindrome

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {

        size_t p1, p2;

        p1 = 0;
        p2 = s.length() - 1;

        while (p1 < p2)
        {

            if (!isalnum(s[p1]))
            {
                p1++;
                continue;
            }

            if (!isalnum(s[p2]))
            {
                p2--;
                continue;
            }

            if (tolower(s[p1]) != tolower(s[p2]))
            {

                return false;
            }
            else
            {

                p1++;
                p2--;
            }
        }

        return true;
    }
    // Time Complexity: O(n), where n is the length of the string s.
    // Space Complexity: O(1), no extra space is used.
};