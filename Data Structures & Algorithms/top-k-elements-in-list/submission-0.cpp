class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;

        for(int i = 0; i < n; i++) mp[nums[i]]++;

        map<int, vector<int>> mp2;

        for(auto i : mp) mp2[i.second].push_back(i.first);

        vector<int> ans(k);
        int id = 0;

        for(auto i : mp2){
            for(int j = 0; j < i.second.size(); j++){
                ans[id] = i.second[j];
                id++;
                id %= k;
            }
        }

        return ans;
        
        
    }
};
