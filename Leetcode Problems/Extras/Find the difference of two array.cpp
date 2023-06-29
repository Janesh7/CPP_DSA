// 2215. Find the Difference of Two Arrays
// Easy


// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.

 

// Example 1:

// Input: nums1 = [1,2,3], nums2 = [2,4,6]
// Output: [[1,3],[4,6]]
// Explanation:
// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
// Example 2:

// Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
// Output: [[3],[]]
// Explanation:
// For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
// Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// -1000 <= nums1[i], nums2[i] <= 1000

// My approach

#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n1, n2;
        vector<vector<int>> ans;
        for(auto i : nums1) n1[i]++;
        for(auto i : nums2) n2[i]++;

        unordered_set<int> st1, st2;
        vector<int> v1;
        for(int i = 0; i < nums1.size(); i++) {
            if(n2.find(nums1[i]) == n2.end()) {
                st1.insert(nums1[i]);
            }
        }
        for(auto i : st1) v1.push_back(i);
        ans.push_back(v1);

        vector<int> v2;
        for(int i = 0; i < nums2.size(); i++) {
            if(n1.find(nums2[i]) == n1.end()) {
                st2.insert(nums2[i]);
            }
        }
        for(auto i : st2) v2.push_back(i);
        ans.push_back(v2);
        return ans;
    }
};

#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
char tab_b[2001];
char* tab=tab_b+1000;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        memset(tab_b,0,sizeof(tab_b));
        for(int n:nums1){
            tab[n]=1;
        }
        vector<int> r1,r2;
        r1.reserve(nums1.size());
        r2.reserve(nums2.size());
        for(int n:nums2){
            if(tab[n]==0){
                if(tab[n]!=2) r2.emplace_back(n);
            }
            tab[n]=2;
        }
        for(int n:nums1){
            if(tab[n]==1){r1.emplace_back(n); tab[n]=0;}
        }
        return vector<vector<int>>{r1,r2};
    }
};

#pragma GCC optimize("Ofast")
// This line is a preprocessor directive specific to the GCC compiler. It suggests the compiler to optimize the code for speed, using the "Ofast" optimization level. This optimization level enables aggressive optimizations that can result in faster code execution, but it may sacrifice certain standards compliance or precision in floating-point calculations.


static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
// This line defines a static variable _ and assigns it the result of a lambda function. The lambda function is immediately invoked due to the trailing () at the end. The purpose of this lambda function is to optimize I/O performance in C++. It disables the synchronization between the C and C++ standard streams (sync_with_stdio(false)), unties the cin and cout streams from the standard C streams (cin.tie(nullptr) and cout.tie(nullptr)), and returns 0. The lambda function is executed once during program initialization due to the static keyword, and its result is discarded.


char tab_b[2001];
char* tab=tab_b+1000;
// This code declares a character array tab_b with a size of 2001. It also declares a pointer tab and assigns it the address of the middle element of tab_b (index 1000). This allows using tab as an offset index for accessing elements in tab_b.


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        memset(tab_b, 0, sizeof(tab_b));
        for (int n : nums1) {
            tab[n] = 1;
        }
        vector<int> r1, r2;
        r1.reserve(nums1.size());
        r2.reserve(nums2.size());
        for (int n : nums2) {
            if (tab[n] == 0) {
                if (tab[n] != 2)
                    r2.emplace_back(n);
            }
            tab[n] = 2;
        }
        for (int n : nums1) {
            if (tab[n] == 1) {
                r1.emplace_back(n);
                tab[n] = 0;
            }
        }
        return vector<vector<int>>{r1, r2};
    }
};
// This code defines a class named Solution. Inside the class, there's a member function findDifference that takes two input vectors nums1 and nums2 as references and returns a vector of vectors of integers (vector<vector<int>>).

// The function first initializes the tab_b array with zeros using memset. This array is used to keep track of numbers encountered in nums1 and nums2.

// Next, it iterates over the elements of nums1 and sets the corresponding element in tab to 1.

// Then, two empty vectors r1 and r2 are declared. These vectors will store the resulting differences between nums1 and nums2.

// The code iterates over the elements of nums2. If the corresponding element in tab is 0 (indicating it was not present in nums1), it checks if it is already marked as 2. If not, it adds the element to r2. After that, the element in tab is marked as 2.

// Next, the code iterates over the elements of nums1 again. If the corresponding element in tab is 1 (indicating it was present in nums1 but not in nums2), it adds the element to r1 and marks it as 0 in tab.

// Finally, the function returns a vector containing r1 and r2, which represent the differences between nums1 and nums2.

// Overall, this code is finding the differences between two vectors (nums1 and nums2) by keeping track of the elements using the tab array. The resulting differences are stored in r1 and r2.