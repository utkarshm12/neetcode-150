class Solution {
    vector<int> dp;
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        return max(solve(0, nums), solve(1, nums));
    }

    int solve(int i, vector<int>& nums){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = nums[i] + max(solve(i+2, nums), solve(i+3, nums));
    }
};
