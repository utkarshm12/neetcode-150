class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        int ans = 1;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                string s = q.front();

                if(s == endWord) return ans;

                for(auto w = wordList.begin(); w != wordList.end();){
                    if(match(s, *w)){
                        q.push(*w);
                        w = wordList.erase(w);
                    } else w++;
                }
                
                q.pop();
            }

            ans ++;
        }

        return 0;
    }

    bool match(string& s1, string& s2){
        int c = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]) c++;
            if(c > 1) return false;
        }
        return c == 1;
    }
};
