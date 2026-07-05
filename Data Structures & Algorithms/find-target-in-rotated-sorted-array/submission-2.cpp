class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1, md = 0;

        while(s <= e){
            md = (s+e)/2;

            if(target == nums[md]) return md;

            if(nums[s] <= nums[md]){
                if(nums[s] <= target && nums[md] >= target) e = md-1;
                else s = md+1;
            }
            else{
                if(nums[md] <= target && nums[e] >= target) s = md+1;
                else e = md-1;
            }

        }

        return -1;
    }
};
