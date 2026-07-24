class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++) if(grid[i][j] == 0) q.push({i, j});

        while(!q.empty()){
            for(int i = 0; i < 4; i++){
                int nr = q.front().first + dir[i].first;
                int nc = q.front().second + dir[i].second;
                if(nr < 0 || nr >= r || nc < 0 || nc >= c || grid[nr][nc] != INT_MAX) continue;
                grid[nr][nc] = grid[q.front().first][q.front().second] + 1;
                q.push({nr, nc});
            }
            q.pop();
        }
    }
};
