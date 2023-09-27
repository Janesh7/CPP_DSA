#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// FIND MAX ELE IN WINDOW

void slidingWindow(const vector<int> &nums, int windowSize)
{
    deque<int> dq; // Create a deque to store elements in the sliding window

    // Process the first window
    for (int i = 0; i < windowSize; ++i)
    {
        // Remove elements from the back of the deque that are smaller than the current element
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i); //PUSHING INDEX
    }

    // Process the remaining windows
    for (int i = windowSize; i < nums.size(); ++i)
    {
        // Print the maximum element in the current window (front of the deque)
        cout << nums[dq.front()] << " ";

        // Remove elements from the front of the deque that are out of the current window
        while (!dq.empty() && dq.front() <= i - windowSize)
        {
            dq.pop_front();
        }

        // Remove elements from the back of the deque that are smaller than the current element
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    // Print the maximum element in the last window
    cout << nums[dq.front()] << " ";
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int windowSize = 3;

    slidingWindow(nums, windowSize);

    return 0;
}
