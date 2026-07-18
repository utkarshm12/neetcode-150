class Twitter {
    unordered_map<int, unordered_set<int>> lists;
    unordered_map<int, vector<pair<int, int>>> mp;
    int time = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({time++, tweetId});
        lists[userId].insert(userId);
        if(mp[userId].size() > 10) mp[userId].erase(mp[userId].begin());
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        // priority_queue<<vector<int>, vector<vector<int>>, greater<vector<int>>> mn;
        priority_queue<vector<int>> mx;

        for(auto follower : lists[userId]){
            if(mp.find(follower) == mp.end()) continue;
            int id = mp[follower].size()-1;
            pair<int, int> p = mp[follower][id];
            mx.push({p.first, p.second, follower, id});
            // if(mx.size() > 10) mx.pop();
        }

        while(!mx.empty() && ans.size() < 10){
            vector<int> top = mx.top();
            mx.pop();
            ans.push_back(top[1]);
            int id = top[3]-1;
            if(id >= 0){
                pair<int, int> p = mp[top[2]][id];
                mx.push({p.first, p.second, top[2], id});
            } 
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        lists[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        lists[followerId].erase(followeeId);
    }
};
