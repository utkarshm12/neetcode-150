class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        sol(nums, 0);
        return ans;
    }

    void sol(vector<int>& nums, int i){
        if(i >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++){
            swap(nums, i, j);
            sol(nums, i+1);
            swap(nums, i, j);
        }
    }

    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
