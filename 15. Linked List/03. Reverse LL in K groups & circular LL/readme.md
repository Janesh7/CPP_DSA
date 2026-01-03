# Reverse a LL in K Groups

**IMP Question**

TC:O(N)
SC:O(n/K) where K is the constant space complexity for all the calls for the group K, and how many calls will it do n/K



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
- head->next = output of recursion will get attached (after reversing the k nodes the head will be at the part where we want to attach the output of the rest, head points to null as we r reversing it, but later upon the return of this function call it would connect the LL
)
- return head of prev LL ie return  prev

Ex 3 5 6 8


for k =2

1>

iterative reverse 3 5, head at 3

```
3->5 where head at 3 would give
5->3->null 
```
we can see head->next is null and we want to attach the op of the recursion here



next(fwd pointer) is on the remaining part 1st node, so we have the track of the rest of the LL
and prev is pointing at 5


recursion gives head of reversed remaining part

SO it becomes

2> 
5->3->8->6

prev which is at 5 is returned, which the head to the LL