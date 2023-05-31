# Floyds Algorithm 

Used to detect loops in LL


In this algorithm we use slow and fast pointers.
The logic is:
- we increment slow pointer with 1 each iteration, and 2 for the fast pointer
- if any pointer finds the null, then we return false, ie no loop exists
- otherwise if loop exists there will be a time when both the pointers will point at the same node and we'll return true

There is a mathematical proof that if the loop exist then a time will come when the slow and the fast pointer will point at the same node
</br>
(When the slow pointer comes to the start of the loop, let the distance between the two pointers be x, so after each iteration this would decrease by 1[as speed of one is twice the other] and after x itrations the distance between the point becomes 0 and they point to the same node) 
- with each iteration the distance between the the pointer decrease by 1

REFER PDF

**How to find start of the loop**

- once we have detected the loop:
- make the slow pointer to head
- increment slow pointer to head for each iteration
- increment the fast pointer BY ONE.
- the two pointers will meet at the start of the loop

**PROOF:**
-let  A: lenght from start to the loop start.
-     B: length from loop start to the fast ptr intersect
-     C: length og the loop 
wkt that distance by fast pointer = 2* distance travelled by the slow ptr


The fast ptr would have covered:
- A + x*C + B, where x is any number of cycles it wouldve traverssed before intrsection

Similarly, slow ptr would have covered
- A + y*C + B, where y is any number of cycles it wouldve traverssed before intrsection which is obv different from x

putting in the eqn gives:
- A + xC + B = - 2A + 2yC + 2B
- **C(x-2y) = A+B**
- let K = x-2y
- C*K = A+B

**Which means that A+B is equal to some K times completing the cycle**
**Therefore, If we know B then we know that it is only A which completes the cycle**
- ie if we r at B we need A more steps to complete the cycle
- Therefore A and B taking single steps would lead us to the start of the cycle


- We are using floyds algo to return the fast ptr 
- and then we implement this algo to get the start

**We can break the cycle**

- We have the head to the start, just find the prev node and make it point to null