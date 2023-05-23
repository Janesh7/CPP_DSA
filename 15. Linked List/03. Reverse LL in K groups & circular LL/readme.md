# Reverse a LL in K Groups

**IMP Question**

Can be solved using recursion
- Solve for the k group and rest recursion would do
- after the reversing the first cluster

Ex 3 7 4 5 6 when k = 2

the 3->7 nodes r reversed 

They become 7->3->NULL


Now the rest of the LL is reversed similary through recursion and attached to the NULL (the head) and the new head ie the PREV node if we consider the iteration 

**ALGORITHM**

- 1 case solve:
    - Iterative way reverse the LL of K size
    - ie reverse first k nodes
- head->next = output of recursion
- return head of prev LL ie return  prev