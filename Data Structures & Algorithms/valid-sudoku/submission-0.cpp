class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++){
            vector<int> freq(9);

            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                freq[num-1]++;
                if(freq[num-1] > 1) return false;
            }
        }

        for(int j = 0; j < 9; j++){
            vector<int> freq(9);

            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0' - 1;
                freq[num]++;
                if(freq[num] > 1) return false;
            }
        }

        for(int i = 0; i < 9; i++){
            vector<int> freq(9);

            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    int r = j + (i/3) * 3;
                    int c = k + (i%3) * 3;
                    if(board[r][c] == '.') continue;
                    int num = board[r][c] - '0' - 1;
                    freq[num]++;
                    if(freq[num] > 1) return false;
                }
            }
        }

        return true;
    }
};
