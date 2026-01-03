// 138. Copy List with Random Pointer
// Medium


// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

 

// Example 1:


// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Example 2:


// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]
// Example 3:



// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]
 

// Constraints:

// 0 <= n <= 1000
// -104 <= Node.val <= 104
// Node.random is null or is pointing to some node in the linked list.


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void inserttail(Node* &head , Node* &tail , int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }    
public:
    Node* copyRandomList(Node* head) {

        // step 1 - create clone list
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;
        while(temp != NULL){
            inserttail(clonehead , clonetail , temp->val);
            temp = temp->next;
        }

        //step 2 - adding clone nodes in original list;
        Node* originalnode = head;
        Node* clonenode = clonehead;

        while(originalnode != NULL && clonenode != NULL){
            Node* originalnext = originalnode->next; 
            originalnode->next = clonenode;
            originalnode = originalnext;

            Node* clonenext = clonenode->next;
            clonenode->next = originalnode;
            clonenode = clonenext;
        }


        //step 3 - marking random pointers
        temp = head;
        while(temp != NULL){
            if(temp->next != NULL ){
                temp->next->random = temp->random ? temp->random->next : temp->random;
                // this =          condition check     if true             if false
            } 
            temp = temp->next->next;    
        }

        // step 4 - making both list normal
        originalnode = head;
        clonenode = clonehead;

        while(originalnode && clonenode){

            originalnode->next = clonenode->next;
            originalnode = originalnode->next;

            if(originalnode != NULL){
                clonenode->next = originalnode->next;
            }
            clonenode = clonenode->next;
        }

        //step 5 - returning head
        return clonehead;
    }
};

// Found in soln section

// Intuition
// To get a O(1) solution, we essentially need to modify the original list (in-place) somehow to keep track of the copies of each node. Most other solutions go with inserting the copy right after the original, but I was in the mood for something fancier.

// Insight: We can store the address (memory pointer) of the copied node inside the original node itself- there is enough space! Or rather, we can make enough space for it...

// Background
// Pointer tagging
// See Wikipedia.
// On a 64-bit system, pointers usually take up 64-bits = 8 bytes of space. But this is a convenient lie- pointers don't really need so much space. Having 64-bits would be enough to reference 2**64 bytes of memory, which is around 1.6 MILLION TERABYTES. Much more RAM than a single machine typically has. So, most operating systems cheat, and only use the first 48-bits of the pointer- the rest are usually set to 0.

// Now, we only need to find a place inside Node where we can stash an entire additional pointer (48-bits). (Remember, we need to modify each node in-place to get an O(1) solution.)

// We can't use next and random since those are pointers and use up at least 48 bits in their respective fields, leaving only 32 bits total - not enough.

// Flipping around the problem, if we somehow had 64 bits inside Node, we could store the pointer in the 48 bits, and use 16 bits to store some other value.

// Oh- what divine coincidence... 16 bits is more than enough to represent all the values from our problem description; the range [-10000, 10000] has 20001 values, which is much less than 2**16 = 65536. (Even 15 bits, with 32768 values, would work... but that is a minor detail.) Maybe we can store val in the top 16-bits of our extra pointer.

// Buuut val is itself just an int, giving us a measely 32 bits. We need 64 bits to store the combination of val (16 bits) and the extra pointer (48 bits). Where do we get the extra 32 bits from?

// Seems like we are stuck... Or are we??

// Time to dig deeper...

// Memory padding in C++ structs
// Here's the Node struct as given in the problem statement:

// class Node {
//     int val;
//     Node* next;
//     Node* random;
//     //...
// };
// Naively, one would think that our Node struct is just 20 bytes in size- 4(int val) + 8(Node* next) + 8(Node* random). (int is 32-bits, and on a 64-bit system, a pointer typically takes up 8 bytes.)

// However, our compiler says Node is really 24 bytes wide:

// cout << sizeof(Node);  // prints 24
// What gives?

// The answer lies in how the fields inside the struct are really laid out in memory. Instead of putting them right next to each other, the compiler is free to leave some blank bytes between them. This space is called padding.

