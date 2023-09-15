/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    //handle base cases of LLs of size 0 or 1
    if (head == NULL || head -> next == NULL){
        return head;
    }
    //init necessary tracking pointers
    struct ListNode* front = head -> next;
    struct ListNode* back = NULL;
    //start loop
    while (front != NULL){
        head -> next = back;
        back = head;
        head = front;
        front = front -> next;
    }
    head -> next = back;
    return head;
}