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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        use two pointers with a dummy node
        l   r
      l     r
        1,2,3,4

            l   r
          l     r 
        1,2,3,4   
        this works because you know that l -> next isn't null
        since r is null and at minimum, l is 2 nodes behind
        so l -> next will always not be null

        l -> next = l -> next -> next;

      l   r
        1

        1
        */

        //assign dummy node and two pointers
        ListNode* dummy = new ListNode(-1, head);
        ListNode* l = dummy;
        ListNode* r = head;

        //adjust r to the right n times
        int i = 0;
        // we can only worry about i and not accessing the next value of a nullptr w/ r bc 1 <= n <= sz
        while (i < n){ 
            r = r -> next;
            i++;
        }

        //move the whole window until r past list at null
        while(r){
            l = l -> next;
            r = r -> next;
        }

        //remove nth node
        /*
        this works because you know that l -> next isn't null
        since r is null and at minimum, l is 2 nodes behind
        so l -> next will always not be null
        */
        l -> next = l -> next -> next;
        return dummy -> next;
        
    }
};


