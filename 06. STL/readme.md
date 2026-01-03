# STL
[Read more](https://www.geeksforgeeks.org/vector-in-cpp-stl/)
Standard template library
- has Algorithms and Conatianers
<br/>

<b>Conatiners</b>

- Sequence containers [ Array , Vector , Deque , List , (Forward List)]
- Container Adaptors [ Stack , Queue , Priority Q ]
- Associative Containers [ Set , Map ,(MultiSet , MultiMAp)]
- Unordered Associative [ Unordered ""]

<br />
<b>Algorithms</b>

- Bsearch
- Lowe/Upper bound
- min/max
- reverse/rotate
- sort/swap,etc

# Containers

## Array 
can include<array>
- to create <b>array<type, size></b> varname , Ex array<int,4> arr = {1,2,3,4}
- it is static i ey not used much , have to specify the size
<br />
FUNCTIONS: 

- arr.size(), 
- arr.empty() -> tell whether empty or not, 
- arr.first() -> returns the first element, 
- arr.back() -> returns last element, 
- arr.at(2) -> returns the element at index 2

## Vector 
- dynamic: If initially the size of vector is 4 and 5th element is added then the size of the vector DOUBLES
- <b>It creates a NEW vector of double the size of the previous vector and places/copy the elements in it</b>
- Size : how much elements it is having currently. This can be determined using size function ie arr.size()
- <b>Capacity : how much memeory is allocated to the vector. This can be determined using capacity function ie arr.capacity()</b>
- Ex: If i create a vector v: vector<int> v; its size and cap are 0; v.push_back(0) if i add 1 element: size and cap 1; v.push_back(1) - size and cap 2; BUT now if we add another element v.push_back(2) , the size becomes 3 and the capacity BECOMES 4 (ie 2*2)
- <b>Initialization - vector<int> v(5,1) initialize vector v with size 5 and all 1s; vector<int> a(v) -> copies the vector v</b>
<br/>
FUNCTIONS: 

-    v.first() -> returns the first element, 
-    v.back() -> returns last element, 
-    <b>v.pop_back() -> Pops the last element inserted </b>
-    <b>v.clear() -> makes the size of the v to 0 BUT NOT CAPACITY</b>
-    <b>v.begin() -> returns a iterator from the beginning of the vector</b>
-    v.at(2) -> returns the element at index 2
-    v.empty() -> tell whether empty or not, 
To run for loops using the iterators:

    for (int i:v)
        cout<<I;


**To make a 2d vector with all values initailized as 0**

```
vector<vector<int>> visited (n,vector<int>(n,0));
```



- **Vectors are passed by value and hence to make any changes they need to be sent as reference. (unlike arrays where a ptr to the 1st element is sent)**

**IMP FUNCTIONS**


- assign() – It assigns new value to the vector elements by replacing old ones

- push_back() – It push the elements into a vector from the back

- pop_back() – It is used to pop or remove elements from a vector from the back.

- **insert()** – It inserts new elements before the element at the specified position

Syntax of insert() in Vector
```
vector_name.insert (position, val);
```

where pos is a ITERATOR

- **erase()** – It is used to remove elements from a container from the specified position or range.

Syntax: 

```
vector_name.erase(position);    for deletion at specific position
vector_name.erase(starting_position, ending_position);    // for deletion in range
```
Parameters:

- Position of the element to be removed in the form of an iterator. **(Do begin+n, n being the index Ex. it+1 will delete the second element)**
- The range specified using start and end iterators.


- swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.

- clear() – It is used to remove all the elements of the vector container

- **emplace()** – It extends the container by inserting new element at position

- **emplace_back()** – It is used to insert a new element into the vector container, the new element is added to the end of the vector


```cpp
// C++ program to illustrate the
// Modifiers in vector
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
	// Assign vector
	vector<int> v;

	// fill the vector with 10 five times
	v.assign(5, 10);

	cout << "The vector elements are: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	// inserts 15 to the last position
	v.push_back(15);
	int n = v.size();
	cout << "\nThe last element is: " << v[n - 1];

	// removes last element
	v.pop_back();

	// prints the vector
	cout << "\nThe vector elements are: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	// inserts 5 at the beginning
	v.insert(v.begin(), 5);

	cout << "\nThe first element is: " << v[0];

	// removes the first element
	v.erase(v.begin());

	cout << "\nThe first element is: " << v[0];

	// inserts at the beginning
	v.emplace(v.begin(), 5);
	cout << "\nThe first element is: " << v[0];

	// Inserts 20 at the end
	v.emplace_back(20);
	n = v.size();
	cout << "\nThe last element is: " << v[n - 1];

	// erases the vector
	v.clear();
	cout << "\nVector size after erase(): " << v.size();

	// two vector to perform swap
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	cout << "\n\nVector 1: ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";

	cout << "\nVector 2: ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";

	// Swaps v1 and v2
	v1.swap(v2);

	cout << "\nAfter Swap \nVector 1: ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";

	cout << "\nVector 2: ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
}
```

## Deque
DOUBLY ENDED QUQUE(deq)
- We can push/pop from BOTH th ends
- NOT CONTIGOUS LIKE vector or array; multiple fixed static arrays top store the elements are these are tracked.. use arrays that is y its sequenced
- Dynamic; initialize: deque<int> d;
<br/>
FUNCTIONS:

-    d.push_back(x) -> Push to back
-    d.push_front(x) -> Push to the front
-    d.pop_back() -> pop from back
-    d.pop_front() -> pop from the front
-    d.at(2) -> returns the element at index 2
-    d.first() -> returns the first element, 
-    d.back() -> returns last element,
-    d.empty() -> tell whether empty or not, 
-   <b>d.erase(<beginning>,<end>) -> delete from the range beg to end ;Ex: d.erase(d.begin(),d.begin()+1) -> deletes 1st element</b>

## List
Implementation is Doubly linked list
- NO RANDOM ACCESS LIKE ARRAY, vector or deque ie have to travel to a certain element and cant go directly.
- INITIALIZATION : list<int> l;list<int> l(5,100) -> create list of 5 element with each being 100
<br/>

FUNCTION

- empty,back,begin,end -> <b>COMPLEXITY IS O(1)</b>
- size()
- l.push_back(x),pop_back()
- l.push_front(x),pop_front()
- l.erase(beg,end) - > COMPLEXITY IS O(n), also l.erase(l.begin()) -> deletes one element ie the first one

## Stack
- LAST IN FIRST OUT (LIFO)
- inistailization : stack<string> s;
- O(1) for all operations
<br/>
FUNCTIONS:

- push(x),pop()
- top()
- size , empty

## Queue
- FIFO
- initialization : queue<string> q;
- O(1) for all operations
<br/>
FUNCTIONS:

- push(x),pop()
- front()
- size , empty

## Priority Queue
- First element always the greatest
- default is like max heap, can be imported with queue lib
- <b>INITIALIZATION priority_queue<int> p; // This creates a max heap <br />
                    priority_queue<int, vector<int>, greater<int> > mini; // creates a min heap 
  </b>
  <br />
NOTE: just for proof of concept he printed and poped the element using the code
```
    int n = maxi.size();
    for (int i= 0;i<n;i++) {
        cout<<maxi.top(); // prints the highest element
        maxi.pop();
    }
```

Here we directly put maxi.size() in loop as we r poping in the same loop aswell which would change the size of q with each iteration and would give faulty error ie will only print 2 elements from 4
  <br />

FUNCTIONS :

- push(x)
- pop()
- empty, size

## Set
- Has only unique elements
- <b>IMPLEMENTED USING BST</b>  ;cant modify, can only delete or insert new elements;
- returns in sorted increasing order
- slower than unordered set(randomly returns ele not sorted) 
- complexity of insertion,find,erase,count is BigO(logn) as for the BST.
NOTE: To create an iterator here:
```
set<int>::iterator it = s.begin();
it++; // increment the iterator -> goes to the next value
```
<br/>
FUNCTIONS :

- insert(x) 
- erase(),size,empty
<b>
- count() -> 0 if not there ,1 otherwise (set has uniq ele)
- find() -> if an element then it returns the iterator of the found element
</b>

## Map
- key value pairs
- uniq key
<b>
- Maps have O(1) for search which are implemented using hashtables ie the case for unordered map but for ordered it is o(logn) coz it is implemented uisng red balck tree or balanced tree
</b>
- sorted for ordered 
- INITIALIZATION: 
```map<int,string> a; 
   a[1] = "kumar";
```
- To print keys:
```
    for (auto i : a)
        cout<<i.first; // NO PARATHENSIS
```
<br />
Functions:
- a.insert(2,"anything");
- a.count(2), find;
- a.erase(key)
- Complexity is O(logn) for all above ops

# IMP NOTE
<br />

Range-based for loop in C++ is added since C++ 11. It executes a for loop over a range. Used as a more readable equivalent to the traditional for loop operating over a range of values, such as all elements in a container.

for ( range_declaration : range_expression ) 
    loop_statement

Parameters :
range_declaration : 
a declaration of a named variable, whose type is the 
type of the element of the sequence represented by 
range_expression, or a reference to that type.
<b>Often uses the auto specifier for automatic type 
deduction. </b>

range_expression : 
any expression that represents a suitable sequence 
or a braced-init-list.

loop_statement : 
any statement, typically a compound statement, which
is the body of the loop.
C++ implementation : 

```
// Illustration of range-for loop 
// using CPP code 
#include <iostream> 
#include <map> 
#include <vector> 

  
// Driver 

int main() 
{ 

    // Iterating over whole array 

    std::vector<int> v = { 0, 1, 2, 3, 4, 5 }; 

    for (auto i : v) 

        std::cout << i << ' '; 

  

    std::cout << '\n'; 

  

    // the initializer may be a braced-init-list 

    for (int n : { 0, 1, 2, 3, 4, 5 }) 

        std::cout << n << ' '; 

  

    std::cout << '\n'; 

  

    // Iterating over array 

    int a[] = { 0, 1, 2, 3, 4, 5 }; 

    for (int n : a) 

        std::cout << n << ' '; 

  

    std::cout << '\n'; 

  

    // Just running a loop for every array 

    // element 

    for (int n : a) 

        std::cout << "In loop" << ' '; 

  

    std::cout << '\n'; 

  

    // Printing string characters 

    std::string str = "Geeks"; 

    for (char c : str) 

        std::cout << c << ' '; 

  

    std::cout << '\n'; 

  

    // Printing keys and values of a map 

    std::map<int, int> MAP( 

        { { 1, 1 }, { 2, 2 }, { 3, 3 } }); 

    for (auto i : MAP) 

        std::cout << '{' << i.first << ", " << i.second 

                  << "}\n"; 
}
```
Output:

0 1 2 3 4 5 <br />
0 1 2 3 4 5 <br />
0 1 2 3 4 5 <br />
In loop In loop In loop In loop In loop In loop <br />
G e e k s <br />
{1, 1} <br />
{2, 2} <br />
{3, 3} <br />


C++ 17 or higher: Range-based loops can also be used with maps like this: 
```
for (auto& [key, value]: myMap) {
    cout << key << " has value " << value << std::endl;
}
```
Here [key, value] works like elements of pair which can be directly accessed without specifying first or second keyword. 

# Algorithms

## Binary Search
- For sorted
- Syntax for vectors: binary_search(v.begin(),v.end(),5)  where 5 is the element to be searched 
- RETURNS WHETHER PRESENT OR NOT, to get the iterator to find the pos of ele use find() for vectors

## Upper bound 
The upper_bound() function is used to find the first element in the range [start, end) whose value is greater than the val and returns an iterator pointing to that value.

## Lower bound 
The lower_bound() method in C++ is used to return an iterator pointing to the first element in the range [first, last) which has a value NOT less than val. <b>This means that the function returns an iterator pointing to the next smallest number just greater than or equal to that number.</b>
<br />

For both if there is no upper/lower bound it returns the end iterator.
<br />
NOTE: Since. it returns an iterator, For both we have to subtract the beign iterator to get the index

```
// lower_bound and upper_bound in vector
 
#include <algorithm> // for lower_bound, upper_bound and sort
#include <iostream>
#include <vector> // for vector
 

using namespace std;
 

int main()
{

    int gfg[] = { 5, 6, 7, 7, 6, 5, 5, 6 };
 

    vector<int> v(gfg, gfg + 8); // 5 6 7 7 6 5 5 6
 

    sort(v.begin(), v.end()); // 5 5 5 6 6 6 7 7
 

    vector<int>::iterator lower, upper;

    lower = lower_bound(v.begin(), v.end(), 6);

    upper = upper_bound(v.begin(), v.end(), 6);
 

    cout << "lower_bound for 6 at index "

         << (lower - v.begin()) << '\n';

    cout << "upper_bound for 6 at index "

         << (upper - v.begin()) << '\n';
 

    return 0;
}
Output
lower_bound for 6 at index 3
upper_bound for 6 at index 6
```

## max, min , reverse and swap

max(a,b)
min(a,b)
swap(a,b)
<br />
string s = "abcd";
reverse(s.begin(),s.end());

## rotate
- begin, how many to rotate(begin+n),end as arguments
- rotate(v.begi(),bv.begin()+1,v.end()); // rotates by 1

## SORT
- <b>BASED ON INTRA SORT: which is a mix of 3 sorting algorithms ie QUICK sort, HEAP sort, and INSERTION sort</b>
- sort(v.begin(),v.end());




-----------------------------------------------------

# Formal notes


---

# C++ Comprehensive Guide - Strings

## Introduction
Strings in C++ are sequences of characters represented as `std::string`. They are part of the C++ Standard Template Library (STL) and provide versatile tools for working with text data. In C++, strings are commonly used for processing and manipulating textual information.

### Including the Library
To use strings, include the appropriate header:

```cpp
#include <string>
```

### Declaring a String
To declare an empty string, use the following syntax:

```cpp
std::string myString;
```

To initialize a string with a value, use:

```cpp
std::string greeting = "Hello, World!";
```

### String Operations
#### Concatenation
You can concatenate strings using the `+` operator or the `append` function:

```cpp
std::string firstName = "John";
std::string lastName = "Doe";
std::string fullName = firstName + " " + lastName;
```

#### Length
To get the length (number of characters) of a string, use the `length` or `size` function:

```cpp
std::string text = "Hello, World!";
int length = text.length(); // or text.size()
```

#### Accessing Characters
You can access individual characters of a string using the subscript operator `[]` or the `at` function:

```cpp
char firstChar = text[0];
char secondChar = text.at(1);
```

#### Substring
To extract a substring from a string, use the `substr` function:

```cpp
std::string text = "Hello, World!";
std::string subString = text.substr(0, 5); // "Hello"
```

### Searching
You can search for substrings or characters in a string using the `find` function:

```cpp
std::string text = "Hello, World!";
size_t found = text.find("World"); // Position of "World" in the string
if (found != std::string::npos) {
    // "World" found in the string
}
```

### Modifying Strings
#### Replace
To replace part of a string with another substring, use the `replace` function:

```cpp
std::string text = "Hello, World!";
text.replace(7, 5, "Universe"); // Replaces "World" with "Universe"
```

#### Insert and Erase
To insert or erase characters in a string, use the `insert` and `erase` functions:

```cpp
std::string text = "Hello!";
text.insert(5, " World"); // Inserts " World" at position 5
text.erase(6, 1); // Erases the space character at position 6
```

### Real-time Usage
#### Scenario 1: String Manipulation
```cpp
#include <iostream>
#include <string>

int main() {
    std::string sentence = "C++ is a powerful programming language.";
    
    // Convert to uppercase
    for (char& c : sentence) {
        c = std::toupper(c);
    }
    
    // Find and replace
    size_t found = sentence.find("POWERFUL");
    if (found != std::string::npos) {
        sentence.replace(found, 8, "awesome");
    }
    
    std::cout << sentence << std::endl;
    
    return 0;
}
```

#### Scenario 2: Tokenization
```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string input = "Apple Banana Cherry";
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    for (const std::string& t : tokens) {
        std::cout << t << std::endl;
    }

    return 0;
}
```

### Important Tips
- Strings in C++ are versatile and can be manipulated in various ways.
- Pay attention to string indexing; the first character is at index 0.
- Be aware of functions like `find`, which return `std::string::npos` if the search fails.
- Strings provide a wide range of functions for efficient manipulation, including appending, replacing, inserting, and erasing.


---

# C++ STL Comprehensive Guide - Vector

## Introduction
The `std::vector` is a dynamic array implementation in C++ that provides dynamic resizing, efficient element access, and various utility functions. It is a fundamental container in the C++ Standard Template Library (STL).

### Creating a Vector
To create an empty vector of a specific type, use the following syntax:

```cpp
std::vector<T> v;
```

### Adding Elements
To add elements to a vector, you can use the `push_back` function:

```cpp
std::vector<int> v;
v.push_back(42); // Adds 42 to the end of the vector
```

### Accessing Elements
You can access elements using the subscript operator or the `at` function:

```cpp
int element = v[0]; // Accesses the first element (index 0)
int element2 = v.at(1); // Accesses the second element (index 1)
```

### Size of Vector
To get the number of elements in a vector, use the `size` function:

```cpp
size_t size = v.size(); // Returns the number of elements in the vector
```

### Iterating Through a Vector
You can use a range-based for loop to iterate through a vector:

```cpp
for (const auto& element : v) {
    // Access and manipulate 'element'
}
```

### Inserting at a Specific Index
To insert an element at a specific index, you can use the `insert` function:

```cpp
v.insert(v.begin() + index, value); // Inserts 'value' at the specified 'index'
```

### Removing Elements
To remove elements from a vector, you can use the `pop_back` function to remove the last element:

```cpp
v.pop_back(); // Removes the last element from the vector
```

### Real-time Usage
#### Scenario 1: Sum of Vector Elements
```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};
int sum = 0;

for (const auto& num : numbers) {
    sum += num;
}
// 'sum' now contains the sum of all elements in 'numbers'
```

#### Scenario 2: Inserting Elements in Sorted Order
```cpp
std::vector<int> sortedVector = {1, 3, 5, 7};
int newValue = 4;

// Insert 'newValue' in sorted order
auto it = std::upper_bound(sortedVector.begin(), sortedVector.end(), newValue);
sortedVector.insert(it, newValue);
```

#### Scenario 3: Sliding Window 

See program

### Important Tips
- Vectors are useful when the size of the container is not known in advance, or it needs to dynamically grow or shrink.
- Be aware that inserting or erasing elements in the middle of a vector can be relatively slow compared to the end due to the need to move elements.
- Use vectors when random access (element-by-index) is a common operation.
- Consider using `reserve` to preallocate memory if you know the approximate size of the vector to reduce reallocations.


Certainly! Here's a comprehensive guide for the `std::deque` (double-ended queue) component of the C++ Standard Template Library (STL):

---

# C++ STL Comprehensive Guide - Deque

## Introduction
A `std::deque` (double-ended queue) is a dynamic array-like container that allows fast insertion and deletion at both ends. It is part of the C++ Standard Template Library (STL) and provides a versatile alternative to `std::vector` and other sequential containers.

### Creating a Deque
To create an empty deque of a specific type, use the following syntax:

```cpp
std::deque<T> d;
```

### Adding Elements
To add elements to a deque, you can use the `push_back` and `push_front` functions:

```cpp
std::deque<int> d;
d.push_back(42); // Adds 42 to the end of the deque
d.push_front(10); // Adds 10 to the front of the deque
```

### Accessing Elements
You can access elements using the subscript operator or the `at` function:

```cpp
int element = d[0]; // Accesses the first element (index 0)
int element2 = d.at(1); // Accesses the second element (index 1)
```

### Size of Deque
To get the number of elements in a deque, use the `size` function:

```cpp
size_t size = d.size(); // Returns the number of elements in the deque
```

### Iterating Through a Deque
You can use a range-based for loop to iterate through a deque:

```cpp
for (const auto& element : d) {
    // Access and manipulate 'element'
}
```

### Inserting at a Specific Index
To insert an element at a specific index, you can use the `insert` function:

```cpp
d.insert(d.begin() + index, value); // Inserts 'value' at the specified 'index'
```

### Removing Elements
To remove elements from a deque, you can use the `pop_back` and `pop_front` functions:

```cpp
d.pop_back(); // Removes the last element from the deque
d.pop_front(); // Removes the first element from the deque
```

### Real-time Usage
#### Scenario 1: Simulating a Queue
```cpp
std::deque<int> queue;
queue.push_back(1);
queue.push_back(2);
queue.push_back(3);
int frontElement = queue.front(); // Retrieves the front element (1)
queue.pop_front(); // Dequeues the front element (removes 1)
```

#### Scenario 2: Simulating a Stack
```cpp
std::deque<int> stack;
stack.push_back(10);
stack.push_back(20);
stack.push_back(30);
int topElement = stack.back(); // Retrieves the top element (30)
stack.pop_back(); // Pops the top element (removes 30)
```

### Important Tips
- Deques are suitable when you need dynamic resizing and efficient insertion/removal at both ends.
- Use `push_back` and `pop_back` for typical stack-like operations.
- Use `push_front` and `pop_front` for typical queue-like operations.
- Consider deque when you need a versatile container for various scenarios where you need elements added or removed from both ends.




---

# C++ STL Comprehensive Guide - Queue

## Introduction
A `std::queue` is a First-In-First-Out (FIFO) data structure in C++ that allows efficient insertion and removal of elements. It is a part of the C++ Standard Template Library (STL) and is commonly used for tasks that require a strict ordering of elements.

### Creating a Queue
To create an empty queue of a specific type, use the following syntax:

```cpp
std::queue<T> q;
```

### Adding Elements
To add elements to a queue, you can use the `push` function:

```cpp
std::queue<int> q;
q.push(42); // Enqueues 42 into the queue
```

### Removing Elements
To remove elements from a queue, you can use the `pop` function:

```cpp
q.pop(); // Dequeues (removes) the front element from the queue
```

### Accessing the Front Element
To access the front (oldest) element in the queue, use the `front` function:

```cpp
int frontElement = q.front(); // Retrieves the front element without removing it
```

### Size of Queue
To get the number of elements in a queue, use the `size` function:

```cpp
size_t size = q.size(); // Returns the number of elements in the queue
```

### Real-time Usage
#### Scenario 1: Breadth-First Search (BFS)
```cpp
#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> graph; // Adjacency list representation of a graph
std::vector<bool> visited; // To track visited nodes
std::queue<int> q; // Queue for BFS

void BFS(int startNode) {
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        std::cout << currentNode << " "; // Process the current node

        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Initialize graph and visited vector
    int startNode = 0; // Start BFS from node 0
    BFS(startNode);
    return 0;
}
```

#### Scenario 2: Simulating a Print Queue
```cpp
#include <iostream>
#include <queue>
#include <string>

std::queue<std::string> printQueue;

void AddToPrintQueue(const std::string& document) {
    printQueue.push(document);
}

void PrintNextDocument() {
    if (!printQueue.empty()) {
        std::string document = printQueue.front();
        printQueue.pop();
        std::cout << "Printing: " << document << std::endl;
    } else {
        std::cout << "Print queue is empty." << std::endl;
    }
}

int main() {
    AddToPrintQueue("Document1");
    AddToPrintQueue("Document2");
    PrintNextDocument(); // Prints "Printing: Document1"
    PrintNextDocument(); // Prints "Printing: Document2"
    PrintNextDocument(); // Prints "Print queue is empty."
    return 0;
}
```

### Important Tips
- Queues are useful for managing tasks or data in a strict first-in-first-out (FIFO) order.
- Use a queue when you need to process elements in a specific order, such as breadth-first search (BFS) in graph traversal or managing tasks in a queue.
- Be cautious of empty queues when using `front` or `pop` functions to avoid runtime errors.
- Use `size` to check the number of elements in the queue.


---

# C++ Comprehensive Guide - Priority Queue

## Introduction
A `std::priority_queue` is a container in C++ that stores elements with associated priorities, allowing for efficient retrieval of the highest-priority element. It is part of the C++ Standard Template Library (STL) and is implemented as a binary heap. Priority queues are often used in algorithms where elements need to be processed in a specific order based on their priorities.

### Including the Library
To use `std::priority_queue`, include the appropriate header:

```cpp
#include <queue>
```

### Creating a Priority Queue
To create an empty priority queue of a specific type, use the following syntax:

```cpp
std::priority_queue<T> myQueue;
```

For example, to create a priority queue of integers:

```cpp
std::priority_queue<int> myIntQueue;
```

### Inserting Elements
To insert elements into a priority queue, you can use the `push` function:

```cpp
std::priority_queue<int> myQueue;
myQueue.push(42);  // Inserts 42 into the priority queue
myQueue.push(10);  // Inserts 10 into the priority queue
```

### Accessing the Top Element
To access the highest-priority element in the priority queue (the element with the maximum value), use the `top` function:

```cpp
int highestPriority = myQueue.top(); // Retrieves the highest-priority element without removing it
```

### Removing Elements
To remove the highest-priority element from the priority queue, use the `pop` function:

```cpp
myQueue.pop(); // Removes the highest-priority element from the priority queue
```

### Size of Priority Queue
To get the number of elements in the priority queue, use the `size` function:

```cpp
size_t size = myQueue.size(); // Returns the number of elements in the priority queue
```

### Real-time Usage
#### Scenario 1: Task Scheduling
```cpp
#include <iostream>
#include <queue>

struct Task {
    std::string name;
    int priority;

    Task(const std::string& n, int p) : name(n), priority(p) {}

    // Define operator< for custom comparison
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

int main() {
    std::priority_queue<Task> taskQueue;
    taskQueue.push(Task("Task A", 2));
    taskQueue.push(Task("Task B", 1));
    taskQueue.push(Task("Task C", 3));

    while (!taskQueue.empty()) {
        Task currentTask = taskQueue.top();
        std::cout << "Executing: " << currentTask.name << std::endl;
        taskQueue.pop();
    }

    return 0;
}
```

#### Scenario 2: Dijkstra's Shortest Path Algorithm
```cpp
#include <iostream>
#include <queue>
#include <vector>

struct Node {
    int id;
    int distance;

    Node(int i, int d) : id(i), distance(d) {}

    // Define operator> for custom comparison (min-heap)
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

void dijkstra(const std::vector<std::vector<int>>& graph, int start) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    std::vector<int> distance(graph.size(), INT_MAX);

    pq.push(Node(start, 0));
    distance[start] = 0;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
            if (graph[current.id][neighbor] > 0 &&
                distance[current.id] + graph[current.id][neighbor] < distance[neighbor]) {
                distance[neighbor] = distance[current.id] + graph[current.id][neighbor];
                pq.push(Node(neighbor, distance[neighbor]));
            }
        }
    }

    // Print shortest distances from the start node to all nodes
    for (int i = 0; i < graph.size(); ++i) {
        std::cout << "Shortest distance from node " << start << " to node " << i << ": " << distance[i] << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 1, 4, 0, 0},
        {1, 0, 4, 2, 7},
        {4, 4, 0, 3, 5},
        {0, 2, 3, 0, 4},
        {0, 7, 5, 4, 0}
    };

    int startNode = 0;
    dijkstra(graph, startNode);

    return 0;
}
```

### Important Tips
- Priority queues are useful when elements need to be processed in order of priority.
- By default, `std::priority_queue` uses the less-than operator (`<`) for comparison. For custom comparison, define `operator<` or provide a custom comparison function when declaring

 the priority queue.
- The highest-priority element is always at the top of the priority queue.
- Elements in the priority queue are automatically sorted based on their priorities.


---

# C++ STL Comprehensive Guide - Stack

## Introduction
A `std::stack` is a Last-In-First-Out (LIFO) data structure in C++ that allows efficient insertion and removal of elements. It is a part of the C++ Standard Template Library (STL) and is commonly used for tasks that require a strict ordering of elements, such as managing function calls or tracking the state of a program.

### Creating a Stack
To create an empty stack of a specific type, use the following syntax:

```cpp
std::stack<T> s;
```

### Adding Elements
To add elements to a stack, you can use the `push` function:

```cpp
std::stack<int> s;
s.push(42); // Pushes 42 onto the stack
```

### Removing Elements
To remove elements from a stack, you can use the `pop` function:

```cpp
s.pop(); // Pops (removes) the top element from the stack
```

### Accessing the Top Element
To access the top (most recently added) element in the stack, use the `top` function:

```cpp
int topElement = s.top(); // Retrieves the top element without removing it
```

### Checking if the Stack is Empty
To check if a stack is empty, use the `empty` function:

```cpp
bool isEmpty = s.empty(); // Returns true if the stack is empty, false otherwise
```

### Real-time Usage
#### Scenario 1: Function Call Stack
```cpp
#include <iostream>
#include <stack>

std::stack<int> callStack;

void FunctionA() {
    callStack.push(1);
    FunctionB();
}

void FunctionB() {
    callStack.push(2);
    // ...
    callStack.pop(); // FunctionB finishes, pop its entry
}

int main() {
    FunctionA();
    while (!callStack.empty()) {
        std::cout << "Function called: " << callStack.top() << std::endl;
        callStack.pop();
    }
    return 0;
}
```

#### Scenario 2: Reversing a String
```cpp
#include <iostream>
#include <stack>
#include <string>

std::string ReverseString(const std::string& input) {
    std::stack<char> charStack;
    
    for (char c : input) {
        charStack.push(c);
    }

    std::string reversed;
    while (!charStack.empty()) {
        reversed += charStack.top();
        charStack.pop();
    }

    return reversed;
}

```

### Important Tips
- Stacks are useful for managing elements in a strict last-in-first-out (LIFO) order.
- Use a stack when you need to keep track of the order in which elements were added or when managing function call stacks.
- Be cautious of empty stacks when using the `top` or `pop` functions to avoid runtime errors.
- Use `empty` to check if the stack is empty.


---

# C++ STL Comprehensive Guide - Map

## Introduction
A `std::map` is a container in C++ that stores key-value pairs with unique keys. It is part of the C++ Standard Template Library (STL) and provides efficient key-based access to values. Maps are often used in scenarios where data needs to be stored and retrieved based on a specific key.

### Creating a Map
To create an empty map with a specific key and value type, use the following syntax:

```cpp
std::map<KeyType, ValueType> m;
```

### Inserting Key-Value Pairs
To insert key-value pairs into a map, you can use the `operator[]` or `insert` function:

```cpp
std::map<std::string, int> scores;

scores["Alice"] = 95; // Inserts "Alice" with a score of 95
scores["Bob"] = 88;   // Inserts "Bob" with a score of 88

// OR

scores.insert(std::make_pair("Charlie", 76)); // Inserts "Charlie" with a score of 76
```

### Accessing Values by Key
To access values in a map using their keys, use the `operator[]` or `find` function:

```cpp
int aliceScore = scores["Alice"]; // Retrieves the score of "Alice"
int bobScore = scores.at("Bob");   // Retrieves the score of "Bob"

// OR

std::map<std::string, int>::iterator it = scores.find("Charlie");
if (it != scores.end()) {
    int charlieScore = it->second; // Retrieves the score of "Charlie"
}
```

### Checking if a Key Exists
To check if a key exists in a map, you can use the `find` function:

```cpp
if (scores.find("David") != scores.end()) {
    // Key "David" exists in the map
}
```

### Size of Map
To get the number of key-value pairs in a map, use the `size` function:

```cpp
size_t size = scores.size(); // Returns the number of key-value pairs in the map
```

### Iterating Through a Map
You can use an iterator to iterate through a map:

```cpp
std::map<std::string, int> scores;

// ...

for (const auto& pair : scores) {
    std::cout << "Name: " << pair.first << ", Score: " << pair.second << std::endl;
}
```

### Real-time Usage
#### Scenario 1: Maintaining a Dictionary
```cpp
#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::string> dictionary;

void AddToDictionary(const std::string& word, const std::string& definition) {
    dictionary[word] = definition;
}

std::string GetDefinition(const std::string& word) {
    if (dictionary.find(word) != dictionary.end()) {
        return dictionary[word];
    } else {
        return "Word not found in the dictionary.";
    }
}

int main() {
    AddToDictionary("apple", "A fruit");
    AddToDictionary("book", "A written or printed work");
    
    std::string word = "book";
    std::string definition = GetDefinition(word);
    
    std::cout << "Definition of '" << word << "': " << definition << std::endl;
    
    return 0;
}
```

#### Scenario 2: Word Frequency Counter
```cpp
#include <iostream>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, int> wordFrequency;

void CountWords(const std::string& text) {
    std::istringstream iss(text);
    std::string word;
    
    while (iss >> word) {
        wordFrequency[word]++;
    }
}

int main() {
    std::string text = "This is a sample text. This text is a sample.";
    
    CountWords(text);
    
    for (const auto& pair : wordFrequency) {
        std::cout << "Word: " << pair.first << ", Frequency: " << pair.second << std::endl;
    }
    
    return 0;
}
```

### Important Tips
- Maps are useful when you need to associate unique keys with values.
- Use `operator[]` when you are sure the key exists; it automatically creates a key-value pair if it doesn't exist.
- Use `find` to safely check for the existence of a key without creating a new entry.
- Maps automatically order their keys in ascending order, making them efficient for searching and retrieval by key.


---

# C++ STL Comprehensive Guide - Unordered Map

## Introduction
An `std::unordered_map` is a container in C++ that stores key-value pairs with unique keys in an unordered manner. It is part of the C++ Standard Template Library (STL) and provides fast key-based access to values. Unordered maps are often used in scenarios where data needs to be stored and retrieved based on specific keys, and the order of elements doesn't matter.

### Creating an Unordered Map
To create an empty unordered map with a specific key and value type, use the following syntax:

```cpp
std::unordered_map<KeyType, ValueType> um;
```

### Inserting Key-Value Pairs
To insert key-value pairs into an unordered map, you can use the `operator[]` or `insert` function:

```cpp
std::unordered_map<std::string, int> scores;

scores["Alice"] = 95; // Inserts "Alice" with a score of 95
scores["Bob"] = 88;   // Inserts "Bob" with a score of 88

// OR

scores.insert(std::make_pair("Charlie", 76)); // Inserts "Charlie" with a score of 76
```

### Accessing Values by Key
To access values in an unordered map using their keys, use the `operator[]` or `find` function:

```cpp
int aliceScore = scores["Alice"]; // Retrieves the score of "Alice"
int bobScore = scores.at("Bob");   // Retrieves the score of "Bob"

// OR

std::unordered_map<std::string, int>::iterator it = scores.find("Charlie");
if (it != scores.end()) {
    int charlieScore = it->second; // Retrieves the score of "Charlie"
}
```

### Checking if a Key Exists
To check if a key exists in an unordered map, you can use the `find` function:

```cpp
if (scores.find("David") != scores.end()) {
    // Key "David" exists in the unordered map
}
```

### Size of Unordered Map
To get the number of key-value pairs in an unordered map, use the `size` function:

```cpp
size_t size = scores.size(); // Returns the number of key-value pairs in the unordered map
```

### Iterating Through an Unordered Map
You can use an iterator to iterate through an unordered map:

```cpp
std::unordered_map<std::string, int> scores;

// ...

for (const auto& pair : scores) {
    std::cout << "Name: " << pair.first << ", Score: " << pair.second << std::endl;
}
```

### Real-time Usage
#### Scenario 1: Maintaining a Dictionary
```cpp
#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> dictionary;

void AddToDictionary(const std::string& word, const std::string& definition) {
    dictionary[word] = definition;
}

std::string GetDefinition(const std::string& word) {
    if (dictionary.find(word) != dictionary.end()) {
        return dictionary[word];
    } else {
        return "Word not found in the dictionary.";
    }
}

int main() {
    AddToDictionary("apple", "A fruit");
    AddToDictionary("book", "A written or printed work");
    
    std::string word = "book";
    std::string definition = GetDefinition(word);
    
    std::cout << "Definition of '" << word << "': " << definition << std::endl;
    
    return 0;
}
```

#### Scenario 2: Word Frequency Counter
```cpp
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

std::unordered_map<std::string, int> wordFrequency;

void CountWords(const std::string& text) {
    std::istringstream iss(text);
    std::string word;
    
    while (iss >> word) {
        wordFrequency[word]++;
    }
}

int main() {
    std::string text = "This is a sample text. This text is a sample.";
    
    CountWords(text);
    
    for (const auto& pair : wordFrequency) {
        std::cout << "Word: " << pair.first << ", Frequency: " << pair.second << std::endl;
    }
    
    return 0;
}
```

### Important Tips
- Unordered maps are useful when you need to associate unique keys with values and don't require a specific order of elements.
- Use `operator[]` when you are sure the key exists; it automatically creates a key-value pair if it doesn't exist.
- Use `find` to safely check for the existence of a key without creating a new entry.
- Unordered maps provide fast key-based access, but they do not maintain the order of elements.



---

# C++ Comprehensive Guide - List

## Introduction
A `std::list` is a doubly-linked list container in C++ that allows efficient insertion and removal of elements at both ends and in the middle. It is part of the C++ Standard Template Library (STL) and provides versatility in scenarios where dynamic resizing and efficient element management are required.

### Including the Library
To use `std::list`, include the appropriate header:

```cpp
#include <list>
```

### Creating a List
To create an empty list of a specific type, use the following syntax:

```cpp
std::list<T> myList;
```

### Adding Elements
To add elements to a list, you can use the `push_back` and `push_front` functions:

```cpp
std::list<int> myList;
myList.push_back(42);  // Adds 42 to the end of the list
myList.push_front(10); // Adds 10 to the front of the list
```

### Accessing Elements
Accessing elements in a list is slightly different from arrays. You can't use the subscript operator directly, but you can use iterators:

```cpp
std::list<int> myList;

// ...

std::list<int>::iterator it = myList.begin(); // Iterator pointing to the first element
int firstElement = *it; // Accessing the first element using the iterator

// OR

int secondElement = std::next(myList.begin(), 1); // Accessing the second element
```

### Size of List
To get the number of elements in a list, use the `size` function:

```cpp
size_t size = myList.size(); // Returns the number of elements in the list
```

### Iterating Through a List
You can use iterators to iterate through a list:

```cpp
std::list<int> myList;

// ...

for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
    // Access and manipulate *it (the current element)
}
```

### Inserting at a Specific Position
To insert an element at a specific position, you can use the `insert` function:

```cpp
std::list<int> myList;

// ...

std::list<int>::iterator it = std::next(myList.begin(), 2); // Iterator pointing to the third element
myList.insert(it, 99); // Inserts 99 before the third element
```

### Removing Elements
To remove elements from a list, you can use the `pop_back`, `pop_front`, or `erase` functions:

```cpp
myList.pop_back(); // Removes the last element
myList.pop_front(); // Removes the first element

std::list<int>::iterator it = std::next(myList.begin(), 2); // Iterator pointing to the third element
myList.erase(it); // Removes the element pointed to by 'it'
```

### Real-time Usage
#### Scenario 1: Implementing a To-Do List
```cpp
#include <iostream>
#include <list>
#include <string>

std::list<std::string> toDoList;

void AddTask(const std::string& task) {
    toDoList.push_back(task);
}

void RemoveTask(const std::string& task) {
    toDoList.remove(task);
}

int main() {
    AddTask("Buy groceries");
    AddTask("Finish report");
    RemoveTask("Buy groceries");

    std::cout << "To-Do List:" << std::endl;
    for (const std::string& task : toDoList) {
        std::cout << "- " << task << std::endl;
    }

    return 0;
}
```

#### Scenario 2: Implementing a Doubly Linked List
```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    std::cout << "Original List:" << std::endl;
    for (int num : myList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Insert 99 after the second element
    std::list<int>::iterator it = std::next(myList.begin(), 1);
    myList.insert(it, 99);

    // Remove the last element
    myList.pop_back();

    std::cout << "Modified List:" << std::endl;
    for (int num : myList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Important Tips
- Lists are useful when you need dynamic resizing and efficient insertion/removal at both ends and in the middle.
- Iterators are commonly used for accessing and manipulating elements in lists.
- Be cautious of iterator invalidation when adding or removing elements, as it may affect the integrity of your list.


---

# C++ Comprehensive Guide - Set

## Introduction
A `std::set` is a container in C++ that stores unique elements in sorted order. It is part of the C++ Standard Template Library (STL) and provides a convenient way to work with sorted collections of data. Sets are often used when you need to maintain a collection of unique values and perform operations like insertion, deletion, and searching efficiently.

### Including the Library
To use `std::set`, include the appropriate header:

```cpp
#include <set>
```

### Creating a Set
To create an empty set of a specific type, use the following syntax:

```cpp
std::set<T> mySet;
```

For example, to create a set of integers:

```cpp
std::set<int> myIntSet;
```

### Inserting Elements
To add elements to a set, you can use the `insert` function:

```cpp
std::set<int> mySet;
mySet.insert(42);  // Adds 42 to the set
mySet.insert(10);  // Adds 10 to the set
```

### Accessing Elements
You can access elements in a set using iterators:

```cpp
std::set<int> mySet;

// ...

std::set<int>::iterator it = mySet.find(42); // Iterator pointing to 42
if (it != mySet.end()) {
    // Element 42 found
    int value = *it; // Accessing the value using the iterator
}
```

### Size of Set
To get the number of elements in a set, use the `size` function:

```cpp
size_t size = mySet.size(); // Returns the number of elements in the set
```

### Iterating Through a Set
You can use iterators to iterate through a set:

```cpp
std::set<int> mySet;

// ...

for (std::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
    // Access and manipulate *it (the current element)
}
```

### Removing Elements
To remove elements from a set, you can use the `erase` function:

```cpp
std::set<int> mySet;

// ...

mySet.erase(42); // Removes the element with the value 42
```

### Real-time Usage
#### Scenario 1: Finding Unique Elements
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> uniqueNumbers;

    uniqueNumbers.insert(5);
    uniqueNumbers.insert(2);
    uniqueNumbers.insert(8);
    uniqueNumbers.insert(5); // Ignored since 5 is already in the set

    std::cout << "Unique Numbers:" << std::endl;
    for (int num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### Scenario 2: Checking for Element Existence
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<std::string> uniqueNames;

    uniqueNames.insert("Alice");
    uniqueNames.insert("Bob");
    
    std::string nameToFind = "Charlie";

    if (uniqueNames.find(nameToFind) != uniqueNames.end()) {
        std::cout << nameToFind << " found in the set." << std::endl;
    } else {
        std::cout << nameToFind << " not found in the set." << std::endl;
    }

    return 0;
}
```

### Important Tips
- Sets are useful when you need to maintain a collection of unique values in sorted order.
- Elements in a set are automatically sorted in ascending order.
- Use `insert` to add elements, and they will be automatically sorted and made unique.
- Use `find` to efficiently check for the existence of an element.
- Sets provide efficient insertion, deletion, and search operations.


---

# C++ Comprehensive Guide - Algorithms

## Introduction
Algorithms in C++ are a set of reusable functions provided by the C++ Standard Template Library (STL) that allow you to perform various operations on containers and sequences. Algorithms provide efficient and generic solutions for tasks such as sorting, searching, and manipulating data in containers.

### Including the Library
To use algorithms, include the appropriate header:

```cpp
#include <algorithm>
```

### Key Concepts
- **Iterators**: Algorithms operate on sequences of elements using iterators. Iterators provide a way to traverse and manipulate the elements in a container.
- **Predicate**: Many algorithms take a predicate, which is a function or a lambda that defines a condition or operation applied to elements.
- **Function Objects (Functors)**: Functors are objects that act like functions and can be used as predicates in algorithms.
- **Complexity**: Understanding the time and space complexity of algorithms is essential for choosing the right one for your needs.

### Sorting
#### `std::sort`
The `std::sort` algorithm arranges elements in ascending order by default but can be customized for different sorting criteria.

```cpp
std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
std::sort(numbers.begin(), numbers.end()); // Sort in ascending order
```

#### `std::stable_sort`
`std::stable_sort` is similar to `std::sort` but preserves the relative order of equal elements.

```cpp
std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
std::stable_sort(numbers.begin(), numbers.end()); // Sort while preserving order
```

### Searching
#### `std::find`
The `std::find` algorithm searches for a specific value in a container.

```cpp
std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
auto it = std::find(numbers.begin(), numbers.end(), 4); // Search for 4
if (it != numbers.end()) {
    // 4 found
}
```

#### `std::binary_search`
`std::binary_search` checks if an element exists in a sorted container using binary search.

```cpp
std::vector<int> sortedNumbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool found = std::binary_search(sortedNumbers.begin(), sortedNumbers.end(), 5); // Check if 5 exists
```

### Aggregating
#### `std::accumulate`
The `std::accumulate` algorithm computes the sum (or other binary operation) of elements in a range.

```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};
int sum = std::accumulate(numbers.begin(), numbers.end(), 0); // Sum of numbers
```

### Modifying
#### `std::transform`
The `std::transform` algorithm applies an operation to elements and stores the result in another container.

```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};
std::vector<int> squaredNumbers;
std::transform(numbers.begin(), numbers.end(), std::back_inserter(squaredNumbers), [](int n) {
    return n * n; // Square each number
});
```

### Removing
#### `std::remove`
The `std::remove` algorithm moves elements matching a condition to the end of the container and returns an iterator pointing to the new end.

```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};
auto newEnd = std::remove(numbers.begin(), numbers.end(), 3); // Remove all 3s
numbers.erase(newEnd, numbers.end()); // Erase the removed elements
```

### Real-time Usage
#### Scenario 1: Finding Maximum Element
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    auto maxElement = std::max_element(numbers.begin(), numbers.end());

    if (maxElement != numbers.end()) {
        std::cout << "Maximum element: " << *maxElement << std::endl;
    }

    return 0;
}
```

#### Scenario 2: Counting Occurrences
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int count = std::count(numbers.begin(), numbers.end(), 5);

    std::cout << "Number of 5s: " << count << std::endl;

    return 0;
}
```

