class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>> pq;
        priority_queue<int> pq;
        vector<int> freq(26);
        int ans = 0;

        for(auto i : tasks) freq[i-'A']++;

        for(auto i : freq){
            if(i > 0) pq.push(i);
        }

        while(!pq.empty()){
            vector<int> temp;
            for(int i = 0; !pq.empty() && i <= n; i++){
                temp.push_back(pq.top()-1);
                pq.pop();
            }
            for(int i = 0; i < temp.size(); i++){
                if(temp[i] > 0) pq.push(temp[i]);
            }
            ans += pq.empty() ? temp.size() : n+1;
        }

        return ans;
    }
};
