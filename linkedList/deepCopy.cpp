/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
        -USE A HASH MAP! (or a vector of pairs in this case?)
        - iterate thru LL once to create new nodes,
        - iterate again to set new nodes' pointers
        */
        unordered_map<Node*, Node*> hashMap;
        Node* tmp = head;
        while(tmp){
            Node* cpy = new Node(tmp -> val);
            hashMap[tmp] = cpy;
            tmp = tmp -> next;
        }
        tmp = head;
        while(tmp){
            hashMap[tmp] -> next = hashMap[tmp -> next];
            hashMap[tmp] -> random = hashMap[tmp -> random];
            tmp = tmp -> next;
        }
        return hashMap[head];
    }
};
