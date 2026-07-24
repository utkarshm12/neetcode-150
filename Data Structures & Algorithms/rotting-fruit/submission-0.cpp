class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<vector<int>> q;
        int ans = 0;

        for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) if(grid[i][j] == 2) q.push({i, j, 0});

        while(!q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];

            ans = max(ans, q.front()[2]);
            for(auto i : d){
                int nr = r + i[0], nc = c + i[1];
                if(nr < 0 || nc < 0 || nr >= row || nc >= col || grid[nr][nc] != 1) continue;
                grid[nr][nc] = 2;
                q.push({nr, nc, ans+1});
            }
            q.pop();
        }

        for(auto i : grid) for(auto j : i) if(j == 1) return -1;
        return ans;
    }
};
