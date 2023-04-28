# Recursion


- If a function calls itself directly or indirectly its called recursion

In better terms:


**If the solution of the bigger problem depends upon a smaller same problem then we use recursion**


- It can be represented in recursive function
- The last case of a recursive function is called **base case**


In recursion 3 things
- base case (return is mandatory)
- recursive function (smaller func and bigger func, refer factorial)
- processing ( might process the data, or print it )

TYPES:
- Tail Recursion: where recursive function comes at the end ( base case -> processing -> recursive function )
- Head recursion : where recursive fucntion is above the processing ( base case -> recursive function -> processing )



<br />

When we dont have a base case we have infinite fucntion calls which will fill the fucntion calls, and a time wil come when the stack memory is filled and hence it will give a segmentation fault( stack overflow ). Hence base case is mandatory.


- Functiona call stack-> main, fact(3), fact(2), fact(1),fact(0)-> returns 1, and so on 1*2*3, returns 6.

