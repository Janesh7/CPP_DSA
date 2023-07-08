// Implement Stack With Linked List

// Contributed by
// Ankit Kharb
// Medium
// yellow-spark
// 80/80
// 30 mins
// 73 %


// 39 upvotes
// Problem Statement
// Suggest Edit
// You need to implement the Stack data structure using a Singly Linked List.
// Create a class named 'Stack' which supports the following operations(all in O(1) time):


// getSize: Returns an integer. Gets the current size of the stack

// isEmpty: Returns a boolean. Gets whether the stack is empty

// push: Returns nothing. Accepts an integer. Puts that integer at the top of the stack

// pop: Returns nothing. Removes the top element of the stack. Does nothing if the stack is empty.

// getTop: Returns an integer. Gets the top element of the stack. Returns -1 if the stack is empty
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints:
// 1 <= T <= 10^6
// 1 <= Q <= 5
// 1 <= Data <= 2^31 - 1

// Where 'Q' is the type of query and 'Data' being the values getting pushed and popped from the stack. 

// Time Limit: 1sec
// Sample Input 1:
// 4
// 3 5
// 3 4
// 1
// 2
// Sample Output 1:
// 2
// false    
// Explanation For Sample Output 1:
// The first two queries ('3') push 5 and 4 on the stack. So the size of stack becomes 2. Therefore the third query ('1') prints the size and since the stack is not empty, the fourth and final query ('2') outputs "false"
// Sample Input 2:
// 4
// 3 5
// 3 4
// 4
// 5
// Sample Output 2:
// 5   
// Explanation For Sample Output 2:
// The first two queries ('3') push 5 and 4 on the stack. The third query ('4') removes the top element of the stack which is 4 and the fourth and final query ('5') print the top element of the stack, 5


class Stack

{

  Node *head;

  int ind;

public:
  Stack()

  {

    // Write your code here

    head = NULL;

    ind = 0;
  }

  int getSize()

  {

    // Write your code here

    return ind;
  }

  bool isEmpty()

  {

    // Write your code here

    return ind == 0 || head == nullptr;
  }

  void push(int data)

  {

    // Write your code here

    Node *n = new Node(data);

    n->next = head;

    head = n;

    ind++;
  }

  void pop()

  {

    // Write your code here

    if (ind != 0) {

      Node *newHead = head->next;

      head->next = nullptr;

      delete head;

      head = newHead;

      ind--;

    }

    else
      return;
  }

  int getTop()

  {

    // Write your code here

    if (ind > 0) {

      return head->data;

    }

    else
      return -1;
  }
};