### Important Tips
- Algorithms in C++ provide powerful and efficient operations for various tasks.
- Understand the requirements of your problem to choose the most suitable algorithm.
- Leverage function objects (functors) or lambda expressions to customize algorithm behavior.
- Pay attention to the complexities (time and space) of algorithms for performance considerations.
- Always include the appropriate header `<algorithm>` when using algorithms.



# Extras

In C++, functors and lambdas are both mechanisms for defining and using functions as objects, which can be particularly useful when working with algorithms like `std::transform`. 

**Functors:**
A functor, short for "function object," is a user-defined type that overloads the `operator()` function. This allows you to create objects that can be called like functions. Functors are often used when you want to pass a custom operation or behavior to an algorithm, like `std::sort` or `std::transform`. Here's an example of a functor:

```cpp
struct MyFunctor {
    int operator()(int x) {
        return x * 2;
    }
};
```

You can then use an instance of `MyFunctor` just like a function:

```cpp
MyFunctor doubleFunction;
int result = doubleFunction(5); // result is 10
```

**Lambdas:**
Lambdas are a more concise and convenient way to define small, inline functions. They were introduced in C++11 and are especially handy when you need a simple, one-time-use function. A lambda has the following general syntax:

```cpp
[ captures ] ( parameters ) -> return_type {
    // function body
}
```

