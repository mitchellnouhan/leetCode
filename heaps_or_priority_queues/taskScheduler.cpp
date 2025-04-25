class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;

        vector<int> char_freq(26, 0);
        for(char task: tasks){
            char_freq[task - 'A']++;
        }

        priority_queue<int> max_heap;
        for(int i = 0; i < 26; i++){
            if(char_freq[i]){
                max_heap.push(char_freq[i]);
            }
        }
        
        queue<pair<int, int>> queue;
        while(!max_heap.empty() || !queue.empty()){
            //process queue
            //optimization to fast forward time:)
            if(!queue.empty() && max_heap.empty()){
                time = queue.front().first;
            }
            if(!queue.empty() && time >= queue.front().first){
                pair<int, int> cur = queue.front();
                queue.pop();
                max_heap.push(cur.second);
            }
            //process max_heap
            if(!max_heap.empty()){
                int cur = max_heap.top();
                max_heap.pop();
                if(cur > 1){
                    queue.push({time + n + 1, cur - 1});
                }
            }
            time++;
        }
        return time;
    }
};
