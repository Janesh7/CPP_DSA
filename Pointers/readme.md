# Pointers

Symbol table: is an important ds created by the compiler in order to keep track of semantics of variable ie it stores informatiom about the scope and binding information about names, information about instances of various entities such as variable and function names, classes, objects, etc.

- a variable is mapped to corresponding address (where the value can be found)        || var -> mem addy ||
- Content of symbol table CANNOT be changed 


<b>ADDRESS OF OPERATOR (& operator) -> returns the address of the memory, IT IS HEXADECIMAL FORMAT</b>

- WHY pointer is used?

<b> POINTER is a variable to store an memory addres .Ex int *ptr = &i; </br>
    NOTE: int *ptr; is avery bad practice, this means we initailized a pointer and it stores and random memory address which can be modified, rather initialize to 0, NULL . ie no memory exists for now ( if u try to print the value of it, segmentation fault)
</b>
- int *ptr = &num; means p and num BOTH are pointing to the same memory address, soo doing num++ and (*p)++ would yield the  same result
<datatype> *p -> systanx to create a pointer, the pointer created is pointing to the <datatype>
<b> * - is a DEREFERENCE OPERATOR , means VALUE OF, ie tell the value in the memory addy</b>

- Size of a pointer of anything is ALWAYS 8 and size of an address is also 8

int *ptr = 0;
<b>ptr = &i; // NOTE : NO * WHILE POINTING THE ADDRESS</b>

- IMP: if we do int *p = &n; int a = *p; and then a++ WILL NOT change the value of n rather only a is changed.
This is because a store the VALUE refrenced by the pointer coz we used deref op. and not the pointer.
If (*p)++ is done thenn n value is changed.

NOTE: ALWAYS USE BRACKETS FOR ABOVE OPERATION

- To copy the pointer : int *q = p; // p in above

<b>IMP: When u try to increment the pointer address</b>
- if u do p = p+1;
let p be the pointer storing the address of an int, and let the adress be 100, then p = p+1 wont become 101 BUT rather would become 104 as int take 4 storage unit so it points to the next int, if it was pointing to a double, then it would go to 108


#### Array name as a pointer
The array's name contains the address of the first element of the array, so you can not change the address stored in the array name. The array's name acts as a constant pointer. You can assign the address of an array to a pointer without using an ampersand (&).

Code
```
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[4]={12,15,20,50};
    int *ptr;         // declaration of void pointer variable
    ptr=arr;          // assign the address of arr[0] to ptr
    for(int i=0;i<4;i++)
    {
        cout<<*ptr<<endl;
        ptr++;         // increment pointer ptr by 1 
    }
    return 0;
}
```

Some advantages of using Pointers are given below:

- Pointers are the variables that are used to store the address of other variables in C/C++.
- Pointer allows us to allocate and deallocate the memory dynamically.
- Pointers help us in simplifying the complexity of the program.
- With the help of pointers, we can improve the execution speed of a program.
- With the help of pointers, we can modify and return more than one variable from a function. 

Types of pointers in C++
 

There are different types of pointers in C++, and they are as follows:

- Null Pointers
- Double Pointers
- Void Pointers
- Wild Pointers
- Dangling Pointer
 

## 1. Null Pointers: 
A NULL pointer is a pointer that is pointing to nothing. If we don’t have the address to be assigned to a pointer, we can use NULL.

 

Advantages of Null pointer are:

- We can initialize a pointer variable when that pointer variable is not assigned any actual memory address.
- We can pass a null pointer to a function argument when we are unwilling to pass any actual memory address.
 

Example:

```
int *p; //Contains garbage value
int *p = NULL; //NULL is constant with vaue 0
int *q = 0; // Same as above
```


Here, we have created a pointer variable that contains garbage values. To dereference the pointer, we have initialized it to NULL to avoid unexpected behavior.

 

Note: An uninitialized pointer variable contains garbage; this will lead to unexpected results or segmentation faults. Hence, we should never leave a pointer uninitialized and instead.

 

Example:

```
#include <iostream>
using namespace std;
int main() {
    // Null Pointer 
    int * ptr = NULL;
    cout << "The value of ptr is " << ptr;
    return 0;
}
```

Output:
The value of ptr is 0
 

 

## 2. Double Pointers:  
We can create a pointer to a pointer that in turn may point to data or another pointer. The first pointer is used to store the address of the variable. And the second pointer is used to store the address of the first pointer. That is why they are also known as double pointers.

 

Example:

```
int a = 10;
int *p = &a; 
int **q = &p;
```
 

Here q is a pointer to a pointer, i.e., a double-pointer, as indicated by **.

 

Example:

```
#include<iostream>
using namespace std;
int main() {
    int a = 10;
    int * p = & a; //pointer
    int ** q = & p; //pointer-to-pointer
    /* Next three statements will print same value i.e. address of a */
    cout << & a << endl;
    cout << p << endl;
    cout << * q << endl;
    /* Next two statements will print same value i.e. address of p */
    cout << & p << endl;
    cout << q << endl;
    /* Next three statements will print same value i.e. value of a */
    cout << a << endl;
    cout << * p << endl;
    cout << ** q << endl;
    return 0;
}
```

Output:
0x7ffcab7af9ac
0x7ffcab7af9ac
0x7ffcab7af9ac
0x7ffcab7af9b0
0x7ffcab7af9b0
10
10
10
 

 

 