For example, the following lambda squares an integer:

```cpp
auto square = [](int x) -> int {
    return x * x;
};
int result = square(5); // result is 25
```

Now, let's analyze the code snippet you provided:

```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};
std::vector<int> squaredNumbers;
std::transform(numbers.begin(), numbers.end(), std::back_inserter(squaredNumbers), [](int n) {
    return n * n; // Square each number
});
```

This code uses the `std::transform` algorithm to apply a transformation to each element in the `numbers` vector and store the results in the `squaredNumbers` vector.

Here's a step-by-step breakdown:

1. `std::vector<int> numbers = {1, 2, 3, 4, 5};`: Initializes a vector named `numbers` containing integers from 1 to 5.

2. `std::vector<int> squaredNumbers;`: Declares an empty vector named `squaredNumbers` that will store the squared values.

3. `std::transform(numbers.begin(), numbers.end(), std::back_inserter(squaredNumbers), [](int n) { return n * n; });`:
   - `std::transform` is an algorithm that applies a given operation to each element in a range and stores the results in another range.
   - `numbers.begin()` and `numbers.end()` define the input range, which includes all elements in the `numbers` vector.
   - `std::back_inserter(squaredNumbers)` specifies the output range and uses `std::back_inserter`, which inserts elements at the end of the `squaredNumbers` vector.
   - `[](int n) { return n * n; }` is a lambda function that takes an integer `n` and returns its square.

