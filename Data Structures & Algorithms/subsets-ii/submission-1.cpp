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
        
        ans.push_back(temp);
        
        for(int j = i; j < nums.size(); j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            temp.push_back(nums[j]);
            sol(nums, temp, j+1);
            temp.pop_back();
        }
        
    }
};
