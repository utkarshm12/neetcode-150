class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = INT_MIN;
        int id = 0, l = 0;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(mx <= nums[i]) mx = nums[i], id = i;
            if(i + 1 >= k){
                if(id < l){
                    mx = nums[l], id = l;
                    for(int j = l+1; j <= i; j++) if(mx <= nums[j]) mx = nums[j], id = j; 
                }
                ans.push_back(mx);
                l++;
            }
        }

        return ans;
    }
};
