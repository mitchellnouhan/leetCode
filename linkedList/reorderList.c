/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head){
    //init helper pointers 
    struct ListNode* hd = head;
    struct ListNode* tmp = head;
    struct ListNode* tail = head;
    //update tail to reach EO LL
    while (tail -> next){
        tail = tail -> next;
    }
    //assign tmp to hd->next
    tmp = hd -> next;

    while (tmp != tail && tail -> next != tmp){
        //Li -> Ln-i & Ln-i -> Li+1
        hd -> next = tail;   
        tail -> next = tmp;
        //update hd
        hd = tmp;
        //move tmp one position behind tail
        while (tmp -> next != tail){
            tmp = tmp -> next;
        }
        //update tail to tmp
        tail = tmp;
        //update tmp back to one node in front of hd
        tmp = hd -> next;
    }
    tail -> next = NULL;
}