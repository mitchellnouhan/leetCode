/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    /*
    looking at fast solutions, here is an alternate method
    instead of doing a check for each node: O(n^2) :(,
    we can just set two pointers a blazin, one is moving twice as fast as the other, 
    if there is a cycle, the faster pointer will collide with the first one,
    if there is no cycle, the faster pointer will eventually hit NULL
    No need for a helper function with this method either.   
    */
    //base cases
    if(head == NULL || head -> next == NULL){
        return false;
    }
    
    //init two pointers
    struct ListNode* point1 = head;
    struct ListNode* point2 = head;
    while (point2 != NULL){
        point2 = point2 -> next;
        if(point2 == NULL){
            return false;
        }

        if (point2 == point1){
            return true;
        }
        
        point1 = point1 -> next;
        point2 = point2 -> next;
    }
    return false;
}