# STL
Standard template library

# Array 
can include<array>
- to create array<type, size> varname , Ex array<int,4> arr = {1,2,3,4}
- it is static i ey not used much , have to specify the size
- FUNCTIONS: arr.size(), 
    arr.empty() -> tell whether empty or not, 
    arr.first() -> returns the first element, 
    arr.back() -> returns last element, 
    arr.at(2) -> returns the element at index 2

# Vector 
- dynamic: If initially the size of vector is 4 and 5th element is added then the size of the vector DOUBLES
- It creates a NEW vector of double the size of the previous vector and places/copy the elements in it
