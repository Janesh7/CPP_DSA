// 424. Longest Repeating Character Replacement

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.

// Constraints:

// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length

#include <iostream>
#include <string>
using namespace std;

// Approach: Sliding Window and set (2 pointers)
class Solution
{
public:
    int characterReplacement(string s, int k)
    {

        int left = 0, right = 0;
        int max_win = 0;
        int len = s.length();
        int char_freq[26] = {0};
        int max_freq = 0; // maintain max freq of the char coz window - max_freq would give us the number of chars that can be replaced

        for (; right < len; right++)
        {

            // include the char in the freq_map and update the max_freq
            max_freq = max(++char_freq[s[right] - 'A'], max_freq);

            // Found the case when we can no longer keep a valid window while replacing
            // chars (checks whether the rest of the chars in window can replace be possibly replaced based on k)
            while ((right - left + 1 - max_freq) > k)
            {
                // reduce the frequency and move left
                --char_freq[s[left++] - 'A'];
                // IMP: we dont have to update max_freq (as an optimization)
                //      because reduce the max_freq won't have any effect on the
                //      answer max_win and will be just an overhead
                //      Ex. Lets say 5 win size , k = 2, so max_freq is 3
                //      For our answer to change 6 should be the win size
                //      & k = 2 is const so max_freq has to be 4.
                //      So lower values like 2 (6-2 = 4) is not valid as it should
                //      be < k (2)
            }

            // update max window
            max_win = max(max_win, (right - left + 1));
        }

        return max_win;
    }
};