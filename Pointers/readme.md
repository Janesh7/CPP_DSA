# Pointers

Symbol table: is an important ds created by the compiler in order to keep track of semantics of variable ie it stores informatiom about the scope and binding information about names, information about instances of various entities such as variable and function names, classes, objects, etc.

- a variable is mapped to corresponding address (where the value can be found)        || var -> mem addy ||

<b>ADDRESS OF OPERATOR (& operator) -> returns the address of the memory, IT IS HEXADECIMAL FORMAT</b>

- WHY pointer is used?

<b> POINTER is a variable to store an memory addres .Ex int *ptr = &i; </br>
    NOTE: int *ptr; is avery bad practice, this means we initailized a pointer and it stores and random memory address which can be modified
</b>