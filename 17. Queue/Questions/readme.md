
# Q1: Queue Reversal

2. Queue Reversal Problem:
   - The problem is to reverse the elements inside a queue.
   - Given queue: 4, 3, 1, 10, 2, 6
   - Required output: 6, 2, 10, 1, 3, 4

3. Approach #1: Using a Stack
   - If a stack is used, elements can be inserted in reverse order and then popped to get the desired result.
   - Explanation of stack behavior: Elements inserted in stack - 1, 2, 3, 4; Elements popped from stack - 4, 3, 2, 1
   - First step of the algorithm: Pop elements from the queue and insert them into the stack.
   - Second step: Pop elements from the stack and insert them back into the queue.
   - Time Complexity: O(n) due to two traversals, Space Complexity: O(n) due to the stack.

4. Approach #2: Using Recursion
   - Explanation of recursion to reverse the queue:
     - Pop the front element from the queue, and then call recursion to reverse the remaining elements.
     - After recursion, push the front element back into the queue, effectively reversing the queue.
   - Time Complexity: O(n) due to one traversal, Space Complexity: O(n) due to the recursive call stack.

6. Approach #1 (Continued):
   - Explanation of the stack-based approach for queue reversal.
   - Stack reverse the input, so 1st step involves popping elements from the queue and inserting them into the stack.
   - Then, the elements are popped from the stack and inserted back into the queue.
   - Time and Space Complexity are discussed for the stack approach.

7. Approach #2 (Continued):
   - Explanation of the recursive approach for queue reversal.
   - The queue contains elements 4, 2, 3, 1, 5, 6, and we are solving the first case (4 is kept aside).
   - Recursion is instructed to reverse the rest of the elements (2, 3, 1, 5, 6).
   - The reversed part is then combined with 4, resulting in the output: 6, 5, 1, 3, 2, 4.
   - Time and Space Complexity are discussed for the recursive approach.

8. Implementing Approach #1 using Stack:
   - Code implementation for approach #1 using a stack to reverse the queue.
   - The steps involve popping elements from the queue and inserting them into the stack.
   - Then, the elements are popped from the stack and inserted back into the queue.
   - Time Complexity is O(n) due to two traversals, and Space Complexity is O(n) due to the stack.

9. Implementing Approach #2 using Recursion:
   - Code implementation for approach #2 using recursion to reverse the queue.
   - Recursion is used to reverse the queue, and then the elements are combined to get the desired output.
   - Time Complexity is O(n) due to one traversal, and Space Complexity depends on the recursive call stack.

10. Conclusion:
    - Summary of both approaches for queue reversal.
    - Approach #1 uses a stack with O(n) time and space complexity.
    - Approach #2 uses recursion with O(n) time complexity and variable space complexity due to the recursive call stack.

11. Next Question: Find Negative Integer in Every Window of Size k
    - Introduction to the next question where negative integers in windows of size k need to be found.
    - Problem discussion and approach are not covered in this segment.



# Q2: Find First Negative Integer in Every Window of Size k

1. Problem Introduction:
   - The problem involves finding the first negative integer in every window of size k in an array.
   - The given array is [-8, 2, 3, -6, 10], and the window size k is 2.
   - We need to find the first negative integer in each 2-sized window.

2. Approach Explanation:
   - The presenter discusses using a sliding window approach to solve the problem.
   - They introduce the concept of a doubly ended queue (deque) and explain its usage.
   - The deque will help maintain the first negative integer in the current window.

3. Sliding Window Approach:
   - The first step is to process the first k-sized window using the deque.
   - The deque will only store negative numbers' indices as we are interested in finding the first negative integer.
   - For the given example, the first k-sized window [-8, 2] is processed, and the deque contains only the index of -8.
   - The answer for the first window is the front element of the deque.

4. Handling Empty Queue:
   - The presenter explains that if the deque is empty, the answer for the window is either the front element or 0, depending on the requirement.
   - For example, if the first k-sized window is [2, 3], the deque will be empty, and the answer for this window is 0.

5. Processing Further Windows:
   - The presenter processes the next window [2, 3] and adds the index of -6 to the deque since it is a negative integer.
   - The answer for this window is the front element of the deque, which is the index of -8.

6. Removal Logic:
   - A 'for' loop is used to process from the (k+1)th index to the end of the array.
   - Removal logic: If the index difference of the front element of the dequeue and the current index is greater than or equal to 'k', the front element is popped.
   - To process the next window [3, -6], the presenter explains the removable logic.
   - As we move to the next window, elements from the previous window will be removed from the deque.
   - For example, in this case, the -8 (index 0) is outside the current window, so it is removed from the deque.

7. Using Deque for Efficient Operations:
   - The presenter clarifies that the use of a deque is beneficial because we can efficiently add elements (push_back) and remove elements (pop_front).
   - The deque maintains elements that are within the current window, making it easy to find the first negative integer.

8. Implementation:
   - The presenter provides code to solve the problem using a deque and a for loop to process windows.
   - The for loop iterates from k to n, and the current window is processed at each step.
   - If an element is negative, its index is added to the deque.
   - The front element of the deque is used as the answer for the current window.

