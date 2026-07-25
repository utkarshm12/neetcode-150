class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<pair<bool, bool>>> ap(r, vector<pair<bool, bool>> (c, pair<bool, bool> {false, false}));
        queue<pair<int, int>> a, p;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> ans;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(i == 0 || j == 0){
                    ap[i][j].first = true;
                    p.push({i, j});
                }
                if(i == r-1 || j == c-1){
                    ap[i][j].second = true;
                    a.push({i, j});
                }
            }
        }

        while(!a.empty()){
            auto [row, col] = a.front();
            a.pop();
            for(auto d : dir){
                int nr = row + d.first;
                int nc = col + d.second;

                if(nr < 0 || nc < 0 || nr >= r || nc >= c || ap[nr][nc].second || heights[row][col] > heights[nr][nc]) continue;
                ap[nr][nc].second = true;
                a.push({nr, nc});
            }
        }

        while(!p.empty()){
            auto [row, col] = p.front();
            p.pop();
            if(ap[row][col].first && ap[row][col].second) ans.push_back({row, col});

            for(auto d : dir){
                int nr = row + d.first;
                int nc = col + d.second;

                if(nr < 0 || nc < 0 || nr >= r || nc >= c || ap[nr][nc].first|| heights[row][col] > heights[nr][nc]) continue;
                ap[nr][nc].first = true;
                p.push({nr, nc});
            }
        }

        return ans;
    }
};
