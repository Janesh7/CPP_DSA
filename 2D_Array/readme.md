# 2 D array 

These are linear array only but we are visualizing it as a 2d array, this can be done using a mathematical function which would tell the index of elements stored.
For ex. A 3x3 matrix : 9 elements (0-8) , formula : Nc*r + c (Nc- number of column): 0th row 1st column : 0+1 = 1, 1st row 1st column : 3 +1 = 4
<br />
IMP: NEVER PUT void example(int Array[][]){} , ALWAYS SPECIFY THE COULMN SIZE Ex: void example(int Arr[][3]) or int a[][2][2] and so on, atleast u have to put column number
<br />
<b>It is needed to compute the relative offset of the item you're actually accessing. The array itself is just a linear block, but rather than you having to to do (row*colwidth + col) (which works, btw) the offsets are done for you by the compiler once it knows the second-order magnitude.</b>
<br />
When it comes to describing parameters, arrays always decay into pointers to their first element.

When you pass an array declared as int Array[3] to the function void foo(int array[]), it decays into a pointer to the beginning of the array i.e. int *Array;. Btw, you can describe a parameter as int array[3] or int array[6] or even int *array - all these will be equivalent and you can pass any integer array without problems.

In case of arrays of arrays (2D arrays), it decays to a pointer to its first element as well, which happens to be a single dimensional array i.e. we get int (*Array)[3].

Specifying the size here is important. If it were not mandatory, there won't be any way for compiler to know how to deal with expression Array[2][1], for example.

To dereference that a compiler needs to compute the offset of the item we need in a contiguous block of memory (int Array[2][3] is a contiguous block of integers), which should be easy for pointers. If a is a pointer, then a[N] is expanded as start_address_in_a + N * size_of_item_being_pointed_by_a. In case of expression Array[2][1] inside a function (we want to access this element) the Array is a pointer to a single dimensional array and the same formula applies. The number of bytes in the last square bracket is required to find size_of_item_being_pointed_by_a. If we had just Array[][] it would be impossible to find it out and hence impossible to dereference an array element we need.

Without the size, pointers arithmetics wouldn't work for arrays of arrays. What address would Array + 2 produce: advance the address in Array 2 bytes ahead (wrong) or advance the pointer 3* sizeof(int) * 2 bytes ahead