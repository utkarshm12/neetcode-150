class Solution {
    unordered_map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}}, 
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    vector<string> ans;
    int n;
public:
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        string s;
        if(digits.size() == 0) return {};
        sol(digits, 0, s);
        return ans;    
    }

    void sol(string& digits, int id, string& s){
        if(s.size() == digits.size()){
            ans.push_back(s);
            return;
        }

        for(int i = 0; i < mp[digits[id]].size(); i++){
            s += mp[digits[id]][i];
            sol(digits, id+1, s);
            s.pop_back();
        }
    }
};
