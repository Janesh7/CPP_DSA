// Insert An Element At Its Bottom In A Given Stack
// Last Updated: 23 Feb, 2023
// Easy
// yellow-spark
// 40/40
// 15 mins
// 85 %


// 94 upvotes
// Problem Statement
// Suggest Edit
// You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.
// Note :
// If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last element represents the element at the top of the stack.
// For Example :
// Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes [9, 7, 1, 4, 5].
// Example

// Follow Up :
// Try to do this without using any other data structure.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints :
// 1 <= T <=100
// 1 <= N <= 10^4
// 0 <= 'X’ and 'MY_STACK[i]’ <= 10^5

// Time limit: 1 second
// Sample Input 1 :
// 2
// 3 8
// 4 3 2
// 4 5
// 6 2 4 9
// Sample Output 1 :
// 8 4 3 2
// 5 6 2 4 9
// Explanation For Sample Input 1 :
// Test Case 1:
// Example

// We are  given 'MY_STACK = [4,3,2] and 'X’ = 8.
// We insert ‘X’ at the bottom of ‘MY_STACK’. 
// So finally, we have 'MY_STACK' = [8, 4, 3, 2]. 

// Test Case 2:
// After inserting an element at its bottom, the stack will be 5 6 2 4 9
// Sample Input 2 :
// 2
// 1 0
// 4 
// 2 5
// 1 9
// Sample Output 2 :
// 0 4
// 5 1 9
// Explanation For Sample Input 2 :
// Test Case 1:
// We are given 'MY_STACK = [4]’ and 'X’ = 0’.
// We insert ‘X’ at the bottom of ‘MY_STACK’. 
// So finally, 'MY_STACK' will become [0, 4]. 

// Test Case 2:
// We are given 'MY_STACK = [1,9]’ and 'X’ = 5.
// So finally, 'MY_STACK' will become [5, 1, 9]. 


void solve(stack<int> &s, int x) {
  // base case
  if (s.empty()) {
    s.push(x);
    return;
  }

  int num = s.top();
  s.pop();

  // recursive call
  solve(s, x);

  s.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x) {
  solve(myStack, x);
  return myStack;
}