9. Handling the Empty Deque:
   - The presenter emphasizes checking if the deque is empty before accessing its front element.
   - If the deque is empty, it means there are no negative integers in the window, so the answer for that window is 0.

10. Time and Space Complexity:
    - The time complexity of the sliding window approach is O(n) since we process each element once.
    - The space complexity is O(k) since we use a deque of size k to maintain elements within the current window.

11. Conclusion:
    - The presenter summarizes the approach using the sliding window and deque to find the first negative integer in every window of size k.
    - They clarify the optimization aspect of the deque for efficient operations.
    - The problem is solved, and they move on to the next question.




# Q3: Reversing the First K Elements of a Queue using Stack

**Approach:**

1. Fetch the first k elements from the queue and put them into a stack.
2. Fetch elements from the stack and push them back into the queue.
3. Fetch the first n-k elements from the queue and push them back at the end.

**Algorithm:**

1. Create an empty stack of integer type.
2. Loop from 0 to k-1:
   - Pop the front element from the queue (`q.front()`) and push it into the stack (`s.push(val)`).
3. Loop while the stack is not empty:
   - Pop an element from the stack (`s.pop()`) and push it into the queue.
4. Loop from 0 to n-k-1:
   - Pop the front element from the queue (`q.front()`) and immediately push it back into the queue.
5. Return the modified queue as the output.

**Time Complexity (T.C):** O(n)  
**Space Complexity (S.C):** O(k)  

**Explanation:**

- The algorithm works by reversing the first k elements using a stack, then reversing them back into the queue, and finally moving the remaining elements to the end of the queue.
- The time complexity is linear as each element is processed once.
- The space complexity is limited by the size of the stack, which is k.

**Note:**
- The code provided in the video demonstrates the implementation of the above algorithm in C++.
- The code includes creating a stack, reversing elements, and modifying the queue.

# Q4: Finding the First Non-Repeating Character in a Stream

**Problem:**

Given a stream of characters, find the first non-repeating character at any given point.

**Approach:**

1. Maintain a count of characters using a data structure (like a map or an array) to track the frequency of characters.
2. Use a queue to maintain the order of characters in the stream.
3. Traverse through the characters in the stream and process them accordingly.

**Algorithm:**

1. Initialize a map (or array) to store the count of each character.
2. Initialize a queue to store the characters in the order they appear.
3. Initialize an empty string called `ans`.
4. Traverse through the stream of characters:
   - Increase the count of the current character in the map.
   - Push the current character into the queue.
   - While the queue is not empty:
     - If the count of the front character of the queue is greater than 1, pop it (repeating character).
     - Else, append the front character of the queue to the `ans`.
5. After the traversal, if the queue is empty, return `"#"`, else return the `ans`.

**Time Complexity (T.C):** O(n)  
**Space Complexity (S.C):** O(26) (for the map/array) + O(n) (for the queue)

**Explanation:**

- The algorithm maintains a count of characters using a data structure (map or array) to efficiently check if a character is repeating.
- It uses a queue to process characters in the order they appear in the stream.
- The algorithm's time complexity is linear, and the space complexity depends on the size of the data structure used to store character frequencies.

**Note:**
- The provided code snippet is a partial implementation of the above algorithm, demonstrating how to use a map (or array) to count character occurrences and a queue to track the characters' order in the stream.
- If you need the full code or any specific code snippets, feel free to ask.



# VVIMP Q5: Finding the Starting Point for Completing a Circular Tour

**Problem:**

Given a circular route with n petrol pumps, each having a certain amount of petrol and distance to the next pump, find the starting point from which a truck can complete the circular tour.

**Approach 1: Brute Force**

- Start from each petrol pump and check if the truck can complete the circular tour.
- This approach has a time complexity of O(n^2) due to the nested loop.

**Approach 2: Queue-Based Approach**

1. Initialize `front`, `rear`, and `start` pointers all at the first petrol pump.
2. Calculate the balance of petrol and distance at the current pump and check if the truck can reach the next pump.
3. If the balance is negative, increment the `start` pointer to move the starting position ahead.
4. If the balance is non-negative, move the `rear` pointer to the next pump.
5. Repeat steps 2-4 until you complete the circular tour or find a suitable starting point.

**IMP: Keep in mind that we increment the rear if the bal is positive.. if it turns to be negative .. WE HAVE TO PUSH FRONT to REAR+1.. ie front = rear + 1.. coz we know that if we start from say step 0 and it turns negative in 3rd index .. we know that even if we start from the next (front+1) .. WE KNOW FOR SURE IT WONT BE ABLE TO.. as the first block contibute smth and even with that we r not able to travel in the 3rd part.. so no point it has been alr claculated.. thats why front=rear+1 .. and not front++**  



**Approach 3: Optimized Approach**

**Once we traverse few blocks.. and at some point we get -ve.. now we can store that deficit and we dont have to traverse that block again.. we know that it will take more than that -ve number to traverse that block.. so we can comapre with the bal before the block and directly come to the conclusion**

