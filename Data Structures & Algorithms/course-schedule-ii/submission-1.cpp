class Solution {
    unordered_map<int, vector<int>> list;
    vector<int> visited, path, ans;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses, 0);
        path.resize(numCourses, 0);
        for(auto i : prerequisites) list[i[0]].push_back(i[1]);
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]) if(dfsc(i)) return {};
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }

    bool dfsc(int i){
        path[i] = 1, visited[i] = 1;
        for(auto j : list[i]){
            if(path[j]) return true;
            if(!visited[j] && dfsc(j)) return true;
        }
        path[i] = false;
        ans.push_back(i);
        return false;
    }
};