## 3. Void Pointers:
A void pointer is a generic pointer; it has no associated type with it. A void pointer can hold an address of any type and can be typecasted to any type. Thus we can use the void pointer to store the address of any variable.

Void pointer is declared by: 

```
void *ptr;
```
 

Note:

1. void pointers cannot be dereferenced. It can, however, be done using typecasting the void pointer.

2. Pointer arithmetic is not possible on pointers of void due to lack of concrete value and size.

 

Example:

```
#include <iostream>
using namespace std;
int main() {
    void * ptr;
    int i = 10;
    // assign int address to void
    ptr = & i;
    cout << "Address of variable i " << & i << endl;
    cout << "Address where the void pointer is pointing " << ptr <<  endl;
    return 0;
}
```

Output:
Address of variable i 0x7ffc848c25f4
Address where the void pointer is pointing 0x7ffc848c25f4
 

 

## 4. Wild Pointers:
 A pointer behaves like a wild pointer when declared but not initialized. So, they point to any random memory location.

 

Example:

```
int *ptr; //wild pointer
*ptr = 5;
```
 

Note: If a pointer p points to a known variable, it’s not a wild pointer.

 

Example:

```
int * p; /* wild pointer */
int a = 10;
p = & a; /* p is not a wild pointer now*/
* p = 12; /* This is fine. Value of a is changed */
```


In the above program, p is a wild pointer till this points to a.

 

 

## Dangling Pointers:
A dangling pointer is a pointer pointing to a memory location that has been freed (or deleted). There are three different ways where Pointer acts as a dangling pointer.

 

a)Function Call

The pointer pointing to the local variable becomes dangling when the local variable is not static.

Example:

```
#include<iostream>
using namespace std;
int * fun() {
    int x = 10;
    return &x;
}
int main() {
    int * p = fun();
    // p points to something which is not 
    // valid anymore 
    cout << * p;
    return 0;
}
```


b) Deallocation of memory

Deallocating a memory pointed by a pointer causes a dangling pointer.

Example:

```
#include<iostream>
using namespace std;
int main() {
    //dynamic memory allocation.
    int * p = (int * ) malloc(sizeof(int));
    //after calling free() p becomes a dangling pointer
    free(p);
    //now p no more a dangling pointer.
    p = NULL;
    return 0;
}
```


c) Variable goes out of scope

When a pointer goes out of scope where it is valid, then it becomes a dangling pointer.

Example:

```
#include<iostream>
using namespace std;
void main() {
    int * ptr;
    ..... //any code statements
    {   int ch;
        ptr = & ch;
    }
    ....
    // Here ptr is dangling pointer
}
```

# Pointers on Array

- We know that the array variable stores the address of the first element of the arr
- therefore cout<<arr; is same as cout<<&arr[0];
- Dereference op can be used directly on an array to get any value
- *arr is same as arr[0]
- We can access any index value by: *(arr+i) , AND IN a[i] WORKS THE SAME WAY.
NOTE: PARATHESIS R IMP
are[i] = *(are+i) internally 
- <b>ALSO i[arr]=*(i+arr) IS VALID AND WORKS SAME AS arr[i], WONT GIVE AMY ERROR, IMP FOR MCQs </b>


if i do arr = arr +1 it gives error coz u can't change the state of symbol table, whereas if a pointer is created then p = p+1 doesn't give any error because we r not changing the adress of ptr in symbol table rather is changing a value.

# Character array
- cout function bis differently implementated for char array and int array
- cout<<arr prints addy of 1st ele, and cout<<ch would print the array.
- IMP FOR MCQS: even if we do char *p = &ch[0] and then cout<<p; would print the whole string unlike array where 1st element addy is printed.
- IMP FOR MCQS: the cout function for char arrays are implemented differently, it prints the memory content untill a null character is encountered. If we take a single char (doesn't have null char) it would give unexpected output as it would print garbage value until null char is encountered
```
char temp = 'z';
char *p = &t;
cout<<p;
op: z06j
```
- char c[6]= 'abcde'; 

The behind the scene process for this is : first abcde is stored in a temp memory then a memory of 6 char is allocated and then the content of the temp memory is copied to it.
- char *p = 'abcde';

<b>IMP: VERY BAD PRACTICE: coz 'abcde' is stored in a temporary memory and then the pointer points to that temp memory which is bad.</b>

#### Passing a pointer to a function
int func (int *p) {cout<<*p;}
- IMP: When u pass pointer in function it is copied and hence if u change the pointer like p=p+1 then this would not change the pointer adress throughout . BUT IF U CHANGE THE VALUE like *p=*p+1 this would change the value pointed by the pointer throughout.
- IMP: When u pass an array as parameter it goes as a pointer always. ie funct(int arr[]) is same as funct(int *arr) internally and externally.
- This approach is better as u r not passing the whole copy of array. Also this can used to send a part of array instead of whole array while calling the function like func(arr+3) would skip the first the memory loc.


# Double pointer lecture

Why do we use data type in pointers?
- to specify which type of data is being handled
- to specify the amount of memory which will be considered for operations


## Double pointers
It is a pointer to a pointer
- to create a pointer of int we do int* so to point an int* we will use int**  (ie pointer to int*) as the type
```
int a =8;
int* P1 = &a;
int** p2 = &P1;
```
So here p2 holds the address of P1, so *p2 and P1 gives the same output ie the address of memory for var a
- cout<<a<<*P1<<**p2 gives the same output.
