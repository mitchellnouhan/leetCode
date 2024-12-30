class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(string token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int operand2 = stack.back();
                stack.pop_back();
                int operand1 = stack.back();
                stack.pop_back();
                int ans;
                if(token == "+")
                    ans = operand1 + operand2;
                else if(token == "-")
                    ans = operand1 - operand2;
                else if(token == "*")
                    ans = operand1 * operand2;
                else
                    ans = operand1 / operand2;
                stack.push_back(ans);
            }
            else
                stack.push_back(stoi(token));
        }
        return stack.back();
    }
};
