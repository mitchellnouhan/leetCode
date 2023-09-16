/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode* head){
   //find the middle of the LL
   struct ListNode* fast = head;
   struct ListNode* slow = head;
   while (fast && fast -> next){
       slow = slow -> next;
       fast = (fast -> next) -> next;
   }

   //reverse the 2nd half of the LL (starting with slow pointer)
   struct ListNode* back = NULL;
   fast = slow -> next;
   while (fast){
       slow -> next = back;
       back = slow;
       slow = fast;
       fast = fast -> next;
   }
   slow -> next = back;

   //merge the 1st half & the reversed 2nd half
   struct ListNode* tmp = slow ->next;
   fast = head;
   back = fast -> next;
   while (tmp){
       fast -> next = slow;
       fast = back;
       

       slow -> next = fast;
       slow = tmp;

       back = back -> next;
       tmp = tmp -> next;
   }
}