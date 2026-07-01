class Solution {
public:
    int maxArea(vector<int>& heights) {
        int s = 0, e = heights.size() - 1, mx = 0;

        while(s < e){
            mx = max(mx, min(heights[s], heights[e]) * (e-s));
            if(heights[s] < heights[e]) s++;
            else e--;
        }

        return mx;
        
    }
};
