# Arrays

- Stores only **similar**
- Contiguous storage units locations
- indexed
- Used when we want to store multiple values of same type as single structure, easier access
- When we **initialize an array, the pointer ( of the decalred variable) points to the first address of the memory location**



- **ADRESS CALC:** imagine an int array v, the v[0] points to loc 100 in memeory
    then v[index] memory location : 100 + 4(size of int)*i
- initialize with 0s : int array[1000000] = {0}; if we use {1} or any other const, only the first(or more) values are stored and rest 0s
- We can initialize th earray with any value by using the fill_n command
    Ex: int array[100];
        fill_n(array,100,1); // initializes with 1

- If we initialize an array with frewer values then  **its size then rest of the array elements r 0s**

- Dont keep the size of the array in the function declaration : int printfunc(int arr[],int lenght){}

- ^^Here we r passing the length in function coz if we have only initialized 2 elements in array of size 15,multiple 0s get printed aswell, therefore we can just send 2 as an argument

- we can get the length of any array using **sizeof()**:
    Ex: int lenght = sizeof(array)/sizeof(int) , 
        here we take the size of the memory location and divide it by the size of each ele, ie if array is of lenght 10, memory size:40,size of int:4

- **NOTE: initializing array like int arr[variable] is a VERY bad practise**

- **IMP NOTE: When we update the array normally passed to the function, the changes remain throughout the program as the var passed int arr[] stores the address to the first memory location. So making changes to it will reflect in main aswell.**




## Reverse an array

- We r tracing(pointer) the start and end  of the array, and swapping them then incrementing start and decrermenting end. 
- We use swap() function to swap. swap(arr[start],arr[stop]);
- We repeat till the end < start



## Unique element of the array
- Unique element Code Stduio Prob statement: Given an array,which has n elements(2m+1 elements). Where all elements appear exactly twice and there is exactly 1 elememt which appears only once .ie how 2m+1 where m is the number of duplicate elements.

- optiomized solution:
    - We kmnow that a^a = 0 ie XOR of the dsame element is always 0
    - So if we XOR all the elements we will get the single remaining element as 0^0^0^0^a = 0^a = a, where there were 4 ele having duplicates (8 ele)which gave the result 0s upon XORing.




--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


# Structured notes

## LEC 1

**Introduction to Arrays:**
- Arrays are a data structure that allows you to store a collection of similar items.
- They are used when you need to work with multiple values of the same type.

```cpp
// Declare an array of integers
int myArray[10];
```

**Indexes in Arrays:**
- Arrays are zero-indexed, meaning the first element has an index of 0, the second element has an index of 1, and so on.

```cpp
// Accessing elements in an array
int element = myArray[0]; // Accessing the first element
```

**Initialization in Arrays:**
- You can initialize an array at the time of declaration by providing values in curly braces.

```cpp
// Initializing an array
int numbers[5] = {1, 2, 3, 4, 5};
```

**Accessing in Array:**
- You can access array elements using indexes.

```cpp
int value = myArray[2]; // Accessing the third element
```

**Maximum/Minimum in an Array:**
- To find the maximum and minimum values in an array, you can use loops to iterate through the elements and keep track of the current maximum and minimum values.

```cpp
int maxVal = findMax(myArray, size);
int minVal = findMin(myArray, size);
```

**Scopes in Array:**
- When you pass an array to a function, you are actually passing a reference to the original array, so any changes made within the function will affect the original array.

```cpp
void modifyArray(int arr[], int size) {
    arr[0] = 42; // Modifying the original array
}
```

**Reverse an Array:**
- To reverse an array, you can use two pointers, one starting from the beginning and the other from the end, and swap elements until they meet in the middle.

```cpp
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        // Swap elements at start and end
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
```

**Linear Search in Array:**
- Linear search is a simple search algorithm that checks each element in the array one by one until it finds the desired element.

```cpp
bool linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return true; // Element found
        }
    }
    return false; // Element not found
}
```



## LEC 2


**Problem Statement:**
- Given an array, you need to swap alternate elements.
- For example, if you have an array [1, 2, 7, 8, 5], you should swap alternate elements to get [2, 1, 8, 7, 5].

**Approach:**
1. Use a loop to iterate through the array.
2. Inside the loop, check if `i + 1` is less than the size of the array to ensure you don't go out of bounds.
3. If it's within bounds, swap the elements at index `i` and `i + 1`.
4. Move the index `i` by 2 (i += 2) to handle alternating elements.

**Code Implementation (C++):**
```cpp
#include <iostream>

// Function to swap alternate elements in the array
void swapAlternate(int arr[], int size) {
    for (int i = 0; i + 1 < size; i += 2) {
        std::swap(arr[i], arr[i + 1]);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int evenArray[] = {1, 2, 3, 4, 5, 6};
    int evenSize = sizeof(evenArray) / sizeof(evenArray[0]);

    int oddArray[] = {1, 3, 2, 7, 11, 8};
    int oddSize = sizeof(oddArray) / sizeof(oddArray[0]);

    // Swap alternate elements and print the results
    swapAlternate(evenArray, evenSize);
    printArray(evenArray, evenSize);

    swapAlternate(oddArray, oddSize);
    printArray(oddArray, oddSize);

    return 0;
}
```

