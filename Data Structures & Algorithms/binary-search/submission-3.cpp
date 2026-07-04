class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        int md = e/2;

        while(s <= e){
            if(nums[md] < target) s = md + 1;
            else if (nums[md] > target) e = md - 1;
            else return md;

            md = (s+e)/2;
        }

        return -1;
    }
};
