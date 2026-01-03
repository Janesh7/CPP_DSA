#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// Approach: 1. Next smaller element and previous smaller element

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        stack<int> st;
        int n = heights.size();
        // prev smaller nums, -1 when we dont find any
        // it's -1 coz when we put in the area formula (next_smallest[i] - prev_smallest[i] - 1); it'll make it positive and +1 and -1 will cancel so width will be just next_smallest[i]
        vector<int> prev_smallest(n, -1);
        // next smaller nums, we cant have this as -1 as that would make the area negative (possibly), so we initialize with n when we dont find any because it's the end
        vector<int> next_smallest(n, n);

        // next smallest
        for (int i = 0; i < n; i++)
        {

            // if the current height is less than the top of the stack, we pop the stack and set the next smallest for that index to the current index ie we found a smaller element
            while (!st.empty() && heights[i] < heights[st.top()])
            {

                next_smallest[st.top()] = i;
                st.pop();
            }

            // push the current index to the stack
            // this is important because we need to find the next smallest for the current index, so we push it to the stack
            st.push(i);
        }

        // clear the stack for the next iteration
        while (!st.empty())
        {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {

            // if the current height is less than the top of the stack, we pop the stack and set the prev smallest for that index to the current index ie we found a smaller element
            while (!st.empty() && heights[i] < heights[st.top()])
            {

                prev_smallest[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        int max_area = 0;

        for (int i = 0; i < n; i++)
        {

            // calculate the area for each index using the formula area = height * width
            // height is the current height and width is the difference between the next smallest and prev smallest indices and -1 because we need to exclude the current index from the width
            int area = heights[i] * (next_smallest[i] - prev_smallest[i] - 1);
            max_area = area > max_area ? area : max_area;
        }

        return max_area;
    }
};

// Approach: 2. Stack approach (1 pass)

/*
    Approach: Monotonic Increasing Stack

    Intuition:
    - We're trying to find the largest rectangle that can be formed in a histogram.
    - For each bar, we want to know how far we can extend it to the left and right while maintaining at least its height.
    - A monotonic increasing stack helps us efficiently track bars where heights are in increasing order.
    - When we encounter a bar that is shorter than the top of the stack, we calculate the area for the bar at the top,
      treating the current index as the right boundary.

    Steps:
    1. Use a stack to store indices of increasing heights.
    2. Iterate through the histogram up to index n (we simulate an extra bar of height 0 at the end).
    3. If the current bar is shorter than the one at the stack's top:
       - Pop from the stack and calculate area with the popped height.
       - Width is determined by the current index and the new top of the stack.
    4. Push the current index onto the stack.
    5. At the end, maxArea holds the largest rectangle found.

    Time Complexity: O(n) — each bar is pushed and popped at most once.
    Space Complexity: O(n) — for the stack.
*/

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        // we iterate till n+1 to make sure we pop all the bars in the stack
        // this is to evaluate the stack even when we reach the end of the histogram
        for (int i = 0; i <= n; ++i)
        {
            // we are adding a 0 height bar at the end to make sure we pop all the bars in the stack
            int currentHeight = (i == n) ? 0 : heights[i];

            // we are looking for a bar where height is smaller then the previous
            // ones as it will be breaking the past contigous height area
            while (!st.empty() && heights[st.top()] > currentHeight)
            {
                // represents current height
                int height = heights[st.top()];
                // pop the top element from the stack because we are evaluating it now
                st.pop();
                // if the stack is empty, it means we can take the whole width from 0 to i
                // if the stack is not empty, we can take the width from the top of the stack to i because the top of the stack is the last bar that is smaller than the current height
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            // push the current index to the stack
            st.push(i);
        }

        return maxArea;
    }
};

// Other approaches

// The idea is simple: for a given range of bars, the maximum area can either from left or right half of the bars, or from the area containing the middle two bars. For the last condition, expanding from the middle two bars to find a maximum area is O(n), which makes a typical Divide and Conquer solution with T(n) = 2T(n/2) + O(n). Thus the overall complexity is O(nlgn) for time and O(1) for space (or O(lgn) considering stack usage).

// Following is the code accepted with 44ms. I posted this because I didn't find a similar solution, but only the RMQ idea which seemed less straightforward to me.

class Solution
{
    int maxCombineArea(const vector<int> &height, int s, int m, int e)
    {
        // Expand from the middle to find the max area containing height[m] and height[m+1]
        int i = m, j = m + 1;
        int area = 0, h = min(height[i], height[j]);
        while (i >= s && j <= e)
        {
            h = min(h, min(height[i], height[j]));
            area = max(area, (j - i + 1) * h);
            if (i == s)
            {
                ++j;
            }
            else if (j == e)
            {
                --i;
            }
            else
            {
                // if both sides have not reached the boundary,
                // compare the outer bars and expand towards the bigger side
                if (height[i - 1] > height[j + 1])
                {
                    --i;
                }
                else
                {
                    ++j;
                }
            }
        }
        return area;
    }
    int maxArea(const vector<int> &height, int s, int e)
    {
        // if the range only contains one bar, return its height as area
        if (s == e)
        {
            return height[s];
        }
        // otherwise, divide & conquer, the max area must be among the following 3 values
        int m = s + (e - s) / 2;
        // 1 - max area from left half
        int area = maxArea(height, s, m);
        // 2 - max area from right half
        area = max(area, maxArea(height, m + 1, e));
        // 3 - max area across the middle
        area = max(area, maxCombineArea(height, s, m, e));
        return area;
    }

public:
    int largestRectangleArea(vector<int> &height)
    {
        if (height.empty())
        {
            return 0;
        }
        return maxArea(height, 0, height.size() - 1);
    }
};

// SEGMENT TREE
// The idea is to build a segment tree, where each node contains the index of the minimum height in the range. The area can be calculated by finding the minimum height in the range and multiplying it by the width of the range. The time complexity is O(nlogn) for building the segment tree and O(logn) for each query.
// The space complexity is O(n) for the segment tree.
// Largest Rectangle in Histogram
// Stack solution, O(NlogN) solution

class SegTreeNode
{
public:
    int start;
    int end;
    int min;
    SegTreeNode *left;
    SegTreeNode *right;
    SegTreeNode(int start, int end)
    {
        this->start = start;
        this->end = end;
        left = right = NULL;
    }
};

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        if (heights.size() == 0)
            return 0;
        // first build a segment tree
        SegTreeNode *root = buildSegmentTree(heights, 0, heights.size() - 1);
        // next calculate the maximum area recursively
        return calculateMax(heights, root, 0, heights.size() - 1);
    }

    int calculateMax(vector<int> &heights, SegTreeNode *root, int start, int end)
    {
        if (start > end)
        {
            return -1;
        }
        if (start == end)
        {
            return heights[start];
        }
        int minIndex = query(root, heights, start, end);
        int leftMax = calculateMax(heights, root, start, minIndex - 1);
        int rightMax = calculateMax(heights, root, minIndex + 1, end);
        int minMax = heights[minIndex] * (end - start + 1);
        return max(max(leftMax, rightMax), minMax);
    }

    SegTreeNode *buildSegmentTree(vector<int> &heights, int start, int end)
    {
        if (start > end)
            return NULL;
        SegTreeNode *root = new SegTreeNode(start, end);
        if (start == end)
        {
            root->min = start;
            return root;
        }
        else
        {
            int middle = (start + end) / 2;
            root->left = buildSegmentTree(heights, start, middle);
            root->right = buildSegmentTree(heights, middle + 1, end);
            root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;
            return root;
        }
    }

    int query(SegTreeNode *root, vector<int> &heights, int start, int end)
    {
        if (root == NULL || end < root->start || start > root->end)
            return -1;
        if (start <= root->start && end >= root->end)
        {
            return root->min;
        }
        int leftMin = query(root->left, heights, start, end);
        int rightMin = query(root->right, heights, start, end);
        if (leftMin == -1)
            return rightMin;
        if (rightMin == -1)
            return leftMin;
        return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
    }
};
// understand via https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-using-segment-tree/