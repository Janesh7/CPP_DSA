// 1502. Can Make Arithmetic Progression From Sequence
// Easy
// 1.7K
// 83
// Companies
// A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

// Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

 

// Example 1:

// Input: arr = [3,5,1]
// Output: true
// Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
// Example 2:

// Input: arr = [1,2,4]
// Output: false
// Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
 

// Constraints:

// 2 <= arr.length <= 1000
// -106 <= arr[i] <= 106


// Sorting

// Approach:
// Sort the given array in ascending order.
// Calculate the common difference by subtracting the second element from the first element.
// Iterate through the remaining elements of the sorted array and check if the difference between the current element and the previous element is equal to the common difference. If not, return false.
// If we finish iterating through all the elements without finding any inconsistencies, return true.
// Intuition:
// The approach for this problem relies on the fact that in an arithmetic progression, the difference between any two consecutive elements is constant. By sorting the array, we ensure that the elements are in ascending order, making it easier to check for a consistent difference. We calculate the common difference and then iterate through the sorted array to verify that the difference between each pair of consecutive elements matches the common difference. If at any point the difference does not match, we know that the array does not form an arithmetic progression. If we reach the end of the iteration without finding any inconsistencies, we conclude that the array forms an arithmetic progression.


class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];

        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] != diff) {
                return false;
            }
        }

        return true;
    }
};


// Without Sorting

// Approach:
// Initialize variables length, min_val, and max_val.
// Iterate through the array to find the minimum and maximum values.
// Calculate the common difference using the formula (max_val - min_val) / (length - 1).
// Iterate through the array and for each element, calculate the expected value based on the minimum value and the index multiplied by the common difference.
// Check if the expected value exists in the array. If not, return false.
// If all expected values are found, return true.
// Intuition:
// The approach for this problem involves finding the minimum and maximum values in the array to determine the range. From the range, we calculate the common difference, assuming the array forms an arithmetic progression. Then, we iterate through the array and check if each element matches the expected value based on the minimum value and the index multiplied by the common difference. If any element deviates from the expected value, we can conclude that the array does not form an arithmetic progression. If all elements match the expected values, we conclude that the array forms an arithmetic progression.



class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        int length = arr.size();
        int min_val = INT_MAX;
        int max_val = INT_MIN;

        for (int num : arr) {
            min_val = std::min(min_val, num);
            max_val = std::max(max_val, num);
        }

        double diff = static_cast<double>(max_val - min_val) / (length - 1);

        for (int i = 0; i < length; i++) {
            double expected = min_val + i * diff;
            bool found = false;
            for (int num : arr) {
                if (std::abs(num - expected) < 1e-9) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }

        return true;
    }
};