class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string, string>> cp(n);

        for(int i = 0; i < n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            cp[i] = {s, strs[i]};
        }

        sort(cp.begin(), cp.end());

        vector<vector<string>> ans;
        int id = 0;
        ans.push_back({cp[0].second});

        for(int i = 1; i < n; i++){
            if(cp[i].first != cp[i-1].first){
                id++;
                ans.push_back({cp[i].second});
            }
            else ans[id].push_back(cp[i].second);
        }

        return ans;

    }
};
