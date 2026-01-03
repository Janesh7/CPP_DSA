// 49. Group Anagrams

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Explanation:

// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// Example 2:

// Input: strs = [""]

// Output: [[""]]

// Example 3:

// Input: strs = ["a"]

// Output: [["a"]]

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            
            // Create a map to store the sorted string as key and the original strings as values
            // The key will be the sorted string and the value will be a vector of strings
            unordered_map <string, vector<string>> m;
    
            for (const string& s: strs) {
    
                vector char_set (26,0);
                for (const char& c: s) {
                    // Increment the count of the character in the char_set array
                    // 'a' is subtracted to get the index in the array
                    char_set [c - 'a']++;
                }
                // Create a string from the char_set array to use as a key in the map
                // The key will be a string of 26 characters, each representing the count of a character
                string id;
                for (int i = 0; i < 26; i++) {
                    // Append the count of each character to the id string
                    // This will create a unique key for each anagram group
                    id += (to_string (char_set[i]) + ',');
                }
                // Push the original string into the vector corresponding to the sorted string key
                // This will group all anagrams together in the map
                m[id].push_back (s);
            }
    
            vector <vector <string>> ans;
            for (const auto& i: m) {
                ans.emplace_back (i.second);
            }
            return ans;
        }
        // time complexity: O(n * k) where n is the number of strings and k is the maximum length of a string
        // space complexity: O(n * k) for storing the strings in the map
    };

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        vector<vector<string>> ans;
        // create a map of string and vector of strings
        // where key is the sorted string and value is the vector of strings
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            // sort the string and put it in the map
            // the key will be the sorted string and value will be the original string
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(s);
        }

        // now simply put the elements  of second column of map in ans

        for (auto i : mp)
        {
            // i.first is the key and i.second is the value
            // i.second is the vector of strings
            ans.push_back(i.second);
        }

        return ans;
    }
    // time complexity: O(n * klogk) where n is the number of strings and k is the maximum length of a string
    // space complexity: O(n * k) for storing the strings in the map
};