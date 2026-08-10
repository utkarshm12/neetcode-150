class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){
            vector<int> cur = pq.top();
            pq.pop();

            int wt = cur[0], i = cur[1], j = cur[2];
            
            if(i == n-1 && j == n-1) return wt;
            if(visited[i][j]) continue;

            visited[i][j] = true;
            for(auto d : dir){
                int nx = i + d[0], ny = j + d[1];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
                int cur_wt = max(wt, grid[nx][ny]);
                pq.push({cur_wt, nx, ny});
            }            
        }

        return -1;
    }
};
