// 242. Valid Anagram

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.
 

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {

        size_t len = s.length();
        // Check if the lengths of the strings are equal
        // If not, they cannot be anagrams
        if (len != t.length())
        {
            return false;
        }

        // Create a hash map to count the occurrences of each character
        // in both strings
        unordered_map<char, int> m;

        for (int i = 0; i < len; i++)
        {
            // Increment the count for the character in string s
            // and decrement the count for the character in string t
            // This way, if the characters match, the count will be zero
            // for that character in the end
            m[s[i]]++;
            m[t[i]]--;
        }

        for (const auto &i : m)
        {

            // If the count for any character is not zero, they are not anagrams
            if (i.second)
            {
                return false;
            }
        }

        return true;
    }
    // Time Complexity: O(n), where n is the length of the strings
    // Space Complexity: O(1), since the hash map will have a fixed size of 26 for lowercase letters
};