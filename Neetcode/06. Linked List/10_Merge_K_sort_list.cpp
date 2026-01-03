// 23. Merge k Sorted Lists

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 
// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []
 

// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.

// Brute force approach is discussed later

/**
 * Problem: Merge k Sorted Linked Lists
 * Approach: Min-Heap (Priority Queue)
 *
 * ---------------------------------------------------------------------------------
 * Thinking Process:
 * ---------------------------------------------------------------------------------
 * - We are given k sorted linked lists.
 * - The goal is to merge all of them into one sorted linked list.
 * - Since each list is sorted, the smallest element among all current heads 
 *   (first nodes of each list) is the one we should append next to the result.
 *
 * - To efficiently find the minimum among the k current nodes,
 *   we use a Min-Heap (Priority Queue).
 * 
 * ---------------------------------------------------------------------------------
 * How It Works (Algorithm Step-by-Step):
 * ---------------------------------------------------------------------------------
 * 1. Initialize a min-heap that stores (value, node) pairs.
 *    The heap allows us to always extract the smallest current node in O(log k) time.
 *
 * 2. Push the head of each non-null linked list into the heap.
 *
 * 3. Create a dummy node (dummyHead) to help construct the resulting linked list.
 *
 * 4. While the heap is not empty:
 *    a. Extract the node with the smallest value.
 *    b. Append it to the result list.
 *    c. If that node has a next node, push the next node into the heap.
 *
 * 5. Return the next of dummyHead as the head of the merged list.
 *
 * ---------------------------------------------------------------------------------
 * Time Complexity:
 * ---------------------------------------------------------------------------------
 * - Total number of nodes = n
 * - Each node is inserted and removed from the heap exactly once.
 * - Each heap operation (push/pop) takes O(log k), where k is the number of lists.
 * - So, total time complexity = O(n log k)
 *
 * ---------------------------------------------------------------------------------
 * Space Complexity:
 * ---------------------------------------------------------------------------------
 * - The heap stores up to k elements at any time => O(k)
 * - Plus the output list which uses existing nodes => O(1) additional
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // If the list vector is empty, return NULL
        if (lists.size() == 0) return NULL;

        // Dummy node to help construct the final result list
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;

        // Min-heap (priority queue) where each element is a pair (val, node)
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        // Step 1: Add the head of each list to the heap
        for (auto head : lists) {
            if (head != NULL) {
                pq.push({head->val, head});
            }
        }

        // Step 2: Extract the minimum element and build the result list
        while (!pq.empty()) {
            // Get the node with the smallest value
            ListNode* minNode = pq.top().second;
            pq.pop();

            // Append the minNode to the result list
            dummyTail->next = minNode;
            dummyTail = dummyTail->next;

            // If there is a next node in the list, push it to the heap
            if (minNode->next != NULL) {
                pq.push({minNode->next->val, minNode->next});
            }
        }

        // Step 3: Return the merged list, skipping the dummy head
        return dummyHead->next;
    }
};


/**
 * Problem: Merge k Sorted Linked Lists
 * Approach: Divide and Conquer (Recursive Merge)
 *
 * ---------------------------------------------------------------------------------
 * Thinking Process:
 * ---------------------------------------------------------------------------------
 * - We are given k sorted linked lists.
 * - A brute-force approach would be to merge the first two, then merge the result with the third, and so on.
 *   But this is inefficient because we repeatedly merge large lists with small ones (unbalanced merging).
 *
 * - A better strategy is inspired by merge sort:
 *   -> Divide the list of linked lists into two halves
 *   -> Recursively merge each half
 *   -> Finally, merge the two sorted merged halves together
 *
 * - This gives us a balanced and efficient merging strategy, minimizing the total number of comparisons.
 *
 * ---------------------------------------------------------------------------------
 * How It Works (Algorithm Step-by-Step):
 * ---------------------------------------------------------------------------------
 * 1. Base case:
 *    - If start > end, return NULL (no lists).
 *    - If start == end, return the single list.
 *
 * 2. Recursive case:
 *    - Divide the list into two halves using mid = (start + end) / 2.
 *    - Recursively merge the left and right halves.
 *    - Merge the two resulting lists using a helper `merge` function.
 *
 * 3. The `merge` function:
 *    - Standard merging of two sorted linked lists using a dummy node.
 *    - Iteratively select the smaller head and move the pointer forward.
 *    - Append the remaining part once one list is exhausted.
 *
 * ---------------------------------------------------------------------------------
 * Time Complexity:
 * ---------------------------------------------------------------------------------
 * - Let k = number of lists, n = total number of nodes
 * - We do log(k) levels of merging (like merge sort)
 * - Each level merges all nodes exactly once => O(n)
 * => Total Time Complexity = O(n log k)
 *
 * ---------------------------------------------------------------------------------
 * Space Complexity:
 * ---------------------------------------------------------------------------------
 * - Recursive stack uses log(k) space
 * => Total Space Complexity = O(log k)
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }

    // Helper function to perform divide and conquer merge
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return NULL;
        if (start == end) return lists[start];

        int mid = start + (end - start) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);

        return merge(left, right);
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* list1Head, ListNode* list2Head) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;

        while (list1Head != NULL && list2Head != NULL) {
            if (list1Head->val < list2Head->val) {
                dummyTail->next = list1Head;
                list1Head = list1Head->next;
            } else {
                dummyTail->next = list2Head;
                list2Head = list2Head->next;
            }
            dummyTail = dummyTail->next;
        }

        dummyTail->next = (list1Head != NULL) ? list1Head : list2Head;
        return dummyHead->next;
    }
};

// Iterative Merge One-by-One

// Idea:
// Start with the first list.
// Merge it with the second list.
// Merge the result with the third, and so on.

// Why Does Divide and Conquer Perform Fewer Comparisons Than Iterative Merging?
// Goal:
// We're merging k sorted linked lists with a total of n nodes.

// Now let’s compare how many comparisons each method makes.

// Iterative (One-by-One) Merging:

// How it works:

// Start with the first list.
// Merge it with the second → result list.
// Merge result with the third → new result list.
// Continue until all k lists are merged.

// What's the problem?
// Every time we merge a new list, the result list gets longer.
// That means each next merge is more expensive (more comparisons).
// Let’s visualize it with numbers (assuming each list has n/k nodes for simplicity):

// Merge L1 and L2     → size: 2n/k         → O(2n/k)
// Merge result with L3 → size: 3n/k         → O(3n/k)
// Merge result with L4 → size: 4n/k         → O(4n/k)
// ...
// Total comparisons ≈ O((2 + 3 + ... + k) * n/k) = O(k^2 * n/k) = O(k * n)
// So comparisons grow linearly with k → inefficient when k is large

// Divide and Conquer Merging:

// How it works:
// Split k lists into halves recursively.
// Merge pairs at each level like a balanced binary tree.
// Each merge step merges two lists of roughly equal size.

// Why is it better?
// Instead of merging small lists with ever-growing larger lists, we merge equally sized lists.
// At every level of the recursion tree:
// All nodes (n total) are merged once.
// And there are only log₂(k) levels.

// | Factor                    | Iterative             | Divide and Conquer      |
// | ------------------------- | --------------------- | ----------------------- |
// | Comparison Efficiency     | Repeated, redundant   | Balanced, minimal       |
// | Merge Pattern             | Unbalanced            | Balanced binary merging |
// | Total Comparisons         | O(k \* n)             | O(n log k)              |
// | Scalability for large `k` | Poor                  | Excellent               |

// --------------------------------------------------------------------------------


// Comparing the two optimized methods:

// | Feature                 | Divide and Conquer            | Min-Heap Approach                 |
// | ----------------------- | ----------------------------- | --------------------------------- |
// | Time Complexity         | O(n log k)                    | O(n log k)                        |
// | Space Complexity        | O(log k) (recursion stack)    | O(k) (priority queue)             |
// | In-place merging        | Yes                           | No (uses heap structure)          |
// | Easier to implement     | Moderate (recursion involved) | Simple if STL priority queue used |
// | Performance in practice | Often faster for small `k`    | Better for large `k`              |

// Which Is Better?
// If k is large (e.g., thousands of lists), the min-heap is generally more efficient in practice, as it avoids deep recursion.

// If k is small to moderate, the divide-and-conquer method may be faster and more memory-efficient due to lower overhead.