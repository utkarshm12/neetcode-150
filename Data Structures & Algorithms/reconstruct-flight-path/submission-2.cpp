class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> list;

        for(auto& ticket : tickets) list[ticket[0]].push_back(ticket[1]);

        for(auto& [src, destns] : list) sort(destns.rbegin(), destns.rend());

        vector<string> res;
        stack<string> st;
        st.push("JFK");

        while(!st.empty()){
            string cur = st.top();

            if(list[cur].empty()){
                res.push_back(cur);
                st.pop();
            }
            else{
                st.push(list[cur][list[cur].size()-1]);
                list[cur].pop_back();
            }
        }

        reverse(res.begin(), res.end());

        return res;
        
    }
};
