// Solution for generating well-formed parentheses combinations
// Problem: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Time Complexity: Explained for each approach
// Space Complexity: Explained for each approach

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Brute Force Approach
    // Idea: Generate all possible combinations of '(' and ')' of length 2n and check if it's valid.
    // The check function ensures that the combination is valid by checking the balance of parentheses.
    bool valid(const string& s) {
        int open = 0;
        for (char c : s) {
            open += (c == '(') ? 1 : -1;
            if (open < 0) return false;  // Invalid if at any point there are more closing parentheses
        }
        return open == 0;  // Valid if all parentheses are balanced
    }

    void dfs(string s, vector<string>& res, int n) {
        if (s.length() == 2 * n) {  // Base case: we have a string of length 2n
            if (valid(s)) res.push_back(s);  // If valid, add to result
            return;
        }
        // Recursively try adding both '(' and ')'
        dfs(s + '(', res, n);
        dfs(s + ')', res, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("", res, n);  // Start DFS with an empty string
        return res;
    }

    // Time Complexity: O(2^2n * n), worst case every string has 2n length and we generate all combinations.
    // Space Complexity: O(2^2n * n), storing all possible combinations in the result.
    
    // -------------------------------------------------------------------------------------------------------------------------
    
    // Backtracking Approach
    // Idea: This is a backtracking approach where we try adding both '(' and ')', but only if it's valid to do so.
    // We keep track of the number of opened and closed parentheses.
    void backtrack(int openN, int closedN, int n, vector<string>& res, string& stack) {
        if (openN == closedN && openN == n) {  // Base case: when we've used all n pairs
            res.push_back(stack);  // Add the valid combination to the result
            return;
        }

        // Add an open parenthesis if we haven't yet used n '('
        if (openN < n) {
            stack += '(';
            backtrack(openN + 1, closedN, n, res, stack);
            stack.pop_back();  // Backtrack
        }
        
        // Add a closed parenthesis if it won't exceed the number of open parentheses
        if (closedN < openN) {
            stack += ')';
            backtrack(openN, closedN + 1, n, res, stack);
            stack.pop_back();  // Backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0, 0, n, res, stack);  // Start with 0 open and 0 closed parentheses
        return res;
    }

    // time Complexity: O(4^n / sqrt(n)), as we generate all possible combinations and filter valid ones.
    // We get this complexity because the number of valid combinations of parentheses is given by the Catalan number C(n) = (2n)! / ((n + 1)! * n!) and this number found using the formula C(n) = 4^n / (n^(3/2) * sqrt(pi))
    // Space Complexity: O(n), for the recursion stack and the result storage.
    
    // -------------------------------------------------------------------------------------------------------------------------
    
    // Dynamic Programming Approach
    // Idea: We use a dynamic programming approach where res[i] stores all valid parentheses combinations for i pairs.
    // The combinations for res[k] are formed by combining the valid combinations for smaller values of i and k-i-1.
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> res(n + 1);
        res[0] = {""};  // Base case: one way to form an empty string

        // Build combinations for each k, from 1 to n
        for (int k = 1; k <= n; ++k) {
            for (int i = 0; i < k; ++i) {
                for (const string& left : res[i]) {
                    for (const string& right : res[k - i - 1]) {
                        res[k].push_back("(" + left + ")" + right);  // Combine valid left and right parts
                    }
                }
            }
        }

        return res[n];  // Return the result for n pairs of parentheses
    }

    // Time Complexity: O(4^n / sqrt(n)), as we generate all possible combinations and filter valid ones.
    // Space Complexity: O(n), for the recursion stack and the result storage.
    
    // -------------------------------------------------------------------------------------------------------------------------
};
