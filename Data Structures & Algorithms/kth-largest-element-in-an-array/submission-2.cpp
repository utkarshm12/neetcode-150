class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int mx = nums[0], mn = nums[0];
        for(auto i : nums) mx = max(mx, i), mn = min(mn, i);
        
        vector<int> v(mx - mn + 1);
        int id = mx-mn;

        for(auto i : nums) v[i-mn]++;

        while(k--){
            while(v[id] == 0) id--;
            v[id]--;
        }

        return id+mn;

    }
};
