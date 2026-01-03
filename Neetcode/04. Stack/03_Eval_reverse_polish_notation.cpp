// 150. Evaluate Reverse Polish Notation

// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:

// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22

// Constraints:

// 1 <= tokens.length <= 104
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {

        stack<int> st;

        for (string i : tokens)
        {

            if (i == "+")
            {

                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                st.push(op1 + op2);
            }
            else if (i == "-")
            {

                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                st.push(op1 - op2);
            }
            else if (i == "*")
            {

                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                st.push(op1 * op2);
            }
            else if (i == "/")
            {

                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                st.push(op1 / op2);
            }
            else
            {

                st.push(stoi(i));
            }
        }

        return st.top();
    }
};

// 1. Brute Force
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        while (tokens.size() > 1)
        {
            for (int i = 0; i < tokens.size(); i++)
            {
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
                {
                    int a = stoi(tokens[i - 2]);
                    int b = stoi(tokens[i - 1]);
                    int result = 0;
                    if (tokens[i] == "+")
                        result = a + b;
                    else if (tokens[i] == "-")
                        result = a - b;
                    else if (tokens[i] == "*")
                        result = a * b;
                    else if (tokens[i] == "/")
                        result = a / b;

                    tokens.erase(tokens.begin() + i - 2, tokens.begin() + i + 1);
                    tokens.insert(tokens.begin() + i - 2, to_string(result));
                    break;
                }
            }
        }
        return stoi(tokens[0]);
    }
};
// Time & Space Complexity
// Time complexity:
// O(n^2) in the worst case, where n is the number of tokens. This is because we may need to iterate through the entire list of tokens for each operation.
// Space complexity:
// O(n)

// 2. Doubly Linked List
class DoublyLinkedList
{
public:
    string val;
    DoublyLinkedList *next;
    DoublyLinkedList *prev;

    DoublyLinkedList(string val, DoublyLinkedList *next = nullptr,
                     DoublyLinkedList *prev = nullptr)
    {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        DoublyLinkedList *head = new DoublyLinkedList(tokens[0]);
        DoublyLinkedList *curr = head;

        for (int i = 1; i < tokens.size(); i++)
        {
            curr->next = new DoublyLinkedList(tokens[i], nullptr, curr);
            curr = curr->next;
        }

        int ans = 0;
        while (head != nullptr)
        {
            if (head->val == "+" ||
                head->val == "-" ||
                head->val == "*" ||
                head->val == "/")
            {
                int l = stoi(head->prev->prev->val);
                int r = stoi(head->prev->val);
                int res = 0;
                if (head->val == "+")
                {
                    res = l + r;
                }
                else if (head->val == "-")
                {
                    res = l - r;
                }
                else if (head->val == "*")
                {
                    res = l * r;
                }
                else
                {
                    res = l / r;
                }

                head->val = to_string(res);
                head->prev = head->prev->prev->prev;
                if (head->prev != nullptr)
                {
                    head->prev->next = head;
                }
            }

            ans = stoi(head->val);
            head = head->next;
        }

        return ans;
    }
};
// Time & Space Complexity
// Time complexity:
// O(n)
// Space complexity:
// O(n)

// 3. Recursion
class Solution
{
public:
    int dfs(vector<string> &tokens)
    {
        string token = tokens.back();
        tokens.pop_back();

        if (token != "+" && token != "-" &&
            token != "*" && token != "/")
        {
            return stoi(token);
        }

        int right = dfs(tokens);
        int left = dfs(tokens);

        if (token == "+")
        {
            return left + right;
        }
        else if (token == "-")
        {
            return left - right;
        }
        else if (token == "*")
        {
            return left * right;
        }
        else
        {
            return left / right;
        }
    }

    int evalRPN(vector<string> &tokens)
    {
        return dfs(tokens);
    }
};
// Time & Space Complexity
// Time complexity:
// O(n)
// Space complexity:
// O(n)

// 4. Stack
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stack;
        for (const string &c : tokens)
        {
            if (c == "+")
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b + a);
            }
            else if (c == "-")
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b - a);
            }
            else if (c == "*")
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b * a);
            }
            else if (c == "/")
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b / a);
            }
            else
            {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};
// Time & Space Complexity
// Time complexity:
// O(n)
// Space complexity:
// O(n)