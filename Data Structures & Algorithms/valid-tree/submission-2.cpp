class Solution {
    vector<int> visited;
    unordered_map<int, vector<int>> list;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        visited.resize(n, 0);

        for(auto i : edges){
            list[i[0]].push_back(i[1]);
            list[i[1]].push_back(i[0]);    
        }

        if(dfs(0, -1)) return false;

        for(int i = 0; i < n; i++) if(!visited[i]) return false;

        return true;
    }

    bool dfs(int i, int parent){
        visited[i] = 1;

        for(auto j : list[i]){
            if(j == parent) continue;
            if(visited[j]) return true;
            if(dfs(j, i)) return true;
        }

        return false;
    }
};
