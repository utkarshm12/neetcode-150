class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> ids;

        for(int i = 0; i <= n; i++){
            while(!ids.empty() && (i == n || heights[ids.top()] >= heights[i])){
                int h = heights[ids.top()];
                ids.pop();
                int w = ids.empty() ? i : i - ids.top() - 1;

                ans = max(ans, h*w);
            }
            ids.push(i);
        }

        return ans;

    }
};
