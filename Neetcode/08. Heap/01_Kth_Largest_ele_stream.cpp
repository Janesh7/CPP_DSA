// 703. Kth Largest Element in a Stream

// You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

// You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

// Implement the KthLargest class:

// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
// int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

// Example 1:

// Input:
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

// Output: [null, 4, 5, 5, 8, 8]

// Explanation:

// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3); // return 4
// kthLargest.add(5); // return 5
// kthLargest.add(10); // return 5
// kthLargest.add(9); // return 8
// kthLargest.add(4); // return 8

// Example 2:

// Input:
// ["KthLargest", "add", "add", "add", "add"]
// [[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

// Output: [null, 7, 7, 7, 8]

// Explanation:

// KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
// kthLargest.add(2); // return 7
// kthLargest.add(10); // return 7
// kthLargest.add(9); // return 7
// kthLargest.add(9); // return 8
 

// Constraints:

// 0 <= nums.length <= 104
// 1 <= k <= nums.length + 1
// -104 <= nums[i] <= 104
// -104 <= val <= 104
// At most 104 calls will be made to add.

#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    // Min-heap to maintain the top K largest elements.
    // The smallest of the K largest elements will be at the top.
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // Stores the required K-th largest element position
    int K;

public:
    // Constructor takes the integer k and a vector of initial numbers
    KthLargest(int k, vector<int>& nums) : K(k) {
        // We iterate through each number in the input array
        for (int i : nums) {
            // Here we could have just called the add function
            if (min_heap.size() < K) {
                // If the heap hasn't yet reached size K, push the element.
                min_heap.push(i);
            } else if (i > min_heap.top()) {
                // If the heap already has K elements and the current element
                // is larger than the smallest in the heap (i.e., min_heap.top()),
                // we pop the smallest and insert the current element.
                // This ensures we always keep the K largest elements.
                min_heap.pop();
                min_heap.push(i);
            }
            // If the current element is smaller than or equal to min_heap.top()
            // and the heap is already size K, we skip it (since it's not in the top K).
        }
    }

    // Adds a new value to the stream and returns the K-th largest element
    int add(int val) {
        // We must first check if the heap has fewer than K elements.
        // Even with the given constraints, this is required.
        //
        // Here's why:
        // Constraint: 1 <= k <= nums.length + 1
        // -> This means nums could be empty (length == 0), and k == 1 is still valid.
        //
        // Example:
        //   vector<int> nums = {};  // empty input
        //   int k = 1;
        //   KthLargest obj(k, nums);
        //   obj.add(5); // First value in stream
        //
        // Without this check, the heap would be empty, and accessing top() would be undefined behavior.
        if (min_heap.size() < K) {
            min_heap.push(val);
        } else if (val > min_heap.top()) {
            // If the new value is larger than the smallest of the current top K,
            // replace the smallest with the new value to maintain top K elements.
            min_heap.pop();
            min_heap.push(val);
        }

        // Return the smallest element in the heap, which is the K-th largest overall.
        return min_heap.top();
    }
    // time complexity: O(log K) for add operation
    // space complexity: O(K) for the min-heap to store the K largest elements
};
