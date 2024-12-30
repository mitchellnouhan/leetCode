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
    ListNode* reverseLL(ListNode* head){
        ListNode* p = nullptr;
        while(head){
            ListNode* n = head -> next;
            head -> next = p;
            p = head;
            head = n;
        }
        return p;
    }
    
    ListNode* removeNth(ListNode* head, int n){
        int i = 0;
        ListNode* p = new ListNode();
        ListNode* cur = head;
        ListNode* ne = cur -> next;
        
        while(i < (n - 1)){
            p = cur;
            cur = ne;
            ne = ne -> next;
            i++;
        }
        p -> next = ne;
        if(cur == head)
            head = ne;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        reverse LL
        remove nth elem
        reverse LL 
        */
        head = reverseLL(head);
        head = removeNth(head, n);
        return reverseLL(head);
        //or this if you're trying to be annoying: 
        //return reverseLL(removeNth(reverseLL(head), n));
    }
};
