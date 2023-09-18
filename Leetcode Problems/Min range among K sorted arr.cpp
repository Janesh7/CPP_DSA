// 632. Smallest Range Covering Elements from K Lists
// Hard


// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

// Example 1:

// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
// Example 2:

// Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
// Output: [1,1]
 

// Constraints:

// nums.length == k
// 1 <= k <= 3500
// 1 <= nums[i].length <= 50
// -105 <= nums[i][j] <= 105
// nums[i] is sorted in non-decreasing order.



// creating a node that will store data and row and column of it
class node{
public:
    int data;
    int row;
    int col;

    node(int d, int r,int c){
        this->data = d;
        row = r;
        col = c;
    }
};

class cmp{
public:
    bool operator()(node* &a,node* &b){
        return a->data > b->data;
    }
};


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // create a min heap to store the data column and row of an element 
        priority_queue<node*,vector<node*>,cmp> pq;
        //declare initial range 
        int mini =  INT_MAX, maxi = INT_MIN;
        // push the first element of each list (min element of each list) in the heap and also update the min and max value
        for(int i = 0; i < nums.size(); i++){
            int val = nums[i][0];
            mini = min(mini,val);
            maxi = max(maxi,val);
            pq.push(new node(val,i,0));
        }
        // the range for all the first elements of the list will be [mini,maxi] 
        int start = mini, end = maxi;

        while(!pq.empty()){
            node* t = pq.top();
            pq.pop();

            mini = t->data;
            
            // if the new range is smaller than the previous one then update the new range 
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            else if(maxi - mini == end - start){
                if(mini < start){
                    start = mini;
                    end = maxi;
                }
            }

            // if next element exists in the list of mini
            if(t->col < nums[t->row].size() - 1){
                // update maxi if its greater than prev maxi
                maxi = max(maxi,nums[t->row][t->col+1]);
                // push the new element in the heap
                pq.push(new node(nums[t->row][t->col+1],t->row,t->col+1));
            }
            else{
                // if we have exhausted one of the lists then that means we have considered all possible ranges that will have atleast one member from each list
                break;
            }
        }
        return {start,end};
    }
};