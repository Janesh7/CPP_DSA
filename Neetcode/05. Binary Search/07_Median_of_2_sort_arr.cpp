// 4. Median of Two Sorted Arrays
// Hard

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    Approach

    Definition of the Median:
    The median is "the middle value when a sorted array is split exactly in half." 
    If the number of elements is odd, the median is the middle element.
    If it's even, the median is the average of the two middle elements.

    For example:
    [1, 5, 8] → 5  
    [1, 3, 5, 8] → 4 ( = (3 + 5) / 2 )

    The first idea that may come to mind is to merge the two arrays and extract the middle value.
    However, this approach has a time complexity of O((m + n) log(m + n)), which does not meet the O(log(m + n)) requirement.
    To achieve O(log(m + n)), we need to use binary search.
*/

/*
    Key to the Problem: Partition and Comparison

    The key to solving this problem efficiently is to "divide each array into left and right parts appropriately."

    Why Divide into Left and Right?
    The median is the "middle value when a sorted array is split exactly in half." 
    If the total number of elements is odd, it’s the one in the center.
    If even, it’s the average of the two central values.

    Therefore, we can compute the median by finding the maximum of the left half or the average of the max of the left and the min of the right.

    However, it's not always the case that all elements of nums1 are smaller than those of nums2, or vice versa.

    For example, if nums1 = [1, 2] and nums2 = [3, 4], you can simply append nums2 after nums1 to get [1, 2, 3, 4], which is sorted, and the median is 2.5.

    However, in the case of nums1 = [1, 3, 8] and nums2 = [7, 9, 10, 11], if we try to merge the arrays directly and sort them, we get [1, 3, 7, 8, 9, 10, 11], where the value 7 from nums2 is smaller than 8 from nums1. This means we can't simply merge the two arrays as-is. Therefore, we divide each array into left and right parts — the left parts of nums1 and nums2 form the "smaller group", and the right parts form the "larger group". We calculate the partition in such a way that the entire combined array would be sorted.

    Since actually merging and sorting the arrays would take more than O(log(m + n)) time, we simulate the sorted array using calculations instead.
    
    These partitions are not correct, but please look at them just to get an idea of how the algorithm works:

    nums1 = [1, 3, | 8]
    nums2 = [7 | 9, 10, 11]

    max_left1 = 3
    min_right1 = 8
    max_left2 = 7
    min_right2 = 9

    if max_left1 <= min_right2 and max_left2 <= min_right1
    = 3 <= 9 and 7 <= 8
    = true → array is correctly partitioned
    
    You don’t need to compare the left and right within the same array (like max_left1 <= min_right1), because both arrays are sorted individually based on what the question says.
*/

/*
    How to Determine Partitions
    The partition that determines the left and right sides is calculated using the binary search left and right.

    partition1 = (left + right) // 2
    partition2 = (len1 + len2 + 1) // 2 - partition1

    partition1: The number of elements on the left side of nums1
    partition2: The number of elements on the left side of nums2
    len1: The length of nums1
    len2: The length of nums2

    Regarding partition2, since both partition1 and partition2 represent the total number of elements on the left side, they should sum up to half the length of the merged nums1 and nums2. This gives the following equation:

    partition1 + partition2 = (len1 + len2 + 1) // 2
    To calculate partition2, it would be:

    partition2 = (len1 + len2 + 1) // 2 - partition1
*/

/*
    What does the +1 mean?
    
    When the total number of elements is even, the median is the average of the two central values.
    This means you add the left maximum value and the right minimum value, and then divide by 2.
    
    When the total number of elements is odd, the median is the single central value. By adding the central value to the left maximum value, the logic becomes consistent for both even and odd cases, simplifying the process.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for binary search efficiency
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int len1 = nums1.size(), len2 = nums2.size();
        int left = 0, right = len1;

        // Binary search loop on nums1
        while (left <= right) {
            // Partition nums1 and nums2
            int part1 = (left + right) / 2;  // Partition index in nums1
            int part2 = (len1 + len2 + 1) / 2 - part1;  // Partition index in nums2

            // Get max of left parts and min of right parts
            // We use INT_MIN and INT_MAX to handle edge cases such as empty partitions
            int maxLeft1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
            int minRight1 = (part1 == len1) ? INT_MAX : nums1[part1];
            int maxLeft2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
            int minRight2 = (part2 == len2) ? INT_MAX : nums2[part2];

            // Check if we have the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total number of elements is even, median is the average of the max of left and min of right
                if ((len1 + len2) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    // If odd, return the max of the left elements
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // Move the right pointer to the left if partition1 is too far right
                right = part1 - 1;
            } else {
                // Move the left pointer to the right if partition1 is too far left
                left = part1 + 1;
            }
        }

        // If no solution is found, return 0. This should never happen.
        return 0.0;        
    }
};

/*
    Step by Step Explanation:

    1. Ensure nums1 is the smaller array:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1);
        We always perform binary search on the smaller array to minimize the search space.

    2. Initialize variables:
        len1, len2 = len(nums1), len(nums2);
        left, right = 0, len1;
        These variables will help in performing binary search and setting up partitions.

    3. Binary Search Loop on nums1:
        while left <= right:
            In each iteration, we partition both arrays into left and right parts.
            part1 = (left + right) / 2;  // Partition index in nums1
            part2 = (len1 + len2 + 1) / 2 - part1;  // Partition index in nums2

    4. Get the maximum of the left part and minimum of the right part:
        max_left1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
        min_right1 = (part1 == len1) ? INT_MAX : nums1[part1];
        max_left2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
        min_right2 = (part2 == len2) ? INT_MAX : nums2[part2];
        These values define the current virtual "cut" in the combined array:
        [ ... max_left1 | min_right1 ... ]
        [ ... max_left2 | min_right2 ... ]

    5. Check if the partition is correct:
        if max_left1 <= min_right2 and max_left2 <= min_right1:
            If so, you've found the correct partition.

            If the total number of elements is even:
            return (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0;

            If the total number of elements is odd:
            return max(max_left1, max_left2);
        Else adjust the left and right bounds of the search to move toward the correct partition.

    6. Edge cases:
        The function handles edge cases like one of the arrays being empty, the arrays being of different sizes, etc. The binary search makes sure we find the correct median even if the arrays are not perfectly balanced.
*/

