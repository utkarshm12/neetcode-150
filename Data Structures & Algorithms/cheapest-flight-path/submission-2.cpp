class Solution {
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> list(n);
        vector<vector<int>> cost(n, vector<int> (k+2, INT_MAX));

        for(int i = 0; i < flights.size(); i++){
            list[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, src, 0});

        while(!pq.empty()){
            vector<int> temp = pq.top(); pq.pop();
            int wt = temp[0], node = temp[1], edge_count = temp[2];

            if(node == dst) return wt;
            
            for(auto n : list[node]){
                int cur = wt + n.second;
                if(edge_count <= k && cur < cost[n.first][edge_count+1]){
                    cost[n.first][edge_count+1] = cur;
                    pq.push({cur, n.first, edge_count+1});
                }
            }
        }
        
        return -1;
    }
};
