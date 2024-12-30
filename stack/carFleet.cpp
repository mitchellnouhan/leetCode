class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //we use the position and speed to calc the time to target
        //then sort the position and time arrays based on
        //position in descending position order
        //using an increasing stack, iterate thru sorted time arr
        //if cur time is < stack top, push
        //return size of the stack
        vector<float> stack;
        vector<pair<int, float>> pos_time;
        for(int i = 0; i < position.size(); i++){
            float time_to_target = ((float)target - position[i]) / speed[i];
            pos_time.push_back({position[i], time_to_target});
        }
        sort(pos_time.rbegin(), pos_time.rend());
        for(auto p: pos_time){
            if(stack.size() == 0 || p.second > stack.back())
                stack.push_back(p.second);
        }
        return stack.size();
    }
};
