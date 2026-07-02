class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = 0, low = INT_MAX;
        int s = 0, e = 1;

        for(int i = 1; i < n; i++){

            if(prices[i] < prices[s]) s = i;
            mx = max(mx, prices[i]-prices[s]);
        }

        return mx;
    }
};
