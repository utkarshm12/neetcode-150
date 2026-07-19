class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        sol(n, s, 0, 0);
        return ans;
    }

    void sol(int n, string& s, int open, int close){
        if(s.length() == 2*n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            s += '(';
            sol(n, s, open+1, close);
            s.pop_back();
        }
        if(close < open){
            s += ')';
            sol(n, s, open, close+1);
            s.pop_back();
        }
    }
};
