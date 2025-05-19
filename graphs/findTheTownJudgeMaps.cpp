class Solution {
public:
    bool person_does_not_trust_suspect(vector<int>& n, int suspect){
        for(int trustee: n){
            if(trustee == suspect){
                return true;
            }
        }
        return false;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> graph(n);
        for(const auto& elem: trust){
            int truster = elem[0];
            int trustee = elem[1];
            graph[truster].push_back(trustee);
        }

        // does one person that trusts nobody exist? 
        vector<int> trusts_nobody;
        for(int i = 1; i <= n; i++){
            if(graph[i].size() == 0){
                trusts_nobody.push_back(i);
            }
        }

        if(trusts_nobody.size() != 1){
            return -1;
        }

        // does everyone trust town judge?
        for(int i = 1; i <= n; i++){
            if(i != trusts_nobody[0] && !person_does_not_trust_suspect(graph[i], trusts_nobody[0])){
                return -1;
            }
        }
        return trusts_nobody[0];
    }
};