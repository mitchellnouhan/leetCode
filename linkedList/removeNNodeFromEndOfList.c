/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //one pass shot attempt(no solution peeking)
    //base cases: 
    if(head -> next == NULL){
        return NULL;
    }

    //init two pointers to head: remove and lookahead
    struct ListNode* remove = head;
    struct ListNode* lookAhead = head;

    //move lookahead forward n - 1 nodes in front of remove
    for (int i = 0; i < (n - 1); i++){
        lookAhead = lookAhead -> next;
    }

    //assign a new pointer called prev to head
    struct ListNode* previous = head;

    //slide remove & lookahead down once
    if (lookAhead -> next != NULL){
        remove = remove -> next;
        lookAhead = lookAhead -> next;
    }
    

    //slide prev,remove, & lookahead until lookahead -> next == NULL
    while (lookAhead -> next != NULL){
        previous = previous -> next;
        remove = remove -> next;
        lookAhead = lookAhead -> next;
    }
    //handle case where we are removing the first node
    if (previous == remove){
        return remove -> next;
    }
    previous -> next = remove -> next;
    return head;
}