# Arrays

- Stores only similar
- Contiguous storage units locations
- indexed
- Used when we want to store multiple values of same type as single structure, easier access
- When we initialize an array, the pointer ( of the decalred variable) points to the first address of the memory location
- ADRESS CALC: imagine an int array v, the v[0] points to loc 100 in memeory
    then v[index] memory location : 100 + 4(size of int)*i
- initialize with 0s : int array[1000000] = {0};
- We can initialize th earray with any value by using the fill_n command
    Ex: int array[100];
        fill_n(array,100,1); // initializes with 1