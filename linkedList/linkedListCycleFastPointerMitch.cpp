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
    bool hasCycle(ListNode* head) {
        /*
        -Key is to use a faster pointer and a slow pointer
        -Iterate thru LL with fast pointer updating twice as fast as the slow
        -If a cycle exists, the fast and slow pointers will eventually meet
        -If the faster pointer breaks, you know there is no cycle
        */
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while (fast){
            if(slow == fast)
                return true;
            slow = slow -> next;
            fast = fast -> next;
            if (fast)
                fast = fast -> next;
        }
        return false;
    }
};
