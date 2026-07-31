class Solution {
    unordered_map<string, vector<string>> list;
    vector<string> res;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        int n = tickets.size()+1;
        for(auto i : tickets) list[i[0]].push_back(i[1]);

        res.push_back("JFK");
        dfs("JFK", n);

        return res;
    }

    bool dfs(string src, int n){
        if(res.size() == n) return true;
        if(list[src].size() == 0) return false;

        for(int i = 0; i < list[src].size(); i++){
            string temp = list[src][i];
            res.push_back(temp);
            list[src].erase(list[src].begin()+i);

            if(dfs(temp, n)) return true;

            list[src].insert(list[src].begin() + i, temp);
            res.pop_back();
        }

        return false;
    }
};
