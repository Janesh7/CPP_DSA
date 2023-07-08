// Sort Stack

// Contributed by
// Prateek_18cb
// Easy
// yellow-spark
// 40/40
// 20 mins
// 80 %


// 29 upvotes
// Problem Statement
// Suggest Edit
// You are given a stack ‘S’. Your task is to sort the sack recursively.
// Note:
// Looping through the stack is not allowed.
// You need to return a stack that is sorted in descending order.
// For Example:
// Given stack S = 1 3 2 
// The output will be 3 2 1 since it is the sorted order.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints:
// 1 <= T <= 5
// 1 <=  N <= 2000
// 0 <= S[i] <= 1000

// Where ‘T’ is the total number of test cases, and 'N’ is the size of the stack, and 'S[i]' is the element of the stack.
// Sample Input 1 :
// 2
// 4
// 1 0 0 2 
// 3 
// 2 4 2
// Sample Output 1 :
// 2 1 0 0
// 4 4 2
// Explanation Of The Sample Input 1:
// For the first test case:
// For the given stack, the resultant sorted stack would be 0 0 1 2.  

// For the second test case:
// For the given stack, the resulting sorted stack would be 2 2 4.   
// Sample Input 2 :
// 2
// 4
// 1 2 3 4     
// 3    
// 5 1 2
// Sample Output 2 :
// 4 3 2 1 
// 5 2 1


void reverseStack(stack<int> &stack) {

  // Write your code here

  vector<int> v;

  while (!stack.empty()) {

    v.push_back(stack.top());

    stack.pop();
  }

  for (auto it : v) {

    stack.push(it);
  }

}