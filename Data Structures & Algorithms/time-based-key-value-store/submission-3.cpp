class TimeMap {
    map<pair<string, int>, string> mp;
    unordered_map<string, vector<int>> mn;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[{key, timestamp}] = value;
        mn[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        vector<int> nums = mn[key];
        int n = nums.size();
        int s = 0, e = n-1;
        int md=0, idx = -1;

        while(s <= e){
            md = (s+e)/2;
            if(nums[md] <= timestamp){
                idx = md;
                s = md+1;
            }
            else e = md-1;
        }
        
        return idx == -1 ? "" : mp[{key, nums[idx]}];
    }
};
