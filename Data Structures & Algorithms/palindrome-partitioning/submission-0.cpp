class Solution {
    int n;
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> temp;
        sol(s, 0, temp);
        return ans;
    }

    void sol(string& s, int id, vector<string>& temp){
        string str;
        if(id == n){
            ans.push_back(temp);
            return;
        }

        for(int i = id; i < n; i++){
            str += s[i];
            if(ispal(str)){
                temp.push_back(str);
                sol(s, i+1, temp);
                temp.pop_back();
            }
        }
    }

    bool ispal(string s){
        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
};
