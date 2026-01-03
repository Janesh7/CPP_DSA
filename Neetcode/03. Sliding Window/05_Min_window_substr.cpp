// 76. Minimum Window Substring
// Hard

// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.

// Follow up: Could you find an algorithm that runs in O(m + n) time?
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int left = 0, right = 0; // left and right pointers for the sliding window
        int min_win = INT_MAX;   // to store the minimum window size
        int str_len = s.length(), sub_str_len = t.length();
        int start = -1, count = 0; // start index of the minimum window and count of characters matched
        int char_map[126] = {0};

        // Fill the char_map with the characters of t
        // and their counts
        for (char i : t)
        {
            char_map[i]++;
        }

        while (right < str_len)
        {
            // If the character at right pointer is present in t
            // and its count is greater than 0, we have a match
            if (char_map[s[right]] > 0)
            {

                count++;
            }
            // Decrease the count of the character at right pointer
            char_map[s[right]]--;
            right++;

            // Now we need to check if we have a valid window
            // A valid window is when the count of matched characters is equal to the length of t
            while (count == sub_str_len)
            {

                // Update the minimum window size if the current window is smaller
                if (right - left < min_win)
                {
                    min_win = right - left;
                    start = left;
                }

                // Now we need to remove the character at left pointer from the window
                char_map[s[left]]++;

                // Update the count of matched characters
                if (char_map[s[left]] > 0)
                {
                    count--;
                }

                // Move the left pointer to the right to shrink the window
                // and check for the next valid window
                left++;
            }
        }

        // If we have not found any valid window, return an empty string
        // Otherwise, return the minimum window substring
        return (start == -1) ? "" : s.substr(start, min_win);
    }
    // Time Complexity: O(m + n) where m is the length of s and n is the length of t
    // Space Complexity: O(1) as we are using a fixed size array of 126 chars
};

// The code of solving this problem is below. It might be the shortest among all solutions provided in Discuss.

string minWindow(string s, string t)
{
    vector<int> map(128, 0);
    for (auto c : t)
        map[c]++;
    int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
    while (end < s.size())
    {
        if (map[s[end++]]-- > 0)
            counter--; // in t
        while (counter == 0)
        { // valid
            if (end - begin < d)
                d = end - (head = begin);
            if (map[s[begin++]]++ == 0)
                counter++; // make it invalid
        }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
}

// Here comes the template.

// For most substring problem, we are given a string and need to find a substring of it which satisfy some restrictions. A general way is to use a hashmap assisted with two pointers. The template is given below.

int findSubstring(string s)
{
    vector<int> map(128, 0);
    int counter;            // check whether the substring is valid
    int begin = 0, end = 0; // two pointers, one point to tail and one  head
    int d;                  // the length of substring

    for ()
    { /* initialize the hash map here */
    }

    while (end < s.size())
    {

            if(map[s[end++]]-- ?)
            { /* modify counter here */
            }

            while (/* counter condition */)
            {

                /* update d here if finding minimum*/

                // increase begin to make it invalid/valid again

                if(map[s[begin++]]++ ?)
                { /*modify counter here*/
                }
            }

            /* update d here if finding maximum*/
    }
    return d;
}
// One thing needs to be mentioned is that when asked to find maximum substring, we should update maximum after the inner while loop to guarantee that the substring is valid. On the other hand, when asked to find minimum substring, we should update minimum inside the inner while loop.

// The code of solving Longest Substring with At Most Two Distinct Characters is below:

int lengthOfLongestSubstringTwoDistinct(string s)
{
    vector<int> map(128, 0);
    int counter = 0, begin = 0, end = 0, d = 0;
    while (end < s.size())
    {
        if (map[s[end++]]++ == 0)
            counter++;
        while (counter > 2)
            if (map[s[begin++]]-- == 1)
                counter--;
        d = max(d, end - begin);
    }
    return d;
}
// The code of solving Longest Substring Without Repeating Characters is below:

int lengthOfLongestSubstring(string s)
{
    vector<int> map(128, 0);
    int counter = 0, begin = 0, end = 0, d = 0;
    while (end < s.size())
    {
        if (map[s[end++]]++ > 0)
            counter++;
        while (counter > 0)
            if (map[s[begin++]]-- > 1)
                counter--;
        d = max(d, end - begin); // while valid, update d
    }
    return d;
}