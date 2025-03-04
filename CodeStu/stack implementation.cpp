// Stack Implementation Using Array

// Contributed by
// Ayush Thakur
// Easy
// yellow-spark
// 40/40
// 20 mins
// 70 %


// 35 upvotes
// Problem Statement
// Suggest Edit
// Stack is a data structure that follows the LIFO (Last in First out) principle. Design and implement a stack to implement the following functions:
// 1. Push(num): Push the given number in the stack if the stack is not full.
// 2. Pop: Remove and print the top element from the stack if present, else print -1.
// 3. Top: Print the top element of the stack if present, else print -1.
// 4. isEmpty: Print 1 if the stack is empty, else print 0.
// 5. isFull: Print 1 if the stack is full, else print 0.
// You have been given ‘M’ operations which you need to perform in the stack. Your task is to implement all the functions of the stack.
// Example:
// We perform the following operations on an empty stack which has capacity 2:

// When operation 1 1 is performed, we insert 1 in the stack.

// When operation 1 2  is performed, we insert 2 in the stack. 

// When operation 2 is performed, we remove the top element from the stack and print 2.

// When operation 3 is performed, we print the top element of the stack, i.e., 3.

// When operation 4 is performed, we print 0 because the stack is not empty.

// When operation 5 is performed, we print 0 because the stack is size 1, which is not equal to its capacity.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints :
// 1 <= T <= 10
// 1 <= N, M <= 10^3

// Time Limit: 1 sec
// Sample Input 1 :
// 1
// 2 6
// 1 1
// 1 2
// 2
// 3
// 4
// 5
// Sample Output 1 :
// 2 1 0 0
// Explanation For Sample Output 1 :
// For test case 1: 
// We perform the following operations on an empty stack which has capacity 2:

// When operation 1 1 is performed, we insert 1 in the stack.

// When operation 1 2  is performed, we insert 2 in the stack. 

// When operation 2 is performed, we remove the top element from the stack and print 2.

// When operation 3 is performed, we print the top element of the stack, i.e., 1.

// When operation 4 is performed, we print 0 because the stack is not empty.

// When operation 5 is performed, we print 0 because the stack is size 1, which is not equal to its capacity.
// Sample Input 2 :
// 1
// 5 5
// 1 2
// 2
// 2 
// 1 1
// 3
// Sample Output 2 :
// 2 -1 1
// Explanation For Sample Output 2 :
// For test case 1: 
// We perform the following operations on an empty stack which has a capacity of 5:

// When operation 1 2 is performed, we insert 2 in the stack.

// When operation 2 is performed, we remove the top element from the stack and print 2.

// When operation 2 is performed, as the stack is empty, we print -1.

// When operation 1 1 is performed, we insert 1 in the stack.

// When operation 3 is performed, we print the top element of the stack, i.e., 1.



#include <bits/stdc++.h>
// Stack class.
class Stack {
private:
  int *arr;
  int tail;
  int max_size;

public:
  Stack(int capacity) {
    arr = new int[capacity];
    tail = 0;
    max_size = capacity;
  }

  void push(int num) {
    if (tail != max_size) {
      arr[tail] = num;
      tail++;
    }
  }

  int pop() {
    if (tail != 0) {
      tail--;
      return arr[tail];
    }
    return -1;
  }

  int top() { return (tail != 0) ? (arr[tail - 1]) : (-1); }

  int isEmpty() { return (tail == 0) ? (1) : (0); }

  int isFull() { return (tail == max_size); }
};