class Solution {
    vector<int> dp1, dp2;
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp1.resize(n, -1);
        dp2.resize(n, -1);

        if(n == 1) return nums[0];

        return max(solve(0, nums, n-1, dp1), solve(1, nums, n, dp2));
    }

    int solve(int i, vector<int>& nums, int n, vector<int>& dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int n1 = nums[i] + solve(i+2, nums, n, dp);
        int n2 = solve(i+1, nums, n, dp);

        dp[i] = max(n1, n2);

        return dp[i];
    }
};
