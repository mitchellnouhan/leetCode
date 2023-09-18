/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //diagnostic code
void printLinkedList(struct ListNode* head){
    struct ListNode* dummy = head;
    while (dummy != NULL){
        printf("%d, ", dummy -> val);
        dummy = dummy -> next;
    }
    printf("\n");
}

struct ListNode* newNode(int value){
    struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new -> val = value;
    new -> next = NULL;
    return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    // create a new LL
    struct ListNode head;
    struct ListNode* tmp = &head;
    // iterate thru LLs and keep adding to new LL while l1 has nodes, l2 has nodes, or there's still a carryover
    int value = 0;
    int carryOver = 0;
    while (l1 || l2 || carryOver){
        value += carryOver;
        carryOver = 0;

        if (l1){
            value += l1 -> val;
            l1 = l1 -> next;
        }

        if (l2){
            value += l2 -> val;
            l2 = l2 -> next;
        }

        if (value > 9){
            carryOver = value / 10;
            value %= 10;
        }
        tmp -> next = newNode(value);
        tmp = tmp -> next;
        value = 0;
    }
    return head.next;
}