class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<long, pair<int, int>>, vector<pair<long, pair<int, int>>>, greater<pair<long, pair<int, int>>>> pq;

        for(auto i : points){
            long x = i[0] * i[0] + i[1] * i[1];
            pq.push({x, {i[0], i[1]}});
            // cout << x << " : " << i[0] << " " << i[1] << endl; 
        }

        while(k--){
            pair<int, int> c = pq.top().second;
            pq.pop();
            ans.push_back({c.first, c.second});
        }

        return ans;
    }
};
