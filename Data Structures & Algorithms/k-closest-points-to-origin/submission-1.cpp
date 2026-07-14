class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<long, vector<int>>, vector<pair<long, vector<int>>>, greater<pair<long, vector<int>>>> pq;

        for(auto i : points){
            long x = i[0] * i[0] + i[1] * i[1];
            pq.push({x, i});
            // cout << x << " : " << i[0] << " " << i[1] << endl; 
        }

        while(k--){
            vector<int> c = pq.top().second;
            pq.pop();
            ans.push_back(c);
        }

        return ans;
    }
};
