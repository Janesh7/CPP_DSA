# Arrays

- Stores only similar
- Contiguous storage units locations
- indexed
- Used when we want to store multiple values of same type as single structure, easier access
- When we initialize an array, the pointer ( of the decalred variable) points to the first address of the memory location
- ADRESS CALC: imagine an int array v, the v[0] points to loc 100 in memeory
    then v[index] memory location : 100 + 4(size of int)*i
- initialize with 0s : int array[1000000] = {0}; if we use {1} or any other const, only the first(or more) values are stored and rest 0s
- We can initialize th earray with any value by using the fill_n command
    Ex: int array[100];
        fill_n(array,100,1); // initializes with 1

- If we initialize an array with frewer values then  its size then rest of the array elements r 0s
- Dont keep the size of the array in the function declaration : int printfunc(int arr[],int lenght){} 
- ^^Here we r passing the length in function coz if we have only initialized 2 elements in array of size 15,multiple 0s get printed aswell, therefore we can just send 2 as an argument
- we can get the length of any array using sizeof():
    Ex: int lenght = sizeof(array)/sizeof(int) , 
        here we take the size of the memory location and divide it by the size of each ele, ie if array is of lenght 10, memory size:40,size of int:4
- NOTE: initializing array like int arr[variable] is a VERY bad practise
- IMP NOTE: When we update the array normally passed to the function, the changes remain throughout the program as the var passed int arr[] stores the address to the first memory location. So making changes to it will reflect in main aswell.

## Reverse an array

- We r tracing(pointer) the start and end  of the array, and swapping them then incrementing start and decrermenting end. 
- We use swap() function to swap. swap(arr[start],arr[stop]);
- We repeat till the end < start

## Unique element of the array
- Unique element Code Stduio Prob statement: Given an array,which has n elements(2m+1 elements). Where all elements appear exactly twice and there is exactly 1 elememt which appears only once .ie how 2m+1 where m is the number of duplicate elements.

- optiomized solution:
    - We kmnow that a^a = 0 ie XOR of the dsame element is always 0
    - So if we XOR all the elements we will get the single remaining element as 0^0^0^0^a = 0^a = a, where there were 4 ele having duplicates (8 ele)which gave the result 0s upon XORing.