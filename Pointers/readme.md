# Pointers

Symbol table: is an important ds created by the compiler in order to keep track of semantics of variable ie it stores informatiom about the scope and binding information about names, information about instances of various entities such as variable and function names, classes, objects, etc.

- a variable is mapped to corresponding address (where the value can be found)        || var -> mem addy ||

<b>ADDRESS OF OPERATOR (& operator) -> returns the address of the memory, IT IS HEXADECIMAL FORMAT</b>

- WHY pointer is used?

<b> POINTER is a variable to store an memory addres .Ex int *ptr = &i; </br>
    NOTE: int *ptr; is avery bad practice, this means we initailized a pointer and it stores and random memory address which can be modified, rather initialize to 0, nullptr. ie no memory exists for now ( if u try to print the value of it, segmentation fault)
</b>
- int *ptr = &num; means p and num BOTH are pointing to the same memory address, soo doing num++ and (*p)++ would yield the  same result
<datatype> *p -> systanx to create a pointer, the pointer created is pointing to the <datatype>
<b> * - is a DEREFERENCE OPERATOR , means VALUE OF, ie tell the value in the memory addy</b>

- Size of a pointer of anything is ALWAYS 8