class Twitter {
    unordered_map<int, unordered_set<int>> mp;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<pair<int, pair<int, int>>> pq;
    int time = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({time++, {tweetId, userId}});
        mp[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        vector<pair<int, pair<int, int>>> temp;
        int sz = 0;
        while(!pq.empty() && sz < 10){
            temp.push_back(pq.top());
            if(mp[userId].find(pq.top().second.second) != mp[userId].end()) ans.push_back(pq.top().second.first), sz++;
            pq.pop();
        }
        for(auto i : temp) pq.push(i);

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        mp[followerId].erase(followeeId);
    }
};
