class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int id = 0, mn = 0, ans = 0;
        stack<int> st;

        for(int i = 0; i < n; i++){

            mn = min(heights[i], mn);
            int ar = mn * (i-id+1);

            if(ar <= heights[i]) ar = heights[i], id = i, mn = heights[i];
            cout << ar << " ";
            ans = max(ans, ar);
        }

        cout << endl;
        
        for(int i = n-1; i >= 0; i--){
            mn = min(heights[i], mn);
            int ar = mn * (id-i+1);

            if(ar < heights[i]) ar = heights[i], id = i, mn = heights[i];
            cout << ar << " ";
            ans = max(ans, ar);
        }

        return ans;
    }
};