The lambda is called for each element in `numbers`, squaring each element, and the results are inserted at the end of the `squaredNumbers` vector. After execution, `squaredNumbers` will contain the squared values of the original `numbers` vector, which would be `{1, 4, 9, 16, 25}`.



---

# C++ Comprehensive Guide - Multi Set, Multi Map, Bitset, and Tuple

## Multi Set and Multi Map
`std::multiset` and `std::multimap` are associative containers that allow multiple elements with the same key. They are part of the C++ Standard Template Library (STL) and are useful when you need to maintain collections of elements sorted by keys.

### Including the Library
To use `std::multiset` and `std::multimap`, include the appropriate header:

```cpp
#include <set> // For std::multiset
#include <map> // For std::multimap
```

### Creating Multi Set and Multi Map
To create empty multi sets and multi maps, use the following syntax:

```cpp
std::multiset<T> myMultiSet;
std::multimap<K, V> myMultiMap;
```

For example, to create a multi set of integers and a multi map of strings to integers:

```cpp
std::multiset<int> myIntMultiSet;
std::multimap<std::string, int> myStringIntMultiMap;
```

### Inserting Elements
You can insert elements into `std::multiset` and `std::multimap` using the `insert` function:

```cpp
std::multiset<int> myMultiSet;
myMultiSet.insert(42); // Inserts 42 into the multi set

std::multimap<std::string, int> myMultiMap;
myMultiMap.insert({"Alice", 25}); // Inserts {"Alice", 25} into the multi map
```

