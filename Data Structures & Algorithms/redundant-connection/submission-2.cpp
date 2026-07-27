class Solution {
    vector<vector<int>> list;
    vector<bool> visited;
    vector<bool> cycle;
    int start = -1;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        list.resize(n+1);
        visited.resize(n+1, false);
        cycle.resize(n+1, false);

        for(auto i : edges){
            list[i[0]].push_back(i[1]);
            list[i[1]].push_back(i[0]);
        }

        dfs(1, -1);

        for(int i = n-1; i >= 0; i--){
            int n1 = edges[i][0], n2 = edges[i][1];
            if(cycle[n1] && cycle[n2]) return edges[i];
        }

        return edges[0];
        
    }

    bool dfs(int i, int parent){
        if(visited[i]){
            start = i;
            return true;
        }

        visited[i] = true;
        for(auto j : list[i]){
            if(j == parent) continue;
            if(dfs(j, i)){
                if(start != -1) cycle[i] = true;
                if(start == i) start = -1;
                return true;
            }
        }
        return false;
    }
};
