class Node {
public:
    unordered_map<char, Node*> letters;
    bool eow;
    Node(){
        eow = false;
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for(char c: word){
            if(cur -> letters.count(c) == 0){
                cur -> letters[c] = new Node();
            }
            cur = cur -> letters[c];
        }
        cur -> eow = true;
    }
    
    bool search_pound(string word, Node* cur){
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(const auto& pair: cur -> letters){
                    if(search_pound(word.substr(i + 1), pair.second)){
                        return true;
                    }
                }
                return false;
            }

            if(cur -> letters.count(c) == 0){
                return false;
            }
            cur = cur -> letters[c];
        }
        return cur -> eow;
    }


    bool search(string word) {
        Node* cur = root;
        return search_pound(word, cur);
    }
};
