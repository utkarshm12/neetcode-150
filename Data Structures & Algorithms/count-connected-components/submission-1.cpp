class Solution {
    vector<vector<int>> list;
    vector<int> visited;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        visited.resize(n, 0);
        list.resize(n);

        for(auto i : edges){
            list[i[0]].push_back(i[1]);
            list[i[1]].push_back(i[0]);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                ans++;
                visit(i);
            }
        }
        return ans;
    }

    void visit(int i){
        visited[i] = 1;
        for(auto j : list[i]) if(!visited[j]) visit(j);
    }
};
