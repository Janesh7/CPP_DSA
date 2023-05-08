# STL
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


## Deque
DOUBLY ENDED QUQUE(deq)
- We can push/pop from BOTH th ends
- NOT CONTIGOUS LIKE vector or array; multiple fixed static arrays top store the elements are these are tracked
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