### Accessing Elements
You can access elements in `std::multiset` and `std::multimap` using iterators. Since there can be multiple elements with the same key, iterators point to ranges of elements.

```cpp
std::multiset<int> myMultiSet = {42, 42, 10, 30, 10};
auto range = myMultiSet.equal_range(10); // Returns a pair of iterators for the range of elements with key 10

for (auto it = range.first; it != range.second; ++it) {
    // Access and work with *it (current element with key 10)
}
```

### Bitset
`std::bitset` is a container that stores a fixed number of bits, each of which can be either 0 or 1. It is useful for efficiently manipulating and storing binary data.

### Including the Library
To use `std::bitset`, include the appropriate header:

```cpp
#include <bitset>
```

### Creating a Bitset
To create a `std::bitset`, specify the number of bits it should hold:

```cpp
std::bitset<N> myBitset;
```

For example, to create a `std::bitset` with 8 bits:

```cpp
std::bitset<8> my8Bitset;
```

### Setting and Clearing Bits
You can set or clear individual bits using the `set` and `reset` functions:

```cpp
my8Bitset.set(2);   // Sets the third bit (index 2) to 1
my8Bitset.reset(5); // Resets the sixth bit (index 5) to 0
```

### Accessing Bits
You can access individual bits using the subscript operator `[]`:

