# STL
Standard template library

# Array 
can include<array>
- to create <b>array<type, size></b> varname , Ex array<int,4> arr = {1,2,3,4}
- it is static i ey not used much , have to specify the size
- FUNCTIONS: arr.size(), 
    arr.empty() -> tell whether empty or not, 
    arr.first() -> returns the first element, 
    arr.back() -> returns last element, 
    arr.at(2) -> returns the element at index 2

# Vector 
- dynamic: If initially the size of vector is 4 and 5th element is added then the size of the vector DOUBLES
- <b>It creates a NEW vector of double the size of the previous vector and places/copy the elements in it</b>
- Size : how much elements it is having currently. This can be determined using size function ie arr.size()
- <b>Capacity : how much memeory is allocated to the vector. This can be determined using capacity function ie arr.capacity()</b>
- Ex: If i create a vector v: vector<int> v; its size and cap are 0; v.push_back(0) if i add 1 element: size and cap 1; v.push_back(1) - size and cap 2; BUT now if we add another element v.push_back(2) , the size becomes 3 and the capacity BECOMES 4 (ie 2*2)
- FUNCTIONS: v.first() -> returns the first element, 
    v.back() -> returns last element, 
    <b>v.pop_back() -> Pops the last element inserted </b>
    <b>v.clear() -> makes the size of the v to 0 BUT NOT CAPACITY</b>