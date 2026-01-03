# Reverse an LL

refer program

# Middle of LL

APPROACH

- If the head is null or the head-> next is null ie the size is 0 or 1, then return the head (null or first ele only which is head in both case)
- If the size of the LL is 2 return head->next ie 1st ele



MAIN
- Make two pointer, fast and slow resp
- fast traverse two nodes at a time, TAKE THE SECOND STEP IF fast(IMP:ALREADY INCREMENTED IN PREVIOUS STEP, so dont do fast->next rather use fast!=null) is not null
- slow traverse one node at a time

So when the fast pointer reaches the end , the slow points to the mid element



FOR ODD: (n/2+1)=3
ex 
1 2 3 4 5 



1>
slow -> 1
fast -> 2



2>
slow -> 2
fast -> 4



3> 
slow -> 3
fast -> NULL exit and return 3rd node




FOR EVEN: (n/2+1) = 4
ex
1 2 3 4 5 6



1>
slow -> 1
fast -> 2



2>
slow -> 2
fast -> 4



3>
slow -> 3
fast -> 6



4> 
first step for fast, it becomes null, therefore no second step
slow -> 4



return 4