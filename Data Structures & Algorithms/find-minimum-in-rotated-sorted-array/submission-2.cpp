class Solution {
public:
    int findMin(vector<int> &nums) {
        int s = 0, e = nums.size()-1, md = 0;
        while(s < e){
            md = (s+e)/2;

            if(nums[md] > nums[e]) s = md+1;
            else e = md;
        }

        return nums[s];
    }
};
