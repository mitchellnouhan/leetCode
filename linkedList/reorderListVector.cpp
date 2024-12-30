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
    void reorderList(ListNode* head) {
        ListNode* tmp = head;
        vector<ListNode* > LL;
        while (tmp){
            LL.push_back(tmp);
            tmp = tmp -> next;
        }
        
        int l = 0;
        int r = LL.size() - 1;
        while (l < r){
            LL[l] -> next = LL[r];
            l++;
            LL[r] -> next = LL[l];
            r--;
        }
        LL[l] -> next = nullptr;
    }
};
