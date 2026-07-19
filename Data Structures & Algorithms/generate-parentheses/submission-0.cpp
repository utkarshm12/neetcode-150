class Solution {
    set<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        sol(2*n, s);
        return vector<string> (ans.begin(), ans.end());
    }

    void sol(int n, string s){
        if(s.length() >= n){
            if(s.length() == n) ans.insert(s);
            return;
        }
        for(int i = 0; i <= s.length(); i++){
            s.insert(i, "()");
            sol(n, s);
            s.erase(i, 2);
        }
    }
};
