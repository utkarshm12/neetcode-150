class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int c = 0, prod = 1, id = 0;
        vector<int> ans(n, 1);

        for(int i = 0; i < n; i++) {

            if(nums[i] == 0){
                c++;
                id = i;
                continue;
            }
            prod *= nums[i];
        }
        if(c > 1) return vector<int>(n, 0);
        if(c == 1){
            vector<int> temp(n, 0);
            temp[id] = prod;
            return temp;
        }

        for(int i = 0; i < n; i++) ans[i] = prod/nums[i];
        
        return ans;

    }
};
