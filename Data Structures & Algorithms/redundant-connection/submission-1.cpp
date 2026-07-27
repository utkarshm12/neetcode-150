class Solution {
    map<int, vector<int>> list;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        for(auto i : edges){
            list[i[0]].push_back(i[1]);
            list[i[1]].push_back(i[0]);
            unordered_map<int, bool> visited;

            // for(auto j : list)
            if(dfs(i[0], -1, visited)) return i;
        }


        
        return {};
    }

    bool dfs(int i, int parent, unordered_map<int, bool>& visited){
        visited[i] = true;

        for(auto j : list[i]){
            if(j == parent) continue;
            if(visited[j]) return true;
            if(dfs(j, i, visited)) return true;
        }

        return false;
    }
};
