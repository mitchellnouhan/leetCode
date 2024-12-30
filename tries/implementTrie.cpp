class Node {
public:
    unordered_map<char, Node*> letters;
    bool eow;
    Node(){
        eow = false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        //init root
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(char c: word){
            if(!cur -> letters[c]){
                cur -> letters[c] = new Node();
            }
            cur = cur -> letters[c];
        }
        cur -> eow = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(char c: word){
            if(!cur -> letters[c]){
                return false;
            }
            cur = cur -> letters[c];
        }
        return cur -> eow;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char c: prefix){
            if(!cur -> letters[c]){
                return false;
            }
            cur = cur -> letters[c];
        }
        return true;
    }
};
