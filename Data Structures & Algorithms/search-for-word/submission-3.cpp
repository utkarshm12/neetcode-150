class Solution {
    bool ans = false;
    int row, col;
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size(), col = board[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    sol(board, word, i, j, 0);
                }
                if(ans) return true;
            }
        }
        return false;
    }

    void sol(vector<vector<char>>& board, string& word, int i, int j, int id){
        if(ans || id == word.size()-1){
            ans = true;
            return;
        }

        board[i][j] = '0'; id++;
        if(i+1 < row && board[i+1][j] == word[id]) sol(board, word, i+1, j, id);
        if(i > 0 && board[i-1][j] == word[id]) sol(board, word, i-1, j, id);
        if(j+1 < col && board[i][j+1] == word[id]) sol(board, word, i, j+1, id);
        if(j > 0 && board[i][j-1] == word[id]) sol(board, word, i, j-1, id);
        board[i][j] = word[id-1];

    }
};
