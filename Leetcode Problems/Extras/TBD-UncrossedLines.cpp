// 1035. Uncrossed Lines
// Medium


// You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

// We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

// nums1[i] == nums2[j], and
// the line we draw does not intersect any other connecting (non-horizontal) line.
// Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

// Return the maximum number of connecting lines we can draw in this way.

 

// Example 1:


// Input: nums1 = [1,4,2], nums2 = [1,2,4]
// Output: 2
// Explanation: We can draw 2 uncrossed lines as in the diagram.
// We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.
// Example 2:

// Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
// Output: 3
// Example 3:

// Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
// Output: 2
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 500
// 1 <= nums1[i], nums2[j] <= 2000


//  Answer by DP - READ SOLN 

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1));
        for(int i=0;i<=n1;++i){
            for(int j=0;j<=n2;++j){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                else if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};



// My intutuion -> WRONG ANS

// Two pointer
// wrong
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int i = nums1.size()-1;
        int j = nums2.size()-1,cnt=0;
        while (i>=0) {
            int temp = j;
            while (j>=0) {
                if (nums1[i]==nums2[j])
                    break;
                j--;
            }
            if (j>=0)
            {
                cnt++;
                nums2.resize(j);
                j--;
                i--;
            }
            else {
                j= temp;
                i--;
            }
        }
        return cnt;
    }
};


// 34 / 74 test cases passed.
// Status: Wrong Answer
// Input:
// [3,3,1,3]
// [1,3,2,3,3,1]
// Output:
// 2
// Expected:
// 3