// In typical systems, pointers are aligned to 8 bytes. For Node, the compiler inserts extra 4 bytes of padding after val to make sure that next is properly aligned. See Typical alignment of C structs on x86 (Wikipedia) for more details.

// We can take advantage of this padding to "procure" the extra space we needed.

// Approach
// We define a separate struct Node2 that is the same as Node, but with uint64_t for the val field instead of int. Crucially, on most systems/compilers, this struct has the same size as Node.

// Now, by casting our Node* pointers to Node2* pointers, we are able to access the padding bytes from the original struct. We can use pointer tagging to store both the original node value and the additional address in this field.

// Code
// assuming 64-bit system
static_assert(sizeof(uintptr_t) == 8);
// number of extra bits that are unused in the pointers.
// we could technically make do with just 15 bits
// since the range of vals is between [-10000, 10000], i.e. 20001 numbers
// and pow(2, 15) == 32768 is enough to store all these nums.
constexpr uint64_t NUM_EXTRA_BITS = 16;
constexpr uint64_t VAL_SHIFT = 64 - NUM_EXTRA_BITS;
constexpr uint64_t make_mask(uint64_t num_bits) {
    return (1ULL << num_bits) - 1;
}
constexpr uint64_t PTR_BITS = make_mask(VAL_SHIFT);
constexpr uint64_t VAL_BITS = make_mask(NUM_EXTRA_BITS) << VAL_SHIFT;
// make sure there is no overlap
static_assert((PTR_BITS & VAL_BITS) == 0);

struct Node2 {
    uint64_t tagged;
    struct Node2* next;
    struct Node2* random;
    int get_v() const {
        return tagged >> VAL_SHIFT;
    }
    void put_v(int v) {
        tagged |= uint64_t(v) << VAL_SHIFT;
    }
    void* get_ptr() const {
        return (void*)(tagged & PTR_BITS); 
    }
    void put(void* ptr, int v) {
        // zero-ing out the field is really crucial to avoid undefined behaviour
        // without this line, we can't be sure about the contents of padding bytes
        tagged = 0;
        put_ptr(ptr);
        put_v(v);
    }
    void put_ptr(void* ptr) {
        assert((int64_t(ptr) & VAL_BITS) == 0);
        tagged |= (int64_t)ptr;
    }
};
// this solution will break if the following assert is false
static_assert(sizeof(Node2) == sizeof(Node));

class Solution {
public:

    Node* copyRandomList(Node* head) {
        Node *copyhead = nullptr, *copytail = nullptr;

        // create copy list and add tagged pointers
        for (Node* p = head; p; p = p->next) {
            auto copy = new Node(p->val);
            if (!copyhead) {
                copyhead = copy;
            }
            if (copytail) {
                copytail->next = copy;
            }
            copytail = copy;
            copy->random = p->random;
            auto* origptr = reinterpret_cast<Node2*>(p);
            // store address of copied node into the original node using pointer tagging
            origptr->put(copy, copy->val);
        }
        // get the addresses from tagged pointer
        for (Node* copy = copyhead; copy; copy = copy->next) {
            if (copy->random) {
                // copy->random is currently the original random node
                auto* taggedptr = reinterpret_cast<Node2*>(copy->random);
                // get the copied node from the original node
                copy->random = (Node*)taggedptr->get_ptr();
            }
        }
        // restore the original values
        for (Node* p = head; p; p = p->next) {
            auto* taggedptr = reinterpret_cast<Node2*>(p);
            p->val = taggedptr->get_v();
        }
        return copyhead;
    }
};
// Another solution
// If you were following closely, you might have noticed an alternate solution which avoids using the padding bytes entirely.

// Our requirements are that we need to store the 48-bit pointer somewhere inside the Node fields. Now note that our next and random fields are themselves pointers, so they only take up 48-bits each, leaving 16+16 = 32 bits unused. We can get another 16 bits from the upper half of val (again, we only need 15 bits to store all the nums between [-10000, 10000]).

// So, by taking 16 bits from each of the three fields, we actually have enough space for our additional pointer. We just need to split it across the three fields. See if you can implement this :)