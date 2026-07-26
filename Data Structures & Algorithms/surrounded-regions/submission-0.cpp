class Solution {
    int row, col;
public:
    void solve(vector<vector<char>>& board) {
        row = board.size(), col = board[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0 || j == 0 || i == row-1 || j == col-1){
                    if(board[i][j] == 'O') fill(board, i, j);
                }
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'N') board[i][j] = 'O';
            }
        }
    }

    void fill(vector<vector<char>>& board, int r, int c){
        if(r < 0 || c < 0 || r == row || c == col || board[r][c] != 'O') return;

        board[r][c] = 'N';
        fill(board, r+1, c);
        fill(board, r-1, c);
        fill(board, r, c+1);
        fill(board, r, c-1);
    }
};
