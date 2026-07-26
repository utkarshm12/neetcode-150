class Solution {
    vector<int> v;
    unordered_map<int, vector<int>> mp;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        v.resize(numCourses, 0);
        vector<int> pv(numCourses, 0);

        for(auto i : prerequisites) mp[i[0]].push_back(i[1]);
        
        for(int i = 0; i < numCourses; i++){
            if(!v[i]){
                if(dfsc(i, pv)) return false;
            }
        }
        return true;
    }

    bool dfsc(int i, vector<int>& pv){
        v[i] = 1;
        pv[i] = 1;

        for(auto j : mp[i]){
            if(v[j] && pv[j]) return true;
            if(!v[j] && dfsc(j, pv)) return true;
        }

        pv[i] = 0;
        return false;
    }
};
