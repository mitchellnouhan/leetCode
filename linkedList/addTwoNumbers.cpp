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
        // create output nodes but continue even if we finish off one list:)
        // do not change inputs for sake of space, create new nodes as you go w/ a dummy node:)
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* dum = new ListNode();
        ListNode* h = dum;
        
        int cur = 0;
        int carry = 0;
        while(h1 || h2 || carry){
            int h1_val = h1 ? h1 -> val : 0;
            int h2_val = h2 ? h2 -> val : 0;

            cur = h1_val + h2_val + carry;
            carry = cur / 10;
            cur %= 10;

            h -> next = new ListNode(cur);

            h = h -> next;
            h1 = h1 ? h1 -> next : nullptr;
            h2 = h2 ? h2 -> next : nullptr;
        }
        return dum -> next;
    }
};