**We start from the 0th index and keep storing the deficit.. therefore we dont even have to traverse in circular manner**

1. Initialize `balance` as 0 and `deficit` as 0.
2. Traverse through the circular route, calculating the balance at each petrol pump.
3. If the balance is negative, add the deficit to it and update `deficit`.
4. If the balance becomes negative after adding the deficit, reset the starting point to the next pump and reset both `balance` and `deficit`.
5. If the balance becomes non-negative, move to the next pump.
6. After completing the traversal, if the total balance and deficit are non-negative, return the starting point; otherwise, return -1.

This optimized approach has a time complexity of O(n) and requires only a single traversal.



# Q6: Interleave Two Halves of a Stack

**Problem:**

Given a stack containing elements, you need to interleave the first half of the stack with the second half using only stack operations.

**Approach:**

1. Push the first half of the stack elements into a new stack (let's call it `tempStack`).
2. Empty the original stack and push elements back into it from `tempStack`.
3. Reverse the original stack to get the interleaved result.

**Explanation:**

1. Push the first half of the stack into `tempStack`:
   - Traverse through the original stack to find its size (let's call it `n`).
   - Push the first `n/2` elements from the original stack into `tempStack`.

2. Empty the original stack and push elements back from `tempStack`:
   - While `tempStack` is not empty, pop an element from it and push it back into the original stack.

3. Reverse the original stack:
   - Create another temporary stack (`reverseStack`).
   - While the original stack is not empty, pop elements from it and push them into `reverseStack`.
   - `reverseStack` will now contain the original stack elements in reversed order.

**Complexity Analysis:**

- Time Complexity: O(n)
- Space Complexity: O(n) due to the use of additional stacks (`tempStack` and `reverseStack`).

**Note:**

While the given approach uses additional stacks to achieve the interleaving, it's important to note that using queues for this problem would be a simpler and more efficient solution, as explained in the previous question's approach.




# Q7: Implementing Multiple Queues Using a Single Array

**Problem:**

You are given an array and need to implement multiple queues using this single array. Each queue should operate in a first-in-first-out (FIFO) manner, and you need to support enqueue and dequeue operations.

**Approach:**

To implement multiple queues using a single array, you can use the "two-pointers" approach along with the "next" array to manage the free slots. This approach allows you to efficiently manage the space and implement multiple queues in a single array.

**Steps:**

1. Initialize the required data structures:
   - Create arrays `front` and `rear` of size `k` to keep track of front and rear indices of each queue.
   - Create an array `next` of size `n` to manage free slots and linked elements.
   - Initialize `freeSpot` as 0, and initialize `front` and `rear` arrays with -1.

2. Initialize the `next` array:
   - Use a loop to set `next[i] = i + 1` for `i` from 0 to `n-1`.
   - Set `next[n-1] = -1`.

3. Implement `enqueue` operation:
   - takes data and qn (queue number)
   - Check if there is space for enqueueing (`freeSpot != -1`).
   - Find the index where the element will be inserted (`index = freeSpot`).
   - Update `freeSpot` with the next free slot (`freeSpot = next[index]`).
   - If the queue is empty (`front[qn-1] == -1`), update `front[qn-1]` to `index`.
   - Otherwise, link the new element to the previous element (`next[rear[qn-1]] = index`).
   - Update `rear[qn-1] = index`.
   - Set `next[index] = -1` to indicate the end of the queue.
   - Insert the element into the array at the calculated index.

4. Implement `dequeue` operation:
   - Check if the queue is empty (`front[qn-1] == -1`).
   - Get the index of the element to be dequeued (`index = front[qn-1]`).
   - Move the front pointer to the next element (`front[qn-1] = next[index]`).
   - Update the next free slot to point to the freed index (`next[index] = freeSpot`).
   - Update `freeSpot = index`.
   - Return the element at the dequeued index.

**Complexity Analysis:**

- Enqueue Operation:
  - Time Complexity: O(1)
  - Space Complexity: O(1)

- Dequeue Operation:
  - Time Complexity: O(1)
  - Space Complexity: O(1)

# Q9: Implementing stack using queue

Certainly! Below are detailed explanations and implementations of how to implement a stack using a queue and how to implement a queue using a stack in C++.

**Implementing Stack using Queue:**

To implement a stack using a queue, we can use two queues. One queue will serve as the main storage for elements, and the other queue will be used temporarily for operations.

Here's how the stack operations can be implemented:

1. **Push Operation:**
   - Enqueue the new element to the first queue.
   - If the second queue is not empty, dequeue all elements from the second queue and enqueue them to the first queue.
   - This step ensures that the newly added element is at the front of the queue, simulating the behavior of a stack.

2. **Pop Operation:**
   - If the first queue is empty, the stack is empty.
   - Dequeue all elements from the first queue except the last one and enqueue them to the second queue.
   - Dequeue and return the last element from the first queue.

3. **Top Operation:**
   - Return the front element of the first queue.

4. **Empty Operation:**
   - Return whether both queues are empty.





