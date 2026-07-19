class Solution {
    vector<vector<int>> ans;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<bool> taken(n, false);
        sol(nums, n, temp, taken);
        return ans;
    }

    void sol(vector<int>& nums, int n, vector<int>& temp, vector<bool>& taken){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!taken[i]){
                taken[i] = true;
                temp.push_back(nums[i]);
                sol(nums, n, temp, taken);
                temp.pop_back();
                taken[i] = false;
            }
        }
    }
};
