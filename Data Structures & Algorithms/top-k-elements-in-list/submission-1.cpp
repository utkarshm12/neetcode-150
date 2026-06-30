class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) mp[nums[i]]++;

        vector<vector<int>> freq(n+1);

        for(auto i : mp) freq[i.second].push_back(i.first);

        vector<int> ans;

        for(int i = n; i >= 0; i--){
            for(int j = 0; j < freq[i].size(); j++){
                ans.push_back(freq[i][j]);
                k--;
                if(k <= 0) return ans;
            }
        }

        return ans;
        
        
    }
};
