class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> temp;
        sol(nums, target, n, temp, 0, 0);
        // for(auto i : res) ans.push_back(i);
        return ans;
    }

    void sol(vector<int>& nums, int& target, int& n, vector<int>& temp, int i, int sum){
        if(i>= n || sum >= target){
            if(sum == target) ans.push_back(temp);
            return;
        }

        if(sum + nums[i] <= target){
            temp.push_back(nums[i]);
            sol(nums, target, n, temp, i, sum+nums[i]);
            temp.pop_back();
        }

        sol(nums, target, n, temp, i+1, sum);
    
    }
};
