class Solution {
    vector<vector<vector<int>>> list;
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int h = n*n - 1, l = 0;
        int ans = h;
        list.resize(n*n);
        create(grid, n);

        return find(grid[0][0], n);
    }
    
    int find(int start, int n){
        vector<int> wt(n*n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        wt[0] = start;
        pq.push({start, 0});

        while(!pq.empty()){
            auto [w, node] = pq.top();
            pq.pop();   

            if(node == n*n -1) return w;
            if(w > wt[node]) continue;

            for(auto& i : list[node]){
                int cw = max(w, i[1]);
                if(cw < wt[i[0]]){
                    wt[i[0]] = cw;
                    pq.push({wt[i[0]], i[0]});
                }
            }
        }

        return wt[n*n-1];
    }

    void create(vector<vector<int>>& grid, int n){
        int id = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(i > 0) list[id].push_back({id-n, grid[i-1][j]});
                if(j > 0) list[id].push_back({id-1, grid[i][j-1]});
                if(i+1 < n) list[id].push_back({id+n, grid[i+1][j]});
                if(j+1 < n) list[id].push_back({id+1, grid[i][j+1]});
                id++;
            }
        }
    }
};
