class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> temp(n, s);
        sol(temp, 0, n);
        return ans;
    }

    void sol(vector<string>& temp, int row, int n){
        
        if(row == n){
            ans.push_back(temp);
            return;
        }

        for(int j = 0; j < n; j++){
            if(check(temp, row, j, n)){
                temp[row][j] = 'Q';
                sol(temp, row+1, n);
                temp[row][j] = '.';
            }
        }
    }

    bool check(vector<string>& temp, int r, int c, int n){
        for(int i = 0; i < n; i++){
            if(i == r) continue;
            if(temp[r][i] == 'Q' || temp[i][c] == 'Q') return false;
        }
        for(int i = 1; i < n; i++){
            if(r+i < n){
                if(c+i < n && temp[r+i][c+i] == 'Q') return false;
                if(c-i >= 0 && temp[r+i][c-i] == 'Q') return false; 
            }
            if(r-i >= 0){
                if(c+i < n && temp[r-i][c+i] == 'Q') return false;
                if(c-i >= 0 && temp[r-i][c-i] == 'Q') return false; 
            }
        }

        return true;
    }
};
