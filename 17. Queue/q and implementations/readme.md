


# **Introduction to Queue:**

- A queue is a linear data structure that follows the FIFO (First-In-First-Out) principle.
- Elements are inserted at the rear (tail) and removed from the front (head) of the queue.
- Analogy: Imagine people standing in line; the person who arrives first is served first.
- Queues have applications in scheduling, managing resources, breadth-first search algorithms, etc.
- Basic operations: Enqueue (add an element to the rear), Dequeue (remove an element from the front), Front (retrieve the front element), Rear (retrieve the rear element), Size (number of elements), IsEmpty (check if the queue is empty).
- Enqueue adds an element after the current rear and updates the rear pointer.
- Dequeue removes the front element and updates the front pointer.
- Size and IsEmpty are useful utility functions.

# **Operations in Queue:**

- The Standard Template Library (STL) in C++ provides a queue container class.
- It encapsulates the queue data structure and provides member functions for common operations.
- Common methods include push (enqueue), pop (dequeue), front (get the front element), back (get the rear element), size (get the number of elements), and empty (check if the queue is empty).
- The front and back methods allow quick access to the front and rear elements, respectively.
- The size method returns the current number of elements in the queue.
- The empty method returns a boolean indicating whether the queue is empty or not.

# **Implementing Queue using Arrays:**

- A queue can be implemented using an array with front and rear pointers.
- The front pointer points to the first element, and the rear pointer points to the last element.
- Enqueue operation: Check if the queue is full, then increment the rear and add the new element.
- Dequeue operation: Check if the queue is empty, then increment the front to remove the element.
- Potential issue: If the rear reaches the end of the array and we have dequeued elements, there will be unused space at the front.
- Circular queue addresses this by allowing the rear to wrap around to the beginning when it reaches the end.
- Circular queue conditions: front and rear pointers move in a cyclic manner within the array's bounds.
- Modulus operation (%) is used to ensure wrap-around behavior when incrementing pointers.

# **Circular Queue:**

- A circular queue is an extension of the basic queue data structure.
- In a circular queue, when the rear reaches the end of the array, it wraps around to the beginning.
- This utilization of circular behavior eliminates the issue of unused space in the array.
- Front and rear pointers are updated using modulo arithmetic to ensure they stay within the array's bounds.
- Enqueue operation: Calculate the next index for the **rear using (rear + 1) % array_size.**
- Dequeue operation: Calculate the next index for the **front using (front + 1) % array_size.**
- Circular queues are particularly useful in scenarios where a fixed-size buffer needs to be efficiently utilized.

# **Input Restricted Queue:**

- An input-restricted queue only allows enqueue operations at the rear.
- This means that elements can only be added to the end of the queue.
- The front pointer moves when dequeue operations occur, while the rear stays fixed.
- Analogous to a ticket queue where new customers only enter from the rear.

# **Output Restricted Queue:**

- An output-restricted queue allows elements to be dequeued from both the front and the rear.
- Elements can be removed from either end, giving more flexibility compared to the input-restricted queue.
- Useful in scenarios where elements need to be removed from both ends.

# **Doubly Ended Queue (Deque):**

- A doubly-ended queue, or deque, supports insertion and deletion from both the front and the rear.
- Provides more versatility than the standard queue, allowing a wider range of operations.
- Useful in cases where elements need to be added or removed from both ends efficiently.
- The STL in C++ offers a deque container class with various methods.

# **Implementation of Deque:**

- A deque can be implemented using an array where elements are inserted and removed from both ends.
- Maintain front and rear pointers for these operations.
- Enqueue at front: Calculate the new **front index** as **(front - 1 + array_size) % array_size.**
- Enqueue at rear: Calculate the new **rear index** as **(rear + 1) % array_size.**
- Dequeue at front: Calculate the new front index similarly to enqueue at front.
- Dequeue at rear: Calculate the new rear index similarly to enqueue at rear.
- Pay attention to edge cases when the deque is empty or full, which can be determined using front and rear pointers.



These detailed technical notes provide a thorough understanding of the concepts discussed in the transcript, including queue introduction, operations, implementations using arrays, circular queues, input and output restricted queues, and doubly-ended queues (deques).