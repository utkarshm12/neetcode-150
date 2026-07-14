class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<long, vector<int>>> pq;

        for(int i = 0; i < points.size(); i++){
            long x = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({x, points[i]});
            if(i >= k) pq.pop();
        }

        while(k--){
            vector<int> c = pq.top().second;
            pq.pop();
            ans.push_back(c);
        }

        return ans;
    }
};
