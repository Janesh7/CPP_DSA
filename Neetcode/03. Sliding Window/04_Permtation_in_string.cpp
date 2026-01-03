// 567. Permutation in String

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        int char_set1[26] = {0};
        int char_set2[26] = {0};

        int len1 = s1.length(), len2 = s2.length();

        if (len2 < len1)
        {
            return false;
        }

        // Fill the char_set1 and char_set2 with the first len1 chars of s2
        // and s1 respectively
        for (int i = 0; i < len1; i++)
        {
            char_set1[s1[i] - 'a']++;
            char_set2[s2[i] - 'a']++;
        }

        if (CheckEqual(char_set1, char_set2))
        {
            return true;
        }
        // Now we need to check for the rest of the chars in s2
        for (int i = 1; i <= len2 - len1; i++)
        {
            // We need to remove the first char of the previous window and add the new char in the current window
            // So we need to update the char_set2 by removing the first char of the previous window and adding the new char in the current window
            char_set2[s2[i - 1] - 'a']--;
            char_set2[s2[i + len1 - 1] - 'a']++;

            if (CheckEqual(char_set1, char_set2))
            {
                return true;
            }
        }

        return false;
    }

private:
    bool CheckEqual(int *cs1, int *cs2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (cs1[i] != cs2[i])
            {
                return false;
            }
        }
        return true;
    }
    // Time Complexity: O(n) where n is the length of s2
    // Space Complexity: O(1) as we are using a fixed size array of 26 chars
};