```cpp
bool bitValue = my8Bitset[3]; // Access the fourth bit (index 3)
```

### Tuple
`std::tuple` is a container that can hold a fixed number of elements of different types. It provides a way to group and work with heterogeneous data.

### Including the Library
To use `std::tuple`, include the appropriate header:

```cpp
#include <tuple>
```

### Creating a Tuple
To create a `std::tuple`, specify the types of elements it should hold:

```cpp
std::tuple<T1, T2, T3, ...> myTuple;
```

For example, to create a tuple containing an integer, a string, and a double:

```cpp
std::tuple<int, std::string, double> myTuple;
```

### Accessing Elements
You can access elements in a `std::tuple` using the `std::get` function:

```cpp
std::tuple<int, std::string, double> myTuple(42, "Hello, World!", 3.14);
int intValue = std::get<0>(myTuple);       // Access the integer (index 0)
std::string stringValue = std::get<1>(myTuple); // Access the string (index 1)
double doubleValue = std::get<2>(myTuple);   // Access the double (index 2)
```

### Real-time Usage
#### Scenario 1: Using Multi Set and Multi Map
```cpp
#include <iostream>
#include <set>
#include <map>

int main() {
    std::multiset<int

> multiSet = {42, 42, 10, 30, 10};
    std::multimap<std::string, int> multiMap;

    multiMap.insert({"Alice", 25});
    multiMap.insert({"Bob", 30});
    multiMap.insert({"Alice", 28});

    // Access all values associated with the key "Alice"
    auto range = multiMap.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
```

