class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> visited(n+1, false);
        vector<int> wt(n+1, INT_MAX);
        vector<vector<pair<int, int>>> list(n+1);

        for(auto& i : times) list[i[0]].push_back({i[1], i[2]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        wt[k] = 0;
        pq.push({wt[k], k});
        int ans = 0;

        while(!pq.empty()){
            auto [w, node] = pq.top();
            visited[node] = true;
            pq.pop();

            for(auto i : list[node]){
                if(visited[i.first]) continue;
                if(w+i.second < wt[i.first]){
                    wt[i.first] = w+i.second;
                    pq.push({wt[i.first], i.first});
                }
            }
        }

        for(int i = 1; i <= n; i++) ans = max(ans, wt[i]);
        for(int i = 1; i <= n; i++) if(!visited[i]) return -1;
        return ans;
    }
};
