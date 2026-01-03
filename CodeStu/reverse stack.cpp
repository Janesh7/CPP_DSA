// Reverse Stack Using Recursion

// Contributed by
// Ashwani
// Easy
// yellow-spark
// 40/40
// 21 mins
// 80 %


// 180 upvotes
// Problem Statement
// Suggest Edit
// Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter itself.


// Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.


// Example:
// Input: [1,2,3,4,5] 
// Output: [5,4,3,2,1]
// add image

// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Sample Input 1 :
// 3
// 2 1 3
// Sample Output 1 :
// 3 1 2
// Explanation To Sample Input 1 :
// Reverse of a give stack is 3 1 2 where first element becomes last and last becomes first.                   
// Sample Input 2 :
// 2
// 3 2
// Sample Output 2 :
// 2 3
// Constraints :
// 0 <= N <= 10^3
// Where 'N' is the number of elements in the given stack.

// Time Limit: 1 sec


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