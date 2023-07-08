# Stack

- LIFO : Last in first out
- example plates in a restruant

- Operations: push, pop || and peek(see the top element), isEmpty

- STL to create a stack

```
stack<type> s;
s.push();
s.pop();
s.top();
s.empty();
```

- Every operation in O(1)

Stacks can be implemented using

- arrays
- Linked List

In arrays the class looks like:

public:
        **int *arr;**
        int top;
        int size;

    // behaviour
    Stack(int size) {
        this -> size = size;
        **arr = new int[size];**
        top = -1;
    }

# Questions

**IMPORTANT POINTS TO NOTE**

- **Recursion is very useful in stack question.. Also STORE EACH VALUE IN EACH STEP AND LATER PUT IT BACK**
- **When we r using s.top() for anything.. do remember to add !s.empty() (stack not empty condition) otherwise it gives an exception**


## Insert at bottom

- Done using recursion
**Steps:**
- Base case: if the stack is empty insert the given element into the stack
- otherwise store the top value and pop the top
- give recursive call
- push back the stored element



## Reverse a stack

- Done using recursion
**Steps:**
- Store the top element of the stack
- recursive call on remaining
- while coming back(after recursive) DO - INSERT AT BOTTOM ALGO

**TC: O(n^2)** , can do in o(n) using extra space.



## Sort the stack

- Done using recursion
**Steps**
- base case: if stack is empty.. just return
- Store the top element of the stack
- recursive call on remaining
- while coming back(after recursive) DO - SORTED INSERT algo ie .. when we add the element we make sure the stack is sorted

### SORTED INSERT

- base case: Find an element which is smaller than the given element or the stack is empty 
**NOTE:** while checking the top of the stack for the condition(element is smaller than the top element) do ADD THE !s.empty() part otherwise throws an exception 
- insert the given element and while going back just add back the popped elements in stack




## Redundent brackets
- Ex. ((a+b)) has redundant brackets .. whereas (a*b+(a+B)) doesnt have any redn brackets
**LOGIC**
- All brackets should have an operator in them
APPROACH-

- Iterate over the string using for
- If the char is an open bracket or an operator -> push in stack
else would be a closing bracket or an English alphabet
- we should consider the closing brackets.. 
- if there is a operator between these brackets .. it means no redundant brackets 

**TC: O(N)**




## Minimum reversals for a valid bracket
Here  we have to make minimum changes in the given expression so the braces becomes valid
**Approach**
- if str length is odd .. return false
- so if we remove all the valid braces from the string we remain with
    - all open braces {{{{{{{{
    - all close braces }}}}}}}}
    - mismatched braces }}}}}{{{{{{
    

We use the below expression to find the min changes which is 
**(a+1)/2 + (b+1)/2** where a and b r number of }, { resp

**IMP: note that its int(a+1)/2 and int(b+1)/2 while computing**
Ex. {{{{
        (4+1)/2 + (0+1)/2 = 5/2 + 1/2= 2 + 0 = 2

    }}}}
        (4+1)/2 + (0+1)/2 = 5/2 + 1/2 = 2 

    }}}{{{
        (3+1)/2 + (3+1)/2 = 4
    CHANGED TO: {}{}{}, with change bit of 0,2,3,5.

    }}}}{{{{
        (4+1)/2 + (4+1)/2 = 5/2 + 5/2 = 4
    CHANGED TO: {}{}{}{} changed 
    
