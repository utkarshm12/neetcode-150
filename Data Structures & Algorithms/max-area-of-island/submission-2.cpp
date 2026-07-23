class Solution {
    int ans = 0;
    int row, col;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int c = 0;
                if(grid[i][j] == 1) area(grid, i, j, c);
            }
        }

        return ans;
    }

    void area(vector<vector<int>>& grid, int i, int j, int& c){
        if(grid[i][j] == 0) return;

        grid[i][j] = 0;
        c++;
        ans = max(ans, c);

        if(i+1 < row) area(grid, i+1, j, c);
        if(i > 0) area(grid, i-1, j, c);
        if(j+1 < col) area(grid, i, j+1, c);
        if(j > 0) area(grid, i, j-1, c);
    }
};
