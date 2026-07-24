class Solution {
    int row, col;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 0) calc(grid, i, j, 0);
            }
        }
    }

    void calc(vector<vector<int>>& grid, int r, int c, int dist){
        if(grid[r][c] < dist) return;
        
        grid[r][c] = min(grid[r][c], dist);
        dist++;

        if(r+1 < row) calc(grid, r+1, c, dist);
        if(r > 0) calc(grid, r-1, c, dist);
        if(c+1 < col) calc(grid, r, c+1, dist);
        if(c > 0) calc(grid, r, c-1, dist);

    }
};
