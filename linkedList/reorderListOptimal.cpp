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
    void printLL(ListNode* head){
        while (head){
            cout << head -> val << " ";
            head = head -> next;
        }
        cout << "\n";
    }
    void reorderList(ListNode* head) {
        //split list in half
        ListNode* head1 = head;
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* head2 = slow -> next;
        slow -> next = nullptr;
        //printLL(head1);
        //printLL(head2);
        

        //reverse order of second half
        ListNode* p = nullptr;
        //ListNode* n;
        while(head2){
            ListNode* n = head2 -> next;
            head2 -> next = p;
            p = head2;
            head2 = n;
        }
        head2 = p;

        //printLL(head1);
        //printLL(head2);
        //merge two lists
        ListNode* tmp = new ListNode();
        ListNode* res = head1;
        while(head1 && head2){
            tmp -> next = head1;
            head1 = head1 -> next;
            tmp = tmp -> next;

            tmp -> next = head2;
            head2 = head2 -> next;
            tmp = tmp -> next;
        } 
        if(head1)
            tmp -> next = head1;
        
    }
};
