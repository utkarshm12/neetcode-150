class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mx = 0;

        for(auto num : nums){
            if(!mp[num]){
                mp[num] = mp[num-1] + mp[num+1] + 1;
                mp[num - mp[num - 1]] = mp[num + mp[num+1]] = mp[num];
                mx = max(mx, mp[num]);
            }
        }

        return mx;
    }
};
