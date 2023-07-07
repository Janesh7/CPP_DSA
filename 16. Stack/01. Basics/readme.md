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

- **Recursion is very useful in stack question.. Also STORE EACH VALUE IN EACH STEP AND LATER PUT IT BACK**