#### Scenario 2: Using Bitset
```cpp
#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> myBitset;

    myBitset.set(2);    // Set the third bit (index 2)
    myBitset.reset(5);  // Reset the sixth bit (index 5)
    myBitset.flip(7);   // Toggle the eighth bit (index 7)

    for (int i = 0; i < myBitset.size(); ++i) {
        std::cout << myBitset[i];
    }

    std::cout << std::endl;

    return 0;
}
```

#### Scenario 3: Using Tuple
```cpp
#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, std::string, double> myTuple(42, "Hello, World!", 3.14);

    int intValue = std::get<0>(myTuple);
    std::string stringValue = std::get<1>(myTuple);
    double doubleValue = std::get<2>(myTuple);

    std::cout << "Int: " << intValue << std::endl;
    std::cout << "String: " << stringValue << std::endl;
    std::cout << "Double: " << doubleValue << std::endl;

    return 0;
}
```

### Important Tips
- `std::multiset` and `std::multimap` allow multiple elements with the same key.
- `std::bitset` is used for efficient manipulation of binary data.
- `std::tuple` allows grouping of heterogeneous data types.
- When using `std::tuple`, remember the index-based element access.

---

# Iterators

Iterators in C++ are fundamental components that provide a way to traverse and manipulate elements within a container or a sequence. They act as a bridge between your code and the underlying data structure, allowing you to access and modify elements without exposing the internal implementation details of the container. Here's a detailed explanation of how iterators work, both in terms of memory and functionality:

## What is an Iterator?

An iterator is an object or a pointer-like entity that points to a specific element within a container. It allows you to navigate through the elements of a container, read their values, and modify them. Iterators provide a uniform way to interact with different types of containers, abstracting away the underlying data structure.

## Types of Iterators

There are several types of iterators in C++, each tailored to specific functionalities and characteristics of containers. The most common types include:

1. **Begin and End Iterators**:
   - `begin()`: Points to the first element in the container.
   - `end()`: Points one past the last element in the container.

2. **Reverse Iterators**:
   - `rbegin()`: Points to the last element in the container.
   - `rend()`: Points to one position before the first element in the container (the position where `begin()` would point).

3. **Insertion and Deletion Iterators**:
   - `inserter()`: Allows insertion at a specified position in certain containers.
   - `back_inserter()`: Allows insertion at the end of a container.
   - `front_inserter()`: Allows insertion at the front of a container.

4. **Iterator Categories**:
   - Input Iterators: Support single-pass read-only access (e.g., `std::istream_iterator`).
   - Output Iterators: Support single-pass write-only access (e.g., `std::ostream_iterator`).
   - Forward Iterators: Support multi-pass read-write access (e.g., `std::forward_list`).
   - Bidirectional Iterators: Support multi-pass read-write access and reverse traversal (e.g., `std::list`).
   - Random-Access Iterators: Support all iterator operations efficiently (e.g., `std::vector`, `std::array`).

## How Iterators Work (Memory-wise)

- **Memory Efficiency**: Iterators are lightweight objects that consume very little memory. They typically consist of a pointer (or an index) to the current element and some additional information needed for navigation.

- **Pointer-like Behavior**: In many cases, iterators behave like pointers. They support operations like dereferencing (using `*`), pointer arithmetic (e.g., `++`, `--`, `+`, `-`), and comparison (e.g., `<`, `<=`, `>`, `>=`) to navigate through the elements of a container.

- **Abstraction**: Iterators provide an abstraction layer that hides the container's internal memory layout. Regardless of the actual container type (e.g., array, list, vector), you can use iterators uniformly.

- **Safety**: Iterators help ensure memory safety by preventing you from accessing or modifying elements outside the container's boundaries. For example, `end()` points one past the last element, and accessing it is undefined behavior.

## Common Iterator Operations

1. **Dereferencing**: Access the value of the element pointed to by the iterator using `*`.

2. **Increment/Decrement**: Move the iterator to the next (`++`) or previous (`--`) element.

3. **Arithmetic Operations**: Some iterators support arithmetic operations, allowing you to jump to specific elements efficiently (e.g., `it + 3`).

4. **Equality/Inequality Comparison**: Compare two iterators for equality (`==`) or inequality (`!=`).

5. **Member Functions**: Iterators may provide additional member functions based on their type, such as `->` for accessing the member of a struct contained in a container.

## Iterator Example

