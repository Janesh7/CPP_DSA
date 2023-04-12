# Reference Variable
To create a refrence variable 
```
int i = 5;
int& j = i // CREATING A REF VAR
```

- Basically we r creating a reference to the same memory as i, so i++ or j++ would lead to the same result
- ie Same memory different names

Why do we need this?


We know that in cpp, the parameters are passed by values in function, and any updation on it will not reflect outside. Therefore if we want to pass by reference we can pass the REFERENCE VARIABLE in the func. the func should be defined as:
```
int funct(int& n) { return n++;}
```
ie we r creating a ref variable to the same memory instead of creating a new copied value of the parameter.
- This saves the memory as in pass by value a new memory is used
- We can use REFERENCE VARIABLE as a return type also: (BUT DONT USE, USE WISELY)
```
int& update(int n)
{
    int a = 10;
    int& ans = a;
    return ans;
}
```
^ THIS CODE GIVES WARNING


NOTE: THIS IS A VERY BAD PRACTISE AS U CAN SEE WE HAVE CREATED A LOCAL VARIABLE a AND WE ARE RETURNING ITS REF, WKT THE VARIBLE A'S MEMORY WOULD BE DELETED ONCE THE FUNCTION IS FULLY EXECUTED
SAME GOES WITH A POINTER



# Memory Allocation

- Wkt, cin>>n; int arr[n]; is a very bad practise, coz we r initializing the memory in runtime, but should be KNOWN by complie time.
- WHY it should be known at complie time and not run time??? 



<b> When a program is executed, a small stack memory is allocated and large heap memory is allocated.SO if we do int arr[10000] it would create a larger stack accordingly(which is done at complie time). So if we r doing at runtime, the stack alloacted would be small and if the stack required is big program will crash</b>


- When we create a var it is stored in stack(static memory alloc). 
- For variable size memory allocation we use heap memory, and not use ^ practise.
- TO USE HEAP MEMORY: WE HAVE TO USE KEYWORD **new** . (dynamic memory alloc)
- NO NAME IS ALLOWED IN HEAP
- Therefore to create a char variable dynamically:
```
new char;
```
is used... this returns an address and that can be stored as a pounter. Therefore full syntax:
```
char* ch = new char;
```
- Takes 9 bytes of memory (8+1), ch->1, and ptr->8
- WHAT HAPPENS INTERNALLY?


So, a memory for char is stored in heap, and the address is returned. **POINTER IS CREATED IN STACK** and points to the memory in heap.

- A pointer takes 8 byte in 64 bit system anf 4 byte in 32 bit system.

```
int* i = new int;
```
12 bytes (8+4 bytes)




