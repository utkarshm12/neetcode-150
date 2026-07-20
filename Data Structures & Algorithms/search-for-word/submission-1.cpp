class Solution {
    bool ans = false;
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();
        string str;
        str += word[0];

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == word[0]){
                    sol(board, word, i, j, r, c, 0, str);
                }
            }
        }
        return ans;
    }

    void sol(vector<vector<char>> board, string& word, int i, int j, int row, int col, int id, string search){
        if(ans || i >= row || i < 0 || j >= col || j < 0 || search == word){
            if(search == word) ans = true;
            return;
        }

        board[i][j] = '0'; id++;
        if(i+1 < row && board[i+1][j] == word[id]) sol(board, word, i+1, j, row, col, id, search+word[id]);
        if(i > 0 && board[i-1][j] == word[id]) sol(board, word, i-1, j, row, col, id, search+word[id]);
        if(j+1 < col && board[i][j+1] == word[id]) sol(board, word, i, j+1, row, col, id, search+word[id]);
        if(j > 0 && board[i][j-1] == word[id]) sol(board, word, i, j-1, row, col, id, search+word[id]);
    }
};
