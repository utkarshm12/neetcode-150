class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        sol(nums, temp, 0);
        return ans;
    }

    void sol(vector<int>& nums, vector<int>& temp, int i){
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        sol(nums, temp, i+1);
        temp.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        
        sol(nums, temp, i+1);
    }
};
