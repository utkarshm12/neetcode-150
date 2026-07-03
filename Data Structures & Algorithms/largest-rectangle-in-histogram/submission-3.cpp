class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int idl = 0, mnl = 0, idr = n-1, mnr = 0, ans = 0;
        stack<int> st;

        for(int i = 0; i < n; i++){

            mnl = min(mnl, heights[i]);
            mnr = min(mnr, heights[n-i-1]);

            int arl = mnl * (i-idl+1);
            int arr = mnr * (idr - n + i + 2);

            if(arl <= heights[i]) arl = heights[i], idl = i, mnl = heights[i];
            if(arr <= heights[n-i-1]) arr = heights[n-i-1], idr = n-i-1, mnr = heights[n-i-1];
            
            // cout << arl << " " << arr << "\n";

            ans = max(ans, max(arl, arr));
        }

        return ans;
    }
};
