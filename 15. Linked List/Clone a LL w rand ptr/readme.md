# Approach 1
- just make/copy whole LL using next ptr
- then now we need to add random ptrs .. do it by brute force the random ptrs from the given LL .. go each node in main and then see the random ptr.. make the random ptr point in the copy .. this operation is O(N^2) as we'll be iterating for each node.. and then we have to move to some pointers away(as it is random migth be n nodees away)

SO TC : O(n^2)

# Approach 2
- just make/copy whole LL using next ptr
- map the nodes 1:1 in a map while iterating ie node 1 in org is mapped to clone node 1 in the map( this all is logical and is not real link)
- we derive a formaula by seing the map ie


**cloneNode -> random = map[orgNode -> random]**, as we have stored the corresponding nodes in mapping
look in vid or pdf for explanation

SO TC: O(n), SC: O(N)

# Approach 3 
with constant SC

In this approach we do the same thing as prev but we dont use the additional space for amp.. we directly change the links 
- Instead of mapping nodes in a map.. we change the link from the ith original node to ith cloned node, therefore the links become criss crossed

ie 1st original node -> 1st cloned node -> 2nd org node -> 2nd cloned node and so on

we r using the 1st org -> 1st cloned node for mapping and we r using the 1st cloned node -> 2nd org node to keep track of the rest od the org/cloned LL

IMP point to remember store next ptr to track the org list while coding

- So now we will be going like ex. node 1 is randomly pointed to 3.. so after the above process node 1 org points to cloned 1 node and random ptr to 3.. according to to our track we have done above the 3rd node org also points to 3rd node cloned. therefore we get the realtion 


So my cloned's random (org/temp -> next -> random) ptr is equal to org/temp-> random->next

Refer pdf for easy understanding with diagram

