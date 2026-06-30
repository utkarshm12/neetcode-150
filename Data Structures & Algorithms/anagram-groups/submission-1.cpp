class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> freq;

        for(auto s : strs){
            vector<int> f(26, 0);
            for(auto ch : s) f[ch-'a']++;

            string id = to_string(f[0]);
            for(int i = 1; i < 26; i++) id += ',' + to_string(f[i]);
            freq[id].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto i : freq) ans.push_back(i.second);

        return ans;
    }
};
