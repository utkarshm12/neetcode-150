class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> mp;
        int n = nums.size();

        for(auto int i = 0; i < n; i++) mp.push_back({nums[i], i});

        sort(mp.begin(), mp.end());

        int i = 0, j = n-1;
        while(i < j){
            if(mp[i].first + mp[j].first > target) j--;
            else if(mp[i].first + mp[j].first < target) i++;
            else{
                if(mp[i].second < mp[j].second) return {mp[i].second, mp[j].second};
                return {mp[j].second, mp[i].second};
            }
        }
    }
};