Here's a simple example using an iterator to traverse a `std::vector`:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Using an iterator to traverse the vector
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " "; // Dereferencing the iterator to access the element
    }

    return 0;
}
```

In this example, we use the `begin()` and `end()` iterators to loop through the `std::vector`, demonstrating the basic functionality of iterators.

## Iterator Invalidation

It's important to note that iterators can become invalidated under certain conditions. For example, if you add or remove elements from a container, iterators may no longer be valid. Care must be taken to ensure that iterators are still valid when used.

## Summary

Iterators are essential components in C++ for traversing and manipulating container elements. They provide a consistent interface for working with different container types and hide the underlying memory details. By understanding the various iterator types and their behaviors, you can efficiently work with containers while maintaining memory safety.

 

---

# C++ Comprehensive Guide - Smart Pointers

## Introduction
Smart pointers are a group of classes in the C++ Standard Library that manage dynamic memory automatically. They are "smart" because they take care of memory allocation and deallocation, making it easier to write safe and reliable C++ code. Smart pointers are essential for preventing memory leaks, dangling pointers, and managing the lifetime of dynamically allocated objects.

## Types of Smart Pointers
C++ provides three types of smart pointers:

1. **`std::shared_ptr`**: Shared pointers allow multiple pointers to share ownership of a dynamically allocated object. The object is deleted automatically when the last shared pointer that owns it goes out of scope.

2. **`std::unique_ptr`**: Unique pointers represent exclusive ownership of a dynamically allocated object. Only one unique pointer can own an object, and when the unique pointer goes out of scope, the object is automatically deleted.

3. **`std::weak_ptr`**: Weak pointers are used in conjunction with shared pointers to break circular references. They do not affect the object's lifetime but can be converted to shared pointers when needed.

### Including the Library
To use smart pointers, include the appropriate header:

```cpp
#include <memory>
```

## Creating Smart Pointers
### `std::shared_ptr`
To create a shared pointer, use `std::make_shared` or `std::shared_ptr` constructor:

```cpp
std::shared_ptr<int> sharedInt = std::make_shared<int>(42);
```

### `std::unique_ptr`
To create a unique pointer, use `std::make_unique` or `std::unique_ptr` constructor:

```cpp
std::unique_ptr<double> uniqueDouble = std::make_unique<double>(3.14);
```

## Accessing Pointed Data
To access the data pointed to by a smart pointer, you can use the `*` and `->` operators, just like with raw pointers:

```cpp
int value = *sharedInt;        // Dereferencing shared pointer
double doubleValue = *uniqueDouble;  // Dereferencing unique pointer
```

## Smart Pointer Ownership
### `std::shared_ptr`
Multiple shared pointers can share ownership of the same object. When the last shared pointer owning the object is destroyed or reset, the object is deleted.

```cpp
std::shared_ptr<int> sharedA = std::make_shared<int>(10);
std::shared_ptr<int> sharedB = sharedA;  // Both sharedA and sharedB own the same object
```

### `std::unique_ptr`
A unique pointer represents exclusive ownership. When a unique pointer goes out of scope, or when you explicitly transfer ownership, the object is deleted.

```cpp
std::unique_ptr<int> uniqueA = std::make_unique<int>(20);
std::unique_ptr<int> uniqueB = std::move(uniqueA);  // Transfer ownership from uniqueA to uniqueB
```

## Converting `std::unique_ptr` to `std::shared_ptr`
You can convert a `std::unique_ptr` to a `std::shared_ptr` if needed:

```cpp
std::unique_ptr<int> uniquePtr = std::make_unique<int>(30);
std::shared_ptr<int> sharedPtr = std::move(uniquePtr);  // Convert uniquePtr to sharedPtr
```

## Cyclic References and `std::weak_ptr`
To break cyclic references (where objects reference each other and prevent each other from being deleted), you can use `std::weak_ptr`. A `std::weak_ptr` does not affect the object's ownership and can be converted to a `std::shared_ptr` when needed.

```cpp
class Node {
public:
    Node(std::shared_ptr<Node> next) : next_(next) {}

private:
    std::weak_ptr<Node> next_;
};
```

## Real-time Usage
### Scenario 1: Using `std::shared_ptr` for Shared Ownership
```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int value) : value_(value) {}

    void Print() {
        std::cout << "Value: " << value_ << std::endl;
    }

private:
    int value_;
};

int main() {
    std::shared_ptr<MyClass> sharedObject = std::make_shared<MyClass>(42);
    sharedObject->Print();

    return 0;
}
```

### Scenario 2: Using `std::unique_ptr` for Exclusive Ownership
```cpp
#include <iostream>
#include <memory>

class MyResource {
public:
    MyResource() {
        std::cout << "Resource acquired." << std::endl;
    }

    ~MyResource() {
        std::cout << "Resource released." << std::endl;
    }
};

int main() {
    std::unique_ptr<MyResource> uniqueResource = std::make_unique<MyResource>();

    return 0;
}
```

### Scenario 3: Using `std::weak_ptr` to Break Cyclic References
```cpp
#include <iostream>
#include <memory>

class Node {
public:
    Node(int data) : data_(data) {}

    std::shared_ptr<Node> GetNext() {
        return next_.lock();
    }

    void SetNext(std::shared_ptr<Node> next) {
        next_ = next;
    }

    int

 GetData() {
        return data_;
    }

private:
    int data_;
    std::weak_ptr<Node> next_;
};

int main() {
    std::shared_ptr<Node> nodeA = std::make_shared<Node>(1);
    std::shared_ptr<Node> nodeB = std::make_shared<Node>(2);

    nodeA->SetNext(nodeB);
    nodeB->SetNext(nodeA);  // Creating a cyclic reference

    // To break the cyclic reference and allow objects to be deleted
    nodeA->SetNext(nullptr);
    nodeB->SetNext(nullptr);

    return 0;
}
```

## Important Tips
- Use `std::shared_ptr` when multiple pointers need to share ownership.
- Use `std::unique_ptr` for exclusive ownership or when transferring ownership.
- Be cautious with cyclic references and use `std::weak_ptr` to break them when necessary.
- Smart pointers automatically release memory when objects go out of scope.

Smart pointers in C++ significantly simplify memory management, enhance code safety, and reduce the risk of memory leaks. They are a crucial feature for modern C++ programming.

---

# C++ Comprehensive Guide - Functors and Lambdas

## Introduction
Functors (function objects) and lambdas are techniques in C++ that enable you to treat functions as objects, making them versatile and customizable. They are widely used for specifying custom behavior, particularly with algorithms, sorting, and predicates.

## Functors (Function Objects)
Functors are objects that behave like functions. They are instances of classes that implement the `operator()` function. Functors can encapsulate state and behavior, making them flexible for customization.

### Creating Functors
To create a functor, define a class with the `operator()` overloaded:

```cpp
class MyFunctor {
public:
    int operator()(int x, int y) {
        return x + y;
    }
};
```

### Using Functors
You can use functors as if they were functions:

```cpp
MyFunctor add;
int result = add(3, 4);  // Equivalent to add.operator()(3, 4)
```

### Real-time Usage
#### Scenario 1: Sorting with Functors
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Comparator {
public:
    bool operator()(int a, int b) {
        return a > b; // Sort in descending order
    }
};

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 9};
    Comparator cmp;

    std::sort(numbers.begin(), numbers.end(), cmp); // Sorting using the functor

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```

#### Scenario 2: Custom Predicate with Functors
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class IsEven {
public:
    bool operator()(int num) {
        return num % 2 == 0;
    }
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    IsEven isEven;

    int evenCount = std::count_if(numbers.begin(), numbers.end(), isEven);

    std::cout << "Number of even elements: " << evenCount << std::endl;

    return 0;
}
```

## Lambdas
Lambdas are anonymous functions that can be defined directly in your code. They offer a concise and readable way to create small, one-time-use functions.

### Creating Lambdas
A lambda has the following syntax:

```cpp
[ captures ] ( parameters ) -> return_type {
    // Function body
}
```

- **captures**: Variables from the outer scope that the lambda can access.
- **parameters**: Parameters passed to the lambda function.
- **return_type**: The return type of the lambda.

Example:

```cpp
auto add = [](int a, int b) -> int {
    return a + b;
};
```

### Using Lambdas
Lambdas are used like regular functions:

```cpp
int result = add(3, 4); // Call the lambda function
```

### Real-time Usage
#### Scenario 1: Using Lambdas with Standard Algorithms
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 9};

    // Using a lambda to sort in ascending order
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
    });

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```

#### Scenario 2: Custom Predicate with Lambdas
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};

    // Using a lambda as a custom predicate
    int evenCount = std::count_if(numbers.begin(), numbers.end(), [](int num) {
        return num % 2 == 0;
    });

    std::cout << "Number of even elements: " << evenCount << std::endl;

    return 0;
}
```

## Important Tips
- Functors are classes that implement the `operator()` function to enable function-like behavior.
- Lambdas provide a concise way to define anonymous functions directly in your code.
- Both functors and lambdas are versatile for customizing behavior, especially with algorithms and predicates.
- Lambdas can capture variables from their enclosing scope, allowing for flexible behavior customization.

Functors and lambdas are essential tools in C++ for customizing behavior in a clean and flexible way. They are particularly useful when working with algorithms, sorting, and predicates in your code.