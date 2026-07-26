class Solution {
    int row, col;
public:
    void solve(vector<vector<char>>& board) {
        row = board.size(), col = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0 || j == 0 || i == row-1 || j == col-1){
                    if(board[i][j] == 'O') {
                        q.push({i, j});
                        board[i][j] = 'N';    
                    }
                }
            }
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(auto d : dir){
                int i = r + d[0], j = c + d[1];
                if(i < 0 || j < 0 || i == row || j == col || board[i][j] != 'O') continue;
                board[i][j] = 'N';
                q.push({i, j});
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'N') board[i][j] = 'O';
            }
        }
        
    }

};