**Notes:**
- The `swapAlternate` function swaps alternate elements in the array by iterating through it and swapping adjacent elements.
- The `printArray` function is used to print the contents of the array.
- The main function demonstrates how to use these functions with both even and odd-sized arrays.





### Question 2: Find Unique Element

**Problem Statement:**
You are given an array of integers where all numbers appear twice except for one unique number that appears only once. Find and return this unique number.

**Example:**
Input: [1, 2, 2, 3, 1]
Output: 3

**Solution Approach:**
1. Initialize a variable `ans` to 0.
2. Iterate through the array.
3. For each element in the array, perform an XOR operation with the `ans`.
4. The XOR operation between the same numbers results in 0, and XOR with 0 returns the number itself.
5. After the loop, the `ans` will contain the unique number.

**C++ Code:**
```cpp
int findUniqueElement(vector<int>& nums) {
    int ans = 0;
    for (int num : nums) {
        ans ^= num;
    }
    return ans;
}
```

### Question 3: Unique Number of Occurrence

**Problem Statement:**
Given an array of integers, determine whether the number of occurrences of each value in the array is unique.

**Example:**
Input: [1, 2, 2, 2, 1, 3]
Output: true

**Solution Approach:**
1. Use a hash map to count the occurrences of each number in the array.
2. Iterate through the map and store the counts in a set.
3. If the size of the set is equal to the size of the map, return true; otherwise, return false.

**C++ Code:**
```cpp
bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> countMap;
    unordered_set<int> uniqueCounts;
    
    for (int num : arr) {
        countMap[num]++;
    }
    
    for (const auto& entry : countMap) {
        if (uniqueCounts.count(entry.second) == 0) {
            uniqueCounts.insert(entry.second);
        } else {
            return false;
        }
    }
    
    return true;
}
```




### Question: Find Duplicates in an Array

**Problem Statement:**
Given an array of integers where each integer appears exactly twice except for one element that appears only once, find and return the element that appears only once.

**Example:**
Input: [1, 2, 3, 2, 1]
Output: 3

**Solution Approach:**
1. Initialize a variable `ans` to 0.
2. Iterate through the entire array.
3. For each element in the array, perform an XOR operation with the `ans`.
4. The XOR operation between the same numbers results in 0, and XOR with 0 returns the number itself.
5. After the loop, the `ans` will contain the unique number.

**Pseudocode:**
```cpp
function findUniqueElement(nums):
    ans = 0
    for num in nums:
        ans = ans XOR num
    return ans
```

**Explanation:**
- Initialize `ans` to 0.
- Loop through the array `nums`.
- For each element `num` in `nums`, perform an XOR operation with `ans`. This operation combines all the elements in the array, effectively canceling out the duplicate elements.
- After the loop, `ans` will contain the unique element.

This pseudocode outlines the steps to find the unique element efficiently using XOR operations.




### Problem Statement: Array Intersection

You are given two sorted arrays, A and B, and you need to find their intersection, i.e., the elements that are common to both arrays.

**Example:**
```
Input:
Array A: [1, 2, 2, 3, 4]
Array B: [2, 2, 3, 4, 5]

Output:
Intersection: [2, 2, 3, 4]
```

### Solution Approach:

1. Initialize two pointers, `i` and `j`, to the first element of arrays A and B respectively.
2. Iterate through both arrays using these pointers.
3. Compare the elements pointed to by `i` and `j`.
4. If the elements are equal, add them to the intersection list and increment both pointers.
5. If the element pointed to by `i` is smaller, increment `i`.
6. If the element pointed to by `j` is smaller, increment `j`.
7. Continue this process until one of the arrays is exhausted.

**Pseudocode:**

```cpp
vector<int> findIntersection(vector<int>& A, vector<int>& B) {
    vector<int> intersection;
    int i = 0; // Pointer for array A
    int j = 0; // Pointer for array B

    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j]) {
            intersection.push_back(A[i]);
            i++; // Move both pointers forward
            j++;
        } else if (A[i] < B[j]) {
            i++; // Move pointer i forward
        } else {
            j++; // Move pointer j forward
        }
    }

    return intersection;
}
```

**Explanation:**

- Initialize two pointers, `i` and `j`, to the first element of arrays A and B.
- Compare the elements pointed to by `i` and `j`.
- If they are equal, add the element to the `intersection` vector and increment both pointers.
- If the element pointed to by `i` is smaller, increment `i`.
- If the element pointed to by `j` is smaller, increment `j`.
- Continue this process until one of the arrays is exhausted.

This pseudocode outlines the steps to find the intersection of two sorted arrays using a two-pointer approach.




Certainly, here are detailed notes on how to find triplets with a given sum in an array using C++:

### Problem Statement: Find Triplets with Given Sum (3sum)

You are given an array of integers and a target sum `K`. Your task is to find all unique triplets in the array that add up to the given sum `K`.

