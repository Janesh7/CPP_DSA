# STL
Standard template library

# Array 
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

# Vector 
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

# Deque
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

# List
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