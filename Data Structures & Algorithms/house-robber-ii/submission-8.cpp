class Solution {
public:
    int solve(int start, int n, vector<int>& nums){
        if(start >= n-1) return nums[start];
        vector<int> dp(n, 0);
        
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);

        for(int i = start+2; i < n; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(solve(0, n-1, nums), solve(1, n, nums));
    }
};