**Example:**
```
Input:
Array: [1, 2, 3, 4, 5, 6, 7, 8]
Target Sum: 15

Output:
Triplets: [1, 5, 9], [2, 4, 9], [2, 5, 8], [3, 4, 8], [3, 5, 7], [4, 6, 7]
```

### Solution Approach:

1. Sort the given array in ascending order.
2. Use three nested loops (i, j, k) to iterate through the array.
3. For each triplet (i, j, k), calculate their sum.
4. If the sum of the triplet is equal to the target sum `K`, add it to the list of triplets.
5. Ensure that you skip duplicates to avoid duplicate triplets.
6. Continue this process until all possible triplets have been checked.

**Pseudocode:**

```cpp
vector<vector<int>> findTriplets(vector<int>& arr, int K) {
    vector<vector<int>> triplets;
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue; // Skip duplicates

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];

            if (currentSum == K) {
                triplets.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;

                while (left < right && arr[left] == arr[left - 1]) left++; // Skip left duplicates
                while (left < right && arr[right] == arr[right + 1]) right--; // Skip right duplicates
            } else if (currentSum < K) {
                left++;
            } else {
                right--;
            }
        }
    }

    return triplets;
}
```

**Explanation:**

- Sort the input array `arr` in ascending order to make it easier to find triplets.
- Use three nested loops. The outer loop (`i`) iterates from 0 to `n - 2`.
- Skip duplicate elements by checking if `arr[i]` is the same as the previous element (`arr[i - 1]`).
- Within the outer loop, initialize two pointers (`left` and `right`) to find the other two elements of the triplet.
- The inner `while` loop calculates the sum of the triplet (`currentSum`) and compares it to the target sum `K`.
- If `currentSum` equals `K`, add the triplet to the `triplets` vector, and increment `left` and decrement `right`.
- Ensure that duplicates are skipped using the inner `while` loops.
- If `currentSum` is less than `K`, increment `left`.
- If `currentSum` is greater than `K`, decrement `right`.
- Continue this process until all possible triplets have been checked.
- Return the vector containing all unique triplets that sum up to `K`.






### Sort 0s and 1s:

#### Problem Statement:

Given an array containing only the elements 0 and 1, sort the array in ascending order. You need to modify the array in-place and should not use any extra space.

**Example:**
```
Input: [1, 0, 1, 0, 1, 0]
Output: [0, 0, 0, 1, 1, 1]
```

#### Solution Approach:

This problem can be efficiently solved using the Two-Pointer approach. The idea is to maintain two pointers, `left` and `right`, and iterate through the array to sort the elements into the correct order.

**Pseudocode:**

```cpp
void sortArray(vector<int>& nums) {
    int left = 0;   // Pointer for 0s
    int right = nums.size() - 1; // Pointer for 1s
    
    while (left < right) {
        while (nums[left] == 0 && left < right) {
            left++;
        }
        while (nums[right] == 1 && left < right) {
            right--;
        }
        if (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
}
```

**Explanation:**

- Initialize two pointers, `left` and `right`. `left` points to the next position to place `0`, and `right` points to the next position to place `1`.
- Use a `while` loop to iterate through the array.
- The `left` pointer moves to the right as long as it points to `0`, and the `right` pointer moves to the left as long as it points to `1`.
- When the pointers stop, swap the elements at `left` and `right`, and increment `left` and decrement `right`.
- Continue this process until `left` is less than `right`.
- The array will be sorted in the desired order after this operation.

### Sort 0s, 1s, and 2s:

#### Problem Statement:

Given an array containing only the elements 0, 1, and 2, sort the array in ascending order. This problem is often referred to as the "Dutch National Flag" problem.

**Example:**
```
Input: [2, 0, 1, 2, 1, 0]
Output: [0, 0, 1, 1, 2, 2]
```

#### Solution Approach:

This problem can be efficiently solved using the Two-Pointer approach, specifically the Dutch National Flag algorithm. The idea is to maintain three pointers: `low`, `mid`, and `high`, and iterate through the array to sort the elements into the correct order.

**Pseudocode:**

```cpp
void sortColors(vector<int>& nums) {
    int low = 0;        // Pointer for 0s
    int mid = 0;        // Pointer for 1s
    int high = nums.size() - 1; // Pointer for 2s
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
```

**Explanation:**

- Initialize three pointers, `low`, `mid`, and `high`. `low` points to the next position to place `0`, `mid` is used for iterating through the array, and `high` points to the next position to place `2`.
- Use a `while` loop to iterate through the array from `mid` to `high`.
- Check the value at the `mid` index:
    - If it's `0`, swap it with the element at the `low` index (since `low` represents the next position for `0`) and increment both `low` and `mid` pointers.
    - If it's `1`, simply increment the `mid` pointer.
    - If it's `2`, swap it with the element at the `high` index (since `high` represents the next position for `2`) and decrement the `high` pointer.
- Continue this process until `mid` is less than or equal to `high`.
- The array will be sorted in the desired order after this operation.

