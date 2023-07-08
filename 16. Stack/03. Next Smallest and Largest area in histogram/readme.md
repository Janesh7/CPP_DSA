# Next smaller element
Q. Find the next smaller element for that element , -1 if no element exists.. example
    2, 1, 4, 3 is 
    1,-1, 3,-1 

**Approach**
- Bruteforce 

but TC: O(n^2)


**Using stack**


- Go from last element to the first
- since its the last element... start the stack with -1, so we can directly put that for the last element (as no more element)
- take the number cur from back using for loop .. 
We do:

- while the top element is greater than the cur.. we pop ie we want an element which is alr pushed and is smaller than the cur.. remember we have -1 alr in last so its guranteed to get it atleast
- after while loop we alr have the ans for that value and we put it into ans array
- we push the current element

take example 2,1,4,3

-1<3 -> true **ans->-1** , push 3, stack-> (3,-1)

3<4 -> true **ans->3**, push 4, stack-> (4,3,-1)

4<1 -> false , pop 4
3<1 -> false , pop 3
-1<1 -> true , **ans->-1** push 1, stack -> (1,-1)

1<2 -> true , **ans->1**



# Largest reactangular area in histogram

Approach:
1. Brute force
- take each rectangle and find area and then take the largest
- area= length* breadth, len is cosnt and is given like 2,1,5,6,2,3.. so we have to maximize breadth
- so like we keep 2 .. we can extend the and next node is 1.. it can be extended from len 1.. and breadth can be extended to 6 (as 6 column) .. so 6x1=6
- same for next 1 .. 
- now for 5.. on left side it cant be extended .. but on the rigth side its 6.. so it can be extended.. 5*2=10.. see pdf for reference.
- similarly do this for various rectangle


So in a nutshell.. iterate over each rectangle.. in each loop check for max left and right .. calculate area and get the max

TC: O(N)


2.  Using stack
- WE USE THE NEXT SMALLER ALGO AS PREV and also make a PREV SMALLER ALGO similarly
- we find columns which are lesser than the value.. ie we can only extend if there is a larger element before or after the cur.. 
- we find these two lesser value prev and next columns index
- we can calculate the width using next-prev+1 ... check pdf for easy

EDGE CASE:
- if all coulmns are equal.. so prev and next will give -1 for all 
- n-p-1 = -1 .. so here area will become negative
- To handle this: prev can be -1 for the first element in the array .. but this is not the case for next.. so if we get next=-1 we can simply make it next = n.. ie it can be extended till last.. as it is equal