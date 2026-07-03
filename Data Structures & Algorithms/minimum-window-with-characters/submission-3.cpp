class Solution {

    bool isSubset(unordered_map<char, int> super, unordered_map<char, int> sub){
        for(auto i : sub) if(super[i.first] < i.second) return false;
        return true;
    }

public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        
        int n = s.size(), l = 0;
        int mn = INT_MAX;
        unordered_map<char, int> ft, fs;
        string ans = "";

        for(auto c : t) ft[c]++;

        for(int i = 0; i < n; i++){
            fs[s[i]]++;
            while(isSubset(fs, ft)){
                if(i - l + 1 < mn){
                    mn = i-l+1;
                    ans = s.substr(l, mn);
                }
                fs[s[l++]]--;
            }
        }

        
        return ans;
    }
};
