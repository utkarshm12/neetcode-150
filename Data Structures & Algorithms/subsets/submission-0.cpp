class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        sub(nums, n, temp, 0);
        return ans;
    }

    void sub(vector<int>& nums, int& n, vector<int> temp, int i){
        if(i >= n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        sub(nums, n, temp, i+1);
        temp.pop_back();
        sub(nums, n, temp, i+1);
    }
};
