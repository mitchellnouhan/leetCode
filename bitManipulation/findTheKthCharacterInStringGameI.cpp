class Solution {
public:
    char kthCharacter(int k) {
        vector<char> st = {'a'};
        while(st.size() < k){
            int st_cur_size = st.size();
            for(int i = 0; i < st_cur_size; i++){
                char c = st[i];
                char new_c = (c + 1) % ('z' + 1);
                st.push_back(new_c);
            }
        }
        return st[k - 1];
    }
};
