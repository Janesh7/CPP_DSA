# Linked List

- LINEAR, not contagious
- collection of nodes
- node - data & ptr(s) to the address of next node (or prev as well)

**WHY**

- In array we need to allocate some memory initialy only
- In case of dyanamic array vector, if we want to add an ele to a vector of size 5, then compiler will allocate an array of size 10, and copy all the ele, and this case is not optimal
- insertion deletion is hard as we have to shift elements 

Advantages of LL
- no memory wastage
- Dynamic
- easy insertion/deletion
- not contagious
- grow and shrink on runtime

TYPES:
- singly
- doubly
- circular
- doubly circular

## Singly

IMP NOTE: **When doing any operation on Linked list send the Address of the Node Pointer ALWAYS, As we want to DO THE CHANGES IN THE MAIN LL ONLY AND DONT WANT TO CREATE A COPY**


```
void insertAtHead(Node* &head, int d) {}

```
Creating a node
```
    Node* temp = new Node(d);
```

- To insert at front we need head
- to insert at end we need tail
- or we have to traverse through

IMP NOTE: **ALWAYS before deleting the node, remove the pointer to the next node as we r only freeing the memory and not removing the ptr** and it would be delete the whole list.