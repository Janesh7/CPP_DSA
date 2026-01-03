/*
    Question: Find the Duplicate Number

    Approach:
    Algorithm Overview:

    Initialize two pointers, slow and fast, to the first element of the input list nums.
    Iterate through the list using the Floyd's Tortoise and Hare algorithm (see below) to find a cycle.
    Once a cycle is found, reset one of the pointers to the beginning of the list and continue iterating until both pointers meet again.

    Detailed Explanation:

    Initialize slow and fast pointers to the first element of the input list nums.
    Enter a loop to detect a cycle:
    a. Update slow to the next element using nums[slow].
    b. Update fast to the next element after nums[fast], effectively moving two steps.
    c. Check if slow is equal to fast. If they are equal, a cycle has been found, and exit the loop.
    After finding the cycle, reset one of the pointers (slow2) to the beginning of the list.
    Enter a loop to find the duplicate element:
    a. Update slow using nums[slow].
    b. Update slow2 using nums[slow2].
    c. Continue this process until slow is equal to slow2, which represents the duplicate element.
    Return the duplicate element found (slow).

    Floyd's Tortoise and Hare Algorithm:
    Floyd's Tortoise and Hare algorithm, also known as Floyd's Cycle Detection algorithm, is an algorithm used to detect loops (cycles)
    in data structures like linked lists or arrays. It has been proven to reliably detect cycles under specific circumstances and can
    be applied to finding duplicate elements.

    This algorithm employs two pointers, referred to as the "tortoise" and the "hare," to traverse the list.

    Tortoise: A pointer that advances one step at a time through the list.
    Hare: A pointer that advances two steps at a time through the list.

    NOTE: nums[fast] gets you to the next node.
    nums[nums[fast]] gets you two nodes ahead, like taking two steps in a linked list.
    We are treating the input array as a linked list where each element points to the next element. So its not slow++ and fast +=2

    Using these pointers, you progress until the hare catches up with the tortoise or a cycle is detected.

    Phase 1 (Cycle Detection):
    Move the tortoise and hare, advancing the hare twice as fast as the tortoise, until the hare catches up with the tortoise or a cycle is detected.

    Phase 2 (Cycle Start Detection):
    Move the tortoise and hare one step at a time until they match again. The position where they match again is the starting point of the cycle,
    corresponding to the duplicate element.

    Let's explain why this works for the problem at hand:

    Properties of Floyd's Tortoise and Hare Algorithm:
    The algorithm ensures that the tortoise and hare will match again at some position in the list. Exploiting this property, if a cycle exists,
    the tortoise and hare will certainly match at some position within the cycle.

    Relation between Duplicate Element and Cycle:
    In the presence of a duplicate element, the duplicate corresponds to the starting point of the cycle. Starting from the first element as the
    tortoise, and moving through the duplicates until reaching a duplicate (cycle start), the hare will join, and the tortoise and hare will match
    again inside the cycle.

    Therefore, the Floyd's Tortoise and Hare Algorithm provides an efficient and reliable way to find duplicate elements.

    We can apply the same algorithm to Linked List cycle II. Let's calculate movement distance of the two pointers with basic math.

    How it works:
    Input: nums = [1,3,4,2,2]
    Initialize slow and fast pointers with nums[0]

    slow = 1 (nums[0])
    fast = 1 (nums[0])
    Start iteration until both pointers are the same value.

    Iteration 1:
    slow: 3 (nums[1])
    fast: 2 (nums[nums[1]] = nums[3])

    Iteration 2:
    slow: 2 (nums[3])
    fast: 2 (nums[nums[2]] = nums[4])

    Now the both pointers are equal, so break the loop.
    Set nums[0] to slow2 pointer. Start iteration again until slow and slow2 are equal.

    Iteration 1:
    slow: 4 (nums[2])
    slow2: 3 (nums[1])

    Iteration 2:
    slow: 2 (nums[4])
    slow2: 2 (nums[3])

    Now the both pointers are equal, so break the loop.
    Input: 2
    Output: 2

    Let's calculate movement distance of slow and fast pointers:

    Let:

    A = distance from start to cycle start (entrance)

    B = distance from cycle start to meeting point

    C = remaining cycle length

    slow pointer moves A + B
    fast pointer moves A + B + C + B

    Since slow moves once and fast moves twice:

    2(A + B) = A + B + C + B

    Simplify:
    2A + 2B = A + 2B + C
    A = C

    Better read the earlier proof in notes

    So, distance A and C are equal. When two pointers meet at node z, fast is re-initialized to start, and each pointer moves one step until they meet again.
    This point is the start of the cycle (duplicate number).

    The second loop with slow and slow2 is necessary to find the starting point of the cycle, which corresponds to the duplicate element in the array.
    The first loop finds the cycle but not the exact duplicate value.

    Try input [2,5,9,6,9,3,8,9,7,1] — output should be 9.

    Complexity:
    Time: O(n)
    Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Finding the intersection point in the cycle
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        // Phase 2: Finding the entrance to the cycle (duplicate)
        int slow2 = nums[0];
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
    // time complexity: O(n)
    // space complexity: O(1)
};