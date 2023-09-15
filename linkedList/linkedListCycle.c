/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool checkCur(struct ListNode* cur, struct ListNode* head){
    struct ListNode* check = head;
    while (check != cur){
        if (check == cur -> next){
            return true;
        }
        check = check -> next;
    }
    if (check == cur -> next){
        return true;
    }
    return false;
}

bool hasCycle(struct ListNode *head) {
    /*
    while we iterate through the linked list, for each node, we check if the cur node points to a previously explored node
    This code worked but was very slow:/
    */
    // base case of linked list of size 0 or uncy
    if (head == NULL || head -> next == NULL){
        return false;
    }

    struct ListNode* cur = head;
    while (cur != NULL){
        if (checkCur(cur, head)){
            return true;
        }
        cur = cur -> next;
    }
    return false;
}