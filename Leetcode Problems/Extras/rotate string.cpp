// 796. Rotate String
// Easy



// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.
 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false
 

// Constraints:

// 1 <= s.length, goal.length <= 100
// s and goal consist of lowercase English letters.
class Solution {

private: 

    bool rotateString(string A, string B, int rotation) {

        for(int i = 0; i < A.length(); i++) {

            if(A[i] != B[(i+rotation)%B.length()]) {

                return false;

            }

        }

        return true;

    }

public:

    bool rotateString(string s, string goal) {

        if(s.length() != goal.length()) {

            return false;

        }

        if(s.length() == 0) {

            return true;

        }

        for(int i = 0; i < s.length(); i++) {

            if(rotateString(s, goal, i)) {

                return true;

            }

        }

        return false;

    }

};