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
    bool hasCycle(ListNode* head) {
        /*
        use a visit hash table
        key,value -> ListNode*, bool
        */
        unordered_map<ListNode*, bool> visited;
        ListNode* tmp = head;
        while(tmp){
            if(visited[tmp] == true)
                return true;
            visited[tmp] = true;
            tmp = tmp -> next;
        }
        return false;
    }
};
