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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;

        ListNode* prev = nullptr;
        ListNode* next = head -> next;
        while(head != NULL){
            head -> next = prev;
            prev = head;
            head = next;
            if(next != nullptr)
                next = next -> next;
        }
        return prev;
    }
};
