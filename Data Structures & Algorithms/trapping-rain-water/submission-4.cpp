class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmx = height[0], rightmx = height[n-1];
        int l = 0, r = n-1;
        int sum = 0;

        while(l < r){
            if(height[l] <= height[r]){
                leftmx = max(leftmx, height[l]);
                sum += leftmx - height[l];
                l++;
            }
            else {
                rightmx = max(rightmx, height[r]);
                sum += rightmx - height[r];
                r--;
            }
        }

        return sum;
    }
};
