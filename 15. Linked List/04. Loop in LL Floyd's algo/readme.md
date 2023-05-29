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

REFER PDF