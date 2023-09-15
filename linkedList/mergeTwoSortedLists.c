/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    //base cases: list1 or list2 are NULL/empty
    if (list1 == NULL && list2 == NULL){
        return list1;
    }
    else if (list1 == NULL){
        return list2;
    }
    else if (list2 == NULL){
        return list1;
    }

    //init the start of the new list with a head node and a tail pointer
    struct ListNode head;
    struct ListNode* tail = &head;
    while (list1 != NULL && list2!= NULL){
        // compare vals of list1 and list2
        //assign tail->next's value to lesser of values between list1/2
        //update list1/2 to their next nodes
        if (list1 -> val <= list2 -> val){
            tail -> next = list1;
            list1 = list1 -> next;
        }
        else{
            tail -> next = list2;
            list2 = list2 -> next;
        }
        //update tail
        tail = tail -> next;
    }
    // at this point either list1 or list2 is null
    // whichever list isn't null, assign tail->next to that non-null list
    if (list1 == NULL){
        tail -> next = list2;
    }
    else{
        tail -> next = list1;
    }
    // return the head
    return head.next;
}