class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int c = 0, prod = 1, id = 0;
        vector<int> pref(n, 1), ans(n, 1);

        for(int i = 0; i < n; i++){
            if(i > 0) pref[i] = pref[i-1] * nums[i-1];
            if(i < n-1) ans[n-i-2] *= nums[n-i-1] * ans[n-i-1];
        }

        for(int i = 0; i < n; i++) ans[i] *= pref[i];

        return ans;

    }
};