// time complexity: O(log(min(m, n))) where m and n are the lengths of the two arrays.
// space complexity: O(1) since we are using a constant amount of space.

// OTHER SOLUTION
// 1. Merge the two arrays and sort them, then find the median.
// 2. Use a two-pointer technique to merge the arrays in O(m + n) time and then find the median.

#include <vector>
using namespace std;

/*
    Approach:

    This approach is much simpler than the binary search method we discussed earlier, but it has a time complexity of O(m + n), where m and n are the lengths of the two input arrays `nums1` and `nums2`. It works by directly merging the arrays while keeping track of the current middle elements.

    Key Concept:
    - The idea is to merge the two sorted arrays as we go, but instead of fully merging them, we stop once we reach the middle of the combined array.
    - The middle element (or the average of the two middle elements, in the case of an even total length) is the median.
    
    This approach works efficiently for smaller arrays or when a direct merge is acceptable. But keep in mind that the time complexity is linear, which is not optimal for very large arrays (as the optimal solution has time complexity O(log(min(m, n)))).

    Let's break this down step-by-step.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();  // Length of the first array
        int m = nums2.size();  // Length of the second array
        
        int i = 0, j = 0;      // Pointers for nums1 and nums2 respectively
        int m1 = 0, m2 = 0;    // m1 and m2 store the current two middle elements

        // The idea is to merge the two arrays up to the middle, without fully merging.
        // The median is either the middle element (if odd length) or the average of the two middle elements (if even length).
        for (int count = 0; count <= (n + m) / 2; count++) {
            m2 = m1;  // Store the previous element (which will be used for calculating the average if needed)
            
            if (i != n && j != m) {  // If we haven't exhausted both arrays
                if (nums1[i] > nums2[j]) {
                    m1 = nums2[j++];  // Choose the smaller element from nums2 and move the pointer
                } else {
                    m1 = nums1[i++];  // Choose the smaller element from nums1 and move the pointer
                }
            } else if (i < n) {  // If nums2 is exhausted, but nums1 still has elements
                m1 = nums1[i++];  // Choose the next element from nums1
            } else {  // If nums1 is exhausted, but nums2 still has elements
                m1 = nums2[j++];  // Choose the next element from nums2
            }
        }

        // After the loop, m1 holds the current middle element.
        // Now, determine whether the total number of elements is odd or even.
        if ((n + m) % 2 == 1) {  // If the total number of elements is odd
            return static_cast<double>(m1);  // The middle element is the median
        } else {  // If the total number of elements is even
            double ans = static_cast<double>(m1) + static_cast<double>(m2);  // Average the two middle elements
            return ans / 2.0;  // Return the average as the median
        }
    }
    /*
        Time Complexity: O(m + n) where m and n are the lengths of the two arrays.
        Space Complexity: O(1) since we are using a constant amount of space for variables.
    */
};

/*
    Detailed Explanation:

    1. **Initialization:**
        - We first initialize two pointers `i` and `j` for `nums1` and `nums2` respectively. These pointers will be used to traverse the two arrays.
        - `m1` and `m2` will hold the current "middle" elements in the process.
        - The loop will iterate `count` times, stopping at the middle of the merged array (i.e., after `(n + m) / 2` iterations).

    2. **Merging Process:**
        - The algorithm works by comparing the current elements of both arrays and selecting the smaller of the two. The selected element is added to the merged sequence, and the pointer (`i` or `j`) of the respective array is moved forward.
        - We only keep track of the last two elements (`m1` and `m2`) during this process because the median is only dependent on the middle elements.
        - If one array is exhausted before the other, we simply continue with the remaining elements of the other array.

    3. **Check for Odd or Even Length of Combined Arrays:**
        - After we have reached the middle, the value of `m1` will be the last element we've processed (i.e., the current middle element of the merged arrays).
        - If the total length of the combined arrays is odd, `m1` is the median.
        - If the total length is even, the median is the average of `m1` and `m2`, which are the two middle elements in the combined array.

    4. **Edge Cases:**
        - This approach handles arrays of different sizes.
        - If one array is empty, the other array's elements directly represent the merged array.

    5. **Time Complexity:**
        - The time complexity of this approach is **O(m + n)**, where `m` and `n` are the sizes of `nums1` and `nums2` respectively. This is because we iterate through both arrays at most once, stopping once we find the median.

    6. **Space Complexity:**
        - The space complexity is **O(1)** as we only use a constant amount of extra space for variables like `m1`, `m2`, `i`, and `j`.

    **Example Walkthrough:**

    - Let nums1 = [1, 3, 8], nums2 = [7, 9, 10, 11].
    - The combined sorted array would be [1, 3, 7, 8, 9, 10, 11], and the middle elements are 8 and 7.
    - The loop will stop after 3 steps, with `m1` = 8 and `m2` = 7.
    - Since the combined length is odd (7 elements), the median is `8`.

    For the case where `nums1 = [1, 3]` and `nums2 = [2]`, the combined sorted array is [1, 2, 3], and the median is 2.

*/

