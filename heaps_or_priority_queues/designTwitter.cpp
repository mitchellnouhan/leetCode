class Twitter {
public:
    int time;
    unordered_map<int, set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;  

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    void getTweetsHelper(int userId, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& min_heap){
        int iterations = (tweets[userId].size() >= 10) ? 10 : tweets[userId].size();
        int start = tweets[userId].size() - 1;
        for(int i = start; i > (start - iterations); i--){
            pair<int, int> tweet = tweets[userId][i];
            int timeStamp = tweet.first;
            int tweetId = tweet.second;
            if(min_heap.size() < 10){
                min_heap.push(tweet);
            }
            else if(timeStamp > min_heap.top().first){
                min_heap.pop();
                min_heap.push(tweet);
            }   
        }
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        getTweetsHelper(userId, min_heap);
        for(int followee: following[userId]){
            getTweetsHelper(followee, min_heap);
        }
        
        while(!min_heap.empty()){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId && following[followerId].count(followeeId) == 0){
            following[followerId].insert(followeeId);
        } 
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};