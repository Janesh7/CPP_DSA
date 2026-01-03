// 155. Min Stack

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

// Constraints:

// -231 <= val <= 231 - 1
// Methods pop, top and getMin operations will always be called on non-empty stacks.
// At most 3 * 104 calls will be made to push, pop, top, and getMin.

// Two stack approach

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MinStack
{

    // Two stacks are used to keep track of the minimum element and the main stack.
    // The main stack (st) stores all the elements, while the second stack (min_st) keeps track of the minimum element.
    stack<int> st;
    stack<int> min_st;

public:
    MinStack()
    {
    }

    void push(int val)
    {

        st.push(val);

        // If the minimum stack is empty or the current value is less than or equal (Imp for duplicate values) to the top of the minimum stack, push it onto the minimum stack.
        if (min_st.empty() || min_st.top() >= val)
        {
            min_st.push(val);
        }
    }

    void pop()
    {

        // If the top of the minimum stack is equal to the top of the main stack, pop it from the minimum stack.
        if (min_st.top() == st.top())
        {
            min_st.pop();
        }

        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return min_st.top();
    }
};
// time complexity of all the operations is O(1) because we are using two stacks to keep track of the minimum element and the main stack.
// The space complexity is O(n) because we are storing all the elements in the main stack and the minimum stack.

// most optimized as per lc

class MinStack
{

    // Using a vector of pairs to store the value and the minimum value at that point.
    // The first element of the pair is the value, and the second element is the minimum value.
    vector<pair<int, int>> min_st;

public:
    MinStack()
    {
    }

    void push(int val)
    {

        // If the minimum stack is empty, push the current value and set it as the minimum.
        // Otherwise, push the current value and the minimum of the current value and the last minimum value.
        min_st.empty() ? min_st.push_back({val, val}) : min_st.push_back({val, min(val, min_st.back().second)});
    }

    void pop()
    {

        min_st.pop_back();
    }

    int top()
    {

        return min_st.back().first;
    }

    int getMin()
    {

        return min_st.back().second;
    }
};

// time complexity of all the operations is O(1) because we are using a vector of pairs to keep track of the minimum element and the main stack.
// The space complexity is O(n) because we are storing all the elements in the vector of pairs.

// Another maths approach

// Intuition
// The problem requires implementing a stack with additional functionality to retrieve the minimum element in constant time. The straightforward approach would be to use an additional stack to keep track of the minimum values, but this solution employs a more space-efficient technique using mathematical encoding.

// Approach
// This implementation uses a single stack and a variable to track the current minimum value. The key insight is encoding values that are smaller than the current minimum:

//  1. We store the actual values if they're greater than or equal to the current minimum
//  2. When pushing a value smaller than the current minimum, we:
//      - Store an encoded value: 2 * val - min (which will always be less than the new minimum)
//      - Update the minimum to this new value
//  3. When retrieving the top element:
//      - If the top of the stack is greater than or equal to the minimum, return it directly
//      - If it's less than the minimum, return the minimum (as the real value was encoded)
//  4. When popping an element:
//      - If the top is less than the minimum (encoded value), we recover the previous minimum using the formula: oldMin = 2 * currentMin - encodedValue
//      - Then update the minimum and pop the stack
// This encoding scheme allows us to recover the previous minimum when we pop a value that was the minimum at insertion time.

// Complexity
// Time complexity: O(1) for all operations (push, pop, top, getMin)

// Space complexity: O(n)

class MinStack
{
public:
    stack<long long> st; // Main stack to store values or encoded values
    long long mn;        // Current minimum value in the stack

    // Initialize an empty stack with minimum set to largest possible value
    MinStack()
    {
        mn = LLONG_MAX;
    }

    // Push a value onto the stack with special encoding for new minimums
    void push(int x)
    {
        long long val = (long long)x;
        if (st.size() == 0)
        {
            // First element case - simply push and set as minimum
            st.push(val);
            mn = val;
        }
        else if (val >= mn)
        {
            // For values >= current minimum, push the actual value
            st.push(val);
        }
        else
        {
            // For values < current minimum:
            // 1. Push encoded value: 2*val - mn (will always be < val when val < mn)
            // 2. Update minimum to the new value
            st.push(2 * val - mn);
            mn = val;
        }
    }

    // Pop the top element from the stack
    void pop()
    {
        if (st.top() < mn)
        {
            // If top is encoded (less than min), calculate and restore previous minimum
            int OldMin = 2 * mn - st.top();
            mn = OldMin;
        }
        st.pop();
    }

    // Return the top element of the stack
    int top()
    {
        if (mn > st.top())
            // If top is an encoded value, return the current minimum (actual value)
            return (int)mn;
        // Otherwise return the actual top value
        return (int)st.top();
    }

    // Return the minimum element in constant time
    int getMin()
    {
        return (int)mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */