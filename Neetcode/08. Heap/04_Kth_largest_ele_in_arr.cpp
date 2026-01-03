// 215. Kth Largest Element in an Array

// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4
 

// Constraints:

// 1 <= k <= nums.length <= 105
// -104 <= nums[i] <= 104

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Sorting
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
// Time complexity: O(n log n) due to sorting
// Space complexity: O(1) for in-place sorting, O(n) if using a separate array for sorting. We are using in-place sorting here.

// Min-Heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Use a min-heap to keep track of the k largest elements
        // The top of the min-heap will be the k-th largest element
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            // Push the current number into the min-heap
            // If the size of the min-heap exceeds k, pop the smallest element
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
    // Time complexity: O(n log k) where n is the number of elements in nums
    // Space complexity: O(k) for the min-heap to store k elements
};

// TLE
class Solution {
public:
    // Main function to find the K-th largest element in the array
    int findKthLargest(vector<int>& nums, int k) {
        // The K-th largest in a sorted array corresponds to (n - k)-th index in 0-based index
        // For example, if array = [1, 2, 3, 4, 5] and k = 2 (2nd largest), the answer is 4,
        // which is at index 5 - 2 = 3
        int targetIndex = nums.size() - k;

        // Call the Quickselect algorithm on the full array
        return quickSelect(nums, 0, nums.size() - 1, targetIndex);
    }

    // Quickselect helper function (similar to quicksort but only goes one side)
    // Basically selecting the K-th largest element using partitioning and if its K then found otherwise check in other partition
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        // Choose the pivot as the rightmost element for simplicity
        int pivot = nums[right];

        // 'p' will track the index where we'll place elements <= pivot
        int p = left;

        // Partition the array so that:
        // - elements <= pivot are moved to the left of p
        // - elements > pivot stay in place (they'll end up on the right)
        for (int i = left; i < right; ++i) {
            if (nums[i] <= pivot) {
                // Swap element at i with element at p (partition index)
                // This ensures that everything <= pivot is on the left
                swap(nums[p], nums[i]);
                p++; // Move partition index to next position
            }
        }

        // After the loop, swap the pivot into its final position
        // This ensures all elements left of p are <= pivot,
        // and all elements right of p are > pivot
        swap(nums[p], nums[right]);

        // Now we check the position of the pivot after partition
        if (p > k) {
            // If pivot index is greater than k, the desired element is in the left subarray
            return quickSelect(nums, left, p - 1, k);
        } else if (p < k) {
            // If pivot index is less than k, the desired element is in the right subarray
            return quickSelect(nums, p + 1, right, k);
        } else {
            // If pivot index == k, we've found the K-th largest element
            return nums[p];
        }
    }
    // Time complexity: O(n) on average, O(n^2) in the worst case (rare with good pivot choice).
    // n^2 can happen if the pivot is always the smallest or largest element. For example, if the array is already sorted or reverse sorted.
    // Like for largest element, if we always choose the last element as pivot, so the right partition will always be empty and we will have to check the left partition which is of size n-1, then n-2, and so on.
    // Space complexity: O(1) for the in-place partitioning, O(log n) for the recursion stack.

};


// Quickselect optimised using median of three strategy
// --- Median-of-Three Logic ---
// This is used to choose a better pivot to avoid worst-case performance in QuickSelect or QuickSort.
// It rearranges three elements — nums[left], nums[mid], and nums[right] — so that the median of these
// three ends up at nums[left + 1], which is then used as the pivot.

// Step 1: swap(nums[mid], nums[left + 1])
// Why this step:
// We move the middle element to left + 1 so we can easily compare and organize the three values.
// This prepares for the next two swaps that will help place the median in the middle position.
// Example:
// nums = [4, 1, 2, 5, 6, 3], left = 0, right = 5, mid = 2 (nums[mid] = 2)
// After swap: nums = [4, 2, 1, 5, 6, 3]

// Step 2: if (nums[left] < nums[right]) swap(nums[left], nums[right]);
// Why this step:
// Ensure that nums[left] holds the largest of the three values so far.
// We want nums[left] ≥ nums[right]
// Example:
// nums = [4, 2, 1, 5, 6, 3] → nums[left] = 4, nums[right] = 3 → 4 < 3 → false → no swap

