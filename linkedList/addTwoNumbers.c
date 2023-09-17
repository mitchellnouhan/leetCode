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

struct ListNode* addUpLinkedLists(struct ListNode* bigHead, struct ListNode* smallHead){
    // init helper variables
    int value = 0;
    int carryOver = 0;
    struct ListNode* prev = NULL;
    struct ListNode* big = bigHead;
    struct ListNode* small = smallHead;
    // iterate through small and big LLs until you reach end of small LL
    while (small != NULL){
        //add the values of the Nodes and modify big LL's val
        value += (big -> val + small -> val);
        //adjust value and carryOver if val is more than 1 digit
        if (value > 9){
            carryOver = value / 10;
            value %= 10;
        }
        else{
            carryOver = 0;
        }
        //update big node's val with value
        big -> val = value;
        //update value for next cycle with carryOver from this cycle
        value = carryOver;
        //update both LLs
        small = small -> next;
        prev = big;
        big = big -> next;
    }
    // while big still has nodes 
    while (big != NULL){
        
        //keep iterating thru big LL and countinue the adding process
        value += big -> val;
        //adjust value and carryOver if val is more than 1 digit
        if (value > 9){
            carryOver = value / 10;
            value %= 10;
        }
        else{
            carryOver = 0;
        }
        //update big node's val with value
        big -> val = value;
        //update value for next cycle with carryOver from this cycle
        value = carryOver;
        //update big LL
        prev = big;
        big = big -> next;
    }
    // once you've reached the end of big LL, check to see if a carried over value is present in the variable value
    if (value){
        //create a new node with value;
        struct ListNode* new = malloc(sizeof(struct ListNode));
        new -> val = value;
        new -> next = NULL;
        //update big node next pointer
        prev -> next = new;
    }
    return bigHead;
}

int grabLen(struct ListNode* head){
    struct ListNode* hd = head;
    int len = 1;
    while (hd -> next){
        len++;
        hd = hd -> next;
    }
    return len;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int len1 = grabLen(l1);
    int len2 = grabLen(l2);
    if (len2 > len1){
        l2 = addUpLinkedLists(l2,l1);
        return l2;
    }
    l1 = addUpLinkedLists(l1,l2);
    return l1;
}