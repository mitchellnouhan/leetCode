class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for (char c : s){
            if(closeToOpen.count(c) == 0)
                stack.push(c);     
            else if (stack.empty() || stack.top() != closeToOpen[c])
                return false;
            else
                stack.pop();
        }
        return stack.empty();
    }
};
