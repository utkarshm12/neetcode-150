class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> wt(n+1, INT_MAX);
        vector<vector<pair<int, int>>> list(n+1);

        for(auto& i : times) list[i[0]].push_back({i[1], i[2]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        wt[k] = 0;
        pq.push({wt[k], k});
        int ans = 0;

        while(!pq.empty()){
            auto [w, node] = pq.top();
            pq.pop();   

            if(w > wt[node]) continue;

            for(auto& i : list[node]){
                int cw = w+i.second;
                if(cw < wt[i.first]){
                    wt[i.first] = cw;
                    pq.push({wt[i.first], i.first});
                }
            }
        }

        for(int i = 1; i <= n; i++){
            if(wt[i] == INT_MAX) return -1;
            ans = max(ans, wt[i]);
        }

        return ans;
    }
};
