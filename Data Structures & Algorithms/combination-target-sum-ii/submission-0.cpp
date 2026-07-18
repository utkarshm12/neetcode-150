class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> temp;
        sort(nums.begin(), nums.end());
        sol(nums, target, n, temp, 0, 0);
        return ans;
    }

    void sol(vector<int>& nums, int& target, int& n, vector<int>& temp, int i, int sum){
        if(i>= n || sum >= target){
            if(sum == target) ans.push_back(temp);
            return;
        }
        
        for(int j = i; j < n; j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            if(sum + nums[j] > target) return;
            temp.push_back(nums[j]);
            sol(nums, target, n, temp, j+1, sum+nums[j]);
            temp.pop_back();
        }
    
    }
};

