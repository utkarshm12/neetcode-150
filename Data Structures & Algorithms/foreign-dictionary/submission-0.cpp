class Solution {
    unordered_map<char, unordered_set<char>> list;
    unordered_map<char, bool> visited;
    string ans;
public:
    string foreignDictionary(vector<string>& words) {
        for(auto w : words)
            for(auto ch : w) list[ch];


        for(int i = 0; i < words.size()-1; i++){
            string s1 = words[i], s2 = words[i+1];
            int sz = min(s1.size(), s2.size());

            if(s1 > s2 && check(s1, s2, sz)) return "";
            for(int j = 0; j < sz; j++){
                if(s1[j] != s2[j]){
                    list[s1[j]].insert(s2[j]);
                    break;
                }
            }
        }

        for(auto i : list){
            if(dfs_cycle(i.first)) return "";
        }

        reverse(ans.begin(), ans.end());
        return ans;
    } 

    bool check(string& s1, string& s2, int sz){
        for(int i = 0; i < sz; i++) if(s1[i] != s2[i]) return false;
        return true;
    }

    bool dfs_cycle(char ch){
        if(visited.find(ch) != visited.end()) return visited[ch];

        visited[ch] = true;
        for(auto i : list[ch]){
            if(dfs_cycle(i)) return true;
        }
        visited[ch] = false;
        ans.push_back(ch);
        return false;
    }
};

