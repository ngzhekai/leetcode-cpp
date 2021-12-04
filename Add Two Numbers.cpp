
// https://leetcode.com/problems/add-two-numbers/
// link to the question in leetcode

/*** Question ***/

// 2. Add Two Numbers


// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

 

// Constraints:

//     The number of nodes in each linked list is in the range [1, 100].
//     0 <= Node.val <= 9
//     It is guaranteed that the list represents a number that does not have leading zeros.

/*** End Of Question ***/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        struct ListNode* ptr1 = l1;
        struct ListNode* ptr2 = l2;        
        struct ListNode* head = NULL;
        int sum = 0, carry = 0;
        
        // check if pointer1 or pointer2 is true
        while (ptr1 || ptr2) {
            //initialize sum
            sum = 0;
            
            // check if pointer1/pointer2 is not null, then sum
            if(ptr1)
                sum += ptr1->val;
            if(ptr2)
                sum += ptr2->val;
            // add the carry into the sum
            sum += carry;
            // determine carry by dividing it with 10
            carry = sum / 10;
            // since a node can only have one digit
            // mod 10, will output the last digit
            // (counting from left)
            sum = sum % 10;
            
            // create a new node for storing the sum
            struct ListNode* newnode = new ListNode(sum);
            
            // check whether it has to be placed after the head
            // or the last node.
            if (head == NULL)
                head = newnode;
            else {
                struct ListNode* lastnode = head;
                while (lastnode->next != NULL) {
                    lastnode = lastnode->next;
                }
                
                lastnode->next = newnode;
                
            }

            // if pointer is not null, set pointer to next
            if(ptr1)
                ptr1 = ptr1->next;
            if(ptr2)
                ptr2 = ptr2->next;
        }
        
        // if carry exist after pointer1 and pointer2 is null, 
        // add it at the end of the linked list.
        if(carry) {
            // create a new node
            struct ListNode* newnode = new ListNode(carry);
            
            //find the last node and add the newnode
            struct ListNode* lastnode = head;
                while (lastnode->next != NULL) {
                    lastnode = lastnode->next;
                }
                
                lastnode->next = newnode;
        }
        return head;
    }
};