// Step 3: if (nums[left + 1] < nums[right]) swap(nums[left + 1], nums[right]);
// Why this step:
// Make sure nums[left + 1] is ≥ nums[right], so that the smallest value is pushed toward the right.
// This helps ensure the median ends up in the middle.
// Example:
// nums = [4, 2, 1, 5, 6, 3] → nums[left + 1] = 2, nums[right] = 3 → 2 < 3 → true → swap
// nums becomes: [4, 3, 1, 5, 6, 2]

// Step 4: if (nums[left] < nums[left + 1]) swap(nums[left], nums[left + 1]);
// Why this step:
// Finally, ensure nums[left] ≥ nums[left + 1], so that the median ends up at nums[left + 1]
// After this, nums[left + 1] holds the pivot (median of the three), and the partitioning starts
// Example:
// nums = [4, 3, 1, 5, 6, 2] → 4 < 3 → false → no swap
//
// After these steps, the median of nums[left], nums[mid], and nums[right] is placed at nums[left + 1]

class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        // Use median-of-three strategy to choose a better pivot
        int mid = (left + right) >> 1;

        // Move the mid value to position left + 1 (so we can easily work with left, left+1, right)
        swap(nums[mid], nums[left + 1]);

        // Ensure nums[left] is greater than nums[right]
        // Helps with descending order partitioning (for K-th largest)
        if (nums[left] < nums[right])
            swap(nums[left], nums[right]);

        // Ensure nums[left + 1] is not smaller than nums[right]
        // Moves a larger element to left+1 if needed
        if (nums[left + 1] < nums[right])
            swap(nums[left + 1], nums[right]);

        // Ensure nums[left] is the largest among the three (left, left+1, right)
        if (nums[left] < nums[left + 1])
            swap(nums[left], nums[left + 1]);

        // Now nums[left+1] holds the pivot (median of left, mid, right)
        int pivot = nums[left + 1];
        int i = left + 1;
        int j = right;

        // Partitioning loop
        while (true) {
            // Move i right while nums[i] > pivot (since we want descending order)
            while (nums[++i] > pivot);

            // Move j left while nums[j] < pivot
            while (nums[--j] < pivot);

            // If pointers cross, partitioning is done
            if (i > j) break;

            // Swap out-of-place elements
            swap(nums[i], nums[j]);
        }

        // Place pivot in its correct position
        nums[left + 1] = nums[j];
        nums[j] = pivot;

        // Return final position of pivot
        return j;
    }

    int quickSelect(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;

        // Iterative quickselect loop
        while (true) {
            // If only one or two elements are left, handle them directly
            if (right <= left + 1) {
                if (right == left + 1 && nums[right] > nums[left])
                    swap(nums[left], nums[right]);
                return nums[k];
            }

            // Partition the current subarray and get pivot position
            int j = partition(nums, left, right);

            // Adjust search range based on pivot's position
            if (j >= k) right = j - 1;
            if (j <= k) left = j + 1;
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        // k-th largest is at index k - 1 in 0-based index (if sorted in descending order)
        return quickSelect(nums, k - 1);
    }
};
// Time complexity: O(n) on average, O(n^2) in the worst case (rare with good pivot choice).
// Space complexity: O(1) for in-place partitioning, O(log n) for the recursion stack in the recursive version, but O(1) in this iterative version.

// This is different from median of medians, which is a more complex algorithm that guarantees O(n) time complexity in the worst case.
/*
Median of Medians Algorithm (a.k.a BFPRT Algorithm)
This is a deterministic, worst-case optimal algorithm for selecting the k-th smallest/largest element in linear time (O(n)).

How it works:
Divide the array into groups of 5 elements.

Sort each group and pick the median.

Recursively find the median of these medians — this becomes your pivot.

Partition the array around this pivot and recurse as needed.

Goal:
Guaranteed good pivot that ensures good balance

Ensures worst-case linear time for selection

Time complexity: O(n) worst-case
Trade-off:
Slower in practice due to constant overhead

Used only when guaranteed performance is critical (e.g., theoretical computer science, some system-level applications)
*/