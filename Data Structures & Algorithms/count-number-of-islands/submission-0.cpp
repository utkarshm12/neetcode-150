class Solution {
    int ans = 0;
    int row, col;
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size(), col = grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    ans ++;
                    visit(grid, i, j);
                }
            }
        }

        return ans;
    }

    void visit(vector<vector<char>>& grid, int i, int j){
        if(grid[i][j] == '0') return;

        grid[i][j] = '0';

        if(i+1 < row) visit(grid, i+1, j);
        if(i > 0) visit(grid, i-1, j);
        if(j+1 < col) visit(grid, i, j+1);
        if(j > 0) visit(grid, i, j-1);
    }
};
