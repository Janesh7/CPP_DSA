// 3. Longest Substring Without Repeating Characters

// Given a string s, find the length of the longest substring without duplicate characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces

#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// Approach: Sliding Window and set (2 pointers)
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int maxLength = 0;
        // Using a set to store characters in the current window
        // and check for duplicates
        unordered_set<char> charSet;

        // Iterate through the string with the right pointer
        // and expand the window until a duplicate is found
        for (int right = 0; right < s.length(); right++)
        {

            // If the character is already in the set, move the left pointer
            // to the right until the duplicate is removed
            while (charSet.find(s[right]) != charSet.end())
            {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
    // Time Complexity: O(n), where n is the length of the string s.
    // Space Complexity: O(min(n, m)), where n is the length of the string s and m is the size of the character set.
    // Constraints say "s consists of English letters, digits, symbols and spaces". I think we have fixed max size of characters consisting of the input string. so O (1) SC.
};

// similar approach using map can be done

// We can optimize the above code by using a hash map to store the last seen index of each character. This allows us to skip the left pointer directly to the next position after the last occurrence of the current character.
// This way, we can avoid the inner while loop and reduce the time.
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int max_len = 0, n = s.length();
        int left = 0;
        // Using a hash map to store the last seen index of each character
        // and check for duplicates
        unordered_map<char, int> last_seen;

        for (int right = 0; right < n; right++)
        {

            char c = s[right];

            // If the character is already in the map and its last seen index is greater than or equal to left,
            // move the left pointer to the right of the last seen index
            if (last_seen.find(c) != last_seen.end() && last_seen[c] >= left)
            {
                left = last_seen[c] + 1;
            }

            max_len = max(max_len, right - left + 1);
            last_seen[c] = right;
        }

        return max_len;
    }
    // time complexity: O(n), where n is the length of the string s.
    // Space complexity: O(min(n, m)) or O (1), where n is the length of the string s and m is the size of the character set.
};